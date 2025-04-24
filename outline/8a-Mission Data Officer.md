The **Mission Data Officer (MDO)** role is vital in our simulation scenarios — they are the **data guardian and insight enabler** across teams. As students rotate through MDO duty, they build core **data science habits**:

- Observation  
- Logging  
- Pattern detection  
- Debugging  
- Team communication

Let’s break it down more clearly:

---

## 📊 Mission Data Officer (MDO)  
**Role Type:** Rotating Student Role  
**Time Commitment:** ~1 hour per flight block  
**Teams Eligible:** Any team (especially Nova Beta, Vega Alpha/Beta, Orion Alpha)

---

### 🎯 Mission Purpose

> Act as your team’s **data quality manager** and **flight log interpreter**.  
You ensure that what your system is seeing, doing, or logging is **correct, complete, and useful** for the mission.

---

### 📋 Core Responsibilities

| Duty | Description |
|------|-------------|
| ✅ **Check Logs** | Confirm your system is recording the right info (object class, sensor value, timestamp, result) |
| 👀 **Watch for Anomalies** | Spot anything strange (e.g., light sensor stuck, empty prediction, temp = 0) |
| 🔄 **Communicate with Orion** | Pass findings to Orion Alpha (e.g., “We missed logging 2 objects in Flight 2”) |
| 🧠 **Support Debrief** | Help your team explain what happened in a flight (“our model misread ‘food’ as ‘tool’”) |
| ✍️ **Write Summary** | One-line report per flight: “3 detections, 1 rejected, light = 85% on Deck B” |
| 💾 **Tag Important Events** | Flag moments like docking, fails, reboots (used by Orion for forecasting)

---

### 🧠 Embedded Data Science Concepts

| Concept | Action |
|--------|--------|
| **Data validation** | “Does our log have all the info we expected?” |
| **Anomaly detection** | “Why was temp = 0 at 11:35?” |
| **Forecast awareness** | “Should we tell Orion we’re seeing lots of food entries?” |
| **Error tracking** | “The object went to Deck A, but it was a robot — model misread it” |
| **Communication** | “We missed our last update — should we re-send it?” |

---

### 🛠️ Tools You Might Use

| Tool | Example |
|------|--------|
| Log file viewer | View `.csv` or `.txt` in Notepad or Python |
| LED indicator or buzzer | Triggered during message/alert events |
| Python or Colab | Optional — use `pandas` to analyze a flight log |
| Whiteboard or notebook | Sketch data flow or missing info before next flight |

---

### 🏆 Why This Role Matters

- No successful mission flies without **data clarity**
- It **frees up coders and builders** to focus on the system
- Helps instructors spot **early system-wide failures**
- Builds **real-world skills**: debugging, system health checks, report writing

---
