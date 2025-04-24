
# 📡 Mission Data Flow Overview – Orion Teams  
> Orion Alpha and Beta serve as mission control: **tracking logs**, **enforcing rules**, **raising alerts**, and **forecasting danger** across the mission.

---

## 🧭 Data Flow Structure: **Orion as the Mission’s Nervous System**

---

### 🔹 1. Pre-Flight (Setup Phase)  
Orion’s job: **define the mission structure, rule-checking system, and alerts.**

| Setup Item | Set By | Purpose | 🧠 Orion Role |
|------------|--------|---------|--------------|
| Flight number / ID | Orion Alpha | Anchor all logs to a single event | Create manifest + log template |
| Ping system setup (for fail detection) | Orion Beta | Track data stream status | Simulate sensor pings, verify uptime |
| Presence sensor install (optional) | Orion Beta | Detect crew approach to deck | PIR or IR module for walk-up logging |
| Rules checklist | Instructor + Orion Alpha | Define what violations to check | Preload conditions into checklist or script |

---

### 🔹 2. In-Flight (Live Run)  
Orion’s job: **monitor logs, sync messages, and raise system-wide alerts.**

| Source | Data Created | Format | Sent To | 🧠 Orion Action |
|--------|--------------|--------|---------|----------------|
| Nova + Vega | Logs: class, confidence, sensor status | CSV/JSON | Orion Alpha | Parse for violations (e.g., confidence < 60%) |
| Orion Beta | Ping success/fail, alert status | Message log | Orion Alpha | Check system health, raise alerts |
| Presence sensor | Object/people movement detected | Boolean or timestamp | Orion Beta | Trigger “approach alert” or log visit |
| Dashboard | Aggregated violations, counts, alerts | Table or printout | Shared with all teams | Visual summary of rule tracking |

---

### 🔹 3. Post-Flight (Scrum & Review)  
Orion’s job: **report flight performance, flag rules broken, and drive data-driven retrospectives.**

| Action | Data Used | Outcome |
|--------|-----------|---------|
| Rule checking | Logs, timestamps, deck state | Score rule violations (trigger/didn’t trigger) |
| Flight summary | Logs, alerts, events | Prepare recap: “3 violations, docking triggered” |
| System health check | Ping logs, presence sensor | Flag stale logs, silent teams |
| Alert replay | Presence → alert → log | “We had 2 deck approaches; both were safe” |

---

## 📋 What Orion Teams Add to the Manifest

| Orion Role | Contribution | Used By |
|------------|--------------|---------|
| **Orion Alpha** | Rule violation log, forecast report, capacity flags | Instructor + Teams |
| **Orion Beta** | Ping checks, presence detection, message sync | Orion Alpha, instructor, or alert devices |

---

## 🔐 Orion’s Data Availability Timeline

| Phase | Data Type | When It’s Available | Notes |
|-------|-----------|----------------------|-------|
| Setup | Mission ID, rules | Day 1 | Defined in shared manifest |
| In-flight | Ping, alerts, sensor sync | Real-time | Logs generated per event |
| Post-flight | Rule violation summary | After each flight | Used for scrum and recap |
| End of day | Flight summary report | After 2–3 flights | Archive or print dashboard

---

## 🔍 Orion Rule & System Dependencies

| Rule | Orion Tracks Using |
|------|--------------------|
| R1 – No humans if light > 70% | Nova + Vega logs |
| R2 – Confidence < 60% | Nova predictions |
| R5 – Limit Deck B to 2 robots | Deck assignment count |
| R6 – Dock after 2 failures | Orion rule log (e.g., 2+ major violations) |
| R7 – Abort if ping fails | Orion Beta ping logs |
| R9 – Require fresh sensor data | Vega log timestamps |
| R11 – Deck A hits 90% | Log-based capacity forecast |
| R12 – Checklist before Flight 3 | Instructor checklist + Orion note |

---

## 🎯 TA + Instructor Support Suggestions

- ✅ Have Orion teams **count rule hits vs misses** after each flight
- ✅ Let Orion Beta **simulate a comms failure** (“Nova offline!”) and trigger system halt
- ✅ Use a **dashboard or poster** to track:
  - Flights complete
  - Rules broken
  - Alerts triggered
  - Capacity per deck

---

## 🎉 Bonus Tools to Make Orion Fun & Hands-On

| Tool | Purpose | Why It’s Fun |
|------|---------|---------------|
| PIR sensor | Detect “crew” near deck | Adds mission realism + triggers alerts |
| RGB LED or NXT flag | Visual system alert | Feels like command center |
| Flight log playback | Chart of what happened when | Makes Orion feel like NASA Ops |
| TA Roleplay | “I’m an investigator—show me what went wrong!” | Turns data into drama

---
