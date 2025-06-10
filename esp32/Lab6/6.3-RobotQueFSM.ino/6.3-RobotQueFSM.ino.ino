/**********************************************************************
 * File       : 6.3-RobotCueSmoothFSM.ino
 * Title      : FSM – Smooth Robot-Arm Demo Cues (Lab 6)
 * Author     : Rudy Martin / Next Shift Consulting
 * Description: Keywords  WAVE | POINT | RESET  trigger soft, gradual
 *              moves on a 4-servo arm (PCA9685 driver).
 **********************************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

/* ---------- I2C + PCA9685 ---------- */
constexpr uint8_t SDA_PIN = 8;
constexpr uint8_t SCL_PIN = 9;
Adafruit_PWMServoDriver pwm(0x40);

/* ---------- Servo helpers ---------- */
uint16_t usToTicks(uint16_t us) { return map(us, 0, 20000, 0, 4095); }
void writeUS(uint8_t ch, uint16_t us) { pwm.setPWM(ch, 0, usToTicks(us)); }

/* ---------- Channels ---------- */
constexpr uint8_t CH_BASE = 0;
constexpr uint8_t CH_SHO  = 1;
constexpr uint8_t CH_ELB  = 2;
constexpr uint8_t CH_WRI  = 3;

/* ---------- Poses (µs) – reduced swing ---------- */
struct Pose { uint16_t b,s,e,w; };

Pose REST  {1500, 1500, 1500, 1500};
Pose POINT {1500, 1350, 1650, 1500};   // modest reach
Pose W1    {1475, 1500, 1500, 1425};   // slight left
Pose W2    {1525, 1500, 1500, 1575};   // slight right

/* ---------- Smooth-move parameters ---------- */
const uint16_t STEP_US        = 15;     // µs size ≈ 1 °
const uint16_t STEP_DELAY_MS  = 40;     // 25 Hz refresh

/* Track current position so we can ease */
Pose cur = REST;

/* ---------- FSM ---------- */
enum State { WAIT, PREP, SMOOTH, IDLE };
State state = WAIT;

String cmd;
Pose  target;                // where we’re heading
unsigned long lastStep = 0;
uint8_t waveCount = 0;

/* ---------- helpers ---------- */
bool easeAxis(uint16_t &curAxis, uint16_t targetAxis) {
  if (curAxis == targetAxis) return true;          // done
  int16_t diff = int16_t(targetAxis) - int16_t(curAxis);
  curAxis += (diff > 0 ? min<uint16_t>(STEP_US, diff)
                       : max<int16_t>(-STEP_US, diff));
  return false;                                    // still moving
}

void writePose(const Pose& p) {
  writeUS(CH_BASE, p.b);
  writeUS(CH_SHO , p.s);
  writeUS(CH_ELB , p.e);
  writeUS(CH_WRI , p.w);
}

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  pwm.begin();  pwm.setPWMFreq(50);
  writePose(REST);
  Serial.println("=== Smooth Robot-Arm ready (WAVE/POINT/RESET) ===");
}

void loop() {
  unsigned long now = millis();

  switch (state) {

  /* ── 1. WAIT for keyword ─────────────────────────── */
  case WAIT:
    if (Serial.available()) {
      cmd = Serial.readStringUntil('\n');
      cmd.trim(); cmd.toUpperCase();
      if      (cmd == "POINT") { target = POINT; state = PREP; }
      else if (cmd == "WAVE")  { waveCount = 4; target = W1; state = PREP; }
      else if (cmd == "RESET") { target = REST; state = PREP; }
      else Serial.println("Try WAVE, POINT, RESET");
    }
    break;

  /* ── 2. PREP – initialise smooth move ────────────── */
  case PREP:
    lastStep = now;
    state = SMOOTH;
    break;

  /* ── 3. SMOOTH stepping every STEP_DELAY_MS ──────── */
  case SMOOTH:
    if (now - lastStep < STEP_DELAY_MS) break;
    lastStep = now;

    bool doneB = easeAxis(cur.b, target.b);
    bool doneS = easeAxis(cur.s, target.s);
    bool doneE = easeAxis(cur.e, target.e);
    bool doneW = easeAxis(cur.w, target.w);
    writePose(cur);

    if (doneB && doneS && doneE && doneW) {          // reached pose
      if (cmd == "WAVE" && waveCount) {              // bounce pose
        target = (waveCount & 1) ? W2 : W1;
        waveCount--;
      } else {
        state = IDLE;
        Serial.println("> Done");
      }
    }
    break;

  /* ── 4. finished ─────────────────────────────────── */
  case IDLE:
    state = WAIT;
    break;
  }
}
