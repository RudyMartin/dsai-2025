### 🛰️ Lab 6 — “Make It Talk!”

*60-minute lesson plan + an extra-simple FSM sketch*

---

## 1. Lesson-at-a-Glance

| Segment (min) | Activity                                                                                                | Why it matters                                                           |
| ------------- | ------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| **0 - 5**     | **Hook** – Play a demo clip (“HELLO, astronauts!”) through the speaker                                  | Grabs attention & shows the goal                                         |
| **5 - 10**    | **Objectives & Safety**                                                                                 | Students know what success looks like; remind them speakers can get loud |
| **10 - 20**   | **Hardware Walk-through** – identify MAX98357 pins, JST leads, ESP32-S3 I²S pins                        | Builds mental map; prevents wiring errors                                |
| **20 - 30**   | **Concept Mini-Lesson** – the 1-2-3-4-5 FSM loop (Sense → Plan → Act → Log → Repeat)                    | Re-uses the pattern they’ve seen since Lab 1                             |
| **30 - 40**   | **Hands-on Wiring** – students pair-check each other’s connections                                      | Peer QA reduces debug time                                               |
| **40 - 45**   | **Code Walk-through** – the *simple* FSM sketch below                                                   | Shows how only three states can still solve a problem                    |
| **45 - 55**   | **Upload & Test** – run the sketch; hear regular “ping” beeps                                           | Immediate win: proves power + I²S are good                               |
| **55 - 60**   | **Wrap-up & Stretch Goals** – point to the two advanced sketches (6.1 & 6.2) for those who finish early | Keeps fast learners busy, slower learners satisfied                      |

---

## 2. Learning Objectives (student-friendly)

1. **Wire** an I²S audio amplifier (MAX98357) to the XIAO ESP32-S3 Sense safely.
2. **Explain** each step of the 1-2-3-4-5 FSM loop in plain language.
3. **Upload & run** a simple FSM sketch that beeps if the amp is working.
4. *(Stretch)* Trigger different sound effects with typed commands.

---

## 3. Required Parts per Team

| Part                                  | Qty        | Notes                                                          |
| ------------------------------------- | ---------- | -------------------------------------------------------------- |
| XIAO ESP32-S3 Sense                   | 1          | Any ESP32-S3 works, but pin numbers match the Sense version    |
| MAX98357 breakout                     | 1          | Adafruit or clone                                              |
| DWEII mini speaker (3 W, 4 Ω)         | 1          | 40 mm **or** 80 mm version                                     |
| JST-pigtail wires                     | \~6        | Red = VIN, Black = GND, Blue = BCLK, Yellow = LRC, Green = DIN |
| Soldered headers / breadboard         | as needed  | Pre-solder before class to save time                           |
| USB-C cable, laptops with Arduino IDE | 1 per team | ESP32 board defs pre-installed      
