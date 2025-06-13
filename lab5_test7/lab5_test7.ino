/**********************************************************************
 * Filename    : lab5_rainbow.ino
 * Description : Diagnostic for 64x64 matrix.
 * Author      : Rudy Martin / Next Shift Consulting
 * Modified    : June 2025
 * PURPOSE: Systematically test the capabilities of Display and Board
 **********************************************************************/
include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

/* geometry plus our best-known control pins */
HUB75_I2S_CFG cfg(64, 64, 1);
void mapPins() {
  auto &g = cfg.gpio;
  g.r1 = 42;  g.g1 = 41;  g.b1 = 40;   // current guess
  g.r2 = 38;  g.g2 = 39;  g.b2 = 37;
  g.a  = 45;  g.b  = 36;  g.c  = 48;  g.d = 35;  g.e = 21;
  g.clk = 2;  g.lat = 47; g.oe  = 14;
  cfg.driver = HUB75_I2S_CFG::FM6126A;   // keep – prevents “snow”
}

MatrixPanel_I2S_DMA* mx = nullptr;

void setup() {
  mapPins();
  mx = new MatrixPanel_I2S_DMA(cfg);
  mx->begin();
  mx->setPanelBrightness(80);
}

void loop() {
  mx->fillScreen(mx->color565(255, 0, 0));  delay(1500);  // RED
  mx->fillScreen(mx->color565(0, 255, 0));  delay(1500);  // GREEN
  mx->fillScreen(mx->color565(0, 0, 255));  delay(1500);  // BLUE
}