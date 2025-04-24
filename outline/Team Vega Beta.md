
## 🌡️ Team Vega Beta – Standalone Sensor Monitoring + Visual Display (ESP32 or Pi)

---

### 1. 🎯 **Mission Role**  
> Continuously monitor the environmental state of one or more space deck zones using connected sensors.  
Display current readings to the crew via OLED/LED or a dashboard, and **log alerts or events** when conditions go out of range.  
This team enables **passive, ambient awareness** of deck safety for the entire mission.

---

### 2. 🧱 **LEGO Build Purpose**  
Build a **sensor station** that looks like a command center, console, or deck monitor post.  
- LEGO-built “wall unit” or status kiosk with sensors embedded  
- Display panel shows readings: light, temp, motion, airlock status  
- Optional: flashing lights or audio buzzer for critical alerts

No object routing here — this team **monitors the habitat**, not objects.

---

### 3. 🧰 **Required LEGO + Hardware Parts**

| Type | Qty | Purpose |
|------|-----|---------|
| LEGO baseplate | 1 | Base for sensor console |
| LEGO bricks/beams | 15–20 | Build standing console structure |
| Transparent panel | Optional | “Sensor window” effect |
| ESP32 or Raspberry Pi | 1 | Sensor polling and display control |
| OLED or LED matrix display | 1 | Shows live data |
| Light sensor (LDR) | 1 | Measures ambient light |
| Temp sensor (DHT22 or similar) | 1 | Reads temperature |
| Optional: buzzer, motion sensor | 1 each | Adds alerts or presence detection |
| Wi-Fi enabled | 1 | Sends logs to NAS or dashboard UI |
| Optional: micro speaker or servo | 1 | Play alert tone or trigger LEGO animation

---

### 4. 🧪 **AI + Data Science System Actions**

| Component | Task |
|----------|------|
| **Sensor polling** | Every 5 seconds, read light/temp values |
| **Display output** | OLED shows: `Temp = 26.5°C | Light = 41%` |
| **Alert logic** | If values exceed safe range, show red light or play buzzer |
| **Logging** | Write sensor logs to NAS or local `.csv` (timestamp + value) |
| **Orion sync** | Logs used by Orion to forecast deck conditions |
| **Reflection data** | “How often was this deck in alert state over 4 flights?”

---

### 5. 🔁 **Interaction Flow (as Passive Monitor)**

```plaintext
Every 5 seconds:
→ Sensor reads values →
→ OLED updates display →
→ If thresholds exceeded: red LED or buzzer activates →
→ Log written to NAS →
→ Orion pulls file to update deck readiness forecast
```

- May issue “pre-warning” to Vega Alpha: “Deck B is too hot to accept next robot”
- Data over multiple flights shows which decks are more volatile

---

### 6. ⏱️ **Feasibility in 5-Day Camp**

✅ Definitely:
- Day 1: Sensor test on breadboard + OLED test
- Day 2: LEGO frame + full polling logic
- Day 3: Display integration + alert states
- Day 4: Logging + integration with Orion dashboard
- Day 5: Final tuning and real-time demo

---

### 🛠️ **Design Constraint: Visible Alerts + Log Feed Required**

> ✨ “Your system must **display deck safety conditions in real-time** and **log status to a shared file** that Orion or instructors can use for decision-making or triggering docking.  
If conditions are unsafe, that must be **immediately visible to your team or others**.”

---
