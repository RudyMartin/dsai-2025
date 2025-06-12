# -----------------------------------------------------------------------------
# ESP32‑S3 Block‑Sorter Helper Library (single‑file bundle)
# -----------------------------------------------------------------------------
#  * No emoji or non‑ASCII pictographs
#  * Added basic safety checks (argument clamps, try/except nets, file swaps)
#  * Suitable for micropython‑package style: copy to /flash; import sub‑modules
# -----------------------------------------------------------------------------

# ====================== lib/umqtt/simple.py ===================================
"""Trimmed MQTT client for MicroPython (publish‑only demo).
Only QoS 0 implemented – perfect for lightweight logging.
"""
import usocket as socket, ustruct as struct

_PKT_CONNECT   = 1
_PKT_CONNACK   = 2
_PKT_PUBLISH   = 3
_PKT_PINGREQ   = 12
_PKT_PINGRESP  = 13
_PKT_DISCONNECT= 14

_DEF_PORT      = 1883


def _encode_len(n):
    enc = bytearray()
    while True:
        n, d = divmod(n, 128)
        enc.append(d | (0x80 if n else 0))
        if not n:
            break
    return enc


class MQTTClient:
    """Ultra‑small subset: connect() / publish() / disconnect() / ping()."""

    def __init__(self, client_id, server, port=_DEF_PORT, keepalive=60):
        self.cid  = client_id if isinstance(client_id, bytes) else client_id.encode()
        self.srv  = server
        self.port = port
        self.ka   = keepalive
        self.sock = None

    # ---------------- private utils ----------------------------------------
    def _send(self, ctl, payload=b""):
        self.sock.write(bytes((ctl << 4,)) + _encode_len(len(payload)) + payload)

    def _read(self, n):
        data = self.sock.read(n) or b""
        if len(data) != n:
            raise OSError("Socket under‑read")
        return data

    # ---------------- public API -------------------------------------------
    def connect(self):
        self.sock = socket.socket()
        self.sock.connect(socket.getaddrinfo(self.srv, self.port)[0][-1])

        vh = b"\x00\x04MQTT\x04\x02" + struct.pack(">H", self.ka)
        pl = struct.pack(">H", len(self.cid)) + self.cid
        self._send(_PKT_CONNECT, vh + pl)

        resp = self._read(4)
        if resp[0] >> 4 != _PKT_CONNACK or resp[3] != 0:
            raise OSError("MQTT CONNACK error rc=%d" % resp[3])

    def publish(self, topic, msg, retain=False):
        if isinstance(topic, str):
            topic = topic.encode()
        if isinstance(msg, str):
            msg = msg.encode()
        flags = 1 if retain else 0
        payload = struct.pack(">H", len(topic)) + topic + msg
        self._send(_PKT_PUBLISH | flags, payload)

    def ping(self):
        self._send(_PKT_PINGREQ)
        # optional: verify PINGRESP

    def disconnect(self):
        try:
            self._send(_PKT_DISCONNECT)
        finally:
            if self.sock:
                self.sock.close()
                self.sock = None

# ====================== pca9685.py ===========================================
"""Small PCA9685 servo helper with angle‑clamp safety."""
from machine import I2C
import time

_MODE1     = 0x00
_PRESCALE  = 0xFE
_LED0_ON_L = 0x06

class PCA9685:
    def __init__(self, i2c: I2C, addr: int = 0x40, freq: int = 50):
        self.i2c  = i2c
        self.addr = addr
        self.reset()
        self.set_pwm_freq(freq)

    def reset(self):
        self.i2c.writeto_mem(self.addr, _MODE1, b"\x00")
        time.sleep_ms(5)

    def set_pwm_freq(self, freq_hz):
        prescale = int(25_000_000 / (4096 * freq_hz) - 1)
        old = self.i2c.readfrom_mem(self.addr, _MODE1, 1)[0]
        self.i2c.writeto_mem(self.addr, _MODE1, bytes([old | 0x10]))  # sleep
        self.i2c.writeto_mem(self.addr, _PRESCALE, bytes([prescale]))
        self.i2c.writeto_mem(self.addr, _MODE1, bytes([old]))
        time.sleep_ms(5)
        self.i2c.writeto_mem(self.addr, _MODE1, bytes([old | 0xA1]))  # restart

    def set_pwm(self, ch: int, on: int, off: int):
        data = bytearray((on & 0xFF, on >> 8, off & 0xFF, off >> 8))
        self.i2c.writeto_mem(self.addr, _LED0_ON_L + 4*ch, data)

    def set_servo_angle(self, ch: int, angle: int):
        angle = max(0, min(180, int(angle)))  # clamp for safety
        pulse_us = 500 + (angle * 2000) // 180  # 0.5‑2.5 ms
        ticks = pulse_us * 4096 // 20_000       # 20 ms period
        self.set_pwm(ch, 0, ticks)

