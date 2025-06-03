

## ✅ Slide 1: **What Is MCP?**

**MCP = Model – Context – Protocol**
A 5-step loop that powers how intelligent systems (like robots or AI assistants) operate.

| **Step** | **Name** | **Student-Friendly Meaning** | **Example**                    |
| -------- | -------- | ---------------------------- | ------------------------------ |
| 1        | Sense    | “What’s happening?”          | Camera sees a block            |
| 2        | Plan     | “What should I do now?”      | Decide to grab or ignore it    |
| 3        | Act      | “Do it!”                     | Move servo to pick it up       |
| 4        | Log      | “Write down what I did.”     | Print action to serial monitor |
| 5        | Repeat   | “Keep going… what’s next?”   | Return to step 1               |

---

## ✅ Slide 2: **Student Nicknames for MCP**

* 🤖 "1–2–3–4–5 Loop"
* 🧠 "The Brain Loop"
* 🔁 **See – Think – Do – Speak – Loop**

| **Word** | **Maps To** | **Meaning**                  | **Example**                        |
| -------- | ----------- | ---------------------------- | ---------------------------------- |
| See      | Sense       | “What did I observe?”        | Sensor reads a button press        |
| Think    | Plan        | “What should I do about it?” | Decide to move or pause            |
| Do       | Act         | “Take the action!”           | Trigger motor or light             |
| Speak    | Log         | “Let someone know”           | Serial output, LED flash, file log |
| Loop     | Repeat      | “Start again with new input” | Re-enter the cycle                 |

---

## ✅ Slide 3: **What Is an FSM?**

A **Finite State Machine** is a tool to help code and visualize these 5 steps.

* Each **state** does something specific (like “WAIT” or “MOVE”)
* You define **transitions** between states
* FSMs make it easy to build robots that follow the **MCP loop**

---

## ✅ Slide 4: **FSM = The Brain That Runs the MCP Loop**

Think of FSM as:

> “The **engine** behind your robot’s **loop** — deciding what to do and when.”

* FSM = software structure
* MCP = system behavior

🔁 You’ll use FSMs to **implement** MCP steps:

* FSM state: “SCAN” → **Sense**
* FSM state: “DECIDE” → **Plan**
* FSM state: “MOVE\_ARM” → **Act**
* FSM state: “REPORT” → **Log**
* Transition back → **Repeat**

---

Let me know if you’d like:

* PowerPoint/Google Slides versions
* A visual flowchart to insert into slides
* A printable classroom wall poster

Happy to generate visuals or export!
