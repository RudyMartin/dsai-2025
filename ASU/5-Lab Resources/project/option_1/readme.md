### 1. **Routing Agent: Destination Decision Maker**

**Add-on Concept**: Instead of fixed destinations, the agent decides where to send each block based on conditions like color, load balance, or “deck rules.”

| Block Class  | Agentic Rule Example                                    |
| ------------ | ------------------------------------------------------- |
| Red (Food)   | If Deck C has < 3 items, send to C. Else, reroute to B. |
| Blue (Human) | Only Deck A if temp sensor < 30°C                       |

**Skills:** condition-based logic, state tracking, sensor fusion
**Agent Behavior:** Optimizes for balanced deck distribution
