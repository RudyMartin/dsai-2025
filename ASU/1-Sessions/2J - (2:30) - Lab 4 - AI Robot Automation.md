Lab Video:

- [Mastering Servo Control: PCA9685 PWM Driver with Arduino Tutorial and Demo](https://www.youtube.com/watch?v=GDnmAI_7lOk&t=9s) - 7 

- How to use PCA9685 16-Channel 12-bit servo drive | Hash Robotics](https://www.youtube.com/watch?v=CVMpIn8olvQ) - 20 mins!!


## 🧠 Lab Progression Context

| Lab       | Focus                     | What Students Learn                                                                                              |
| --------- | ------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| **Lab 1** | 🤖 LLM/RAG Chatbot        | How to ask questions and get responses from a language model. Teaches basic reasoning + context use              |
| **Lab 2** | 🎯 Custom Vision Model    | Train a block classifier (6 colors × 2 sizes) using Roboflow. Export to Microcontroller                          |
| **Lab 3** | 🚨 Decision + Alert Agent | Turn classifier outputs into action **based on confidence**. Use FSM, light GPIO/LED/Buzzer based on result      |
| **Lab 4** | 🌐 Conditional Decisions  | Add **external conditions** (e.g. temperature, deck rules). Action is **context-dependent**, not just confidence |


For **Lab 4**, where you're introducing **context-aware decisions**, the name should reflect that **external conditions** now influence the system’s behavior — not just the model output.

---

## 🔭 Lab 4 Focus Recap

### 👇 What Changes:

* Lab 3: Action was based **solely on model confidence**
* Lab 4: Action is based on **confidence + external context**

  * e.g., temperature, light level, deck rules, time of day
  * Example: A "yes" classification might still be rejected if the environment is “unsafe”

---

## 🧠 Learning Goals:

* Combine multiple inputs
* Introduce conditional logic
* Reinforce FSM branching
* Treat environment as part of the **decision context**

---

## ✅ Script Name

```plaintext
lab4_contextual_decision_agent.ino
```


---



