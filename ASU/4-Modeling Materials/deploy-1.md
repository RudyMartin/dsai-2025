
### 🔧 Where the Models Come From (ESP32-S3 Edition)

For ESP32-S3 teams (Nova Alpha, Vega Alpha, Vega Beta):

#### ✅ **Model Source: Roboflow + Edge Training**
1. **Students collect image data** using phones or ESP32-CAM snapshots.
2. **Upload to Roboflow** for labeling and preprocessing (e.g., resizing to 96x96 or 128x128, grayscale or RGB).
3. **Train a lightweight model** in Roboflow or export to:
   - **TensorFlow Lite (TFLite) Micro** for classification
   - Quantized INT8 format to reduce memory footprint

#### ⚙️ **How the Model Is Deployed**:
- Compiled into firmware using **Arduino IDE** or **PlatformIO**
- Uses **TensorFlow Lite Micro runtime** (embedded C++) → runs on-device
- Model is <250KB ideally, fits in ESP32-S3 Flash
- Prediction loop triggered by image capture (camera or sensor snapshot)

---

### 🧠 For Raspberry Pi Teams (Nova Beta, Orion Alpha/Beta)

These have much more power:
- Use **TFLite** or **ONNX Runtime** on Pi 5
- Larger models allowed: up to 10–50MB typical
- Can even run **full object detection** (YOLOv5s/YOLOv8n or custom MobileNetSSD)
- Trained with Roboflow, exported, and deployed locally

---

### Summary by Team:
| Team        | Device      | Model Format        | Where Model Comes From                | Max Size      |
|-------------|-------------|---------------------|----------------------------------------|----------------|
| Nova Alpha  | ESP32-S3    | TFLite Micro (INT8) | Roboflow export → compiled into C array | <250KB       |
| Nova Beta   | Raspberry Pi 5 | TFLite or ONNX     | Roboflow-trained detection model        | <50MB         |
| Vega Alpha  | ESP32-S3    | TFLite Micro        | Binary classification from LED states  | <250KB        |
| Vega Beta   | ESP32-S3    | TFLite Micro        | Custom classifier for safety eval      | <250KB        |
| Orion Alpha | Raspberry Pi 5 | TFLite or ONNX     | Visual flag/alert classifier            | <50MB         |
| Orion Beta  | Raspberry Pi 5 | TFLite or ONNX     | Forecast state classifier               | <50MB         |

Would you like a slide or visual to explain this deployment pipeline to students or TAs?
