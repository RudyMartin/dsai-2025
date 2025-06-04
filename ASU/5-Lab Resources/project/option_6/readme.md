### 6. **Communication Agent (Multi-Agent System)**

**Add-on Concept**: Simulate a networked team (robot arm + forecast module + deck monitor). One agent updates others on deck status.

| Agent Role     | Info Shared                  |
| -------------- | ---------------------------- |
| Arm Agent      | "Placed red block on Deck C" |
| Forecast Agent | "Deck C is 80% full"         |
| Routing Agent  | "Next red block → Deck B"    |

**Agent Behavior:** Coordinated decisions using messages
