
## 💬 **Camp Materials Reimbursement Request**

Designing the new Artemis camp curriculum has been a truly rewarding experience. It’s been exciting to see the potential of hands-on learning with Generative AI and Robotics come to life for students in such a meaningful way.

As we transitioned from concept to implementation, it became clear that providing students with rich, group-based, project kits would require a deeper investment in materials than I had originally anticipated. To ensure a high-quality experience, I’ve personally funded all 6 Lab Kits and all 8 Capstone Kits — essentially using my entire camp stipend to do so.

To help offset these material costs and sustain this level of engagement for our students, I’m requesting an additional $2,000 in support. A detailed breakdown of the kit expenses is included below.

Thank you sincerely for your time and consideration.

Warm regards,

Rudolph Martin

---


## 📊 **Budget Table – Artemis DSAI 2025 Camp (24 Students)**


### ✅ **Recalculated Totals**

| **Category**                    | **Qty** | **Unit Cost** | **Total Cost** | **Notes**                                                 |
| ------------------------------- | ------: | ------------: | -------------: | --------------------------------------------------------- |
| 🔬 Lab Kits + Shared Supplies   |       6 |      \$184.33 |     \$1,105.98 | 1 kit per group; includes reusable tools and electronics  |
| 🧰 Capstone Kit – Type A        |       3 |      \$147.23 |       \$441.69 | High-torque robotic arm & controller (3 students per kit) |
| 🧪 Capstone Kit – Type B        |       2 |      \$109.42 |       \$218.84 | Sensor fusion, LED display, I/O board                     |
| 🧠 Capstone Kit – Type C        |       3 |      \$129.13 |       \$387.39 | Voice command AI, LED + speaker setup                     |
| **Capstone Kits (Group Total)** |       8 |             — | **\$1,047.92** | Each kit supports 3 students; total = 24 students         |
| **✅ GRAND TOTAL**               |       — |             — | **\$2,153.90** | All materials covered for full camp + capstone            |

---

### ❌ Correction Needed

The **GRAND TOTAL** shown as **\$3,986.00** is not correct.

> **Correct Grand Total: \$1,105.98 + \$1,047.92 = \$2,153.90**

---

If you're trying to **add additional expenses** or **account for all 24 individual student kits**, we’d need to adjust the quantity or calculation logic (e.g., multiplying per-student equivalents).

Would you like help formatting a version that assumes **1 kit per student (×24)** instead of per-group?


---


Breakdown of Lab  Kit Costs (Assuming we assign students into 6 Groups to cut costs. Currently we our out of pocket on all this and  soliciting help.)

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


### 💵 **Total Cost for Lab 1 (All 6 Teams)**

| Metric               | Value        |
| -------------------- | ------------ |
| Total Cost (6 teams) | **\$0** |
| Per Group Cost       | **\$0*  |


**✅ Lab 1 is the foundation**, giving students hands-on experience with Python and LLM logic in Colab — setting the stage for real-world applications with physical devices in Lab 2.

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


**✅ Lab 2 is the hardware on-ramp**, introducing embedded AI by deploying a trained model directly to the ESP32-S3. With built-in camera input and serial output, students begin running edge inference with minimal setup — setting the stage for physical I/O in upcoming labs.

---

### ✅ Requirements Alignment

#### ✅ Functional

| Requirement                | Met by                            |
| -------------------------- | --------------------------------- |
| Embedded model execution   | Freenove ESP32-S3 WROOM CAM board |
| Image-based classification | Onboard OV2640 camera             |
| Debugging via computer     | USB-C serial connection           |

#### ✅ Narrative / Mission

| Requirement                              | Met by                                |
| ---------------------------------------- | ------------------------------------- |
| First edge-device AI execution           | Deployed model runs on ESP32 hardware |
| Hands-on introduction to inference logic | Students observe model predictions    |
| Foundation for real-time system feedback | Prepares for visual display in Lab 3  |


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

### 🧰 **Materials in the Group Kit**

| Item                                   | Qty | Unit Cost | Subtotal | Notes                              |
| -------------------------------------- | --- | --------- | -------- | ---------------------------------- |
| **64×64 RGB LED Matrix Panel (HUB75)** | 1   | \$47.91   | \$47.91  | Full-color display panel           |
| **TXS0108E Logic Level Shifter**       | 1   | \$3.75    | \$3.75   | 8-channel 3.3V to 5V level shifter |
| **External 5V 4A Power Supply**        | 1   | \$10.00   | \$10.00  | Dedicated supply for LED matrix    |
| **Jumper wires, breadboard, sockets**  | 1   | \~\$2.00  | \$2.00   | For matrix and logic hookup        |
| **Freenove ESP32-S3 CAM Board**        | —   | Reused    | \$0.00   | Already purchased in Lab 2         |

---

