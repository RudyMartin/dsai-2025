

**TOPIC VIDEO**

[Adding AI to your ESP32 is Easier than You Think!](https://www.youtube.com/watch?v=ILh38jd0GNU) - 10 min

---

## 🔧 How This Applies to Our Labs and Keystone Projects

**Using: Seeed XIAO ESP32-S3 Sense + OV2640 Camera**

Your board already includes:

* ✅ High-performance **ESP32-S3** chip with AI support
* 🎤 A **MEMS Microphone** for audio ML tasks
* 📷 A plug-in **OV2640 Camera** for image-based models

This means **all four core AI lab types** and our **Keystone Capstone Projects** can be built on this one board — no extra modules required unless students want to customize further.

---

### ✋ **Lab 1–2: Gesture or Presence Recognition (Custom Input Classification)**

**Example Application**:

* Classify sensor inputs like “object detected” or “door opened” using a **PIR**, **IR sensor**, or even a **button tap pattern**.

**Why It Matters**:

* Teaches how to treat any incoming signal as *classifiable data*.
* Forms the basis for student-created agents like “Deck Monitor” or “Airlock Trigger”.

🔧 Options:

* Use Edge Impulse with labeled sensor input (manually triggered or PIR-based).
* If needed, extend the board with an MPU6050 or assign canned data for simulation.

---

### 🔊 **Lab 3–4: Keyword Spotting with Built-in Microphone**

**Example Application**:

* Detect commands like “go,” “stop,” or “check” using the onboard mic.

**Why It Matters**:

* Powers voice-activated agents.
* Pairs with Capstone teams building interactive or audio-driven tools (e.g., the “Talking Robot Arm” or “Command Deck”).

🔧 Notes:

* Requires ESP-IDF or patched Arduino firmware to enable microphone input.
* Data Forwarder won’t work (audio data too fast) — use `edge-impulse-daemon`.

---

### 🖼️ **Lab 5: Image Classification (Lego Sorting or Block ID)**

**Example Application**:

* Classify LEGO blocks or objects into categories using the OV2640 camera.

**Why It Matters**:

* Enables autonomous systems like **Nova’s Object Scanner** or **Orion’s Cargo Sorter**.
* Introduces pre-processing, quantization, and model input preparation.

🔧 Tips:

* Train a model in Edge Impulse or Colab.
* Export `.h` model and run inference with TensorFlow Lite Micro.

---

### 🎯 **Capstone: Object Detection for Deck Scanning or Multi-Class Analysis**

**Example Application**:

* Detect multiple objects in a camera view with bounding boxes (e.g., “food” vs. “equipment”).

**Why It Matters**:

* Core technology behind Capstone Missions like **Orion’s Overload Forecaster** or **Vega’s Deck State Monitor**.
* Great for web-based interfaces: students access real-time camera view and detections over Wi-Fi.

🔧 Setup:

* Use the custom `CameraWebInference` sketch (Edge Impulse + WebServer).
* View detections directly in browser.

---

### 💬 **Bonus: Language Models for Experimental Missions (Tiny Stories)**

**Example Application**:

* Generate short, silly responses based on text prompts (“The robot says hello!”).

**Why It Matters**:

* Great creative twist — makes AI feel more personal.
* Optional mission layer: use as voice output companion, mission journal generator, etc.

🔧 Warning:

* Just a toy at ESP32 level. Real LLM experiments should use laptop or Pi.
* Trained on TinyStories dataset — good for storytelling, not accuracy.

---

## 🔁 Student Pathways Using This Board

| **Lab/Project**  | **Sensor/Tool Used**     | **Real Mission Role**                    |
| ---------------- | ------------------------ | ---------------------------------------- |
| Lab 1–2          | PIR / Button / MPU6050   | Input classifier or gesture detector     |
| Lab 3–4          | Built-in Microphone      | Voice command listener                   |
| Lab 5            | OV2640 Camera            | Image classifier (sorting, deck tagging) |
| Capstone         | Camera + Wi-Fi           | Object detector for forecasting/logging  |
| Bonus (Optional) | Text generator (TinyLLM) | Talking bot, journal assistant           |

---

