
# 🚀 Full Setup Instructions (Blank ESP32 + Blank NAS)

---

# 📦 Part 1 — Set up the NAS folders and permissions

✅ **1. Create team folders on the NAS**
- Log into your NAS Admin Panel.
- Go to **Shared Folders**.
- Create a main folder:  
  ```
  /missions/2025/
  ```
- Inside `/missions/2025/`, create **one folder per team**:
  ```
  nova_alpha_logs/
  nova_beta_logs/
  vega_alpha_logs/
  vega_beta_logs/
  orion_alpha_logs/
  orion_beta_logs/
  ```

✅ **2. Create user accounts for teams**
- Create a **user** per team:
  - Username: `nova_alpha`
  - Password: `[simple secure password]`
- Set **folder permissions**:
  - Team user **can only write** to their own `/missions/2025/[team]_logs/` folder.
  - No admin rights anywhere else.

✅ **3. Enable SMB File Sharing (Windows/Mac compatible)**
- Enable **SMB** (Server Message Block) protocol on your NAS:
  - **Synology Example**: Control Panel → File Services → SMB → Enable.
- Optional: Enable **guest access** (read-only) for easy downloads later.

✅ **NAS Side Done.**

---

# 📡 Part 2 — Configure the WiFi

✅ **4. Create a dedicated WiFi for the camp**
- SSID: `AI_Mission_2025`
- Password: `SpaceMission2025`
- Network should allow devices to:
  - Reach the NAS local IP (e.g., `192.168.1.50`).

✅ **5. Optional but Smart:**
- Lock router DNS to **LAN only** (no public Internet if you want control).
- Turn on **Client Isolation** if you don't want students snooping on each other's devices.

✅ **WiFi Side Done.**

Instructions for ASUS __> Here’s the short version first, then the “why” in plain language.


## Quick Pick

| Goal                                                                 | Best Asus Mode                            | Why it works offline                                                                                                      |
| -------------------------------------------------------------------- | ----------------------------------------- | ------------------------------------------------------------------------------------------------------------------------- |
| **Single, self-contained Wi-Fi + NAS lab (no other router present)** | **Wireless Router mode (default)**        | Router hands out IP addresses (DHCP), so every laptop, ESP32, and the NAS can “see” one another even without a WAN cable. |
| Large space, need several nodes                                      | AiMesh **(all nodes in “Router/AP” mix)** | Same DHCP brain as above, but extra nodes extend coverage.                                                                |
| Already have *another* box giving out IP addresses                   | Access Point mode                         | Asus just adds Wi-Fi; it won’t try to run its own DHCP.                                                                   |
| Any other listed mode (Repeater / Media Bridge)                      | **Skip**                                  | They expect an existing internet Wi-Fi signal to repeat or bridge—doesn’t exist in an offline lab.                        |

---

## Step-by-Step for an Internet-Free Lab

1. **Factory-reset the router** (optional but clean slate helps).
2. **Leave it in “Wireless Router mode.”**
   *It will complain there’s no WAN—ignore or switch WAN type to “None/Disabled.”*
3. **Set a LAN subnet** you like, e.g. `192.168.20.1/24`.
4. **Enable DHCP** (default) so every device auto-gets an address.
   *If you want fixed addresses for the NAS or printers, create DHCP reservations.*
5. **Plug the NAS into any LAN port** (or the WAN port if the UI lets you repurpose it as LAN).
6. Give the **NAS either a static IP or a DHCP reservation**—makes it easy for students to find, e.g. `192.168.20.100`.
7. **Disable automatic firmware updates** (they’ll fail without internet and slow boot time).
8. Optional quality-of-life tweaks:

   * Add a local **DNS name** in the router (“camp-nas.local” → 192.168.20.100).
   * Turn off **NTP sync** on clients or point them to the router as an NTP server so timestamps stay sane.
   * Enable **SMB/AFP/NFS** shares on the NAS plus a guest-read-only folder for handouts and a writeable upload folder for student logs.


---

### What students will see

* Join SSID “Artemis-Lab”.
* They get an address like `192.168.20.42`.
* NAS is reachable at `\\camp-nas.local\shared` or `smb://192.168.20.100/shared`.
* ESP32 boards can POST JSON straight to `http://192.168.20.100/upload`.

---

# 🧠 Part 3 — Flash and Setup ESP32

