## 🛰️ Team Nova Beta – LEGO Integration Plan (Full Inference + Logging + Handoff)

---

### 1. 🎯 **Mission Role**  
> Deploy a **full object detection model** on Raspberry Pi 5 to identify mission-critical LEGO objects, **log predictions**, display results, and **trigger downstream team actions**.

---

### 2. 🧱 **LEGO Build Purpose**  
Create a **stationary object inspection platform** for showcasing and testing different LEGO objects:
- Students present an object under a fixed Pi camera
- LEGO frame ensures consistent object positioning
- Based on the detected class, the system:
  - **Logs the result**
  - **Displays the output visually**
  - **Sends an alert or message to Team Vega or Team Orion**
- Optional: move a small LEGO mechanism or flag using NXT servo based on detection

---

### 3. 🧰 **Required LEGO + Hardware Parts**

| Type | Qty | Purpose |
|------|-----|---------|
| 🔹 LEGO base plate | 1 | Object staging area |
| 🔹 LEGO bricks (3–5 object classes) | 6–10 | Sample set for training + detection |
| 🔹 Technic beams + pegs | 10–15 | Frame to stabilize object position |
| 🔹 Small turntable or axle set | 1 (optional) | Allow spinning or sliding object base |
| 🔹 NXT servo motor | 1 | Move LEGO arm/flag on detection (optional) |
| 🔹 Raspberry Pi 5 (8GB) | 1 | AI inference + dashboard |
| 🔹 USB or CSI camera | 1 | Object capture |
| 🔹 Access to NAS or Flask runtime | 1 | Log or share data with other teams |
| 🔹 LED, OLED or screen | 1 | Display classification live |

---

### 4. 🧪 **AI/System Actions**

| Component | Task |
|-----------|------|
| **Roboflow-trained model** | Detects object class from live camera feed |
| **Python + TFLite or ONNX** | Runs full detection model on Pi |
| **Flask or OLED output** | Displays prediction to user |
| **Python logging module** | Writes result to log file or shared NAS path |
| **(Optional) UDP / MQTT sender** | Notifies other teams: “object_detected = red_brick” |
| **NXT motor** | (Optional) Animates result with motion or signal |
| **LEGO structure** | Holds object in consistent location for inference |

---

### 5. 🔁 **Interaction Flow (with Integration Constraint)**

```plaintext
Student places object → Pi runs model →
Prediction displayed (Flask or OLED) →
Result logged to NAS OR message sent via Wi-Fi →
Team Vega or Orion receives result → starts follow-up action
```

Examples:
- Detects "Tool A" ➜ sends `object_detected=tool_a` ➜ Vega starts sensor scan
- Logs "Rock Sample C" ➜ Orion reads log ➜ raises alert

---

### 6. ⏱️ **24-Hour Execution Feasibility**

✅ **YES – highly doable**, especially with these supports:
- Provide a **preconfigured Flask dashboard template**
- Use shared Roboflow dataset from Nova Alpha
- Use prewritten Python script for NAS logging and UDP messaging
- LEGO build focuses on structure + presentation, not robotics
- Optional NXT servo motion can be added if time allows

