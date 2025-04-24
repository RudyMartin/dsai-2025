Our intial data set only included a few common fields and 

## ✅ Current Data Lets Us Assert:

| Rule ID | Rule Description |
|---------|------------------|
| R1 | No **human** if `light > 70%` |
| R2 | No **food** if `temp > 30°C` |
| R3 | Reject predictions with `confidence < 60%` |
| R4 | Flag if `true_class = robot` but `predicted_class = human` |
| R5 | Limit `Deck A` to ≤5 humans per day (*needs rollup logic*) |
| R6 | Raise alert if 2+ `⚠️` rows in a row |

---

## 🚫 Rules We *Know About* But *Cannot Currently Assert* From This Data Alone:

| Rule ID | Rule Description | Why It’s Missing |
|---------|------------------|------------------|
| R7 | Require override note for manual insertions | ❌ No `insertion_method` field |
| R8 | Disallow object if system ping fails | ❌ No `system_status` or `ping_success` field |
| R9 | Don’t allow duplicate predictions | ❌ No `object_id` to track object continuity |
| R10 | Vega sensors must log within last 60 sec | ❌ No explicit `sensor_log_time` or Vega/Nova sync ID |
| R11 | Dock automatically after 2 consecutive flight failures | ❌ No binary `flight_passed` flag or flight grouping ID |
| R12 | Log review must be complete before next flight | ❌ No event status for `review_completed` or timestamps from Orion |

---

## 🧭 Additional Data You’d Need to Assert These

| Needed Field | Purpose |
|--------------|---------|
| `object_id` | Track if objects were reused / misrouted |
| `flight_id_group` or `mission_id` | Group rows into distinct “flights” for analysis |
| `insertion_method` (auto/manual) | Determine if object was inserted manually |
| `system_ping` (bool) | Check if comms were active during event |
| `review_completed_by_orion` | Ensure procedural compliance |
| `sensor_log_time` or `last_vega_ping` | Cross-check freshness of data

---
