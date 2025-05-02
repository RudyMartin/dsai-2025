**64×64 HUB75 RGB LED matrix Assembly Guide** 

This assumes a **ESP32** using Adafruit parts.


## 🧩 PARTS LIST (FOR ONE PANEL)

| Qty        | Item                                                                | Adafruit PID              |
| ---------- | ------------------------------------------------------------------- | ------------------------- |
| 1️⃣        | 64×64 RGB LED Matrix Panel (HUB75 interface)                        | Varies¹                   |
| 1️⃣        | ESP32 Dev Board (ESP32-S3 recommended – e.g., ESP32-S3 Feather)     | 5395 (S3 Feather)         |
| 1️⃣        | **5V 4A Power Adapter** (barrel plug, 2.1mm center positive)        | **1466**                  |
| 1️⃣        | **DC Jack to Screw Terminal Adapter**                               | **368**                   |
| 1️⃣        | **Power Cable (JST-VH 4-pin to tinned leads)** for LED panel        | **3975**                  |
| 1️⃣        | **GPIO Ribbon Cable 2×8 IDC (16-pin)** for HUB75 connection         | **4170**                  |
| 🧵         | Jumper wires (female-to-female or female-to-male)                   | 1956 (pack of 40)         |
| 🪛         | Small screwdriver (for terminal screws)                             | Any small flat-head       |
| (Optional) | **Level Shifter (e.g., 74AHCT125 or 74HC245)** for 3.3V to 5V logic | 1787 (Quad level shifter) |

---

### 📝 Notes:

* ¹ The matrix panel itself depends on what resolution and scan rate you want. Common choices:

  * 64×64 2.5mm pitch: [Adafruit PID 2277](https://www.adafruit.com/product/2277) (currently out of stock often)
  * 64×64 3mm or 4mm pitch available on SparkFun, AliExpress, Amazon, etc.
* The **ESP32** could be:

  * [ESP32-S3 Feather (PID 5395)](https://www.adafruit.com/product/5395)
  * Or use other dev boards if you adapt the GPIOs in code

Would you like a matching wiring diagram with all these PID-labeled components?


---

## 🛠️ STEP-BY-STEP ASSEMBLY

---

### **🔋 POWER CONNECTION – PANEL SIDE**

1. **Insert 4-pin power cable**
   ➤ Plug the **JST-VH (white plug)** into the power port on the LED panel
   *(It only fits one way.)*

2. **Wire power leads to terminal block**
   ➤ Take the **2 red wires** from the pigtail → insert into **“+”** terminal
   ➤ Take the **2 black wires** → insert into **“–”** terminal
   ➤ Tighten screws firmly.

3. **Connect to power supply**
   ➤ Plug **barrel jack of the 5V 4A power adapter** into the DC screw terminal
   ➤ Plug the adapter into the wall **(do this last)**

---

### **📊 DATA CONNECTION – PANEL TO ESP32**

4. **Attach 2x8 ribbon cable**
   ➤ Plug one end into the **HUB75 data connector** on the matrix (usually labeled “IN” or “Input”)
   ➤ Leave the other end to wire to the ESP32

5. **Wire the ribbon to ESP32 GPIOs**
   Here’s a **common wiring table**:

| HUB75 Pin | Ribbon Color | ESP32 GPIO | Function      |
| --------- | ------------ | ---------- | ------------- |
| R1        | Red          | GPIO 25    | Red (upper)   |
| G1        | Green        | GPIO 26    | Green (upper) |
| B1        | Blue         | GPIO 27    | Blue (upper)  |
| R2        | ...          | GPIO 14    | Red (lower)   |
| G2        | ...          | GPIO 12    | Green (lower) |
| B2        | ...          | GPIO 13    | Blue (lower)  |
| A         | ...          | GPIO 15    | Row select    |
| B         | ...          | GPIO 2     | Row select    |
| C         | ...          | GPIO 4     | Row select    |
| D         | ...          | GPIO 5     | Row select    |
| LAT       | ...          | GPIO 32    | Latch         |
| OE        | ...          | GPIO 16    | Output Enable |
| CLK       | ...          | GPIO 33    | Clock         |
| GND       | Black        | GND        | Shared Ground |

> ✳️ **Important:** Only use the panel’s **GND wire** to connect to ESP32 **GND** for logic stability.

---

### **💻 POWER UP + TEST**

6. **Power on sequence**
   ➤ Plug in **ESP32 to USB first**
   ➤ THEN plug in the **5V adapter to wall power**
   *(This avoids brownout or boot errors.)*

7. **Upload demo code**
   ➤ Use Arduino with `ESP32-HUB75-MatrixPanel-DMA` library
   ➤ Try an example sketch like `PatternPlasma` or `ScrollingText`

---

## ✅ You’re Done!

You now have:

* Clean power delivery (no smoke 💨)
* Ribbon-wired GPIO control
* Shared ground for logic signals
* Flicker-free panel once your code is running

---

## 🧠 Final Notes

* ✅ **Do not power ESP32 from this 5V source** — use USB for the ESP32 separately.
* ✅ **Make sure ESP32 GND is connected to matrix GND** to avoid logic signal errors.
* ✅ Only turn on the panel power once everything is wired.

---