### 💵 **Total Cost for Lab 3 (All 6 Teams)**

| Metric         | Value        |
| -------------- | ------------ |
| Total Lab Cost | **\$383.46** |
| Per Group Cost | **\$63.91**  |


**✅ Lab 3 introduces shared visual systems**, enabling groups to display AI-driven results and coordinate outputs — bridging embedded sensing with real-time feedback for Lab 4’s robotics.


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

**✅ Lab 4 brings motion to life**, combining physical robotics with AI logic and control systems — setting the groundwork for voice-command interaction and environment sensing in Lab 5.

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
| **LEGO baseplate (white/neutral 32x32)**    | 6     | \$10.00   | \$60.00   | Object platform                                                 |
| **LEGO bricks / wood blocks (3–5 classes)** | 1 set | Shared    | \$0.00   | 24 large + 6 medium for voice-labeled object scenarios          |
| **Camera/LED mount (Technic pegs + beams)** | 6     | Reused    | \$0.00   | For stable placement of camera and lights                       |
| **Jumper wires + connectors**               | 6     | \~\$1.00  | \$6.00   | Power + GPIO wiring                                             |
| **Shared power supply + tips**              | —     | Shared    | —        | Provided via universal adjustable supply in shared inventory    |

---

### 💵 **Total Cost for Lab 5 (All 6 Teams)**

| Metric         | Value        |
| -------------- | ------------ |
| Total Lab Cost | **\$219.66** |
| Per Group Cost | **\$36.61**  |


**✅ Lab 5 blends vision and voice**, empowering students to create intelligent agents that respond to camera input and spoken commands — forming a complete sense-think-act loop and laying the foundation for capstone system integration.

---

### ✅ Requirements Alignment

#### ✅ Functional

| Requirement                     | Met by                              |
| ------------------------------- | ----------------------------------- |
| Real-time visual recognition    | XIAO ESP32-S3 onboard camera        |
| Voice-triggered actions         | Onboard digital microphone + TFLite |
| Interactive control (servo/LED) | SG92R servo + RGB LED feedback      |

#### ✅ Narrative / Mission

| Requirement                               | Met by                            |
| ----------------------------------------- | --------------------------------- |
| Responsive environment simulation         | Voice + camera-based input logic  |
| Visual status signaling                   | RGB LED (green/red for state)     |
| Hardware continuity into Capstone systems | Reuse of camera, servo, LED, base |

---

Here’s the final **cost breakdown** of Labs 1–5 **plus Shared Supplies**, along with the **per group average**:

---

## 🧪 Lab Kits Cost Summary (Labs 1–5, All 6 Teams)

| Lab                     | Total Cost (All Teams) | Per Group Cost |
| ----------------------- | ---------------------- | -------------- |
| Lab 1                   | \$0.00                 | \$0.00         |
| Lab 2                   | \$179.34               | \$29.89        |
| Lab 3                   | \$383.46               | \$63.91       |
| Lab 4                   | \$65.57                | \$10.93        |
| Lab 5                   | \$219.66               | \$36.61        |



---

## 🧰 Shared Supplies Cost Breakdown

| Item                                      | Quantity | Unit Cost | Subtotal     |
| ----------------------------------------- | -------- | --------- | ------------ |
| Adjustable Power Supply (3V\~24V 6A)      | 1        | \$33.14   | \$33.14      |
| Hex Screws, Washers, Nuts Kit (3 packs)   | 3        | \$10.00   | \$30.00      |
| Digital Caliper                           | 1        | \$19.48   | \$19.48      |
| Lead Solder Wire (0.3mm/50g)              | 1        | \$7.19    | \$7.19       |
| Universal 5V 3A Power Adapter (11 tips)   | 1        | \$6.80    | \$6.80       |
| Digital Multimeter Tester                 | 1        | \$13.95   | \$13.95      |
| Electric Screwdriver Set (Fanttik E1 Max) | 1        | \$48.97   | \$48.97      |
| Potentiometer Kit (80pcs)                 | 1        | \$11.99   | \$11.99      |
| Colorful Wooden Blocks (150 pcs)          | 1        | \$21.99   | \$21.99      |
| Servo Tester (2 pcs)                      | 1        | \$16.48   | \$16.48      |
| Long Needle Nose Pliers (3 sets)          | 3        | \$9.99    | \$29.97      |
| WGGE Wire Stripper & Cutter               | 1        | \$7.99    | \$7.99       |
| **Total Shared Supplies**                 | —        | —         | **\$257.95** |

## 📊 Lab Kits Total

| **Category**         | **Amount**     |
| -------------------- | -------------- |
| Total Lab Kit Cost   | \$848.03       |
| Shared Supplies Cost | \$257.95       |
| **Lab Kits Total**   | **\$1,105.98** |
| **Per Group (÷6)**   | **\$184.33**   |

---









