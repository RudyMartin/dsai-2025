/**********************************************************************
 * File       : 6.1-AudioConnDebugFSM.ino
 * Title      : FSM – MAX98357 Connection Debug Beeper  (Lab 6)
 * Author     : Rudy Martin / Next Shift Consulting
 * Description: Plays a 1 kHz beep 10× to verify wiring, then idles
 **********************************************************************/

#include "driver/i2s.h"

// ─── Pin map (XIAO ESP32-S3) ─────────────────────────────────────────
constexpr int I2S_BCLK = 36;   // Bit-clock
constexpr int I2S_LRC  = 35;   // Word-select / LR-clock
constexpr int I2S_DOUT = 34;   // Data-out

// ─── Audio test tone (8-bit unsigned, 8 kHz, 1 kHz square) ───────────
const uint8_t testTone[8] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF};

// ─── FSM states ──────────────────────────────────────────────────────
enum State { INIT, BEEP, GAP, FINISH, IDLE };
State currentState = INIT;

uint8_t  beepsRemaining = 10;
unsigned long stateStart = 0;
const unsigned long BEEP_MS = 250;
const unsigned long GAP_MS  = 250;

void playBuffer(const uint8_t* buf, size_t len) {
  i2s_write(I2S_NUM_0, buf, len, nullptr, portMAX_DELAY);
}

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
    .bck_io_num = I2S_BCLK,
    .ws_io_num  = I2S_LRC,
    .data_out_num = I2S_DOUT,
    .data_in_num  = I2S_PIN_NO_CHANGE
  };
  i2s_driver_install(I2S_NUM_0, &cfg, 0, nullptr);
  i2s_set_pin(I2S_NUM_0, &pins);
}

void setup() {
  Serial.begin(115200);
  setupI2S();
  Serial.println("=== AudioConnDebugFSM (Lab 6) started ===");
}

void loop() {
  switch (currentState) {

  case INIT:
    stateStart = millis();
    currentState = BEEP;
    Serial.println("> Starting beep sequence");
    break;

  case BEEP:
    playBuffer(testTone, sizeof(testTone));
    if (millis() - stateStart >= BEEP_MS) {
      stateStart = millis();
      currentState = GAP;
    }
    break;

  case GAP:
    if (millis() - stateStart >= GAP_MS) {
      if (--beepsRemaining == 0) {
        currentState = FINISH;
      } else {
        stateStart = millis();
        currentState = BEEP;
      }
    }
    break;

  case FINISH:
    Serial.println("✓ Debug beeps done – entering IDLE");
    i2s_zero_dma_buffer(I2S_NUM_0);
    currentState = IDLE;
    break;

  case IDLE:
    // nothing
    break;
  }
}
