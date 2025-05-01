

## 📊 **Team Orion Beta – Data Aggregation + Forecast Dashboard (Raspberry Pi 5)**  
**Now with Optional Camera for Visual Forecast Logs**

---

### 🎯 **Mission Role**  
Aggregate data from **Nova and Vega** logs (e.g., predictions, sensor readings, gate usage), run basic **trend analysis**, and trigger high-level **docking recommendations**.  
Now supports an **optional camera** to **capture forecast states**, daily summary displays, or interactive moments.

---

### 🧱 LEGO Build Purpose

Create a **mission operations deck** with:

- Pi-powered **forecast visualization panel**
- Mounted screen or graph area
- Optional: camera for **visual capture of forecast events**
- Build theme: control room, data observatory, or ops desk

---

### 🧰 Key Hardware + Additions

| Type             | Qty | Purpose                                                              |
|------------------|-----|----------------------------------------------------------------------|
| Raspberry Pi 5   | 1   | Run data aggregation + Flask dashboard                              |
| HDMI screen / OLED | 1   | Display forecast results or charts                                 |
| USB/CSI camera   | 1   | Optional: capture key dashboard states or reaction moments           |
| Wi-Fi connected  | 1   | Receive logs from Nova/Vega and sync with Orion Alpha if needed      |
| CSV/JSON parser  | 1   | Read log formats from other teams                                    |

---

### 🧪 Forecasting + System Logic

| Component     | Task                                                                         |
|---------------|------------------------------------------------------------------------------|
| Data ingestor | Load logs from Nova Beta, Vega Alpha/Beta                                    |
| Aggregator    | Count object classes, alert rates, entry frequency by time                   |
| Forecaster    | Estimate “Deck C will overflow in 2 more food objects”                       |
| Dashboard     | Visual summary of last 5 system events or projected trends                   |
| Camera (opt.) | Time-lapse or triggered image of forecast status or alert conditions         |

---

### 🔁 **Interaction Flow (with Camera)**

1. Orion Beta receives logs:  
   - Nova Beta: `{object: Tool, time: 10:32}`  
   - Vega Alpha: `{temp: 31.2, status: alert}`  
2. Forecast logic calculates: “Deck B near temp limit”  
3. Dashboard shows:  
   - **[Temp: HIGH]**  
   - **[Objects: 6 FOOD – 1 away from limit]**  
4. Camera captures forecast screen or status display (optional)  
5. Log entry:  
   `{timestamp, forecast: "Food overload imminent", image: forecast_009.jpg}`  
6. Orion Alpha can also reference these logs for mission-wide messaging

---

### ⏱️ **Feasibility Timeline with Camera**

| Day       | Activities                                                                   |
|-----------|-------------------------------------------------------------------------------|
| **Day 1** | Log parsing practice (CSV/JSON) + test Pi dashboard                          |
| **Day 2** | Aggregate values: food counts, alert frequency                               |
| **Day 3** | Build forecast logic + display trend line or message                         |
| **Day 4** | Connect to shared log folder + test camera capture on forecast threshold     |
| **Day 5** | Polish visual interface + save key forecast states as log images             |

---

### 🛠️ **Design Constraints**
- Forecast output must be **clearly visible or readable**
- Log format must match Orion Alpha and include timestamps
- If using camera: filenames should reflect **event or day state**

---

### 💡 Optional Upgrades
- Save **daily summary snapshot** of object class distribution (chart + image)  
- Use **animated graphics** for docking warnings (e.g., deck fill % bar)  
- Display **“Top Deck at Risk”** with heatmap or trend line

---

All Orion and Vega teams now have camera-enhanced activities.  
Would you like a single-page **summary grid (PDF or sheet)** of all camera uses across teams?

old_stuff__>
## 📡 Team Orion Beta – Forecasting, Logging, and Docking Coordination (Raspberry Pi 5 or Laptop)

---

### 1. 🎯 **Mission Role**  
> Monitor the mission-wide system by **collecting and analyzing flight logs** from Nova and Vega teams.  
Forecast when space decks will **exceed safe limits**, **trigger alerts or docking requests**, and generate reports.  
This team enables **long-range decision-making** based on real-time and historical data.

---

### 2. 🧱 **LEGO Build Purpose**  
Build a **mission control console** to visualize mission status:
- Use LEGO to construct a dashboard with **gauges, lights, or flags**
- Use NXT motor to **raise flags** or spin an alert wheel when forecasts are triggered
- Optional: LEGO “comm tower” lights up if docking is required

No sensors or object detection here — this is a **data aggregation and signal-response unit**.

---

### 3. 🧰 **Required Hardware + LEGO Parts**

| Type | Qty | Purpose |
|------|-----|---------|
| LEGO bricks + baseplate | 15–20 | Console design for mission control |
| Raspberry Pi 5 or laptop | 1 | Log reader, data processor |
| OLED display or HDMI screen | 1 | Show charts or dashboard |
| NXT servo motor | 1 | Raise a flag, rotate sign when docking is triggered |
| Wi-Fi connection | 1 | Pulls logs from NAS or local share |
| CSV log parser script (Python) | 1 | Parses Nova/Vega logs into flight summaries |
| Data dashboard (Flask or Jupyter) | 1 | Display object counts, alerts, deck usage %

---

### 4. 🧪 **AI + Data Science System Actions**

| Component | Task |
|----------|------|
| **Pull logs** from Nova + Vega | Gather object classifications, sensor states |
| **Parse + summarize logs** | Count objects per deck, failed entries, unsafe zones |
| **Forecast overloads** | Predict when a deck will be too full (e.g., >80% food to Deck C) |
| **Trigger docking protocol** | If conditions are forecast to fail in next flight, raise flag or signal |
| **Display dashboard** | Real-time display of deck status, forecasts, recent logs |
| **Data storytelling** | End-of-day report: “Deck A had 4 unsafe human entries; docking triggered once”

---

### 5. 🔁 **Interaction Flow (as Mission Control)**

```plaintext
Every flight:
→ Orion reads Nova + Vega logs →
→ Updates object counts by deck →
→ Calculates forecast (deck at 75% capacity) →
→ Triggers docking if needed (motor flag) →
→ Displays status on dashboard
```

- Teams look to Orion for system alerts (“We can’t accept more humans on Deck A”)
- Orion may send early warnings before a flight

---

### 6. ⏱️ **Feasibility in 5-Day Camp**

✅ Highly suitable for students into data, dashboards, or logic:
- Day 1: CSV parsing + data structure test
- Day 2: Manual dashboard (count entries)
- Day 3: Forecast logic + docking trigger
- Day 4: Dashboard display + NXT signal
- Day 5: Present system-wide findings

---

### 🛠️ **Design Constraint: Forecasts + Dock Trigger Required**

> ✨ “Your system must read flight logs from Nova and Vega, and **predict when the habitat system will fail** (e.g., overload, bad environment).  
If a deck is at risk, you must trigger a docking or raise a warning — visibly and digitally.  
You are the brain of the mission. Without you, we fly blind.”

---
