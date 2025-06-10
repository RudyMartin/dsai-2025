/**********************************************************************
 * File       : 6.3-RobotCueFSM.ino
 * Title      : FSM – Robot-Arm Demo Cues (Lab 6)
 * Author     : Your Name / Class Demo
 * Description: Listens for "WAVE", "POINT", "RESET" on Serial,
 *              then drives 3–4 servos via PCA9685 through tiny moves.
 **********************************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

/* ---------- I²C + PCA9685 ---------- */
constexpr uint8_t SDA_PIN = 8;
constexpr uint8_t SCL_PIN = 9;
Adafruit_PWMServoDriver pwm(0x40);

/* ---------- Servo helper ---------- */
uint16_t usToTicks(uint16_t us) {          // convert µs to PCA ticks (12-bit @ 50 Hz)
  return map(us, 0, 20000, 0, 4095);
}
void writeMicroseconds(uint8_t ch, uint16_t us) {
  pwm.setPWM(ch, 0, usToTicks(us));
}

/* ---------- Servo channel map ---------- */
constexpr uint8_t CH_BASE = 0;
constexpr uint8_t CH_SHO  = 1;
constexpr uint8_t CH_ELB  = 2;
constexpr uint8_t CH_WRI  = 3;

/* ---------- Pose definitions (µs) ---------- */
struct Pose { uint16_t base, sho, elb, wri; };

Pose REST  {1500, 1500, 1500, 1500};  // neutral
Pose POINT {1500, 1200, 1700, 1500};  // forward reach
Pose WAVE1 {1400, 1500, 1500, 1300};  // left tilt
Pose WAVE2 {1600, 1500, 1500, 1700};  // right tilt

/* ---------- FSM states ---------- */
enum State { WAIT_CMD, RUN_PATTERN, IDLE };
State state = WAIT_CMD;

String cmd;
uint8_t stepIdx = 0;
unsigned long lastStep = 0;

/* ---------- tiny pattern runner ---------- */
void setPose(const Pose& p) {
  writeMicroseconds(CH_BASE, p.base);
  writeMicroseconds(CH_SHO , p.sho );
  writeMicroseconds(CH_ELB , p.elb );
  writeMicroseconds(CH_WRI , p.wri );
}

/* ---------- setup ---------- */
void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  pwm.begin();
  pwm.setPWMFreq(50);
  setPose(REST);
  Serial.println("=== RobotCueFSM ready (send WAVE / POINT / RESET) ===");
}

/* ---------- loop ---------- */
void loop() {
  switch (state) {

  /* ── 1. WAIT for keyword ─────────────────────────────── */
  case WAIT_CMD:
    if (Serial.available()) {
      cmd = Serial.readStringUntil('\n');
      cmd.trim(); cmd.toUpperCase();
      if (cmd == "WAVE" || cmd == "POINT" || cmd == "RESET") {
        Serial.print("> Received "); Serial.println(cmd);
        stepIdx = 0;
        lastStep = millis();
        state = RUN_PATTERN;
      } else {
        Serial.println("Try WAVE, POINT, or RESET");
      }
    }
    break;

  /* ── 2. Execute tiny pattern, non-blocking ───────────── */
  case RUN_PATTERN: {
      unsigned long now = millis();
      if (now - lastStep < 500) break;           // 0.5 s per step

      lastStep = now;

      if (cmd == "POINT") {
        setPose(stepIdx == 0 ? POINT : REST);
        if (++stepIdx > 1) state = IDLE;

      } else if (cmd == "WAVE") {
        // WAVE pattern: WAVE1 → WAVE2 → WAVE1 → REST
        if      (stepIdx == 0) setPose(WAVE1);
        else if (stepIdx == 1) setPose(WAVE2);
        else if (stepIdx == 2) setPose(WAVE1);
        else                   { setPose(REST); state = IDLE; }
        stepIdx++;

      } else if (cmd == "RESET") {
        setPose(REST);
        state = IDLE;
      }
      break;
    }

  /* ── 3. End of pattern ───────────────────────────────── */
  case IDLE:
    state = WAIT_CMD;
    Serial.println("> Done");
    break;
  }
}

