/**********************************************************************
 * File       : lab6_demo_queue.ino
 * Title      : Quick-Demo – Queue Actions (2-to-6 DOF)
 * Author     : Rudy Martin / Next Shift Consulting
 **********************************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

/* ─────── CONFIG – edit only these two lines ────────────────────── */
#define DOF_MOTORS 6            /* 2 ≤ DOF_MOTORS ≤ 6                */
const uint8_t SERVO_CH[6] = { 0, 1, 2, 3, 4, 5 };  // PCA9685 channels

/* ─────── Safety check ──────────────────────────────────────────── */
#if DOF_MOTORS < 2 || DOF_MOTORS > 6
#error "DOF_MOTORS must be between 2 and 6"
#endif

/* ─────── Driver setup ──────────────────────────────────────────── */
constexpr uint8_t SDA_PIN = 8, SCL_PIN = 9;
Adafruit_PWMServoDriver pwm(0x40);
inline uint16_t us2t(uint16_t us){ return map(us,0,20000,0,4095); }
inline void writeUS(uint8_t ch, uint16_t us){ pwm.setPWM(ch,0,us2t(us)); }

/* ─────── Pose definition (array style) ─────────────────────────── */
struct Pose { uint16_t p[6]; uint16_t hold; };

Pose makePose(std::initializer_list<uint16_t> pulses, uint16_t ms){
  Pose po{{1500,1500,1500,1500,1500,1500}, ms};
  int i=0; for(uint16_t v: pulses) { if(i<6) po.p[i++] = v; }
  return po;
}

/* ─────── Action sequences (only first DOF_MOTORS entries used) ─── */
const Pose REST = makePose({1500,1500,1500,1500,1500,1500}, 400);

const Pose WAVE_SEQ[] = {
  makePose({1450,1500,1500,1450}, 400),
  makePose({1550,1500,1500,1550}, 400),
  makePose({1450,1500,1500,1450}, 400),
  REST
};
const Pose POINT_SEQ[] = {
  makePose({1500,1350,1650}, 600),
  REST
};

struct ActionDef { const Pose* seq; uint8_t len; };
enum ActID { WAVE, POINT, RESET };
const ActionDef ACTS[] = {
  { WAVE_SEQ , sizeof(WAVE_SEQ )/sizeof(Pose) },
  { POINT_SEQ, sizeof(POINT_SEQ)/sizeof(Pose) },
  { &REST    , 1 }
};

/* ─────── Simple circular queue ─────────────────────────────────── */
constexpr uint8_t QSZ=10; ActID q[QSZ]; uint8_t h=0,t=0;
inline bool qEmpty(){ return h==t; }
inline bool qFull(){ return uint8_t(t+1)%QSZ==h; }
bool enqueue(ActID id){ if(qFull())return false; q[t]=id;t=(t+1)%QSZ;return true; }
ActID dequeue(){ ActID id=q[h];h=(h+1)%QSZ;return id; }

/* ─────── FSM vars ──────────────────────────────────────────────── */
uint8_t poseIdx=0; unsigned long poseStart=0; bool running=false;
const ActionDef* cur=nullptr;

/* ─────── Helper: write a whole pose safely ─────────────────────── */
void loadPose(const Pose& po){
  for(uint8_t i=0;i<DOF_MOTORS;i++) writeUS(SERVO_CH[i], po.p[i]);
  poseStart = millis();
}

/* ─────── Arduino setup ─────────────────────────────────────────── */
void setup(){
  Serial.begin(115200);
  Wire.begin(SDA_PIN,SCL_PIN);
  pwm.begin(); pwm.setPWMFreq(50);
  loadPose(REST);
  Serial.println(F("Demo ready – type comma words (wave,point,reset)"));
}

/* ─────── Action starter ────────────────────────────────────────── */
void start(ActID id){
  cur=&ACTS[id]; poseIdx=0; running=true; loadPose(cur->seq[0]);
  Serial.printf(">> %s\n", id==WAVE?"WAVE":id==POINT?"POINT":"RESET");
}

/* ─────── Main loop ─────────────────────────────────────────────── */
void loop(){
  unsigned long now=millis();

/* 1️⃣ SENSE – parse comma list */
  if(Serial.available()){
    String ln=Serial.readStringUntil('\n'); ln.trim(); ln.toUpperCase();
    int st=0;
    while(true){
      int c=ln.indexOf(',',st); String tok=(c==-1)?ln.substring(st):ln.substring(st,c);
      if(tok=="WAVE") enqueue(WAVE);
      else if(tok=="POINT") enqueue(POINT);
      else if(tok=="RESET") enqueue(RESET);
      if(c==-1)break; st=c+1;
    }
    if(!running && !qEmpty()) start(dequeue());
  }

/* 2-3️⃣ PLAN & ACT – advance pose after hold time */
  if(running && now-poseStart>=cur->seq[poseIdx].hold){
    if(++poseIdx>=cur->len){          // finished action
      running=false;
      if(!qEmpty()) start(dequeue());
    }else loadPose(cur->seq[poseIdx]);
  }

/* 4️⃣ LOG every second */
  static unsigned long logPrev=0;
  if(now-logPrev>1000){ logPrev=now;
    Serial.print("Queue:"); Serial.println((t+QSZ-h)%QSZ);
  }
/* 5️⃣ REPEAT – loop restarts */
}
