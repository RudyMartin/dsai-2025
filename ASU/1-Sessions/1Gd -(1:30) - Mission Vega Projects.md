

## 🚀 Mission Vega – Sensor-Aware Decision Agents

**Theme**: Make the robot arm smarter by reacting to real-world inputs and optimizing movement.

---

### 🔧 Setup Summary

| **Hardware**                                       | **Software**                     |
| -------------------------------------------------- | -------------------------------- |
| ESP32-S3 + camera                                  | MicroPython or Arduino IDE       |
| Robot Arm with 4–6 DOF + PCA9685                   | Pre-trained object classifier    |
| LED strip (optional)                               | JSON-based log format (optional) |
| Temp/light/humidity sensors (DHT11/SHT30/LDR/etc.) | Sensor read scripts              |

---

### 🧠 Learning Outcomes

* React to the environment using sensor input.
* Optimize routing with condition-based logic.
* Use control structures to manage timing and avoid collision.
* Simulate “smart systems” that make decisions like a warehouse bot or traffic controller.

---

### 🛰️ Agent Extensions Covered

#### 1. **Routing Agent (Decision Logic)**

**What it does**: Decides the destination deck based on the object type and current state.

| Example Rule                                                         |
| -------------------------------------------------------------------- |
| If object = “food” and Deck C has < 3 → send to Deck C; else Deck B. |

**Skills**: If/else logic, use of memory/state, route optimization
**Sensors**: None required – state stored in memory
**Assessment**: Log of routing decisions matches desired rules.

---

#### 2. **Environmental Awareness Agent**

**What it does**: Reads environment sensors (e.g., heat, light) to guide placement.

| Input             | Agent Decision       |
| ----------------- | -------------------- |
| Temp > 30°C       | Avoid Deck A         |
| Light < threshold | Turn on guidance LED |

**Skills**: Sensor fusion, condition-triggered routing
**Sensors**: DHT11, LDR, SHT30, or similar
**Assessment**: Correct behavior based on real-time sensor input.

---

#### 3. **Traffic Controller Agent**

**What it does**: Checks motor or shuttle state before moving an object.

| Condition       | Action      |
| --------------- | ----------- |
| Conveyor = busy | Wait        |
| Path = clear    | Move object |

**Skills**: Timers, condition checks, avoid collisions
**Sensors**: Optional IR/photogate or mocked state
**Assessment**: Time-sequenced logic works under delay/load conditions.

---

### 📘 Suggested Schedule

| **Time**  | **Activity**                                       |
| --------- | -------------------------------------------------- |
| 0–15 min  | Sensor test and setup                              |
| 15–30 min | Logic planning – draw condition diagrams           |
| 30–60 min | Implement: one agent per pair                      |
| 60–90 min | Debug and test each scenario                       |
| 90–105m   | Peer test: swap setups and test behavior           |
| 105–120m  | Log results and debrief: What did the agent learn? |

