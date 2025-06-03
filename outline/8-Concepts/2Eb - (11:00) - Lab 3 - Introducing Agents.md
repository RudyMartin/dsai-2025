

## ✅ Slide 5: From FSM to Agents — Who Does What?

So far, we’ve talked about the **FSM Brain** that runs the **MCP Loop**:

| FSM State | MCP Step | Meaning           | Example                          |
| --------- | -------- | ----------------- | -------------------------------- |
| `SEE`     | Sense    | Look for input    | Camera or sensor sees something  |
| `THINK`   | Plan     | Decide what to do | Pick the best image to display   |
| `ACT`     | Act      | Take action       | Show something on LED Matrix     |
| `SPEAK`   | Log      | Record the result | Print to serial or write to file |
| `REPEAT`  | Repeat   | Start again       | Wait and go back to SEE          |

---

## ✅ Slide 6: Now Add Agents — The Mission Crew!

FSM tells us *what* to do… but **Agents** tell us *how*.

| Agent Name         | Role in System        | Example Task                         |
| ------------------ | --------------------- | ------------------------------------ |
| `DataCleaner`      | Filters messy files   | Skip non-image files                 |
| `ImageHandler`     | Draws to the matrix   | `process_image("cat64.h")`           |
| `DirectiveLoader`  | Updates mission goals | Reads from `/mission_directive.json` |
| `PipelineSelector` | Chooses file source   | SPIFFS or built-in header?           |
| `LoopManager`      | Controls repetitions  | How many files? How long to wait?    |

> 💡 Think of **agents** like mission crew:
>
> * The FSM is the commander
> * Agents are the experts who get stuff done

---

## ✅ Slide 7: Swappable Agents = Flexible Projects

You can **swap agents** for different missions:

| Project             | Agent Swap Idea                         |
| ------------------- | --------------------------------------- |
| LED Billboard       | Swap `ImageHandler` to scroll text      |
| Sound-Activated Bot | Swap `DirectiveLoader` to mic listener  |
| Smart Camera        | Add `ObjectDetector` agent for analysis |

🎯 **This is how your Capstone projects can grow**:

* Replace one agent and your robot does something new.
* Plug in new data and update the behavior.
* Reuse the FSM + MCP structure every time.

---

### ✅ Next: Let’s Open `MissionCrew_Lab3.ino` and Explore the Agent Setup

