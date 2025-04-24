## 🌡️ Team Vega Alpha – Environmental Sensor Monitoring + Condition Logging (ESP32-S3)

---

### 1. 🎯 **Mission Role**  
> Monitor deck conditions (e.g., light, temperature, motion) and determine if **incoming objects** from Nova are allowed under current environmental thresholds.  
Trigger **physical actions** (e.g., open a LEGO airlock) or **log alerts** if safety thresholds are violated.  
Vega Alpha is the **first responder** to object drop-offs.

---

### 2. 🧱 **LEGO Build Purpose**  
Build a **sealed LEGO test chamber** to simulate a habitat module.  
- Sensors are mounted inside (light, temp, motion)  
- An NXT servo motor opens a hatch if the object passes all safety checks  
- Optional: light filters or shaded areas to simulate safe/unsafe deck zones  
- The object comes in from Nova Alpha and is evaluated **before entry is permitted**

---

### 3. 🧰 **Required LEGO + Hardware Parts**

| Type | Qty | Purpose |
|------|-----|---------|
| LEGO baseplate | 1 | Test chamber base |
| Technic bricks/beams | 10–20 | Build structure and mount sensors |
| Transparent bricks | Optional | Simulate “window” letting in light |
| LEGO object tray | 1 | For incoming objects from Nova |
| ESP32-S3 | 1 | Reads sensors and controls output |
| Light sensor (e.g., LDR) | 1 | Measures ambient light level |
| Temp sensor (e.g., DHT11/DHT22) | 1 | Measures thermal safety |
| Optional: motion or proximity sensor | 1 | Detects if object arrived |
| NXT servo motor | 1 | Opens hatch or signals “safe” |
| LED indicator | 1 | Green = safe, Red = reject |
| Wi-Fi connection | 1 | Sends log to NAS or Orion

---

### 4. 🧪 **AI + Data Science System Actions**

| Component | Task |
|----------|------|
| **Sensor polling** | Read light/temp every second |
| **Threshold logic** | Compare values to safety limits (e.g., temp < 28°C) |
| **Decision logic** | If all conditions OK → open hatch; else → blink red LED |
| **Flight log entry** | Write result: {object_id, time, status: safe/unsafe, values} |
| **Notify Orion** | Message or file written to NAS for logging or forecasting |
| **Data science hook** | Reflect: “How many unsafe entries did we catch?”

---

### 5. 🔁 **Interaction Flow (with Space Deck Integration)**

```plaintext
Nova drops object into Vega’s LEGO chamber →
Sensor scan begins →
Light = OK, Temp = TOO HOT →
Object is rejected, log written →
Orion reads logs: ‘Deck A conditions unsafe for human’ →
Counts against safe capacity forecast
```

- The team learns to **tune thresholds** (e.g., adjust for shade, simulate coolers)
- Logs help Orion determine if a **dock override** or **environmental alert** is needed

---

### 6. ⏱️ **Feasibility in 5-Day Camp**

✅ Yes — and sensor logic is easy to scaffold:
- Day 1: Test sensors individually on breadboard
- Day 2: Build LEGO structure, mount sensors
- Day 3: Combine reading + logic + motor control
- Day 4: Format logs, test integration with Nova
- Day 5: Final polish + real-time response demo

---

### 🛠️ **Design Constraint: Sensor Feedback + Log Required**

> ✨ “Your system must **analyze conditions of an incoming object and respond digitally and physically**.  
You must **log a result** to the flight manifest (safe/rejected + values), which Orion uses for forecasting and mission health.”

---
