
Sending LLM Messages to 64x64 matrix

- [Distance Sensor using 64x64](https://www.youtube.com/watch?v=lvr1SKRGgqc&t=149s)





---

## 🧠 Lab Progression Context 

| Lab       | Focus                     | What Students Learn                                                                                              |
| --------- | ------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| **Lab 1** | 🤖 LLM/RAG Chatbot        | How to ask questions and get responses from a language model. Teaches basic reasoning + context use              |
| **Lab 2** | 🎯 Custom Vision Model    | Train a block classifier (6 colors × 2 sizes) using Roboflow. Export to Microcontroller                          |
| **Lab 3** | 🚨 Decision + Alert Agent | Turn classifier outputs into action **based on confidence**. Use FSM, light GPIO/LED/Buzzer based on result      |


---

## ✅ What Lab 3 Teaches

Lab 3 marks the transition:

* From passive model → **active agent**
* From output → **output + judgment**
* From basic loop → **FSM + real-world signals**

It’s the **first time the system reacts**. This is crucial in the agent design loop.

---


---

### 🔧 Script Name:

lab3_confidence_alert_agent.ino



---

## 📂 Suggested Folder Structure So Far

```
/labs/
├── lab1_llm_chatbot/
│   └── chatbot_llm_rag.ino
├── lab2_block_classifier/
│   └── block_classify_model_test.ino
├── lab3_confidence_alert_agent/
│   ├── lab3_confidence_alert_agent.ino
│   ├── gpio_output.h
│   ├── led_output.h
│   ├── buzzer_output.h
│   └── llm_sample_inputs.json
```

---

## Review OF FSM State Design



| FSM State               | MCP Step | Meaning          |
| ----------------------- | -------- | ---------------- |
| `STATE_SENSE_INPUT`     | Sense    | Read JSON input  |
| `STATE_DECIDE_ACTION`   | Plan     | Parse + choose   |
| `STATE_ACT_ON_DECISION` | Act      | Show result      |
| `STATE_LOG_RESULT`      | Log      | Print to Serial  |
| `STATE_WAIT_NEXT_INPUT` | Repeat   | Prepare for next |
