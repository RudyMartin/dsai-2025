
# ✅ Minimum Viable Build Lists per Team

---

## 🛰️ **Team Nova – Vision + Object Detection**

> **Mission:** Build a smart identifier system that detects mission-critical Lego objects and responds by activating a mechanism.

### 🧰 Hardware

| Component | Quantity | Notes |
|----------|----------|-------|
| 🔹 NXT Brick | 1 | Core controller |
| 🔹 NXT Servo Motor | 1–2 | To push/rotate objects after detection |
| 🔹 LEGO Base Plate | 1 | Object staging area |
| 🔹 LEGO Parts (Colorful Bricks) | 5–10 | Use for Roboflow model training |
| 🔹 LEGO Beams + Pegs | 15+ | Frame + object guide lanes |
| 🔹 Rotation Sensor (built-in) | ✔️ | Useful for counting actions |
| 🔹 ESP32-S3 (Alpha) or Pi 5 (Beta) | 1 | Vision model deployment |
| 🔹 Camera Module | 1 | OV2640 for ESP32 or USB/CSI for Pi |
| 🔹 Bluetooth setup (Pi → NXT) | 1 | Send `OPENHATCH` or similar signal |
| 🔹 Mounting arm / servo frame | 1 | Holds motor for sorting task |

---

## 🌡️ **Team Vega – Environment Monitoring + Sensor Logic**

> **Mission:** Monitor environmental conditions inside a LEGO base (light, temp, motion) and trigger alerts or actions based on thresholds.

### 🧰 Hardware

| Component | Quantity | Notes |
|----------|----------|-------|
| 🔹 NXT Brick | 1 | Main controller |
| 🔹 Touch Sensor | 1 | Optional reset or event trigger |
| 🔹 Light Sensor | 1 | Monitor day/night cycles in "base" |
| 🔹 Servo Motor | 1 | Open/close vents, rotate beacon, etc. |
| 🔹 LEGO Technic Beams | 10+ | Build enclosure or “moon base” shell |
| 🔹 LEGO Panels or Roof Parts | Optional | Create variable light conditions |
| 🟢 ESP32 or Pi (optional) | 1 | For sensor logging or sync to Orion |
| 🟢 Small OLED screen or LED | 1 | Show current sensor reading or alert |
| 🟡 NAS sync (if paired with Orion) | — | Optional log output |

---

## 📡 **Team Orion – Command, Logging, and Sync**

> **Mission:** Act as central command to collect logs, trigger remote devices (via Bluetooth or Wi-Fi), and coordinate team behaviors.

### 🧰 Hardware

| Component | Quantity | Notes |
|----------|----------|-------|
| 🔹 NXT Brick | 1 | (Optional) Can act as physical UI or display unit |
| 🔹 Raspberry Pi 5 | 1 | Main system hub |
| 🔹 USB Flash or NAS access | 1 | Store models, logs, configs |
| 🔹 Bluetooth Module / Adapter | 1 | Needed to connect to NXT devices |
| 🟢 OLED screen or dashboard UI | 1 | Show logs or object detections |
| 🟢 Python Script (data logger) | 1 | Reads inputs and logs to disk |
| 🟢 Basic interface (buttons or touch sensor) | 1 | Trigger sync or reset actions |
| 🔹 Display panel or LEGO control board | 1 | Student-built UI for visual output |
| 🟡 Optional NXT Motor | 1 | To add a symbolic action (e.g. swing arm when sync complete) |

---

## 🧪 Optional Shared Items (1–2 per camp)

| Item | Use Case |
|------|----------|
| Spare LEGO structures | For testing across missions |
| Marker pens or stickers | Label objects for object detection training |
| Measuring tape or ruler | Measure distances for ultrasonic sensors |
| USB power banks | Untethered Pi or ESP32 deployments |
| Portable routers (AX5400) | NAS + closed Wi-Fi network |
| Label maker or name tags | For team kits + storage boxes |


