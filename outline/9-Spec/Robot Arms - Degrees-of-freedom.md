Here are structured tables for **4-DOF**, **5-DOF**, and **6-DOF** robotic arm configurations using SG92R servos with a PCA9685 controller. This layout will help you compare and choose between the designs for student builds or project complexity.

---

### 🤖 **4 Degrees of Freedom (4DOF)**

| **Component** | **Servo Type**     | **PWM Channel** | **Expected Range**   |
| ------------- | ------------------ | --------------- | -------------------- |
| Base          | SG92R (9G 360° CR) | PCA9685 CH0     | 90° to 175°          |
| Shoulder      | SG92R (9G 360° CR) | PCA9685 CH1     | 20° to 90°           |
| Elbow         | SG92R (9G 360° CR) | PCA9685 CH2     | 50° to 80°           |
| Gripper       | SG92R (9G 360° CR) | PCA9685 CH3     | Open: 0°, Close: 30° |

> ✅ Good for simple pick-and-place tasks.
> ❗ Wrist is fixed or passive in this setup.

---

### 🤖 **5 Degrees of Freedom (5DOF)**

(*Current System*)

| **Component** | **Servo Type**     | **PWM Channel** | **Expected Range**    |
| ------------- | ------------------ | --------------- | --------------------- |
| Base          | SG92R (9G 360° CR) | PCA9685 CH0     | 90° to 175°           |
| Shoulder      | SG92R (9G 360° CR) | PCA9685 CH1     | 20° to 90°            |
| Elbow         | SG92R (9G 360° CR) | PCA9685 CH2     | 50° to 80°            |
| Wrist         | SG92R (9G 360° CR) | PCA9685 CH3     | Optional – Basic tilt |
| Gripper       | SG92R (9G 360° CR) | PCA9685 CH4     | Open: 0°, Close: 30°  |

> 🧠 Balance of functionality and simplicity. Ideal for educational use.

---

### 🤖 **6 Degrees of Freedom (6DOF)**

| **Component** | **Servo Type**     | **PWM Channel** | **Expected Range**   |
| ------------- | ------------------ | --------------- | -------------------- |
| Base          | SG92R (9G 360° CR) | PCA9685 CH0     | 90° to 175°          |
| Shoulder      | SG92R (9G 360° CR) | PCA9685 CH1     | 20° to 90°           |
| Elbow         | SG92R (9G 360° CR) | PCA9685 CH2     | 50° to 80°           |
| Wrist Tilt    | SG92R (9G 360° CR) | PCA9685 CH3     | Optional             |
| Wrist Rotate  | SG92R (9G 360° CR) | PCA9685 CH4     | 0° to 180°           |
| Gripper       | SG92R (9G 360° CR) | PCA9685 CH5     | Open: 0°, Close: 30° |

> 🔁 Adds wrist rotation for advanced tasks like orientation adjustment.
> ❗ Slightly more challenging for students to calibrate.

---

### ⚠️ Notes for All Versions

* The SG92R is labeled as "360°", but **actual PWM-controlled movement is closer to \~270°**.
* All setups use the **PCA9685** with **50Hz PWM frequency**.
* Shared **5V power rail** for servos; **3.3V logic** for ESP32-S3.
* Always **center the servos** to \~90° (1500µs) before mechanical installation.