✅ **6. Install MicroPython firmware on ESP32**
(Only needs to be done once.)

- Download MicroPython firmware for ESP32-S3 from [official site](https://micropython.org/download/esp32/).
- Flash using a tool like `esptool.py`:

```bash
esptool.py --chip esp32s3 erase_flash
esptool.py --chip esp32s3 write_flash -z 0x0 esp32s3-xxxxxx.bin
```

✅ **7. Install a simple WebREPL or USB Serial connection**
- Use **Thonny IDE** or **Ampy** to connect over USB.

✅ **8. Upload Starter Script to ESP32**
Here’s the **basic starter code**:

```python
# wifi_connect.py

import network
import time

def connect_wifi(ssid, password):
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print('Connecting to network...')
        wlan.connect(ssid, password)
        timeout = 10  # seconds
        start = time.time()
        while not wlan.isconnected():
            if time.time() - start > timeout:
                raise Exception("Could not connect to WiFi")
            time.sleep(1)
    print('Connected:', wlan.ifconfig())
    return wlan.ifconfig()

# main.py

from wifi_connect import connect_wifi
import urequests
import time
import machine

SSID = 'AI_Mission_2025'
PASSWORD = 'SpaceMission2025'
TEAM_NAME = 'nova_alpha'

# Connect WiFi
connect_wifi(SSID, PASSWORD)

# Dummy detection simulation
def fake_detection():
    return {
        'timestamp': time.time(),
        'object': 'robot',
        'confidence': 88,
        'decision': 'Deck B'
    }

# Save detection to CSV locally
def save_to_csv(data):
    filename = f"/{TEAM_NAME}_log.csv"
    try:
        with open(filename, "a") as f:
            f.write("{},{},{},{}\n".format(
                data['timestamp'],
                data['object'],
                data['confidence'],
                data['decision']
            ))
    except Exception as e:
        print("Error writing CSV:", e)

# OPTIONAL: Send small JSON event (stretch goal)
def send_event_to_nas(data):
    try:
        url = "http://[your-nas-ip]:5000/event"  # NAS webhook endpoint if available
        response = urequests.post(url, json=data)
        print(response.text)
    except Exception as e:
        print("Error sending event:", e)

# Main Loop Example
while True:
    result = fake_detection()
    save_to_csv(result)
    # send_event_to_nas(result)  # Only if webhook server is running
    print("Detection logged.")
    time.sleep(60)  # every minute
```

✅ ESP32 will:
- Connect to WiFi.
- Generate fake detections (replace with real camera input later).
- Save CSV locally with timestamped records.
- **(Optional)** Send events to your NAS via HTTP POST if you have a simple server.

---

# 🛠️ Part 4 — Optional NAS Mini Server (Only for Push Events)

If you want automatic event logging without just copying CSVs:

✅ **9. Install a lightweight server on your NAS (for events)**

If your NAS supports Docker or Python:
- Install **Flask** (Python):

```python
# server.py (on NAS)

from flask import Flask, request
import json
import os

app = Flask(__name__)

@app.route('/event', methods=['POST'])
def event():
    data = request.get_json()
    team = data.get('team', 'unknown_team')
    logfile = f"/missions/2025/{team}_logs/{team}_events.csv"
    os.makedirs(os.path.dirname(logfile), exist_ok=True)
    with open(logfile, 'a') as f:
        f.write(json.dumps(data) + "\n")
    return "OK", 200

app.run(host='0.0.0.0', port=5000)
```

- This simple server will **listen for ESP32 event POSTs** and log them per team.

✅ **Otherwise**, you can manually download the CSVs later from ESP32 over USB.

---

# 📋 Quick Checklist to Get You Going:

| Step | Status |
|:---|:---|
| Create NAS folders by team | ✅ |
| Create NAS team accounts | ✅ |
| Set up WiFi network `AI_Mission_2025` | ✅ |
| Flash MicroPython to ESP32s | ✅ |
| Upload WiFi Connect + CSV Save scripts | ✅ |
| Test WiFi connection and CSV save | ✅ |
| (Optional) Install tiny Flask server for live event push | ✅ |

---

  
# 🚀 Would you like me to:
- Package this into a **one-page Student Setup Checklist** 📋?
- OR make a **simplified Student Starter Code Bundle** you could distribute in the camp?

👉 Let me know — we’re so close to having a professional-grade field system ready!
