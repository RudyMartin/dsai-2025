/**********************************************************************
 * File       : fsm_camera_sdlogger.ino
 * Title      : FSM Camera SD Logger
 * Author     : Rudy Martin / Next Shift Consulting
 * Description: FSM that alternates streaming + picture save
 *              Logs captured JPEGs to SD card every few seconds
 **********************************************************************/

#include "esp_camera.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <WiFi.h>
#include <time.h> // For timestamp-based filenames

// ==== Camera Model ====
#define CAMERA_MODEL_ESP32S3_EYE
#include "camera_pins.h"

// ==== FSM States ====
enum State {
  STREAMING,
  PICTURE
};
State currentState = STREAMING;

// ==== Timing ====
unsigned long startTime = 0;
unsigned long stateStart = 0;
const unsigned long STATE_DURATION = 15000;
const unsigned long TOTAL_DURATION = 30000;
unsigned long lastPictureTime = 0;

// ==== SD Card ====
#define SD_CS_PIN 10  // Adjust if using different CS pin
bool sdOK = false;

// ==== Setup ====
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("📸 FSM Camera SD Logger Starting...");

  // Initialize camera
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = 12;
  config.fb_count = psramFound() ? 2 : 1;
  config.fb_location = psramFound() ? CAMERA_FB_IN_PSRAM : CAMERA_FB_IN_DRAM;
  config.grab_mode = CAMERA_GRAB_LATEST;

  if (esp_camera_init(&config) != ESP_OK) {
    Serial.println("❌ Camera init failed");
    return;
  }

  // Initialize SD card
  Serial.println("📂 Mounting SD card...");
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("❌ SD card mount failed");
  } else {
    sdOK = true;
    Serial.println("✅ SD card mounted");
  }

  // Set up timers
  startTime = millis();
  stateStart = millis();
}

// ==== Main Loop ====
void loop() {
  unsigned long now = millis();

  if (now - startTime > TOTAL_DURATION) {
    Serial.println("✅ FSM complete. Halting.");
    while (true) delay(1000);
  }

  if (now - stateStart > STATE_DURATION) {
    currentState = (currentState == STREAMING) ? PICTURE : STREAMING;
    stateStart = now;
    Serial.print("🔄 Switched to state: ");
    Serial.println((currentState == STREAMING) ? "STREAMING" : "PICTURE");
  }

  switch (currentState) {
    case STREAMING:
      Serial.println("📡 Simulating stream...");
      delay(1000);
      break;

    case PICTURE:
      if (now - lastPictureTime >= 4000) {
        captureAndSave();
        lastPictureTime = now;
      }
      break;
  }
}

// ==== Helper: Capture and Save to SD ====
void captureAndSave() {
  if (!sdOK) {
    Serial.println("⚠️ Skipped capture – SD not ready");
    return;
  }

  camera_fb_t* fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("❌ Frame capture failed");
    return;
  }

  // Generate filename using timestamp
  time_t now = time(NULL);
  struct tm* timeinfo = localtime(&now);
  char filename[64];
  strftime(filename, sizeof(filename), "/img_%Y%m%d_%H%M%S.jpg", timeinfo);

  File file = SD.open(filename, FILE_WRITE);
  if (!file) {
    Serial.println("❌ Failed to open file for writing");
    esp_camera_fb_return(fb);
    return;
  }

  file.write(fb->buf, fb->len);
  file.close();
  esp_camera_fb_return(fb);

  Serial.print("📸 Saved: ");
  Serial.println(filename);
}
