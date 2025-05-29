
# 📦 DSAI 2025: Baseline Options and Mission Alignment

These three **"fallback" project options** are **lightweight, accessible entry points** for students or teams with limited hardware or those who are newer to embedded AI systems. They fit neatly within our **Mission Nova** tier and are excellent stepping stones toward the more advanced **Mission Vega** and **Mission Orion** tracks.

---

## 🧭 Where These Options Fit

| Option     | Description                                         | Mission Level          | Purpose                                                                                         |
| ---------- | --------------------------------------------------- | ---------------------- | ----------------------------------------------------------------------------------------------- |
| ✅ Option 1 | Camera-Based Motion Detection using ESP32 or Webcam | **Nova**               | Introduces basic computer vision without physical movement. Helps students understand sensing.  |
| ✅ Option 2 | Simulated Conveyor Using LEDs or Serial Output      | **Nova → Vega Bridge** | Builds logic skills. Introduces routing and decision-making using state-based triggers.         |
| ✅ Option 3 | Google Colab + OpenCV Motion Detection              | **Nova**               | Allows laptop-only teams to engage in visual detection logic. Great for teams with no hardware. |

---

## 🪐 Fallback Options Overview

### ✅ Option 1: Camera-Based Motion Detection

**Concept:** Detecting motion visually
**Mission Level:** 🌱 Mission Nova
**What You Need:**

* ESP32-S3 with camera (OV2640/OV5640) or USB webcam
* Pretrained script: ESP-WHO or OpenCV background subtraction
* (Optional) Stream to laptop or web dashboard

**What Students Do:**

* Detect visual motion (e.g., hand wave)
* Log frame/time and highlight motion region
* Trigger screen message (e.g., “Motion Detected!”)

**Why It Works:**

* Introduces visual sensing
* No motor or mechanical build required
* Reinforces theme: "Agents that see and respond"

---

### ✅ Option 2: Simulated Conveyor with LEDs

**Concept:** Routing based on state
**Mission Level:** 🌱 Nova or stepping into 🚦 Vega
**What You Need:**

* ESP32 + LED strip (or just serial monitor)
* Conditional logic: mock sensor data or timing events

**What Students Do:**

* Write routing logic (e.g., “If temp > 30, send to cold deck”)
* Use LEDs or print statements to simulate actions
* Add randomness to simulate real-time updates

**Why It Works:**

* Students design motion logic before building mechanics
* Great practice in if-else, flags, and decision logic
* Builds foundation for Vega-style routing agents

---

### ✅ Option 3: OpenCV in Google Colab

**Concept:** Visual logic in software
**Mission Level:** 🌱 Mission Nova
**What You Need:**

* Laptop with webcam or sample videos
* Google Colab + OpenCV code

**What Students Do:**

* Run frame-difference or optical flow detection
* Visualize where motion is occurring
* Adjust sensitivity, log false positives

**Why It Works:**

* Zero hardware dependency
* Helps students understand visual AI logic
* Easy for solo learners or remote demos

---

## 🛠 How to Use These Options

* Use these for students who **need a ramp** into hardware or are **working solo**.
* Teaching Assistants can **assign or scaffold** these based on student readiness.
* These projects can also be **early checkpoints** before unlocking more advanced builds.

---





## ✅ Option 1: **Camera-Based Motion Detection with ESP32 or Webcam**

**Concept Covered:** Detecting motion visually (Computer Vision)

### What You Need:

* ESP32-S3 with OV2640/OV5640 (or USB webcam + OpenCV in Colab)
* Static objects + movement (hands, paper, toys)
* Optional: Stream video to web page or laptop

### What Students Do:

1. Use a pretrained motion detection script (ESP-WHO or OpenCV background subtraction).
2. Trigger a message (e.g., “Motion Detected!”) on screen or serial monitor.
3. Log the frame/time and optionally color-highlight the motion region.

### Learning Outcome:

* They **see the concept** of movement detection in action without physical motors.
* Ties back to your theme of agents "seeing and reacting".

---

## ✅ Option 2: **Simulated Conveyor with LEDs or Terminal Output**

**Concept Covered:** Routing decisions based on state

### What You Need:

* ESP32 board, LED strip or serial output
* Conditional logic + sensor or mock input

### What Students Do:

1. Use simulated data (e.g., `object = food`, `temp = high`).
2. Write code to "route" these items by turning on different LEDs or printing:
   `-> Route to Deck A`, `-> Route to Cold Storage`.
3. Add randomness or timing to simulate real-time events.

### Learning Outcome:

* Students **design motion logic** even if nothing moves physically.
* Emphasizes **if-else reasoning and environmental triggers**.

---

## ✅ Option 3: **Google Colab Interactive with OpenCV**

**Concept Covered:** Motion detection logic + result interpretation

### What You Need:

* Google Colab + OpenCV sample
* Webcam-enabled laptops or use sample videos

### What Students Do:

1. Run code that detects frame difference or uses optical flow.
2. Visualize where movement is happening.
3. Modify sensitivity or detection thresholds.

### Learning Outcome:

* Students understand **how software tracks movement** and adapts behavior.
* Can tie in evaluation: e.g., false positives in motion detection.

---

## Bonus Theme Tie-In

| Theme Element        | Covered In…                                    |
| -------------------- | ---------------------------------------------- |
| “Make It Move & See” | Motion detection without physical movement     |
| “Agentic Systems”    | Simulated logic to reroute based on triggers   |
| “Optimization”       | Adjust detection thresholds for better results |

---

Would you like a quick lesson plan or code scaffold for one of these fallback activities?
