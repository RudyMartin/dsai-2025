### 2. **Traffic Controller Agent**

**Add-on Concept**: Add a **conveyor belt** or **shuttle platform**. The agent decides whether to move an object now or wait (like stoplights or traffic signals).

| State             | Action                    |
| ----------------- | ------------------------- |
| Belt is full      | Wait before placing block |
| Shuttle in motion | Pause movement            |

**Agent Behavior:** Optimizes for flow control and avoids collisions
