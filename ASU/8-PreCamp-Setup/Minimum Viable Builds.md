

# ✅ Minimum Viable Builds per Mission

---

## 🛰️ NOVA – **Object Detection + Classification**

### 🎯 Goal: Detect a LEGO object → classify it → do something with that prediction.

| Component | Min Build |
|-----------|-----------|
| 🔹 Detection System | **ESP32-CAM** or **Pi + webcam** running pre-trained Roboflow model |
| 🔹 Input Surface | LEGO baseplate + fixed frame or whiteboard backdrop for consistent vision |
| 🔹 Actuation (Nova Alpha) | 1 x NXT servo OR LED light to indicate result (accept/reject) |
| 🔹 Logging (Nova Beta) | CSV/JSON output to NAS or local Pi folder with object class & time |

### 🧰 Hardware:
- 2x ESP32-S3 (or 1x ESP + 1x Pi)
- 1–2 cameras
- 1–2 LEGO object sample sets
- 1x NXT motor (or LEDs as fallback)
- Optional: OLED for display

### 🧱 LEGO:
- Simple detection stage (baseplate + support wall)
- Hinged gate OR rotating servo plate
- Optional bin to “receive” accepted objects

---

## 🌡️ VEGA – **Sensor Monitoring + Environment Checks**

### 🎯 Goal: Measure environmental conditions + make decisions based on thresholds.

| Component | Min Build |
|-----------|-----------|
| 🔹 Sensor Platform | **ESP32 or Pi** wired to light + temp sensor |
| 🔹 Logic | Simple threshold comparison (“If temp > 30, reject”) |
| 🔹 Feedback | 1x LED (red/green) or OLED showing sensor state |
| 🔹 Actuation (Alpha) | 1x NXT motor to open/close LEGO hatch |
| 🔹 Display (Beta) | OLED or dashboard showing real-time readings

### 🧰 Hardware:
- 1–2x ESP32 or 1x Pi
- Light sensor (LDR) + temp sensor (DHT11/DHT22)
- 1x OLED or LED strip
- Optional: buzzer or second LED for alert state
- Optional: NXT motor for hatch

### 🧱 LEGO:
- Sensor mount wall (Technic frame or brick platform)
- Simple hatch (hinged piece or servo-driven flap)
- Light shading (for light sensor tuning)

---

## 📡 ORION – **Data Analysis + Communication + Forecasting**

### 🎯 Goal: Receive logs, analyze data, predict capacity, and trigger events.

| Component | Min Build |
|-----------|-----------|
| 🔹 Log Aggregator (Alpha) | Python script or Google Sheet collecting Nova/Vega logs |
| 🔹 Forecast Logic | Simple count per deck + warning threshold (e.g., “Deck C = 4 food”) |
| 🔹 Alert System | Printout, flag raise, or LED light if deck exceeds safe limit |
| 🔹 Message Relay (Beta) | ESP32 or Pi handling MQTT or JSON messaging between teams |

### 🧰 Hardware:
- 1x Pi or laptop (Orion Alpha)
- 1x ESP32 (Orion Beta) or use same Pi
- Shared network folder or NAS access
- Optional: LED flag or buzzer on threshold breach
- Optional: web dashboard (Flask or Streamlit)

### 🧱 LEGO:
- Simple tower or console with colored flags
- Servo flag raiser or rotating LEGO alert disk
- Labelled “zones” for Deck A/B/C status

---

## 🧠 Summary: Absolute Minimum Kit by Mission

| Mission | Must-Have Devices | Minimum LEGO | Optional Enhancements |
|---------|-------------------|--------------|------------------------|
| **Nova** | ESP32 + camera | Baseplate + sorting gate | OLED, dashboard, object bins |
| **Vega** | ESP32 + 2 sensors | Hatch wall or light box | Display, buzzer, motion |
| **Orion** | Pi or laptop | Console + flags | Log viewer, Streamlit app, MQTT messages |

---

