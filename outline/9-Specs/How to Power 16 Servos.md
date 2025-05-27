See  also:

- [Linking Multiple PCA9685 Servo Driver Boards](https://www.youtube.com/watch?v=v1f_EDHV390)

Here's a **step-by-step breakdown** of the YouTube video [“How to Power & Wire 16 Servo Motors for Arduino using PCA9685”](https://www.youtube.com/watch?v=UeS5nY345kc)

## 🔧 **GOAL OF THE VIDEO**

The video shows how to **control and power up to 16 servo motors** using an **Arduino and a PCA9685 PWM driver** — with attention to power needs and wiring safely.

---

# 🧠 STEP-BY-STEP GUIDE (WITH CONTEXT + EXTRA CLARITY)

---

## 🔹 **STEP 1: Understanding Your Hardware**

### 🧩 Components Used:

* **Arduino** (any model with I2C will do)
* **PCA9685 PWM Driver** – this allows control of 16 PWM signals with I2C
* **Servo Motors:**

  * *SG90* (small)
  * *MG995* (medium)
  * *MG996R* (or clone – larger torque)
* **External Power Supply** (5V, up to 15A)
* Breadboard, wires, terminal blocks, multimeter (optional)

---

## 🔹 **STEP 2: Learn Your Servos’ Needs**

⚙️ All servo motors used in the video operate at:

* **Voltage**: 5V
* **PWM Frequency**: \~50Hz
* **Pulse Width**: \~500–2500 µs

🔍 **Important**: Even if servos use the same voltage/frequency, their *torque, speed*, and *precision* can vary.

---

## 🔹 **STEP 3: Estimate Current Consumption**

### 📏 Measurement Setup:

* Connect a servo to a **bench power supply**
* Observe current draw while it moves:

  * At **5V no load**: \~12mA idle, \~300mA when moving
  * At **6V no load**: \~400–460mA when moving

### 📐 Rough Estimate:

If each servo draws up to **600mA max**, then:

```
600mA × 16 servos = 9600mA = 9.6A
Add 20% buffer → 9.6A × 1.2 = ~11.5A
```

🔌 Use a **5V 15A** external power supply to be safe.

---

## 🔹 **STEP 4: Plan Your Power Connections**

### ⚡ Two Key Rules:

1. **Signal is controlled by Arduino** 🧠
2. **Power is supplied by external 5V source** 🔋

🔌 **Servo Motors get their power directly from external supply.**

* Do *not* use the V+ pins on PCA9685 (they’re left disconnected).
* The PCA9685 only sends **PWM signal** and shares **common ground**.

---

## 🔹 **STEP 5: Wiring Diagram (Simplified)**

### 🧷 Power Wiring:

* Connect **5V from power supply** to a **terminal block**
* From the terminal block, power all servo **VCC pins**
* Connect **Grounds together**: Arduino GND, servo GND, power supply GND, PCA9685 GND

### 🔄 Signal Wiring:

* Connect **SDA and SCL** from Arduino to PCA9685
* VCC (logic) → Arduino 5V
* Connect each servo's **signal wire** to one of the PCA9685 PWM outputs

---

## 🔹 **STEP 6: Additional Considerations**

* 🧰 Add **capacitors** at the power source to smooth voltage drops.
* 📏 Use **shorter, thicker wires** (correct gauge) to avoid overheating.
* 🧯 Avoid running more than **10A** through a single PCA9685 board.

---

## 🤯 INTERESTING FACTS

* The **PCA9685** is based on I2C communication, meaning you can daisy chain **multiple boards** — potentially control **hundreds of servos**!
* Some large servos like **MG996R** can draw *over 2A* under high load.
* **Capacitors** act like shock absorbers in electronics — they help stabilize the voltage when servos suddenly move.

---

# 🔍 FOLLOW-UP MENU – WHERE TO EXPLORE NEXT

**A. PCA9685 Basics** – How it works, addressing multiple boards, PWM limits
**B. Servo Motor Types** – Compare SG90, MG995, and MG996R: torque, weight, cost
**C. Power Supply Safety** – Choosing the right voltage, current, and fuse protection
**D. Capacitors 101** – Why they matter and how to size them
**E. Arduino Code** – How to code for the PCA9685 to control servos in sequence

---

Let me know which follow-up you'd like to explore — or if you want a wiring diagram visual!

