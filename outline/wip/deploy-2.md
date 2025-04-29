

## ✅ **Raspberry Pi 5 — microSD Model Loading**
**Fully supported.**  
In fact, **most Pi 5s boot from microSD**, so:

- You can **partition the card** and store models in a known folder (e.g., `/home/pi/models/`)
- Or use a **secondary microSD card via USB reader** if boot is from NVMe

### Example:
```python
import tensorflow as tf
interpreter = tf.lite.Interpreter(model_path="/home/pi/models/my_model.tflite")
interpreter.allocate_tensors()
```

✔️ Supports both TFLite and ONNX  
✔️ Easy model swapping, offline  
✔️ Great for **students to manually update models**

---

## ⚠️ **ESP32-S3 — microSD Card (via SPI or SDMMC)**
**Yes, with caveats.**  
Most ESP32-S3 dev boards **do not include** a microSD slot by default, but:

- You can connect one via **SPI or SDMMC** bus
- Use **Arduino SD library** or ESP-IDF's FATFS support to:
  - Mount card
  - Load `.tflite` file into memory

### Example (Arduino pseudo-code):
```cpp
#include <SD.h>
File modelFile = SD.open("/model.tflite");
modelFile.readBytes((char*)modelData, modelFile.size());
// Load into TensorFlow Lite Micro runtime
```

### ⚠️ Constraints:
- Total model size must fit in RAM or Flash (ideally < 250KB)
- Model must be read **in full** and **stored in memory buffer**
- Performance is slower than flash-based deployment

---

## Summary Table: microSD for Model Deployment

| Device        | microSD Support | Notes |
|---------------|------------------|-------|
| Raspberry Pi 5 | ✅ Native        | Use for model storage, hot-swapping, offline updates |
| ESP32-S3       | ⚠️ With Adapter  | Must use SPI-based microSD reader and FAT filesystem |

---

### 🔧 Recommended Setup for Camp:
| Team        | microSD Use Case |
|-------------|------------------|
| **Nova Alpha / Vega Alpha / Vega Beta** (ESP32-S3) | Pre-load model on SD card using USB adapter → inserted into ESP32 breakout board with SD slot |
| **Nova Beta / Orion Alpha / Orion Beta** (Raspberry Pi 5) | Copy TFLite/ONNX models to `/models/` folder on microSD → load on boot |

---

Would you like a sample circuit diagram or SD wiring pinout for ESP32-S3 with microSD?
