## 🛰️ Team Nova Alpha – LEGO Integration Plan

### 1. 🎯 Mission Role
> Build an embedded AI system that detects specific LEGO objects and triggers a mechanical reaction using LEGO/NXT — with minimal power and no internet.

---

### 2. 🧱 LEGO Build Purpose
Create a **small object sorting platform or gate**:
- Students present a LEGO object (e.g., red brick, yellow plate, wheel) in front of a mounted ESP32 camera
- Based on detection, the system **activates an NXT servo motor**
- The servo moves an arm, gate, or platform piece to either:
  - **Approve** and "accept" the object (e.g. push it into a bin)
  - Or **reject** it (e.g. rotate away)

---

### 3. 🧰 Required LEGO Parts

| Type | Qty | Purpose |
|------|-----|---------|
| 🔹 Base plate | 1 | Stable platform for presentation |
| 🔹 Bricks (3+ object types) | 6–10 | Objects to classify in Roboflow |
| 🔹 Technic beams | 10+ | Frame for object area and servo arm |
| 🔹 Pegs and axles | 10+ | Connect rotating parts |
| 🔹 Small wheel or plate | 1 | Optional: make rotating platform |
| 🔹 NXT servo motor | 1 | Action trigger based on prediction |

Optional:
- **Color-coded bins or sides** for sorting outcome

---

### 4. 🧪 AI/System Actions

| Component | Task |
|----------|------|
| **ESP32-S3** | Captures image, runs object detection locally |
| **Roboflow-trained model** | Identifies class: Brick A, Brick B, etc. |
| **ESP32 GPIO** | Sends HIGH signal or message to NXT |
| **NXT** | Rotates LEGO mechanism based on received signal |
| **LEGO** | Physically “accepts” or “rejects” item by moving a part |

---

### 5. 🔁 Interaction Flow

```plaintext
Student places object ➜ ESP32 identifies ➜ 
Sends “open gate A” ➜ NXT receives command ➜ 
Motor moves arm ➜ LEGO platform rotates or pushes object
```

---

### 6. ⏱️ Feasibility in 24 Hours

✅ **YES — Highly doable**

- Small, focused build
- Model can be trained quickly with 10–15 images per object class
- Pre-made detection script + NXT-G program can be provided
- Students can build and iterate on mechanics while training model

---

🛠️ Design Constraint

>✨ Mission Integration Rule: “Your solution must output a signal or result that another team can use — either physically (via LEGO motion), digitally (via Wi-Fi), or visually (via display). NASA systems are never standalone — your tech is one part of a mission.”
