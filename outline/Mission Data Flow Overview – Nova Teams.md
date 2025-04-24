# 🛰️ Mission Data Flow Overview – Nova Teams  
> Focused on what Nova Alpha and Beta teams do, when data is created, and how it connects to rules, automation, and storytelling.

---

## 🧭 Data Flow Structure: **Nova’s Contributions to the Mission Brain**

---

### 🔹 1. Pre-Flight (Setup Phase)  
Nova’s job: **capture data and prepare the AI model.**

| Setup Item | Set By | Purpose | 🧠 Nova Role |
|------------|--------|---------|--------------|
| Object class labels | Nova Beta | Establish categories for training | Choose LEGO types: food, tool, human, robot |
| Image dataset | Nova Alpha | Capture photos for model training | Take 10–15 images per object class |
| Model architecture + confidence logic | Nova Alpha | Select base model + define confidence threshold | Train + test in Roboflow, set rejection rule |
| Test plan | Instructor + Nova | Define how predictions will trigger physical results | “If prediction = food, activate servo A” |

---

### 🔹 2. In-Flight (Live Run)  
Nova’s job: **run object detection in real time and trigger outcomes.**

| Source | Data Created | Format | Sent To | 🧠 Nova Action |
|--------|--------------|--------|---------|----------------|
| Camera module | Captured image | Frame | ESP32 or Pi | Triggered on object placement |
| ML model output | Predicted class + confidence | JSON/CSV | Nova Beta + Orion Beta | Save locally + forward for rule checks |
| Gate decision | Accepted/rejected, servo triggered | GPIO / log | Orion Alpha | Used to simulate movement or rejection |
| Log entry | Class, confidence, timestamp, deck assigned | Row per object | NAS, Orion Alpha | Powers rule checks, storytelling, analytics |

---

### 🔹 3. Post-Flight (Scrum / Review)  
Nova’s job: **analyze predictions, review failures, and improve the model.**

| Action | Data Used | Outcome |
|--------|-----------|---------|
| Review predictions vs ground truth | Log + flight video | Identify confusion or “flip” errors |
| Track confidence distribution | Log file | Spot weak object classes |
| Adjust threshold if needed | Nova model config | Improve acceptance quality |
| Tell story of sorting logic | Log, servo reaction, missed detections | “We predicted ‘tool’, but it was ‘food’. Here’s why...” |

---

## 📋 What Nova Teams Add to the Manifest

| Nova Role | Key Contribution | Used By |
|-----------|------------------|---------|
| **Nova Alpha** | Prediction class, confidence, GPIO result | Orion for rule 1, 2, 4 enforcement |
| **Nova Beta** | Final log (class, time, deck) | Orion Alpha for dashboard + deck forecasting |

---

## 🔐 Nova’s Data Availability Timeline

| Phase | Data Type | When It’s Available | Notes |
|-------|-----------|----------------------|-------|
| Setup | Class names + training images | Day 1 | Students upload to Roboflow |
| Model output | Class + confidence | Real-time | From ESP32 or Pi |
| Log entry | Object log + deck assigned | End of each flight | Synced to Orion or NAS |
| Model tweak | Threshold change or retraining | Day 3–4 | Optional based on error review |

---

## 🔍 Nova Rules & Data Dependencies

| Rule | Data Needed | What Nova Provides |
|------|-------------|--------------------|
| R1 – No humans on Deck A if light > 70% | Nova prediction, deck assignment | `true_class`, `deck`, `confidence` |
| R2 – Reject if confidence < 60% | Confidence score | `confidence` field |
| R4 – No food to Deck C if light > 80% | Prediction + deck route | `true_class`, `deck` |
| R8 – Delay if servo not reset | Hardware state | GPIO event log or lack thereof |
| R10 – Override note on manual insert | Logging discipline | Note + timing of skipped prediction |
| R11 – Forecast deck occupancy | Final log row per object | `deck`, `timestamp`, `object` |

---

## 🎯 TA + Instructor Support Suggestions

- ✅ Have Nova teams **record a prediction video** to spot “model flipping”
- ✅ Let students **visually check** confidence score on OLED or serial print
- ✅ Use a printable **Prediction Report Card** after each flight:
  - Object
  - True class
  - Predicted class
  - Confidence
  - Was it accepted?
  - Did the servo trigger?

---
