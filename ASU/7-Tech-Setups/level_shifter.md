### When—and when *not*—to drop a 3.3 V ↔ 5 V I²C level shifter into our labs

| Camp module                                                              | I²C parts in play                                | Typical V<sub>DD</sub> & logic                         | Do we **need** a level shifter?                                  | Why / why not                                                                                                   |
| ------------------------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------------ | ---------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- |
| **Lab 1 – Practical Python + Chatbot (no hardware)**                     | None                                             | —                                                      | —                                                                | Pure software; nothing on the wire.                                                                             |
| **Lab 2 – Block-Classification FSM**<br>(ESP32-S3 WROOM CAM)             | OV5640 camera (DVP, not I²C)                     | 3.3 V                                                  | **No**                                                           | Camera and ESP32 share the same 3.3 V rail.                                                                     |
| **Lab 3 – Sensor-Logging FSM**<br>(ESP32-S3 + SHT30, light sensors)      | SHT30, BH1750, etc.                              | 3.3 V                                                  | **No**                                                           | All chosen sensors are 3.3 V tolerant; ESP32 drives them directly.                                              |
| **Lab 4 – Contextual-Decision FSM**<br>(ESP32-S3 + PCA9685 servo driver) | PCA9685 (I²C)                                    | Logic 3.3 V **if** you tie its V<sub>DD</sub> to 3.3 V | **Usually no**                                                   | Our wiring guides power PCA9685 V<sub>DD</sub> from the ESP32’s 3.3 V pin, so its SDA/SCL already sit at 3.3 V. |
| **Lab 5 – Mission-Deck FSM**<br>(ESP32-S3 + HUB75 LED matrix)            | None on I²C; HUB75 is TTL-parallel               | 5 V data lines                                         | **Use the 8-bit TXS0108E level shifter you already ordered**     | That board handles *parallel* level conversion; the small bi-directional I²C shifter isn’t used here.           |
| **Capstone – Advanced logging / dashboard add-ons**<br>(Raspberry Pi 5)  | 20×4 LCD backpack, legacy 5 V sensors, RTC, etc. | 5 V logic                                              | **Yes** → this is the *sweet spot* for the I²C logic-level board | The Pi speaks 3.3 V; any add-on that insists on 5 V pull-ups must be isolated via a bi-directional shifter.     |

---

#### Quick decision checklist for mentors & students

1. **What is the peripheral’s logic voltage?**
   *If it’s 3.3 V*, you can wire it straight in.
   *If it’s 5 V only (or you must power it at 5 V for other reasons)*, move to step 2.

2. **Does the datasheet say its SDA/SCL are 3.3 V-tolerant?**
   *Yes* → skip the shifter.
   *No / unknown* → **insert the I²C level shifter** between board and micro.

3. **Mixed-rail bus?** If even one device is strictly 5 V while the MCU is 3.3 V, the whole bus must live at 3.3 V. A bi-directional shifter lets each side keep its own pull-ups, so both domains stay happy.

---

#### Where the part adds value in our program

* **Capstone extensions** (e.g., Pi-based dashboards, fancy I²C sensor hats)
  Students will likely bolt on 5 V modules picked up in the “build-your-own” phase; the shifter prevents accidental Pi GPIO damage and is a teachable moment about voltage domains.

* **Spare kit flexibility**
  Having a couple of pre-soldered shifters in the tool bin means you can safely swap in last-minute parts from the makerspace without re-speccing the whole power tree.

* **Teaching aid**
  Demonstrating a logic analyzer trace with and without proper level conversion is a great five-minute show-and-tell on electrical robustness.

---

### TL;DR

* **Most ESP32-based labs (2 – 4)**: everything already runs at 3.3 V, so the little I²C shifter stays in the parts drawer.
* **Raspberry Pi add-ons in the Capstone**: that’s exactly when you snap the module in—between the Pi’s 3.3 V SDA/SCL and any stubborn 5 V I²C device.
* **If you aren’t sure**: check the peripheral’s datasheet; if the logic-high threshold is > 3.3 V, use the shifter. Better safe than smoked-GPIO!
