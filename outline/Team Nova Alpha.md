Absolutely! Here's the **refreshed and complete version** of **Team Nova Alpha** using your 6-part format, now with the **Integration Constraint** included at the end — just like we did for Nova Beta.

---

## 🛰️ Team Nova Alpha – LEGO Integration Plan (Embedded Vision + Physical Action)

---

### 1. 🎯 **Mission Role**
> Build an **embedded AI system** using the ESP32-S3 to detect LEGO objects and **trigger a robotic action** using LEGO/NXT — with **minimal power** and **no internet**.

This team operates at the **edge**, focusing on efficient, fast, local execution.

---

### 2. 🧱 **LEGO Build Purpose**
Create a **simple object classifier + action platform**:
- Students place a LEGO object (e.g., red brick, wheel, tool) in front of the camera
- Based on the prediction, the system **activates a NXT servo motor**
- The motor moves a LEGO **gate, arm, or trapdoor** to sort or respond to the item:
  - ✅ Accept the item into a bin or slot
  - ❌ Reject it by turning it away or closing access

---

### 3. 🧰 **Required LEGO + Hardware Parts**

| Type | Qty | Purpose |
|------|-----|---------|
| 🔹 LEGO base plate | 1 | Stable surface for object staging |
| 🔹 LEGO bricks (3+ object types) | 6–10 | Sample set for classification |
| 🔹 Technic beams | 10–15 | Build the frame and mechanical arm |
| 🔹 Pegs, axles, and stops | 10+ | Connect movable parts (arm/gate) |
| 🔹 Turntable or hinge | 1 (optional) | Add rotating element |
| 🔹 NXT servo motor | 1 | Receives signal from ESP32 to move LEGO mechanism |
| 🔹 ESP32-S3 | 1 | Runs quantized model locally |
| 🔹 OV2640 camera | 1 | Captures object image |
| 🔹 Battery or USB-C power | 1 | Portable use |

Optional:
- Colored bins or trays for accepted vs rejected classes
- Stickers/labels for detected object classes

---

### 4. 🧪 **AI/System Actions**

| Component | Task |
|-----------|------|
| **ESP32-S3** | Captures image and runs TFLite Micro model |
| **Roboflow-trained model** | Detects object class (e.g. Brick A, Brick B) |
| **ESP32 GPIO or UART** | Sends command (e.g., "GATE_A") to NXT |
| **NXT Brick + Servo** | Moves LEGO mechanism based on received signal |
| **LEGO elements** | Provide visual/physical output of detection result |

---

### 5. 🔁 **Interaction Flow (with Integration Constraint)**

```plaintext
Student places object → ESP32 captures + classifies →
Sends command (e.g. “rotate_gate_A”) →
NXT motor responds with movement →
(OPTIONAL) Action is logged or triggers a follow-up by Vega or Orion
```

Example:  
- Detects “Tool A” ➜ Opens hatch ➜ Drops into Vega’s environmental scanner build

---

### 6. ⏱️ **Feasibility in 24 Hours**

✅ **YES – Highly doable**, even for novice teams:
- Roboflow model can be trained quickly with ~10 images/class
- ESP32 code can be preloaded or lightly templated
- LEGO/NXT motion can be kept simple (1-move servo)
- Teams can prototype cardboard or LEGO frames if Technic parts are limited

---

### 🛠️ **Design Constraint – Integration Protocol**

> ✨ Mission Integration Rule: “Your solution must output a signal or result that another team can use — either physically (via LEGO motion), digitally (via Wi-Fi), or visually (via display). NASA systems are never standalone — your tech is one part of a mission.”

- May **drop sorted item** into a LEGO container built by Vega
- May **send a GPIO signal or file** indicating detection to be picked up by Orion
- Result must be **usable** by another team’s logic


