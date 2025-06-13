/**********************************************************************
 * Filename    : lab5_rainbow.ino
 * Description : Diagnostic for 64x64 matrix.
 * Author      : Rudy Martin / Next Shift Consulting
 * Modified    : June 2025
 * PURPOSE: Systematically test the capabilities of Display and Board
 **********************************************************************/
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

/* geometry */
HUB75_I2S_CFG cfg(64, 64, 1);

/* corrected pin map */
void mapPins() {
  auto &g = cfg.gpio;
  g.r1 = 37;  g.g1 = 41;  g.b1 = 40;     // upper RGB
  g.r2 = 38;  g.g2 = 39;  g.b2 = 42;     // lower RGB

  g.a  = 45;  g.b = 36;  g.c = 48;  g.d = 35;  g.e = 21;
  g.clk =  2;  g.lat = 47;  g.oe = 14;

  cfg.driver = HUB75_I2S_CFG::FM6126A;   // keeps panel out of “snow”
}

MatrixPanel_I2S_DMA *mx = nullptr;

void rainbow() {
  const uint16_t col[7] = {
    mx->color565(255,0,0),   mx->color565(255,128,0),
    mx->color565(255,255,0), mx->color565(0,255,0),
    mx->color565(0,0,255),   mx->color565(75,0,130),
    mx->color565(148,0,211)
  };
  uint8_t h = 64/7;
  for (uint8_t i=0;i<7;++i) mx->fillRect(0,i*h,64,h,col[i]);
}

void setup() {
  Serial.begin(115200);
  mapPins();

  mx = new MatrixPanel_I2S_DMA(cfg);
  mx->begin();
  mx->setPanelBrightness(60);
  mx->clearScreen();
  rainbow();
  delay(2000);
}

int x=0,y=0,dx=1,dy=0;
void loop() {
  mx->drawPixel(x,y,mx->color565(255,255,255));
  delay(30);
  mx->drawPixel(x,y,0);
  x+=dx; y+=dy;
  if (dx==1 && x==63)      {dx=0; dy=1;}
  else if (dy==1 && y==63) {dx=-1;dy=0;}
  else if (dx==-1&& x==0)  {dx=0; dy=-1;}
  else if (dy==-1&& y==0)  {dx=1; dy=0;}
}