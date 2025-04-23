## 🛰️ **Team Nova Beta – Vision AI Systems (Beta Unit)**

### 🎯 **Mission Objective**
Build a **full object detection system** using a **Raspberry Pi 5** that can identify mission-critical LEGO objects, **log results**, and **transmit actionable insights** to other teams (e.g., Vega for follow-up testing or Orion for mission coordination).

---

### 🧱 **LEGO Build Purpose**
Create a **static object presentation station**, such as a sorting platform, rotating carousel, or grid-based inspection area. Use LEGO components to:
- Hold or present objects
- Guide object alignment under camera
- (Optional) Move or reveal items using an NXT servo

---

### 🧪 **System Responsibilities**

| Task | Description |
|------|-------------|
| **Run object detection model** | Trained via Roboflow, deployed on Pi |
| **Display prediction live** | Use Flask dashboard or OLED for output |
| **Log results** | Save to CSV locally and/or sync to NAS |
| **Trigger next team** | Based on detected object, send:
- UDP message to Vega (e.g., “sample_ready: red_brick”)
- File log to NAS for Orion to pick up
| **(Optional) Move LEGO part** | NXT motor shows detection outcome (flag, gate, turntable)

---

### 🔁 **Integration Constraint**

> ✨ “Your detection system must produce a result that another team can use.”  
That means:
- **Logging to shared NAS** for Orion to analyze
- Or **sending an event** to Vega so they respond (e.g., initiate test on sample)

---

### ⏱️ **Feasibility in 24 Hours**
✅ Yes, especially if:
- Flask or OLED display is templated
- Communication script is provided (UDP or log writer)
- Teams agree in advance on **event names or file paths**

---

Would you like the same integration restatement for Nova Alpha before we proceed to Vega Alpha?
