# 🛰️ Mission Data Flow Overview 


---

## 🧭 Data Flow Structure: **Who Needs What, and When**

---

### 🔹 1. Pre-Flight (Setup Phase)  
Orion’s job: **establish the mission data contract.**

| Available Data | Set By | Purpose | 🧠 **Orion Needs / Does** |
|----------------|--------|---------|---------------------------|
| Flight number / mission ID | Orion Alpha or Instructor | Anchor logs to specific events | 🛠️ Create log template & mission manifest |
| Sensor calibration values | Vega Teams | Ensure safe thresholds | ✅ Validate expected sensor ranges |
| Object class definitions | Nova Teams | Set prediction expectations | 📋 Review class names + test cases |
| Team roles / checklists | Instructor | Assign tasks and logs | 🧭 Track who is logging and reviewing |

---

### 🔹 2. In-Flight (Live Run)  
Orion’s job: **monitor live status, sync logs, raise alerts.**

| Source | Data Created | Format | Sent To | 🧠 **Orion Use / Action** |
|--------|--------------|--------|---------|----------------------------|
| Nova Alpha | Class, confidence, action taken | JSON/CSV | Orion Beta | 🧠 Use for confidence checks & gate errors |
| Nova Beta | Final log per object | JSON/CSV | NAS / Orion Alpha | ✅ Match prediction to result, log to deck |
| Vega Alpha | Temp/light + pass/fail decision | CSV/stream | Orion Alpha | ⚠️ Check for rule violations |
| Vega Beta | OLED output, alerts | Display/log | Orion Beta | 👀 Confirm alerts were shown to crew |
| Orion Beta | Pings, message events, sensor trip | Logs | Orion Alpha | 📡 Route alerts, flag sync failures |
| Orion Alpha | Aggregated logs, triggers, alerts | Summary tables | Dashboard | 🔍 Rule engine, auto-docking, capacity monitoring |

> 💡 Orion's *live mission* is to:
- Verify data is fresh
- Monitor **presence sensor** events
- Send system-wide alerts
- Track any "silent" failure in other teams

---

### 🔹 3. Post-Flight (Scrum & Review)  
Orion’s job: **tell the story of what happened, what failed, and what must change.**

| Action | Used By | Data Needed | 🧠 **Orion Role** |
|--------|---------|-------------|-------------------|
| Rule checks | Orion Alpha + TA | All logs + sensor data | ✅ Trigger summary violations |
| Visualization | Orion Alpha | Logs, class counts, alerts | 📈 Build deck charts, alert timelines |
| Storytelling | All Teams | Logs, events, failures | 🗣️ Orion confirms/denies team claims (“You say it was safe, but light was 85%”) |
| Debrief | Instructor-led | Summary sheet | 🧠 Orion leads "mission log replay" |

---

## 📋 What Each Team Adds to the Data Manifest

| Team | Data Contributed | Used By Orion For |
|------|------------------|-------------------|
| **Nova Alpha** | Predicted class + confidence | Rule 1, 2, 4 (classification logic) |
| **Nova Beta** | Timestamped object logs | Assignment accuracy + deck forecast |
| **Vega Alpha** | Sensor readings + threshold result | Rule 3, 4, 7 (risk checks) |
| **Vega Beta** | OLED messages + sensor display | Crew communication tracking |
| **Orion Beta** | Message logs, ping success/fail | Rules 6, 7, 9 (alert health + presence) |
| **Orion Alpha** | Aggregated logs + rule results | Final audit + dashboard display |

---

## 🔐 Data Availability Timeline

| Phase | Data | When It’s Available | Orion Activity |
|-------|------|----------------------|----------------|
| Setup | Rules, thresholds, ID | Day 1 | Build manifest + rule checker |
| In-flight | Predictions, sensor values | Real-time | Monitor events, trigger alerts |
| Post-flight | Logs + summaries | After each flight | Scorecard: rule pass/fail |
| End of day | Reports, charts, recap | After ~3 flights | Publish “Mission Logbook” or alert report |

---

## 🔍 Example - How Orion Connects to Rules + Tracking

| Rule | Orion Dependency |
|------|------------------|
| R1 – No humans on Deck A > 70% | Cross-check Nova class + Vega light |
| R2 – Confidence < 60% → reject | Flag low-confidence logs |
| R3 – Temp > 30°C → abort | Enforce Vega gating rule |
| R5 – Limit Deck B robots | Tally from Nova logs |
| R6 – Dock after 2 fails | Count failed flights using trigger logic |
| R7 – Abort if ping fails | Confirm via Orion Beta logs |
| R9 – Vega must log in last 60 sec | Track sensor freshness timestamps |
| R11 – Deck A hits 90% | Forecast from Nova logs |

---
