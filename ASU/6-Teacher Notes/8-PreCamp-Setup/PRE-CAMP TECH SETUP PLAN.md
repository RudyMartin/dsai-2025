

## 🚧 PRE-CAMP TECH SETUP PLAN (Refined & Prioritized)

We’ll break it into 3 tiers:
- ✅ **Must-Do** (critical before students arrive)
- ⚠️ **Nice-to-Have** (speeds up day 1)
- ⭐ **Stretch Prep** (adds polish if time allows)

---

### ✅ **MUST-DO (CRITICAL CORE SETUP)**

| System | Setup Task | Notes |
|--------|------------|-------|
| **ESP32-S3** | Flash latest firmware (Arduino or MicroPython) | Test Wi-Fi + camera (OV2640) + GPIO pin out |
| | Confirm USB-C power works + Grove connectors if used | Pre-label each one with a team ID |
| **Raspberry Pi 5** | OS installed (64-bit), all updates applied | Headless setup preferred for space/efficiency |
| | Install Python 3.9+, TFLite, Flask, pip packages | Confirm camera works (CSI or USB webcam) |
| **NXT Bricks** | Charge all battery packs or AA units | Preload a “motor test” program |
| | Confirm Bluetooth/USB can communicate with Pi | Use NXT-G or NXC listener sketch |
| **Router/NAS** | Plug in USB drive, enable SMB or FTP sharing | Set IP to 192.168.88.1 or similar, enable DHCP |
| | Create shared folder: `/mission_logs/` | Test write access from Pi & ESP32 |
| **Sensors (for Vega)** | Wire up at least 2 example units (light + temp) to ESP32 | Test reading + trigger thresholds in code |
| **Roboflow** | Create org-level teacher account | Create base dataset with labeled sample images |
| | Generate base model and download `.tflite` for testing | Prepackage for ESP32 and Pi teams |
| **Code Templates** | Upload all starter files to GitHub/Drive/USB | One folder per team: ESP32, Pi, NXT, logging |
| | Include a README with connection diagrams + flow examples | Bonus: QR code on build sheet links to GitHub |

---

### ⚠️ **NICE-TO-HAVE (Saves You Time on Day 1)**

| Task | Why It Helps |
|------|--------------|
| Create pre-flashed SD cards for Pi | Eliminates install/setup time |
| Pre-label kits by team (Nova Alpha, etc.) | Streamlines handout process |
| Assemble 1 working test build | Demo station for debugging |
| Prepare team instruction booklets | Reduce bottlenecks asking "what do we do?" |
| Print flight manifest templates | So you’re not designing them under pressure |

---

### ⭐ **STRETCH PREP (Only if You Have Time)**

| Task | Bonus Outcome |
|------|---------------|
| Configure MQTT broker on Pi or local server | Enables real-time comms testing |
| Build a basic dashboard template (Orion) | Live log display for all teams |
| Prep a “broken config” kit for debug challenge | Great for teaching troubleshooting |
| Create "Test Flight 0" data | Ensures all logs show up as expected before students touch it |

---

### 🧠 Pre-Camp Checklist Summary

| Category | Task Complete? |
|----------|----------------|
| ESP32 cam + GPIO tested | ✅ / ❌ |
| Pi 5 camera + Flask runs | ✅ / ❌ |
| NXT charged + reacts to commands | ✅ / ❌ |
| NAS share works | ✅ / ❌ |
| Sensors read & trigger | ✅ / ❌ |
| Roboflow account + base model ready | ✅ / ❌ |
| Team kits labeled + organized | ✅ / ❌ |
| Code + instructions printed/shared | ✅ / ❌ |

---

Would you like:
- A printable **checklist version** of this for your setup day(s)?
- Or a **Google Sheet version** for you + volunteers to track who’s setting up what?
