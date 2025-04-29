
We're proposing:

- **Nova Alpha**, **Nova Beta**, **Vega Alpha**, **Vega Beta** → **ESP32-S3** (lightweight, sensors, movement, Wokwi-compatible)  
- **Orion Alpha** and **Orion Beta** → **Raspberry Pi 5** (heavyweight data aggregation, forecasting, dashboards, communications)

| Track | **ESP32 Teams** | **PI Teams** |
|:---|:---|:---|
| Hardware | **ESP32 / ESP32-S3** | **Raspberry Pi 5** |
| Focus | Lightweight, edge computing, sensors, real-time physical actuation | Heavyweight computing, object detection dashboards, full OS features |
| Groups | Nova Alpha, Nova Beta, Vega Alpha, Vega Beta | Orion Alpha, Orion Beta |
| Power | Tiny, low-power | Full computer |
| Coding | Arduino C++ (or Micropython) | Python / Linux / Flask apps |
| Real-world I/O | Fast: move motor, read sensor, blink lights | Slower, but can run complex models and dashboards |
| WOW | Real-time mechanical movements | Fancy visual displays, animated dashboards |

---
# 🚀 Why  this works for students:

| Why this is smart | Reason |
|:---|:---|
| 🔥 Keeps ESP32 Teams focused on **physical WOW demos** | Servos moving, lights flashing, hatches opening — fast, reliable |
| 🧠 Keeps Pi Teams focused on **data intelligence, forecasting, and dashboards** | Pi5’s real OS, file handling, web dashboards, multiple threads, perfect for Mission Control simulation |
| 🔥 Simplifies ESP32 instruction | Only have to teach Arduino/C++ on those teams — less switching between Python and C++ mid-week |
| 💬 Leaves heavy messaging (MQTT, REST) and heavy data parsing (CSV logs) to the Pi Teams | Better hardware fit — Pi5 can easily run mini-servers, dashboards, and more verbose protocols |
| 💻 Still allows impressive screen-based demos for parents | Orion teams can show dashboards, graphs, alert charts on big screens |
| 🎯 Reduces hardware troubleshooting | Only two teams deal with Pi power issues, SD cards, Linux stuff — not everyone |

---
# 🧩 New Hardware Matrix if you do this:

| Team | Hardware | Key Features |
|:---|:---|:---|
| Nova Alpha | ESP32-S3 | Object detection, servo sorting gate |
| Nova Beta | ESP32-S3 | Object detection, LED dashboard or small OLED |
| Vega Alpha | ESP32 | Sensor monitoring, flashing alerts |
| Vega Beta | ESP32-S3 | Environmental object gate (airlock servo + sensors) |
| Orion Alpha | **Raspberry Pi 5** | Messaging receiver/transmitter, network dashboard, alert LEDs |
| Orion Beta | **Raspberry Pi 5** | Data aggregation, forecasting dashboard, docking triggers |

---
# ✨ Parent "WOW" Showcase Plan

| Track | Visual WOW Demo |
|:---|:---|
| Nova Alpha | Sorter moving objects into different chutes live |
| Nova Beta | Object displayed + LED/light-up deck assignment |
| Vega Alpha | Sensors trigger flashing lights or alarms |
| Vega Beta | Airlock hatch opens or closes based on sensor data |
| Orion Alpha | Mission control messaging tower: LEDs flash + dashboard updates |
| Orion Beta | Mission forecasting screen + LEGO flag raising on overload |

---

# 🛠️ Code Simplification:

| ESP32 Teams | Pi5 Teams |
|:---|:---|
| Arduino/C++ | Python (Flask, Jupyter, or MQTT libraries) |
| Wokwi compatible | No Wokwi, real hardware only |

This helps your instructors a LOT.

You can have **one instructor** focused on helping ESP32 coding (Wokwi + Arduino IDE)  
and **one instructor** focused on **Pi Python scripting + data handling.**

---

# 📣 Final Recommendation:

✅ **YES – make Nova and Vega projects ESP32** (lightweight, moving parts)  
✅ **YES – make Orion projects Raspberry Pi 5** (heavy dashboard, forecasting, messaging)

This is a **great split** between **Mechanical WOW** and **Data Intelligence WOW.**

---
