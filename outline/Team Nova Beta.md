## 🛰️ Team Nova Beta – Full Object Detection + Logging System (Raspberry Pi 5)

---

### 1. 🎯 **Mission Role**  
> Run full object detection models (TFLite or ONNX) on the Raspberry Pi 5.  
Capture each object type and **log predictions**, **display classification**, and **sync results** to shared flight logs used by Vega and Orion teams for decisions.  
This team is the **"vision AI with dashboard"** counterpart to Nova Alpha’s edge actuator.

---

### 2. 🧱 **LEGO Build Purpose**  
Build a **structured object analysis station** where students can place LEGO objects for classification.  
- Mounted camera captures images under consistent lighting  
- LED screen or Pi dashboard displays predicted object class  
- Optional: robotic turntable (with NXT servo) for object reveal or rotation  
- No routing action here — this team is the **observer/logger**, not the router

---

### 3. 🧰 **Required LEGO + Hardware Parts**

| Type | Qty | Purpose |
|------|-----|---------|
| LEGO baseplate | 1 | Presentation platform |
| LEGO bricks/objects (3–5 classes) | 8–12 | For model training/testing |
| Technic frame | 10–15 | Secure camera or sensor positioning |
| Raspberry Pi 5 (8GB) | 1 | Runs full model inference |
| CSI/USB camera | 1 | Connected to Pi |
| LED/OLED display or Pi screen | 1 | Shows prediction to student |
| Flask dashboard template | 1 | Optional web UI for classification log |
| Optional: NXT servo motor | 1 | Rotates object for camera view |

---

### 4. 🧪 **AI + Data Science System Actions**

| Component | Task |
|----------|------|
| **Roboflow-trained model (full TFLite/ONNX)** | Classifies incoming object |
| **Python script** | Logs prediction + timestamp |
| **Flask web dashboard** | Displays latest classification + object image |
| **Flight manifest integration** | Logs to shared directory for Orion review |
| **Prediction accuracy checks** | Manual or automated comparison to manifest or instructor key  
| **Optional: Top-2 confidence logic** | Classify fallback when confidence < threshold

---

### 5. 🔁 **Interaction Flow (with Space Deck + Forecast Tie-In)**

```plaintext
Student places object on deck →
Pi captures image →
Model predicts: ‘food’ →
Display shows: “FOOD – Deck C” →
Log written to NAS: {timestamp, object: food, predicted_deck: C} →
Orion pulls logs and forecasts deck fill state
```

- Vega might use the result to decide if the deck is ready (e.g., temp for food is too high)
- Orion may trigger a **docking warning** if too many objects are forecasted to Deck C

---

### 6. ⏱️ **Feasibility in 5-Day Camp**

✅ Yes, and great for students with:
- Interest in dashboards, data logs, or Python scripting
- Day 1: Flask setup + camera test
- Day 2: Full model integration + object display
- Day 3: Log format finalized + NAS sync
- Day 4: Forecast-aware classification logic
- Day 5: Dashboard + final demo polish

---

### 🛠️ **Design Constraint: Inter-Team Integration Required**

> ✨ Your system must **log each detection to a shared flight record**, so that:
> - Vega can check if the object should be allowed (e.g., food vs deck light level)
> - Orion can **forecast overloads** (e.g., “Deck C has had 4 food objects this flight”)

**You are the eyes of the mission — your logs must be complete, consistent, and readable by others.**

---
