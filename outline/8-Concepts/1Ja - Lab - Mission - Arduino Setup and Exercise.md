
We're using the **Seeed Studio XIAO ESP32S3 Sense** with a built-in **OV2640 camera**, you can stream live video to your laptop via Wi-Fi using the Arduino IDE. 

Here's a step-by-step guide to get you started:

---

## ✅ Step 1: Install the ESP32 Board Package

1. **Open Arduino IDE**.
2. Navigate to **File > Preferences**.
3. In the **"Additional Board Manager URLs"** field, add:

   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

   
   ```
OR If  using  Seeedstudio boards:

   ```

  https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json

   
   ```
4. Go to **Tools > Board > Boards Manager**.
5. Search for **"esp32"** and install the latest version by **Espressif Systems**.

---

## ✅ Step 2: Select the Correct Board

1. Go to **Tools > Board**.
2. Select **"XIAO\_ESP32S3"** or **"ESP32S3 Dev Module"** if the former isn't available.

---

## ✅ Step 3: Configure Board Settings

Ensure the following settings under the **Tools** menu:

* **USB CDC On Boot**: Enabled
* **Upload Mode**: UART
* **PSRAM**: Enabled
* **Flash Size**: 8MB
* **Partition Scheme**: Default 8MB with spiffs

---

## ✅ Step 4: Load the Camera Web Server Example

1. Go to **File > Examples > ESP32 > Camera > CameraWebServer**.
2. If you don't see this example, ensure the ESP32 board package is correctly installed.

---

## ✅ Step 5: Modify the Example Code

1. **Select the Camera Model**:

   At the top of the sketch, locate the camera model definitions. Uncomment the line for **AI Thinker** and comment out the others:

   ```cpp
   #define CAMERA_MODEL_AI_THINKER
   // #define CAMERA_MODEL_WROVER_KIT
   // #define CAMERA_MODEL_ESP_EYE
   // #define CAMERA_MODEL_M5STACK_PSRAM
   // #define CAMERA_MODEL_M5STACK_WIDE
   // #define CAMERA_MODEL_M5STACK_ESP32CAM
   // #define CAMERA_MODEL_TTGO_T_JOURNAL
   ```

   > **Note**: The XIAO ESP32S3 Sense uses the same pin configuration as the AI Thinker model.

2. **Set Wi-Fi Credentials**:

   Replace the placeholders with your Wi-Fi SSID and password:

   ```cpp
   const char* ssid = "YOUR_SSID";
   const char* password = "YOUR_PASSWORD";
   ```

---

## ✅ Step 6: Upload the Sketch

1. Connect your XIAO ESP32S3 Sense to your computer via USB.
2. Select the appropriate **Port** under **Tools > Port**.
3. Click the **Upload** button.

---

## ✅ Step 7: Access the Camera Stream

1. Open the **Serial Monitor** at a baud rate of **115200**.

2. After the board connects to Wi-Fi, it will display an IP address, e.g.:

   ```
   Camera Ready! Use 'http://192.168.1.100' to connect
   ```

3. Open your web browser and navigate to the displayed IP address to view the live camera stream.

---

## 🛠 Troubleshooting Tips

* **No IP Address Displayed**: Ensure your Wi-Fi credentials are correct and the board is within range.
* **Serial Monitor Shows Gibberish**: Confirm the baud rate is set to **115200**.
* **Camera Not Detected**: Double-check the camera module is securely connected.

---

For more detailed information and advanced configurations, refer to Seeed Studio's official documentation: ([Seeed Studio][1]).

Feel free to ask if you need assistance with additional features like saving images to an SD card or integrating with cloud services!

[1]: https://wiki.seeedstudio.com/xiao_esp32s3_camera_usage/?utm_source=chatgpt.com "Camera Usage in Seeed Studio XIAO ESP32S3 Sense"
