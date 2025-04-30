
## 🧾 ✨ Agent Card Template (for student teams)

Use this as a fill-in form or display board for each team.

---

### 🔹 Agent Name: `____________________`

### 🔹 Role / Mission:
> What is this agent trying to accomplish?

---

### 🔹 Architecture Type (✓ one or more):
- [ ] Reflex Agent
- [ ] Model-Based Reflex
- [ ] Goal-Based
- [ ] Utility-Based
- [ ] Learning Agent

---

### 🔹 Inputs:
> What sensors or data does the agent receive?

Example: camera, light sensor, dashboard screenshot, button

---

### 🔹 Outputs / Actions:
> What can the agent do in response?

Example: move servo, flash LED, send signal, trigger alert

---

### 🔹 Internal Model (if any):
> Does it remember past events or states?

Example: stores brightness level, tracks last prediction, buffers readings

---

### 🔹 Human in the Loop?
- [ ] Yes — how: `_________________`
- [ ] No — fully autonomous

---

### 🔹 Learning or Updating?
- [ ] Yes — describes how: `_________________`
- [ ] No — fixed behavior

---

### 🔹 What would make this agent smarter?
> Open discussion: Could it learn more? Sense more? Ask questions?

---

## 🧠 Optional: Rating Circle (Visual Thinking Aid)
Let students rate how “agentic” their bot is on each axis:

| Trait           | Score (1–5) |
|----------------|-------------|
| Autonomy        | 🔘🔘🔘⚪⚪ |
| Learning        | 🔘🔘⚪⚪⚪ |
| Planning        | 🔘⚪⚪⚪⚪ |
| Feedback Use    | 🔘🔘🔘🔘⚪ |
| Human Interaction | 🔘🔘⚪⚪⚪ |

---

## 🧩 Mermaid Agent Template (Diagram View)

Use the Agentic Flow Diagram slide to create a visual flowchart of their agent's operations. Tools like Mermaid Live Editor can be helpful for creating flowcharts.

Swap this code  to create flow image:

```mermaid
---
config:
      theme: redux
---
flowchart TD
  subgraph AGENT["🤖 Agent: Nova Alpha"]
    INPUT[📷 Perception: Image Sensor]
    MODEL[🧠 Model: Classifier NA_1.tflite]
    STATE[🧾 Internal State: Last Prediction]
    DECIDE{Confidence ≥ Threshold?}
    ACT[🛞 Action: Servo Gate Movement]
    H1[👤 Human: Button Tie Breaker]
  end

  INPUT --> MODEL --> STATE --> DECIDE
  DECIDE -- Yes --> ACT
  DECIDE -- No --> H1 --> ACT
```

