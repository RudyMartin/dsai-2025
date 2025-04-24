
In a **real NASA mission**, especially during space station operations or interplanetary flight, there are **multiple types of resource access points**, each designed to ensure mission continuity under **limited conditions** (power, bandwidth, crew, time). Let’s break this down clearly:

---

## 🚀 Real NASA Mission – Key Resource Access Points

| Access Point | Description | Camp Equivalent |
|--------------|-------------|-----------------|
| 🛰️ **Onboard Systems (Local)** | Systems on the spacecraft that run autonomously or can be controlled by astronauts — includes life support, guidance, robotic arms, sensors | ESP32 object detection, LEGO actuation, sensor gates |
| 🌐 **Telecom Link to Earth (DSN)** | The Deep Space Network provides communication between mission control and the spacecraft — subject to time delays (minutes to hours) | Offline NAS log sync / inter-team message relay |
| 📡 **Command & Data Handling (C&DH)** | The spacecraft’s internal computer and data bus — routes sensor input, runs autonomous logic, stores logs | Raspberry Pi teams logging flight events, Nova/Vega dashboards |
| 💾 **Flight Data Recorder (FDR)** | Stores key system telemetry (temp, pressure, power) for later review — even after failure | Orion Alpha’s log analysis of object counts, forecast errors |
| 👩‍🚀 **Crew-Operated Terminals** | Interfaces astronauts use to monitor systems, override automation, or input decisions | Orion dashboards, Pi dashboards, LEGO control consoles |
| 🔧 **Maintenance Lockers** | Tools, spare parts, testing equipment — used to repair or reroute systems in-flight | Your Flight Technician’s inventory and ziplock kits |
| 🧠 **Mission Control (Earth)** | Human teams who monitor telemetry, provide high-level guidance, approve or deny actions (e.g., docking) | Orion Alpha and Beta acting as mission analysts + coordinators |
| 🔄 **Redundant Pathways** | Parallel systems (backup battery, alternate comms path, software fallback) | Manual override switches, redundant Pi/ESP32s in camp builds |

---

## 🧭 Mission Resource Types (All Actively Monitored)

| Resource | Monitored For |
|----------|---------------|
| **Power** | Usage spikes, battery drain, heat load |
| **Thermal** | Overheating instruments or decks |
| **Environmental** | Oxygen, CO₂, pressure, temp, light (just like your Vega teams!) |
| **Data bandwidth** | Limits on how much can be transmitted or processed |
| **Physical storage** | Space on decks, cargo areas, robotics bay (reflected in your Space Deck capacity modeling) |
| **Human bandwidth** | Crew time — there are often “crew-hour budgets” per activity

---

## 🧑‍🚀 How This Ties to Your Camp

Your system design is *shockingly close* to the real thing:

| Real NASA | Camp Simulation |
|-----------|-----------------|
| Crew dashboards | Orion dashboard (Flask / OLED) |
| Sensor thresholds | Vega light/temp gating |
| Docking schedule | Orion forecast and Deck capacity modeling |
| Object routing | Nova Alpha servo gate → Deck A/B/C |
| Systems sync | Orion Beta messages / log monitors |
| Flight readiness check | Flight Technician checklist role |
| Mission logs / post-flight reports | Orion Alpha logs + MDO summaries |

---

### 💡 Bonus Thought:
NASA uses a system called **"Flight Rule Management"** — a dynamic rulebook that governs what actions are allowed when.

You could simulate this by:
- Giving Orion Alpha a list of rules ("No humans on Deck A if light > 70%")
- Letting teams challenge rules with a justification ("We added a shade to Deck A — reclassify?")

---

