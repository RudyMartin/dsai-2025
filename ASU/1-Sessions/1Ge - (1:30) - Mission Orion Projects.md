
## 🛰️ Mission Orion – Multi-Agent Intelligence & Coordination

**Theme**: Build a team of agents that work together, share information, and dynamically adjust based on goals and environment.

---

### 🔧 Setup Summary

| **Hardware**                              | **Software**                                |
| ----------------------------------------- | ------------------------------------------- |
| Multiple ESP32-S3 boards w/ robot arms    | Arduino or MicroPython + JSON messaging     |
| Shared deck (or shared virtual storage)   | Simple memory management / counters         |
| Sensors (temp, light, object type)        | Log-based routing, inter-agent messages     |
| Optional: OLED/LED displays or shared log | Simulated radio (e.g., file or print-based) |

---

### 🧠 Learning Outcomes

* Design agents with unique roles (planner, arm, sensor, etc.)
* Track goals, adapt actions based on history and targets
* Send/receive info to simulate agent communication
* Collaborate across teams in real-time

---

### 🌌 Agent Extensions Covered

#### 1. **Resource Allocation Agent**

**What it does**: Picks which robot or path to use depending on load or object type.

| Task          | Assignment Logic                     |
| ------------- | ------------------------------------ |
| Large block   | Assign to Arm B                      |
| High-priority | Assign to nearest available resource |

**Skills**: Prioritization, branching logic, fairness
**Assessment**: Balanced task distribution over time.

---

#### 2. **Goal-Seeking Agent with Feedback**

**What it does**: Tracks routed objects and changes behavior to hit goals.

| Current State       | Goal      | Adjustment         |
| ------------------- | --------- | ------------------ |
| Deck A: 4 tools     | Target: 2 | Stop sending tools |
| Deck C: 1 food item | Target: 3 | Prioritize food    |

**Skills**: Counters, dynamic goal re-checking
**Assessment**: Agent stops when goals are met, adapts when not.

---

#### 3. **Communication Agent (Multi-Agent System)**

**What it does**: Shares updates across agent types (e.g., placement logs, status alerts).

| Agent         | Message                        |
| ------------- | ------------------------------ |
| Arm Agent     | “Red block placed on Deck C”   |
| Sensor Agent  | “Deck C temp = 35°C”           |
| Routing Agent | “Redirect red block to Deck B” |

**Skills**: Structured messaging (via JSON, files, serial)
**Assessment**: Other agents respond to shared information.

---

### 🧭 Suggested Schedule

| **Time**  | **Activity**                                            |
| --------- | ------------------------------------------------------- |
| 0–20 min  | Role Assignment & Setup                                 |
| 20–40 min | Implement Resource Allocation agent                     |
| 40–60 min | Add goal-tracking agent (block counts or priorities)    |
| 60–90 min | Implement agent communication system (console/file/LED) |
| 90–105m   | Test inter-agent coordination across roles              |
| 105–120m  | Share logs, reflect: How well did the system cooperate? |


