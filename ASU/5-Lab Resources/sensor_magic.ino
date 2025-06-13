/**********************************************************************
 * File       : sensor_magic.ino
 * Title      : Simple sensor testing
 * Author     : Jazzanae Holmes
 * Description:
 * Modified   : Jun 12, 2025
 **********************************************************************/
# Author : Jazzanae Holmes

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SHT31.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Create sensor object
Adafruit_SHT31 sht30 = Adafruit_SHT31();

// Motion sensor pin
const int motionPin = 13;
bool motionDetected = false;

void setup() {
  Serial.begin(115200);

  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Initializing...");
  display.display();

  // Initialize SHT30
  if (!sht30.begin(0x44)) {
    Serial.println("Couldn't find SHT30");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("SHT30 not found!");
    display.display();
    while (true);
  }

  // Setup motion sensor pin
  pinMode(motionPin, INPUT);
}

void loop() {
  float temperature = sht30.readTemperature();  // °C
  float humidity = sht30.readHumidity();        // %

  motionDetected = digitalRead(motionPin);

  // Display on Serial Monitor
  Serial.print("Temp: "); Serial.print(temperature); Serial.print(" °C, ");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.print(" %, ");
  Serial.print("Motion: "); Serial.println(motionDetected ? "YES" : "NO");

  // Display on OLED
  display.clearDisplay();
  display.setCursor(0, 0);

  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");

  display.print("Motion: ");
  display.println(motionDetected ? "YES" : "None");

  display.display();

  delay(2000); // Wait 2 seconds before next reading
}
