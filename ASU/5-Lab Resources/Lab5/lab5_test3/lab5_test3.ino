#include <Adafruit_Protomatter.h>

uint8_t rgbPins[]  = {7, 8, 9, 10, 11, 12};
uint8_t addrPins[] = {17, 18, 19, 20};  // Try 4 pins first
uint8_t clockPin   = 14;
uint8_t latchPin   = 15;
uint8_t oePin      = 16;

Adafruit_Protomatter matrix(32, 1, 1, rgbPins, 4, addrPins, clockPin, latchPin, oePin, false);

void setup() {
  Serial.begin(115200);
  delay(3000);
  
  Serial.println("Testing HUB75 connection...");
  
  // Try to initialize as 32x32 first (simpler)
  ProtomatterStatus status = matrix.begin();
  Serial.print("Status: ");
  Serial.println(status);
  
  if (status == PROTOMATTER_OK) {
    Serial.println("HUB75 connection working!");
    matrix.fillScreen(0x001F); // All blue
    matrix.show();
  } else {
    Serial.println("HUB75 connection failed");
  }
}

void loop() {}