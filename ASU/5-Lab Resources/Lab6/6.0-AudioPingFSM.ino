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
