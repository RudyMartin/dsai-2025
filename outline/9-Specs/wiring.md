

## 1️⃣ Wiring Diagram: ESP32 + PCA9685 + ULN2003 + 5V Power Supply

### 🧰 Components

* **Microcontroller**: Seeed Studio XIAO ESP32-S3 Sense
* **Servo Driver**: PCA9685 16-Channel PWM Servo Driver
* **Servos**: 5x SG92R 9G Continuous Rotation Servos
* **Stepper Motor**: 28BYJ-48 Stepper Motor
* **Stepper Driver**: ULN2003 Driver Board
* **Power Supply**: 5V 3A Wall Adapter (Barrel Jack: 5.5mm x 2.1mm/2.5mm)([Kev's Robots][1], [Adafruit Learning System][2], [Tutorials for Newbies][3], [Adafruit Learning System][4])

### 🔌 Wiring Connections

#### **ESP32 to PCA9685 (I2C Communication)**

* **ESP32 GPIO21 (SDA)** → PCA9685 SDA
* **ESP32 GPIO22 (SCL)** → PCA9685 SCL
* **ESP32 3.3V** → PCA9685 VCC
* **ESP32 GND** → PCA9685 GND([ESP Boards][5])

#### **PCA9685 Power Connections**

* **PCA9685 V+** → 5V from Power Supply
* **PCA9685 GND** → GND from Power Supply([Cirkit Designer][6], [Adafruit Learning System][7])

*Note*: V+ powers the servos; ensure it's connected to the 5V supply.

#### **Servos to PCA9685**

* **Servo Signal Wires** → PCA9685 Channels 0–4
* **Servo Power Wires** → PCA9685 V+
* **Servo Ground Wires** → PCA9685 GND([Tutorials for Newbies][8], [CSDN Blog][9])

#### **ESP32 to ULN2003 (Stepper Control)**

* **ESP32 GPIO16** → ULN2003 IN1
* **ESP32 GPIO17** → ULN2003 IN2
* **ESP32 GPIO18** → ULN2003 IN3
* **ESP32 GPIO19** → ULN2003 IN4([Makerguides.com][10])

#### **ULN2003 Power Connections**

* **ULN2003 VCC** → 5V from Power Supply
* **ULN2003 GND** → GND from Power Supply([espblockly.com][11], [Random Nerd Tutorials][12])

#### **Stepper Motor to ULN2003**

* **Stepper Motor Connector** → ULN2003 Motor Output Pins([espblockly.com][11])

#### **Power Supply Distribution**

* **5V Output** → PCA9685 V+, ULN2003 VCC
* **GND Output** → PCA9685 GND, ULN2003 GND, ESP32 GND

*Ensure all grounds are connected together to maintain a common reference.*

---

## 2️⃣ Camera Code: ESP32-S3 Sense Sending Classification Labels via Serial

The Seeed Studio XIAO ESP32-S3 Sense comes equipped with an onboard camera. Assuming you have a trained image classification model (e.g., via TensorFlow Lite), the following code captures an image, processes it, and sends the classification result over Serial to the main ESP32 controller:

### 📄 Sample Code

```cpp
#include <Arduino.h>
// Include necessary libraries for camera and ML model
// #include <esp_camera.h>
// #include <TensorFlowLite.h>
// Add other required includes and model files

void setup() {
  Serial.begin(115200);
  // Initialize camera
  // camera_config_t config = { ... };
  // esp_camera_init(&config);
  // Load ML model
  // Initialize TensorFlow Lite model
}

void loop() {
  // Capture image
  // camera_fb_t *fb = esp_camera_fb_get();
  // if (!fb) {
  //   Serial.println("Camera capture failed");
  //   return;
  // }

  // Preprocess image and run inference
  // float* input = preprocess(fb);
  // int class_id = run_inference(input);
  // String class_label = get_class_label(class_id);

  // For demonstration, we'll use a placeholder
  String class_label = "CLASS_1"; // Replace with actual classification result

  // Send classification result over Serial
  Serial.println(class_label);

  // Release the frame buffer
  // esp_camera_fb_return(fb);

  delay(2000); // Wait before next capture
}
```

*Note*: The above code is a template. You'll need to integrate your specific camera initialization and machine learning model inference code.

---

If you need further assistance with integrating your specific ML model or setting up the camera configuration, feel free to ask!

[1]: https://www.kevsrobots.com/learn/pca9685/04_introduction_to_pca9685.html?utm_source=chatgpt.com "PCA9685 Servo Driver"
[2]: https://learn.adafruit.com/micropython-hardware-pca9685-pwm-and-servo-driver/tdicola-hardware?utm_source=chatgpt.com "Hardware | CircuitPython Hardware: PCA9685 PWM & Servo Driver | Adafruit Learning System"
[3]: https://newbiely.com/tutorials/arduino-nano-esp32/arduino-nano-esp32-28byj-48-stepper-motor-uln2003-driver?utm_source=chatgpt.com "Arduino Nano ESP32 - 28BYJ-48 Stepper Motor ULN2003 Driver"
[4]: https://cdn-learn.adafruit.com/downloads/pdf/16-channel-pwm-servo-driver.pdf?utm_source=chatgpt.com "[PDF] Adafruit PCA9685 16-Channel Servo Driver"
[5]: https://www.espboards.dev/sensors/pca9685/?utm_source=chatgpt.com "ESP32 PCA9685 16-Channel 12-bit PWM/Servo Driver - ESPBoards"
[6]: https://docs.cirkitdesigner.com/project/published/755a5fbb-8c9b-40ca-870d-5b666be9dd69/esp32-controlled-stepper-and-servo-motor-system-with-pca9685-pwm-and-esp32-cam?utm_source=chatgpt.com "ESP32-Controlled Stepper and Servo Motor System with PCA9685 ..."
[7]: https://learn.adafruit.com/16-channel-pwm-servo-driver?view=all&utm_source=chatgpt.com "Adafruit PCA9685 16-Channel Servo Driver"
[8]: https://newbiely.com/tutorials/raspberry-pi/raspberry-pi-28byj-48-stepper-motor-uln2003-driver?utm_source=chatgpt.com "Raspberry Pi - 28BYJ-48 Stepper Motor ULN2003 Driver | Raspberry Pi Tutorial"
[9]: https://blog.csdn.net/qq_54861577/article/details/126273427?utm_source=chatgpt.com "ESP32（或ESP32CAM）使用PCA9685模块arduino，自定义I2C引脚_esp32 pca9685-CSDN博客"
[10]: https://www.makerguides.com/28byj-48-stepper-motor-arduino-tutorial/?utm_source=chatgpt.com "28BYJ-48 Stepper Motor with ULN2003 Driver and Arduino Tutorial"
[11]: https://espblockly.com/stepperMotor.html?utm_source=chatgpt.com "Stepper Motor - ESP32 Tutorial"
[12]: https://randomnerdtutorials.com/esp32-stepper-motor-28byj-48-uln2003/?utm_source=chatgpt.com "ESP32 Stepper Motor (28BYJ-48 and ULN2003 Driver)"
