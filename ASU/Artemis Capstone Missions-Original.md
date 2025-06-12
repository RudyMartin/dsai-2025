Here's a clean set of **Team-to-Capstone Assignment Cards** — one per team — showing:

* 🎯 **Mission Role**
* 🔧 **Primary Capstone Package**
* 🧰 **Key Tools & Shared Resources**
* ✅ **Use Cases and Connections**

---

### 🟥 **Team Nova Alpha – Object Detection + Actuation**

**🎯 Mission Role:**
Sort and route LEGO objects using servo mechanisms based on AI predictions.

**🔧 Capstone Package:**
🟦 **Package A – Robotics**

**🧰 Tools:**

* SG92R 9g Micro Servo (reused)
* LEGO baseplate + pieces (reused)
* RC Servo Tester (shared)
* Clear Ruler (Lab 5)
* ESP32-S3 CAM board (from Lab 2)

**✅ Use Cases:**

* Object routing (Deck A/B/C)
* Servo-controlled gates
* Connected to detection output from LLM or camera

---

### 🟦 **Team Nova Beta – Logging & Display**

**🎯 Mission Role:**
Log object detections and system messages; display results visually.

**🔧 Capstone Package:**
🟪 **Package C – Talkers + Display**

**🧰 Tools:**

* 64×64 RGB LED Matrix Panel (reused)
* ESP32-S3 CAM board (Lab 2)
* TXS0108E Logic Shifter (reused)
* 5V 4A Power Supply (shared)
* MAX98357 Audio Amp (Capstone C)

**✅ Use Cases:**

* Visual status display for other teams
* LLM messages / classification results
* Optional audio confirmation or feedback

---

### 🟨 **Team Vega Alpha – Sensor Dashboard**

**🎯 Mission Role:**
Monitor conditions (temperature, humidity, motion); post alerts.

**🔧 Capstone Package:**
🟩 **Package B – Sensors**

**🧰 Tools:**

* SHT30 Temp/Humidity Sensor (Capstone B)
* HC-SR501 Motion Sensor (Capstone B)
* Shared LED Matrix (visual warnings)
* ESP32 board with display

**✅ Use Cases:**

* Alert if deck is too hot/humid
* Motion detection for object arrival
* Feed into Orion forecasting system

---

### 🟩 **Team Vega Beta – Environmental Gate**

**🎯 Mission Role:**
Allow/reject object entry based on environmental readings and logic.

**🔧 Capstone Package:**
🟦🟩 **Packages A + B (Servo + Sensor)**

**🧰 Tools:**

* SG92R Servo (reused)
* HC-SR501 or SHT30 Sensor (Capstone B)
* ESP32 board
* Logic control with shared LLM agent

**✅ Use Cases:**

* Stop gate if “deck too full”
* Only allow objects if temp < threshold
* Combine physical and digital rules

---

### 🟨 **Team Orion Alpha – Forecast + Health Monitoring**

**🎯 Mission Role:**
Predict deck overloads, alert team of dangerous trends.

**🔧 Capstone Package:**
🟪🟩 **Packages B + C (Sensor + Talkers)**

**🧰 Tools:**

* Shared LED Matrix (alert display)
* Logs from Nova Beta
* Optional voice/audio feedback
* ESP32-S3 for processing

**✅ Use Cases:**

* Count how many food items in Deck C
* Predict issues before they occur
* Trigger alerts (visual or audible)

---

### 🟪 **Team Orion Beta – Robots That Talk**

**🎯 Mission Role:**
Enable robotic systems to communicate with speech or sound feedback.

**🔧 Capstone Package:**
🟪 **Package C – Talkers**

**🧰 Tools:**

* XIAO ESP32-S3 Sense (w/ mic)
* MAX98357 I2S Audio Amp
* Speaker (reused or add-on)
* Logic response to events or voice command

**✅ Use Cases:**

* Say “Deck C Full” when threshold reached
* Respond to spoken command (forward/back/stop)
* Announce forecasted issues audibly

---

