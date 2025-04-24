
# ✅ 1. **Tradeoff Map** – How to Adapt When Resources Are Tight

This gives you **backup plans** and **equivalent substitutions** when time, people, or parts are limited — without breaking the simulation.

---

### 🛰️ NOVA – Object Detection

| Core Component | Ideal | Tradeoff Option | Notes |
|----------------|-------|-----------------|-------|
| ESP32 + Camera | Run model locally | 📸 Use Pi + webcam (centralized inference) | Still allows live classification, slower |
| NXT Servo | Actuates sorting gate | 🔦 Use LEDs (Green/Red) + log action | Avoids mechanical build, keeps data flow |
| Roboflow Model | Custom LEGO classes | 🎓 Use premade model for 2–3 categories | Speeds setup if student upload fails |
| LEGO Sorting Mechanism | Hinged servo platform | 📥 Static bin + LED indicators | Reduces moving parts, still valid outcome |

---

### 🌡️ VEGA – Sensor Monitoring

| Core Component | Ideal | Tradeoff Option | Notes |
|----------------|-------|-----------------|-------|
| ESP32 + DHT/Light | Real-time thresholds | 📄 Pre-load values or simulate logs | Useful if sensor pins break or time is short |
| OLED Display | Shows temp/light | 🔴 Use LEDs or write to log only | Keeps feedback loop alive with minimal wiring |
| NXT Hatch Mechanism | Servo-based gate | 🎯 Flip card manually on “safe/unsafe” | Reduces servo dependency, keeps logic |
| LEGO Lab Module | Full light-sealed room | 🧱 Wall + canopy or “windowed box” | Can build flat or partial scene and still run logic |

---

### 📡 ORION – Forecasting & Logs

| Core Component | Ideal | Tradeoff Option | Notes |
|----------------|-------|-----------------|-------|
| Pi + Parser Dashboard | Real-time visualization | 📈 Use Google Sheet + manual CSV import | Teaches data science without needing web stack |
| Live Logs from Teams | NAS write or message | 📂 Teams email/upload logs once per flight | Maintains flow without local network |
| Forecast Logic | Predict dock trigger | 📊 Set a static limit ("no more than 4 objects") | Can teach constraint tracking without modeling |
| Physical Flag Actuator | Servo raises signal | 🟥 Manual flag card or LED | Keeps visibility of mission state

---

✅ **General Tradeoffs Table**

| If You Lose This... | Do This Instead |
|----------------------|------------------|
| NXT motor | Use LED signal or manual card |
| Camera | Use preloaded sample images |
| Wi-Fi/NAS | Use USB drive or verbal report |
| OLED display | Use serial console or log file |
| Sensor | Simulate value + teach modeling logic |
| Object classification | Use label cards and simulate prediction |
| Full dashboard | Print log summaries or use Sheets

---

