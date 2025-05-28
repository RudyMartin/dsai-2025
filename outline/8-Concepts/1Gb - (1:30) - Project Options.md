

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
