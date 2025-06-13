/**********************************************************************
 * Filename    : lab5_message_passing.ino
 * Description : Diagnostic for 64x64 matrix.
 * Author      : Rudy Martin / Next Shift Consulting
 * Modified    : June 2025
 * PURPOSE: Systematically test the capabilities of Display and Board
 **********************************************************************/
/*********************************************************************
  MatrixPortal S3 64×64 HUB75 Quick Test  (ESP32-HUB75-MatrixPanel-I2S-DMA ≥ v3.0.11)

  ✔ Adafruit MatrixPortal S3 default pin map
  ✔ Handles 1/32-scan panels (E line present)
  ✔ FM6126A driver init enabled
*********************************************************************/

#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

/* ── 1. Panel geometry ──────────────────────────────────────────── */
constexpr uint16_t kWidth  = 64;
constexpr uint16_t kHeight = 64;
constexpr uint8_t  kChain  = 1;

/* ── 2. MatrixPortal-S3 hard-wired GPIOs ────────────────────────── */
constexpr uint8_t PIN_R1 = 40, PIN_G1 = 41, PIN_B1 = 42;
constexpr uint8_t PIN_R2 = 45, PIN_G2 = 46, PIN_B2 = 47;

constexpr uint8_t PIN_A = 38, PIN_B = 39, PIN_C = 34;
constexpr uint8_t PIN_D = 35, PIN_E = 36;        // keep E for 1/32-scan

constexpr uint8_t PIN_LAT = 37;
constexpr uint8_t PIN_OE  = 21;
constexpr uint8_t PIN_CLK = 33;

/* ── 3. Build config object (3-arg ctor) ────────────────────────── */
HUB75_I2S_CFG mxcfg(kWidth, kHeight, kChain);

void mapPins() {
  auto &g = mxcfg.gpio;
  g.r1  = PIN_R1;  g.g1  = PIN_G1;  g.b1  = PIN_B1;
  g.r2  = PIN_R2;  g.g2  = PIN_G2;  g.b2  = PIN_B2;

  g.a   = PIN_A;   g.b   = PIN_B;   g.c   = PIN_C;
  g.d   = PIN_D;   g.e   = PIN_E;   // comment g.e for 1/16-scan panels

  g.lat = PIN_LAT; g.oe  = PIN_OE;  g.clk = PIN_CLK;

  /* Most 64×64 panels use the FM6126A line-latch timing */
  mxcfg.driver = HUB75_I2S_CFG::FM6126A;
}

/* ── 4. Instantiate driver ──────────────────────────────────────── */
MatrixPanel_I2S_DMA *matrix = nullptr;

/* ── 5. Helper: rainbow bars ────────────────────────────────────── */
void rainbowBars() {
  const uint16_t c[7] = {
    matrix->color565(255,0,0),  matrix->color565(255,128,0),
    matrix->color565(255,255,0),matrix->color565(0,255,0),
    matrix->color565(0,0,255),  matrix->color565(75,0,130),
    matrix->color565(148,0,211)
  };
  uint8_t h = kHeight / 7;
  for (uint8_t i=0;i<7;++i) matrix->fillRect(0,i*h,kWidth,h,c[i]);
}

/* ── 6. Arduino setup ───────────────────────────────────────────── */
void setup() {
  Serial.begin(115200);
  mapPins();

  matrix = new MatrixPanel_I2S_DMA(mxcfg);
  if (!matrix->begin()) {
    Serial.println("❌ matrix.begin() failed – check PSRAM or wiring");
    while (true) {}
  }
  matrix->setPanelBrightness(60);   // 0-255
  matrix->clearScreen();
  rainbowBars();                    // hold rainbow for 2 s
  delay(2000);
}

/* ── 7. Loop: white pixel around the border ─────────────────────── */
int x = 0, y = 0, dx = 1, dy = 0;
void loop() {
  matrix->drawPixel(x, y, matrix->color565(255,255,255));
  delay(30);
  matrix->drawPixel(x, y, 0);

  x += dx;  y += dy;
  if (dx==1  && x==kWidth-1)   {dx=0; dy=1;}
  else if (dy==1 && y==kHeight-1){dx=-1;dy=0;}
  else if (dx==-1 && x==0)     {dx=0; dy=-1;}
  else if (dy==-1 && y==0)     {dx=1; dy=0;}
}
