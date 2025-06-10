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
| USB-C cable, laptops with Arduino IDE | 1 per team | ESP32 board defs pre-installed                                 |

---

## 4. Teacher Prep (before class)

1. Copy the **three** sketch files into the starter repo:

   * `6.0-AudioPingFSM.ino` ← ultra-simple (**shown below**)
   * `6.1-AudioConnDebugFSM.ino` ← ten-beep tester
   * `6.2-LLMAudioCueFSM.ino` ← keyword sound player
2. Flash `6.0` to one demo board so you can play the first beep instantly.
3. Verify the WAV clips (`ok.wav`, `warn.wav`, etc.) are in SPIFFS for the stretch demo.

---

## 5. Extra-Simple FSM Sketch

*(Copy into **6.0-AudioPingFSM.ino**)*

```cpp
/**********************************************************************
 * File       : 6.0-AudioPingFSM.ino
 * Title      : FSM – Super-Simple Speaker Ping (Lab 6)
 * Author     : Your Name / Class Demo
 * Description: 1) Checks if MAX98357 responds,
 *              2) Plays a short beep once a second (5×),
 *              3) Stops and prints "DONE".
 **********************************************************************/

#include "driver/i2s.h"

/* ---------- Pin Map (XIAO ESP32-S3 Sense) ---------- */
constexpr int I2S_BCLK = 36;   // Bit-clock (BCLK)
constexpr int I2S_LRC  = 35;   // Word-select (LRC)
constexpr int I2S_DOUT = 34;   // Data-out (DIN)

/* ---------- Tiny 1 kHz Square-Wave Sample (8 kHz) --- */
const uint8_t PING[8] = {0x00, 0xFF, 0x00, 0xFF,
                         0x00, 0xFF, 0x00, 0xFF};

/* ---------- FSM States ----------------------------- */
enum State { CHECK, BEEP, WAIT, DONE };
State state = CHECK;

unsigned long lastTime = 0;
uint8_t pingsLeft = 5;           // play 5 beeps

/* ---------- Helper: send one sample buffer --------- */
void playPing() {
  i2s_write(I2S_NUM_0, PING, sizeof(PING), nullptr, portMAX_DELAY);
}

/* ---------- I²S Setup ------------------------------ */
void setupI2S() {
  i2s_config_t cfg = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 8000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_8BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = 0,
    .dma_buf_count = 4,
    .dma_buf_len = 64,
    .use_apll = false
  };
  i2s_pin_config_t pins = {
    .bck_io_num   = I2S_BCLK,
    .ws_io_num    = I2S_LRC,
    .data_out_num = I2S_DOUT,
    .data_in_num  = I2S_PIN_NO_CHANGE
  };
  i2s_driver_install(I2S_NUM_0, &cfg, 0, nullptr);
  i2s_set_pin(I2S_NUM_0, &pins);
}

void setup() {
  Serial.begin(115200);
  setupI2S();
  Serial.println("6.0-AudioPingFSM ready");
}

void loop() {
  switch (state) {

  /* 1️⃣  SENSE & PLAN — quick “connection” test */
  case CHECK: {
      // Simply send one ping; if wiring is bad we’ll hear nothing
      playPing();
      Serial.println("> Ping test sent");
      lastTime = millis();
      state = WAIT;
      break;
    }

  /* 2️⃣  ACT — beep once a second, five times */
  case BEEP:
    playPing();
    lastTime = millis();
    state = WAIT;
    break;

  /* 3️⃣  LOG & delay between beeps (non-blocking) */
  case WAIT:
    if (millis() - lastTime >= 1000) {       // 1-second gap
      if (--pingsLeft == 0) {
        state = DONE;
        Serial.println("✓ DONE — speaker verified");
      } else {
        state = BEEP;                        // go beep again
      }
    }
    break;

  /* 4️⃣  REPEAT? No — we stay here */
  case DONE:
    // Nothing more to do
    break;
  }
}
```

### Why this sketch is “student-friendly”

* **Only three real states** to reason about.
* **Short buffer** avoids explaining WAV parsing.
* Uses the exact same I²S pins they’ll keep in later labs.
* Finishes automatically so the Serial window stops scrolling.

---

## 6. Tips for a Smooth 60 min Session

1. **Colour-code wires** in advance (red = VIN, black = GND, etc.).
2. Keep **spare pre-wired amps** on hand—hardware faults waste time.
3. Encourage **pair programming**: one student reads steps aloud, the other types.
4. The moment **one pair hears a beep**, let them cheer—peer motivation works.
5. End with “**What part was confusing?**” to gather feedback for next time.

---

### Next Steps

Students who finish early flash **6.1** (ten-beep tester) or **6.2** (keyword WAV player), giving natural differentiation without extra prep.

Happy teaching, and enjoy the first *talking* gadget of your camp! 🎙️🛰️
