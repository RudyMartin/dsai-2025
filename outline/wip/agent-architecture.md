
## 🎓 Classic Agent Architectures 

Here are the foundational agent types and flows typically taught in AI curricula:

---

### 1. **Simple Reflex Agent**
**Flow:**
```text
Perceive → Act
```

- Behavior is a direct **mapping from sensor input to action**
- No memory, no reasoning
- Often implemented with **condition-action rules**

🧠 **Example**: If object is red → turn left  
🧪 Camp Use: ESP32 color-sorter with no model

---

### 2. **Model-Based Reflex Agent**
**Flow:**
```text
Perceive → Update Internal State → Act
```

- Has a **belief state** or memory of the world
- Can deal with **partial observability**
- More stable and context-aware

🧠 **Example**: If last 3 frames = “dark” → turn on light  
⚙️ Camp Use: Vega Alpha environment monitor

---

### 3. **Goal-Based Agent**
**Flow:**
```text
Perceive → Reason → Select Action to Reach Goal → Act
```

- Chooses actions by reasoning about **future consequences**
- Evaluates which action leads to the goal state

🧠 **Example**: "Find the object" or "Reach safe state"
🌐 Often used in planning or navigation (e.g., search algorithms)

---

### 4. **Utility-Based Agent**
**Flow:**
```text
Perceive → Evaluate Utility → Choose Best Action → Act
```

- Optimizes for **a utility function** (not just goal achievement)
- Can handle tradeoffs and uncertainty

🧠 **Example**: Choose path that’s fastest *and* safest  
📈 Often used in autonomous vehicles, smart resource allocation

---

### 5. **Learning Agent**
**Flow:**
```text
Perceive → Learn From Experience → Improve Performance → Act
```

- Learns from interactions with the environment
- Can modify performance elements (e.g., model weights, rules)

🧠 **Example**: A classifier that improves with labeled examples
🧪 Camp Use: Student-built models trained in Roboflow

---

### 🧠 Bonus: **Deliberative vs Reactive vs Hybrid Agents**

| Type | Description |
|------|-------------|
| **Reactive** | Reflex-based, acts immediately |
| **Deliberative** | Thinks ahead, uses planning |
| **Hybrid** | Mix of both — common in robotics and agent systems |

---

## 📊 Summary Diagram: Agentic Flows

| Agent Type              | Senses | Memory | Goals | Learning | Used in Camp? |
|-------------------------|--------|--------|-------|----------|---------------|
| Reflex Agent            | ✅     | ❌     | ❌    | ❌       | Sorting Servo |
| Model-Based Reflex      | ✅     | ✅     | ❌    | ❌       | Env Monitor   |
| Goal-Based              | ✅     | ✅     | ✅    | ❌       | Orion Alpha   |
| Utility-Based           | ✅     | ✅     | ✅    | ❌       | Orion Beta    |
| Learning Agent          | ✅     | ✅     | ✅    | ✅       | Roboflow Models |

---

## 🧠 Suggestion for Camp
Teach students how their ESP32 or Pi bot **fits into one of these types** — then ask:
- Can you make it smarter?
- Can it learn or make better decisions?
- Can it ask a human for help?

---
