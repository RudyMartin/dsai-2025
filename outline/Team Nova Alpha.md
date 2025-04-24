## 🛰️ Team Nova Alpha – Embedded Object Detection + Actuation (ESP32-S3)

---

### 1. 🎯 **Mission Role**  
> Detect and classify mission-critical LEGO objects (e.g., humans, robots, tools, supplies) **at the edge** using the ESP32-S3 with an attached camera.  
Based on predictions, the system **physically routes** the object using LEGO mechanisms and **passes actionable results** to Vega and Orion teams.

---

### 2. 🧱 **LEGO Build Purpose**  
Create a **compact object intake station** with a motor-driven gate or sorter.  
- LEGO frame holds the object during detection  
- NXT servo or technic assembly **routes the object** into Deck A/B/C  
- Supports Space Deck rules:
  - Humans must be routed to Deck A (life support)
  - Robots to Deck B (robotics)
  - Supplies/tools to Deck C (storage)

Optional: Add a red LED “reject” light if object class is unknown

---

### 3. 🧰 **Required LEGO + Hardware Parts**

| Type | Qty | Purpose |
|------|-----|---------|
| LEGO baseplate | 1 | Staging area for object |
| LEGO bricks/objects (3–4 classes) | 6–10 | Sample inputs for detection |
| Technic beams + pegs | 10–15 | Build gate arm or sliding sorter |
| NXT servo motor | 1 | Physically responds to classification |
| ESP32-S3 | 1 | Runs object detection (TFLite Micro) |
| OV2640 camera | 1 | Mounted on LEGO frame |
| GPIO wires | 1–2 | Triggers NXT or LED |
| Optional: red/green LED | 1 each | Signal accept/reject state |

---

### 4. 🧪 **AI + Data Science System Actions**

| Component | Role |
|----------|------|
| **Roboflow-trained model** | Classifies object (e.g., `human`, `robot`, `tool`, `food`) |
| **ESP32 inference script** | Runs prediction locally, routes result |
| **GPIO trigger** | Sends HIGH/LOW to NXT motor controller |
| **Flight manifest log** | Stores prediction, timestamp, routing result (for Orion review) |
| **Error tracking** | “Misrouted object” logic: compares predicted route vs actual outcome from Orion logs (data science reflection point)

---

### 5. 🔁 **Interaction Flow (Including Space Deck Constraint)**

```plaintext
Student inserts object →
ESP32 captures image →
Model predicts: 'robot' →
If Deck B is not full →
Trigger motor to move object into Deck B chute →
Log result to shared flight record →
Orion validates match against forecast
```

- If ESP32 can’t confidently classify, reject the object or trigger a warning LED
- Flight logs store object type + destination for **later analysis by Orion**

---

### 6. ⏱️ **Feasibility in 5-Day Camp**

✅ Absolutely:
- Day 1: Camera test + Roboflow + servo test
- Day 2: Build sorter + test predictions
- Day 3: Integrate logging + Space Deck rules
- Day 4: Flight + refinement
- Day 5: Presentation

---

### 🛠️ **Design Constraint: Inter-Team Output Required**

> ✨ Your object classification system must **produce both a physical action (routing) and a digital log** that informs **Vega’s sensors** (they test conditions of routed objects) and **Orion’s forecasting** (they predict deck usage and dock timing).

---