# ====================== camera_pins_esp32s3.py ===============================
"""Configure Freenove ESP32‑S3 CAM pins safely; returns bool for success."""
from machine import Pin
import camera

_CAM_PINS = {
    'pwdn':  0,
    'reset': -1,
    'xclk':  10,
    'siod':  18,
    'sioc':  17,
    'd7':    15,
    'd6':    16,
    'd5':    6,
    'd4':    7,
    'd3':    11,
    'd2':    9,
    'd1':    8,
    'd0':    14,
    'vsync': 13,
    'href':  12,
    'pclk':  4,
}

_DEF_FRAME = camera.FRAME_VGA

def init_camera(framesize=_DEF_FRAME):
    if camera.isinitialized():
        return True
    try:
        camera.init(0, 0, 0, False)
        for name, gp in _CAM_PINS.items():
            if gp >= 0:
                camera.set_pin(name, Pin(gp))
        camera.framesize(framesize)
        camera.flip(0); camera.mirror(0)
        return True
    except Exception as e:
        print("Camera init failed:", e)
        return False

# ====================== img_utils.py =========================================
"""Capture‑and‑resize helper; raises explicit errors on failure."""
import camera

_DEF_SIZE = (96, 96)

def capture_rgb(size=_DEF_SIZE):
    buf = camera.capture()
    if buf is None:
        raise RuntimeError("Camera capture failed: buffer empty")
    img = camera.decode(buf, pixel_format=camera.RGB888)
    if img is None:
        raise RuntimeError("camera.decode returned None")
    w0, h0 = img.shape[1], img.shape[0]
    w1, h1 = size
    if w0 < w1 or h0 < h1:
        raise ValueError("Source smaller than target size")
    sx, sy = w0 // w1, h0 // h1
    rgb = bytearray(w1 * h1 * 3)
    k = 0
    for y in range(0, h0, sy):
        row = img[y]
        for x in range(0, w0, sx):
            r, g, b = row[x]
            rgb[k:k+3] = bytes((r, g, b)); k += 3
    return rgb

# ====================== edge_infer.py ========================================
"""Edge TFLite‑Micro inference with shape/size guards."""
import tflm_runtime.interpreter as tflm
import ulab as np

class EdgeInfer:
    def __init__(self, model_path="/models/blocks.tflite", shape=(1,96,96,3)):
        self.shape = shape
        self.interpreter = tflm.Interpreter(open(model_path, "rb").read())
        self.interpreter.allocate_tensors()
        self.inp = self.interpreter.get_input_details()[0]["index"]
        self.out = self.interpreter.get_output_details()[0]["index"]

    def classify(self, rgb):
        if len(rgb) != self.shape[1]*self.shape[2]*self.shape[3]:
            raise ValueError("RGB input size mismatch")
        arr = np.array(rgb, dtype=np.uint8).reshape(self.shape)
        self.interpreter.set_tensor(self.inp, arr)
        self.interpreter.invoke()
        scores = self.interpreter.get_tensor(self.out)
        idx = int(scores.argmax())
        conf = float(scores.max())/255.0
        return idx, conf

# ====================== cloud_fallback.py ====================================
"""Roboflow REST fallback with basic HTTP error handling."""
import urequests as rq, ujson as json

_URL = "https://detect.roboflow.com/{proj}/{ver}"

def classify_block(img_bytes, api_key, proj="blocks", ver="1"):
    url = _URL.format(proj=proj, ver=ver)
    try:
        resp = rq.post(url, params={"api_key": api_key}, files={"file": img_bytes})
        if resp.status_code != 200:
            raise RuntimeError("HTTP {}".format(resp.status_code))
        data = json.loads(resp.text)
        if not data.get("predictions"):
            return "unknown", 0.0
        p = data["predictions"][0]
        return p["class"], p["confidence"]
    finally:
        try:
            resp.close()
        except:  # noqa: E722
            pass

# ====================== update.py ============================================
"""OTA model updater with network and file safety checks."""
import os, ssl, socket

_CHUNK = 1024


def _https_stream(url):
    host = url.split("/", 3)[2]
    path = url[url.find("/", 8):]
    s = socket.socket(); s.connect(socket.getaddrinfo(host, 443)[0][-1])
    s = ssl.wrap_socket(s, server_hostname=host)
    req = "GET {} HTTP/1.0\r\nHost: {}\r\n\r\n".format(path, host)
    s.write(req.encode())
    while s.readline() != b"\r\n":
        pass  # skip headers
    return s


def check_and_apply(model_path, base_raw_url):
    try:
        cur_ver = open("/models/version.txt").read().strip()
    except OSError:
        cur_ver = "0"

    try:
        with _https_stream(base_raw_url + "version.txt") as sock:
            remote_ver = sock.read().decode().strip()
    except Exception as e:
        print("Version check failed:", e)
        return False

    if remote_ver == cur_ver:
        return False

    tmp = model_path + ".new"
    try:
        sock = _https_stream(base_raw_url + "blocks_v{}.
