/**********************************************************************
 * File       : lab6_demo_queue_ascii.ino
 * Title      : Queue Actions Demo (2-to-6 DOF, ASCII only)
 * Author     : Rudy Martin / Next Shift Consulting
 **********************************************************************
 * RULES
 *  1. All #defines, structs, enums FIRST.
 *  2. Function prototypes next.
 *  3. #include libraries.
 *  4. Globals (poses, queues, pins).
 *  5. Functions, setup(), loop().
 *********************************************************************/

/* 1. CONSTANTS AND TYPES */
#define DOF_MOTORS 4         /* set 2-6 */
#if DOF_MOTORS < 2 || DOF_MOTORS > 6
#error "DOF_MOTORS must be 2..6"
#endif

struct Pose { uint16_t p[6]; uint16_t hold; };  /* servo pulses + wait time (ms) */
enum   ActID { WAVE, POINT, RESET };

/* 2. MANUAL PROTOTYPES */
Pose  makePose(std::initializer_list<uint16_t>, uint16_t);
bool  qEnq(ActID);
ActID qDeq(void);
void  startAction(ActID);

/* 3. LIBRARIES AND DRIVER */
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

const uint8_t I2C_SDA = 8, I2C_SCL = 9;
const uint8_t SERVO_CH[6] = {0,1,2,3,4,5};

Adafruit_PWMServoDriver pwm(0x40);
inline uint16_t usToTicks(uint16_t us){ return map(us,0,20000,0,4095); }
inline void writeUS(uint8_t ch,uint16_t us){ pwm.setPWM(ch,0,usToTicks(us)); }

/* 4. GLOBAL DATA */
/* Pose helpers */
Pose makePose(std::initializer_list<uint16_t> v,uint16_t ms){
  Pose po{{1500,1500,1500,1500,1500,1500}, ms};
  int i=0; for(uint16_t x:v) if(i<6) po.p[i++]=x;
  return po;
}
const Pose REST = makePose({1500,1500,1500,1500,1500,1500}, 400);
const Pose WAVE_SEQ[]  = { makePose({1450,1500,1500,1450},400),
                           makePose({1550,1500,1500,1550},400),
                           makePose({1450,1500,1500,1450},400),
                           REST };
const Pose POINT_SEQ[] = { makePose({1500,1350,1650},600), REST };

struct ActionDef { const Pose* seq; uint8_t len; };
const ActionDef ACTS[] = {
  { WAVE_SEQ , sizeof(WAVE_SEQ )/sizeof(Pose) },
  { POINT_SEQ, sizeof(POINT_SEQ)/sizeof(Pose) },
  { &REST    , 1 }
};

/* simple circular queue */
const uint8_t QSIZE = 10; ActID q[QSIZE]; uint8_t qHead=0,qTail=0;
bool qEmpty(){ return qHead==qTail; }
bool qFull (){ return uint8_t(qTail+1)%QSIZE==qHead; }
bool qEnq  (ActID id){ if(qFull())return false; q[qTail]=id; qTail=(qTail+1)%QSIZE; return true; }
ActID qDeq(){ ActID id=q[qHead]; qHead=(qHead+1)%QSIZE; return id; }

/* FSM variables */
const uint16_t STEP_MS = 30;
uint8_t poseIdx = 0; unsigned long poseStart = 0;
bool running = false; const ActionDef* curAct = nullptr;

/* 5. FUNCTIONS */
void loadPose(const Pose& po){
  for(uint8_t i=0;i<DOF_MOTORS;i++) writeUS(SERVO_CH[i], po.p[i]);
  poseStart = millis();
}
void startAction(ActID id){
  curAct = &ACTS[id]; poseIdx = 0; running = true; loadPose(curAct->seq[0]);
  switch(id){
    case WAVE:  Serial.println(">> WAVE");  break;
    case POINT: Serial.println(">> POINT"); break;
    case RESET: Serial.println(">> RESET"); break;
  }
}

/* Arduino setup */
void setup(){
  Serial.begin(115200);
  Wire.begin(I2C_SDA,I2C_SCL);
  pwm.begin(); pwm.setPWMFreq(50);
  loadPose(REST);
  Serial.println("Enter comma list: wave, point, reset");
}

/* Arduino loop */
void loop(){
  unsigned long now = millis();

  /* SENSE: read comma list */
  if(Serial.available()){
    String line = Serial.readStringUntil('\n');
    line.trim(); line.toUpperCase();
    int s=0;
    while(true){
      int c = line.indexOf(',', s);
      String tok = (c==-1) ? line.substring(s) : line.substring(s, c);
      if(tok=="WAVE")  qEnq(WAVE);
      else if(tok=="POINT") qEnq(POINT);
      else if(tok=="RESET") qEnq(RESET);
      if(c==-1) break; s = c + 1;
    }
    if(!running && !qEmpty()) startAction(qDeq());
  }

  /* PLAN + ACT: step pose when hold time elapsed */
  if(running && now - poseStart >= curAct->seq[poseIdx].hold){
    if(++poseIdx >= curAct->len){
      running = false;
      if(!qEmpty()) startAction(qDeq());
    } else loadPose(curAct->seq[poseIdx]);
  }

  /* LOG once a second */
  static unsigned long logT = 0;
  if(now - logT > 1000){
    logT = now;
    Serial.printf("Queue length: %u\n", (qTail + QSIZE - qHead) % QSIZE);
  }
}
