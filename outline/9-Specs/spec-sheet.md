
# 🤖 Robot Arm + Conveyor Belt System – Hardware Specification

## 🧠 Controller

- **Microcontroller**: Seeed Studio XIAO ESP32-S3 Sense
- **Camera**: Arducam 64MP AutoFocus (ESP32-compatible)
- **Operating Voltage**: 3.3V logic
- **Communication**: Serial over USB or UART
- **Used Interfaces**:
  - I2C (PCA9685)
  - Digital IO (Stepper via ULN2003)
  - Camera pins (predefined by XIAO S3 Sense)

---

## 🤖 Robot Arm

### 📐 Arm Type
- 5 Degrees of Freedom: **Base**, **Shoulder**, **Elbow**, **Wrist**, **Gripper**
- Lightweight, classroom-grade construction

### 🔩 Servo Motors

| **Component** | **Servo Type**     | **PWM Channel** | **Expected Range** |
|---------------|--------------------|------------------|---------------------|
| Base          | SG92R (9G 360° CR) | PCA9685 CH0      | 90° to 175°         |
| Shoulder      | SG92R (9G 360° CR) | PCA9685 CH1      | 20° to 90°          |
| Elbow         | SG92R (9G 360° CR) | PCA9685 CH2      | 50° to 80°          |
| Wrist         | SG92R (9G 360° CR) | PCA9685 CH3      | Optional            |
| Gripper       | SG92R (9G 360° CR) | PCA9685 CH4      | Open: 0°, Close: 30° |

> ⚠️ Note: Despite “360°” label, servos behave closer to ~270° under PWM control.

### 🧠 Servo Control

- **Controller**: PCA9685 16-Channel PWM Servo Driver
- **Interface**: I2C (`SDA`: GPIO21, `SCL`: GPIO22)
- **I2C Address**: `0x40` (default)
- **PWM Frequency**: 50Hz
- **Power Input**:
  - `V+`: 5V (servo motor power)
  - `VCC`: 3.3V (logic from ESP32)
  - `GND`: shared with all components

---

## 📸 Camera System

- **Model**: Arducam 64MP AutoFocus (connected to ESP32-S3)
- **Mounting**: Suggested L-bracket viewing the gripper from above/side
- **Purpose**: Captures object images for classification
- **Output**: Sends label string (`CLASS_1` to `CLASS_6`) via Serial to main loop

---

## 🚚 Conveyor Belt System

### ⚙️ Motor

- **Type**: 28BYJ-48 Stepper Motor (5V, 4-phase)
- **Gear Reduction**: ≈ 64:1 (~2048 steps per full rotation)

### 🔌 Stepper Driver

- **Module**: ULN2003A 4-phase stepper driver
- **Control Pins** (ESP32 GPIOs):

| **ULN2003 Pin** | **ESP32 Pin** |
|-----------------|---------------|
| IN1             | GPIO16        |
| IN2             | GPIO17        |
| IN3             | GPIO18        |
| IN4             | GPIO19        |

- **Power Input**: 5V from same wall supply as servos

### 🧱 Mounting

- Free-standing or optionally screwed to same base as arm
- Conveyor should be **within reach radius** of robot arm
- Arm picks object from conveyor, classifies, and places to appropriate location

---

## 🔌 Power Supply

- **Type**: Wall adapter 5V 3A (15W)
- **Connector**: Barrel Jack (5.5mm outer, 2.1–2.5mm inner)
- **Distribution**:
  - **5V rail** powers:
    - PCA9685 V+ (servos)
    - ULN2003 (stepper)
  - **3.3V rail** comes from ESP32 for logic
  - **GND** shared across all components

> 💡 Recommendation: Add 470–1000µF capacitor across V+ and GND near PCA9685.

---

## 🧰 GPIO Overview

| **Function**       | **Pin(s)**     | **Details**                  |
|--------------------|----------------|------------------------------|
| PCA9685 SDA/SCL    | GPIO21 / GPIO22| I2C control for servos       |
| Stepper IN1–IN4    | GPIO16–GPIO19  | Controls conveyor movement   |
| Camera interface   | Fixed          | Onboard on XIAO S3 Sense     |
| Serial output      | USB or UART TX | For class label transmission |

---

## 🧪 Development Notes

- All components currently tested via **breadboard setup**
- You may want to design a **PCB or power rail breakout** to improve reliability
- System is intended for **low-torque, low-load educational demos**

---

```

Would you like this spec exported as a `.pdf` or `.md` file for download?


```

Would you like this spec exported as a `.pdf` or `.md` file for download?
