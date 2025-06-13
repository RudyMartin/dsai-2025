/*********************************************************************
  MatrixPortal S3 64×64 panel — correct GPIO map
  Library: ESP32-HUB75-MatrixPanel-I2S-DMA v3.0.11+
*********************************************************************/
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

/* 1️⃣  Panel geometry */
constexpr uint16_t WIDTH  = 64;
constexpr uint16_t HEIGHT = 64;
constexpr uint8_t  CHAIN  = 1;

/* 2️⃣  MatrixPortal-S3 factory pin mapping  */
HUB75_I2S_CFG cfg(WIDTH, HEIGHT, CHAIN);
/*  Protomatter example →
      rgbPins = {42,41,40,38,39,37}
      addrPins= {45,36,48,35,21}
      CLK=2  LAT=47  OE=14                                          */
void mapPins() {
  auto &g = cfg.gpio;
  g.r1 = 42;  g.g1 = 41;  g.b1 = 40;
  g.r2 = 38;  g.g2 = 39;  g.b2 = 37;
  g.a  = 45;  g.b  = 36;  g.c  = 48;
  g.d  = 35;  g.e  = 21;                 // keep E for 1/32-scan
  g.clk = 2;  g.lat = 47;  g.oe = 14;

  cfg.driver   = HUB75_I2S_CFG::SHIFTREG;   // default
  // cfg.driver = HUB75_I2S_CFG::FM6126A;   // ← uncomment if still blank
}

/* 3️⃣  Globals */
MatrixPanel_I2S_DMA *mx = nullptr;

/* 4️⃣  Setup — solid red so it’s obvious */
void setup() {
  Serial.begin(115200);
  mapPins();

  mx = new MatrixPanel_I2S_DMA(cfg);
  if (!mx->begin()) {
    Serial.println("matrix.begin() failed — check PSRAM & power");
    while (true) {}
  }
  mx->setPanelBrightness(80);
  mx->fillScreen(mx->color565(255, 0, 0));   // big red field
}

void loop() {}   // nothing else


