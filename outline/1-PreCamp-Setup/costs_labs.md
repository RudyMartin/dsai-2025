Breakdown of Lab  Kit Costs

---

### 🔬 **Lab 1 – Practical Python, ChatBots**
---

### 🎯 **Goal:**

Introduce students to Python and basic AI logic through Google Colab notebooks. This is a software-only lab with no hardware required.

🧰 Materials per Group Lab Kit

| Item                       | Qty | Unit Cost | Subtotal | Notes                              |
| -------------------------- | --- | --------- | -------- | ---------------------------------- |
| Google Colab Access        | —   | \$0.00    | \$0.00   | Free cloud-based Jupyter notebooks |
| LLM API Key (Shared, Opt.) | 1   | —         | —        | Instructor provides shared access  |
| Example Notebook Templates | —   | \$0.00    | \$0.00   | Provided in GitHub repo            |


💵 Total Cost for Lab 1 (All 6 Teams): $0.00


---

### 🔬 **Lab 2 – Arduino, Deploying Model to ESP32**

---

### 🎯 **Goal:**

Run a trained classification model on a **Freenove ESP32-S3 WROOM**, using the onboard OV2640 camera. Results are viewed via USB serial monitor. This lab introduces model deployment and prepares teams for physical interaction in Lab 3 and beyond.

---

### 🧰 Lab 2 Materials per Group Lab Kit

| Item                                  | Qty | Unit Cost | Subtotal | Notes                                       |
| ------------------------------------- | --- | --------- | -------- | ------------------------------------------- |
| **Freenove ESP32-S3 WROOM CAM Board** | 1   | \$17.99   | \$17.99  | Includes camera, USB-C, LED, boot/reset     |
| **Freenove ESP32-S3 Breakout Board**  | 1   | \$11.90   | \$11.90  | Expands GPIO pins for sensors, servos, etc. |
| **USB-C to USB-A Cable**              | —   | Included  | —        | Comes with Freenove kit                     |
| **Mini screwdriver (in kit)**         | —   | Included  | —        | For terminal blocks                         |
| **Colored Wood Blocks**               | —   | Shared    | —        | For classification and modeling images      |
| **Computer / Serial Monitor**         | —   | School    | —        | Python or Arduino IDE monitor               |

---

### 💵 **Total Cost for Lab 2 (All 6 Teams)**

| Metric               | Value        |
| -------------------- | ------------ |
| Total Cost (6 teams) | **\$179.34** |
| Per Group Cost       | **\$29.89**  |

✅ Lab 2 is the hardware **on-ramp**, introducing embedded model execution with easy debugging and no sensor wiring needed yet.


Here is the finalized Lab 3 budget page in the same format:

---

## 🔬 **Lab 3 – LED Display + LLM Connection**

---

### 🎯 **Goal:**

Build a system that:

* Displays classification or LLM-based output on a **64×64 RGB LED Matrix**
* Connects and communicates with the **ESP32-S3**
* Uses **logic-level shifting** for safe 3.3V → 5V signal control
* Prepares students for shared **capstone visual systems**

---

### 🧰 Lab 3 Materials per Group Lab Kit

| Item                                   | Qty | Unit Cost | Subtotal | Notes                             |
| -------------------------------------- | --- | --------- | -------- | --------------------------------- |
| **64×64 RGB LED Matrix Panel (HUB75)** | 1   | Provided  | —        | Already owned, full-color display |
| **TXS0108E Logic Level Shifter**       | 1   | Provided  | —        | Handles all 3.3V → 5V logic lines |
| **External 5V 4A Power Supply**        | 1   | \$10.00   | \$10.00  | Dedicated supply for LED matrix   |
| **Jumper wires, breadboard, sockets**  | 1   | \~\$2.00  | \$2.00   | For matrix and logic hookup       |
| **Freenove ESP32-S3 CAM Board**        | —   | Reused    | —        | Already purchased in Lab 2        |

---

### 💵 **Total Cost for Lab 3 (All 6 Teams)**

| Metric               | Value       |
| -------------------- | ----------- |
| Total Cost (6 teams) | **\$72.00** |
| Per Group Cost       | **\$12.00** |

---

### ✅ Requirements Alignment

#### ✅ Functional

| Requirement                 | Met by             |
| --------------------------- | ------------------ |
| Display model or LLM output | 64×64 Matrix       |
| Safe logic levels           | TXS0108E           |
| Power isolation             | External 5V supply |

#### ✅ Narrative / Mission

| Requirement                       | Met by                           |
| --------------------------------- | -------------------------------- |
| Common visual messaging system    | Panel used across Labs 6–10      |
| Consistent interface for teamwork | Reused setup supports continuity |
| LLM interactivity                 | Output can be triggered via text |

