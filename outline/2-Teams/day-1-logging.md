
## 📋 Option A: **Serial Logging (Basic + Reliable)**
Logs are printed over USB serial (can be copied from the console in Thonny or Arduino IDE).

```python
from time import time
import machine

def log_camera_event(team, filename, duration=None, status="success", notes=""):
    timestamp = time()
    log_entry = f"{team},{timestamp},baseline_test,{filename},{duration},{status},{notes}"
    print(log_entry)  # Output over serial

# Example use
log_camera_event("Nova Alpha", "alpha_test_01.jpg", 6, "success", "Camera test successful")
```

💡 Use `print()` output in Thonny or PuTTY to **copy logs into CSV manually later**.

---

## 📦 Option B: **microSD Card Logging**
Requires a microSD card breakout wired to the ESP32 (via SPI).

### ✅ Circuit Notes
- CS = Pin 5  
- MOSI = 23  
- MISO = 19  
- SCK = 18

---

### 🐍 Code (MicroPython SD Log)

```python
import os
import machine
import sdcard
import uos
from time import time

# Setup SPI for SD
spi = machine.SPI(1, sck=machine.Pin(18), mosi=machine.Pin(23), miso=machine.Pin(19))
cs = machine.Pin(5, machine.Pin.OUT)
sd = sdcard.SDCard(spi, cs)
uos.mount(sd, "/sd")

# Logging function
def log_to_sd(team, filename, duration=None, status="success", notes=""):
    timestamp = time()
    log_line = f"{team},{timestamp},baseline_test,{filename},{duration},{status},{notes}\n"
    with open("/sd/video_log.csv", "a") as f:
        f.write(log_line)
    print("✅ Log written to /sd/video_log.csv")

# Example use
log_to_sd("Nova Beta", "beta_test_01.jpg", "", "success", "Snapshot saved")
```

📁 After logging, just pop the SD card and read `video_log.csv` on your computer.

Here's a circuit diagram for the ESP32-S3 wiring?

[![ESP32: Guide for MicroSD Card Module Arduino | Random Nerd Tutorials](https://tse3.mm.bing.net/th/id/OIP.0EZA_6QvVJFNV2P395szGQHaH-?pid=Api)](https://randomnerdtutorials.com/esp32-microsd-card-arduino/)
e Pin | ESP32-S3 GPIO | Function       |
|--------------------|---------------|----------------|
| **CS**             | GPIO5         | Chip Select    |
| **MOSI**           | GPIO23        | SPI MOSI       |
| **MISO**           | GPIO19        | SPI MISO       |
| **SCK**            | GPIO18        | SPI Clock      |
| **VCC**            | 3.3V          | Power Supply   |
| **GND**            | GND           | Ground         |
