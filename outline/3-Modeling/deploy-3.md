

# 📦 microSD Card with ESP32-S3
The **ESP32-S3** communicates with the **microSD card** over the **SPI bus**.

You need 4 main SPI connections:
- **MISO** – Master In Slave Out (data from SD card to ESP32)
- **MOSI** – Master Out Slave In (data from ESP32 to SD card)
- **SCK** – Serial Clock
- **CS** – Chip Select (sometimes called SS, Slave Select)

Plus **power** (3.3V or 5V depending on your SD card adapter) and **GND**.

---

# 🛠️ Basic Wiring Diagram

```plaintext
ESP32-S3         microSD Card Adapter
=========        ====================
3.3V             VCC
GND              GND
GPIO18           SCK (Clock)
GPIO19           MISO (Master In Slave Out)
GPIO23           MOSI (Master Out Slave In)
GPIO5            CS (Chip Select)
```

**(GPIO numbers can vary if you want — but these are common defaults.)**

---

# 🎯 Visual Diagram (Text Format)

```plaintext
    +-----------------+
    |    ESP32-S3      |
    |                 o| 3.3V -----> VCC (microSD)
    |                 o| GND ------> GND (microSD)
    |                 o| GPIO18 ---> SCK
    |                 o| GPIO19 ---> MISO
    |                 o| GPIO23 ---> MOSI
    |                 o| GPIO5  ---> CS
    +-----------------+

    +-----------------+
    | microSD Adapter  |
    +-----------------+
```

---

# ⚡ Important Notes:
- **Power**: Some SD adapters accept both 3.3V or 5V — but **ESP32 GPIOs are 3.3V** logic level!  
  ⚠️ **Warning**: Directly connecting 5V-only adapters could damage ESP32 if level shifting isn’t handled. Choose 3.3V-compatible modules!
- **Libraries**:  
  - Arduino IDE → `SD.h` and `SPI.h`
  - PlatformIO or ESP-IDF → use FATFS + SPI drivers
- **Mount SD before accessing files**:
  ```cpp
  if (!SD.begin(GPIO5)) {  // CS pin
      Serial.println("Card Mount Failed");
      return;
  }
  ```

---

# 🛠️ Example Hardware Needed
| Part | Notes |
|------|-------|
| ESP32-S3 dev board | With enough free GPIOs |
| microSD breakout board | SPI version, not SDIO direct |
| Jumper wires | Female-Female or Male-Female depending on your hardware |

---

# ✅ Summary Flow for Your Camp Students:

1. Save trained `.tflite` model to microSD card
2. Insert into microSD adapter wired to ESP32-S3
3. Mount SD card at boot
4. Read model file into memory
5. Run TensorFlow Lite Micro inference!

---

