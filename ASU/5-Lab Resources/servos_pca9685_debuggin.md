# Debugging the PCA9685 C16 channel connection

It’s almost certainly just a power-rail mix-up if it not working:

| PCA9685 pin | What it powers                          | Must be tied to…                                                                   | Typical voltage |
| ----------- | --------------------------------------- | ---------------------------------------------------------------------------------- | --------------- |
| **VCC**     | The logic IC + on-board “PWR” LED       | **3 V 3** pin on your ESP32-S3                                                     | 3.0 – 3.6 V     |
| **GND**     | Logic reference **and** servo reference | Any ESP32 **GND** pin **and** the servo-supply ground                              | 0 V             |
| **V+**      | Only the high-current servo outputs     | A separate 5 – 6 V supply (or the ESP’s 5 V pin if your servos are < 500 mA total) | 5 V (typ.)      |

### Why the board’s LED stays dark

The on-board LED (if your breakout has one) is wired between **VCC** and **GND**.
Feeding only **V+ → 5 V** will not light it, because V+ is isolated from the logic rail. Until the chip’s VCC pin sees 3 V 3, the PCA9685 is completely “dead” on I²C.

### Quick fix wiring checklist

1. **Logic power**

   * VCC → ESP32 **3V3**
   * GND → ESP32 **GND**

2. **I²C lines**

   * SDA → GPIO 8
   * SCL → GPIO 9

3. **Servo power (optional now, essential later)**

   * V+ → 5 V **supply** (or ESP32 5 V pin if current is low)
   * Servo-PSU GND → same common ground as step 1

4. **Re-run your sketch** → the Serial monitor should now report “✓ PCA9685 detected …”.

### About the screw-terminal / barrel-jack pads

* Those big solder pads or green screw terminals on many PCA9685 boards are **paralleled** to V+ and GND.
* They exist purely to carry the servo current (amps, not milliamps).
* Feel free to land your 5 V supply there for sturdier wiring, but it won’t light the LED unless VCC is also powered.

### If it’s still silent

| Symptom                              | Likely cause                                                      | What to try                                    |
| ------------------------------------ | ----------------------------------------------------------------- | ---------------------------------------------- |
| LED still off                        | VCC line not actually connected (cold solder joint, wrong header) | Continuity-check between ESP32 3V3 and VCC pad |
| LED on, but I²C scanner sees nothing | SDA/SCL swapped, pullups missing/disabled, wrong address jumpers  | Verify wiring & look for `0x40` address        |
| Random resets when servos move       | 5 V rail sagging or GND not common                                | Use a beefier 5 V supply and join grounds      |

Once VCC is correctly tied to 3 V 3, the board should wake up instantly and your **CHECK\_CONNECTION** state will print a clean success message.
