/**********************************************************************
 * File       : 2.3-ServoDriveDebugFSM.ino          // easy to remember!
 * Title      : MCP/FSM – Servo Driver Test + Connection Check
 * Author     : Rudy Martin / Next Shift Consulting
 * Description: 1️⃣ Verifies the PCA9685 is present on I²C
 *              2️⃣ Sweeps a servo 20 times (up + down = 1 cycle)
 *              3️⃣ Prints status messages at every step
 **********************************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// ─── Board-specific I²C pins (Freenove ESP32-S3) ─────────────────────
constexpr uint8_t SDA_PIN = 8;
constexpr uint8_t SCL_PIN = 9;

// ─── Servo Driver Setup ──────────────────────────────────────────────
Adafruit_PWMServoDriver pwm(0x40);     // PCA9685 default address
constexpr uint8_t  SERVO_CH = 0;       // use channel 0
constexpr uint16_t MIN_US  = 500;      // 0 °
constexpr uint16_t MAX_US  = 2500;     // 180 °
constexpr uint16_t STEP_US = 10;       // micro-step size

// ─── FSM States ──────────────────────────────────────────────────────
enum State {
  CHECK_CONNECTION,
  SWEEP_UP,
  SWEEP_DOWN,
  IDLE
};
State currentState = CHECK_CONNECTION;

// ─── Timing & loop-limit helpers ─────────────────────────────────────
unsigned long lastStepTime = 0;
const unsigned long STEP_DELAY = 5;    // ms between micro-steps
const uint8_t  MAX_CYCLES  = 20;       // total up-and-down sweeps
uint8_t  cyclesRemaining   = MAX_CYCLES;
uint16_t pulse             = MIN_US;   // current servo pulse width

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.println("\n=== ServoDriveDebugFSM Initialised ===");
}

void loop() {
  switch (currentState) {
  /* ────────────────────────────────────────────────────────────── */
case CHECK_CONNECTION: {
    // MCP Step 1 (SENSE): probe the device
    Wire.beginTransmission(0x40);       // start TX (no return value)
    uint8_t err = Wire.endTransmission();  // 0 = success

    // MCP Step 2 (PLAN) & 4 (LOG): decide and report
    if (err == 0) {
      Serial.println("✓ PCA9685 detected at 0x40 – starting sweep test");
      pwm.begin();
      pwm.setPWMFreq(50);
      lastStepTime = millis();
      currentState = SWEEP_UP;
    } else {
      Serial.print("✗ PCA9685 NOT found (I²C error ");
      Serial.print(err);
      Serial.println(") – retrying in 1 s");
      delay(1000);
    }
    break;
  }

  /* ────────────────────────────────────────────────────────────── */
  case SWEEP_UP:
  case SWEEP_DOWN: {
      unsigned long now = millis();
      if (now - lastStepTime >= STEP_DELAY) {
        lastStepTime = now;

        // MCP Step 3 (ACT): move the servo one micro-step
        pwm.writeMicroseconds(SERVO_CH, pulse);

        // MCP Step 2 (PLAN): update pulse & check limits
        if (currentState == SWEEP_UP) {
          pulse += STEP_US;
          if (pulse >= MAX_US) {
            pulse = MAX_US;
            currentState = SWEEP_DOWN;
            Serial.println("> Reached MAX, sweeping down");
          }
        } else {                       // SWEEP_DOWN
          pulse -= STEP_US;
          if (pulse <= MIN_US) {
            pulse = MIN_US;
            cyclesRemaining--;
            Serial.print("> Cycle complete – remaining: ");
            Serial.println(cyclesRemaining);

            if (cyclesRemaining == 0) {
              currentState = IDLE;
              Serial.println("=== Test finished – entering IDLE ===");
            } else {
              currentState = SWEEP_UP;
            }
          }
        }
      }
      break;
    }

  /* ────────────────────────────────────────────────────────────── */
  case IDLE:
    // Do nothing – leave the servo at MIN_US
    break;
  }
}
