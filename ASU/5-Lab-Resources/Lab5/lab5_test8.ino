/**********************************************************************
 * Filename    : lab5_rainbow.ino
 * Description : Diagnostic for 64x64 matrix.
 * Author      : Rudy Martin / Next Shift Consulting
 * Modified    : June 2025
 * PURPOSE: Systematically test the capabilities of Display and Board
 **********************************************************************/
/*********************************************************************
Upload it, open the Serial Monitor (115 200 baud) so you know which colour is active, and snap your photos during each 30-second window.
*********************************************************************/
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

/* Geometry (unchanged) */
HUB75_I2S_CFG cfg(64, 64, 1);

/* *** CURRENT pin guess – keep as-is for now ********************* */
void mapPins() {
  auto &g = cfg.gpio;
  g.r1 = 42;  g.g1 = 41;  g.b1 = 40;   // upper  RGB
  g.r2 = 38;  g.g2 = 39;  g.b2 = 37;   // lower  RGB

  g.a = 45;  g.b = 36;  g.c = 48;  g.d = 35;  g.e = 21;

  g.clk = 2;  g.lat = 47;  g.oe = 14;

  cfg.driver = HUB75_I2S_CFG::FM6126A;   // stays – prevents “snow”
}

/* Driver object */
MatrixPanel_I2S_DMA *mx = nullptr;

void announce(const char *txt) {
  Serial.println();
  Serial.println("==========");
  Serial.println(txt);
  Serial.println("==========");
}

void setup() {
  Serial.begin(115200);
  mapPins();

  mx = new MatrixPanel_I2S_DMA(cfg);
  if (!mx->begin()) {
    Serial.println("matrix.begin() failed — check PSRAM");
    while (true) {}
  }
  mx->setPanelBrightness(80);
}

/* Show one colour for 30 seconds, print banner */
void showColour(const char *name, uint16_t colour565) {
  announce(name);
  mx->fillScreen(colour565);
  delay(30'000);                       // 30 000 ms = 30 s
}

void loop() {
  static uint8_t loopCount = 0;
  if (loopCount >= 10) {                // done after 10 cycles
    announce("Finished 10 loops — Halting");
    while (true) {}                     // leave last colour displayed
  }

  showColour("RED",   mx->color565(255, 0, 0));
  showColour("GREEN", mx->color565(0, 255, 0));
  showColour("BLUE",  mx->color565(0, 0, 255));
  showColour("BLACK (blank)", mx->color565(0, 0, 0));

  loopCount++;
}