---

Here's the updated **Lab 4** budget with the actual **DIY 4DOF Wood Arm Kit** and **PCA9685 16-channel servo driver** included:

---

## 🔬 **Lab 4 – Robot Arm + TinkerCAD**

---

### 🎯 **Goal:**

Build and simulate a basic robot arm:

* Use pre-assembled wooden 4DOF robot arms with SG90 servos
* Drive servos using a dedicated PCA9685 board
* Explore robotic kinematics via TinkerCAD simulation or sketching
* Control movement from ESP32 using I2C-based servo driver

---

### 🧰 Lab 4 Materials per Group Lab Kit

| Item                                          | Qty | Unit Cost | Subtotal | Notes                                         |
| --------------------------------------------- | --- | --------- | -------- | --------------------------------------------- |
| **4DOF Wood Robot Arm Kit (w/ SG90 servos)**  | 6   | \$25.57   | \$153.42 | Pre-assembled, each includes 4 servos         |
| **PCA9685 16-channel PWM Servo Driver Board** | 6   | \~\$5.00  | \$30.00  | Enables stable multi-servo control over I2C   |
| **Jumper wires + breadboard**                 | 6   | \~\$2.00  | \$12.00  | Reused or budgeted for signal/power wiring    |
| **Freenove ESP32-S3 CAM Board**               | —   | Reused    | —        | From Lab 2                                    |
| **USB cable and power source**                | —   | Reused    | —        | Supplied via laptop or shared 5V power supply |

---

### 💵 **Total Cost for Lab 4 (All 6 Teams)**

| Metric         | Value        |
| -------------- | ------------ |
| Total Lab Cost | **\$195.42** |
| Per Group Cost | **\$32.57**  |

---

### ✅ Requirements Alignment

#### ✅ Functional

| Requirement                    | Met by                               |
| ------------------------------ | ------------------------------------ |
| Robotic motion (multi-axis)    | 4DOF Arm Kit with SG90 servos        |
| Multi-servo coordination       | PCA9685 I2C servo driver             |
| Physical-to-simulation mapping | TinkerCAD / visual design discussion |

#### ✅ Narrative / Mission

| Requirement                           | Met by                   |
| ------------------------------------- | ------------------------ |
| Physical routing design               | Arm mimics sorting logic |
| Mechanical simulation/visual thinking | TinkerCAD integration    |
| Transition to Capstone builds         | Reuse arm + PCA driver   |

Here is the **updated Lab 5** cost summary and materials list — **PIR motion sensor removed**, focusing only on the **camera and voice command system via XIAO ESP32-S3**:

---

## 🔬 **Lab 5 – Motion Detection + Conveyor** *(Updated)*

---

### 🎯 **Goal:**

Simulate intelligent conveyor control using **camera input and voice commands** (e.g., “forward,” “stop”) on the **XIAO ESP32-S3**. This lab introduces lightweight ML logic, real-time interaction, and servo actuation.

---

### 🧰 Lab 5 Materials per Group Lab Kit

| Item                                        | Qty   | Unit Cost | Subtotal | Notes                                                           |
| ------------------------------------------- | ----- | --------- | -------- | --------------------------------------------------------------- |
| **XIAO ESP32-S3 Sense (w/ camera + mic)**   | 6     | \$23.61   | \$141.66 | Camera + digital mic support TFLite & voice command integration |
| **SG92R 9g Micro Servo Motor**              | 6     | Reused    | \$0.00   | Already listed in earlier lab inventory                         |
| **18mm RGB LED (Adafruit 4042)**            | 6     | \~\$2.00  | \$12.00  | Used for visual status (green = active, red = stop)             |
| **LEGO baseplate (white/neutral 32x32)**    | 6     | Reused    | \$0.00   | Object platform                                                 |
| **LEGO bricks / wood blocks (3–5 classes)** | 1 set | Reused    | \$0.00   | 24 large + 6 medium for voice-labeled object scenarios          |
| **Camera/LED mount (Technic pegs + beams)** | 6     | Reused    | \$0.00   | For stable placement of camera and lights                       |
| **Jumper wires + connectors**               | 6     | \~\$1.00  | \$6.00   | Power + GPIO wiring                                             |
| **Shared power supply + tips**              | —     | Shared    | —        | Provided via universal adjustable supply in shared inventory    |

---

### 💵 **Total Cost for Lab 5 (All 6 Teams)**

| Metric         | Value        |
| -------------- | ------------ |
| Total Lab Cost | **\$159.66** |
| Per Group Cost | **\$26.61**  |

---



