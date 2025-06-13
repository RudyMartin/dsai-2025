/**********************************************************************
 * File       : fsm_camera_sdlogger.ino
 * Title      : FSM Camera Picture Logger with SD Card
 * Description: Uses FSM to take periodic pictures and save to SD card.
 * Author     : Rudy Martin / Next Shift Consulting
 **********************************************************************/

#include "esp_camera.h"
#include "FS.h"
#include "SD_MMC.h"
#include <SPI.h>

// ===================
// Camera Configuration
// ===================
#define CAMERA_MODEL_ESP32S3_EYE
#include "camera_pins.h"

// ========== Flash Mode ==========
#define flash_mode true         // Set to false to disable flash LED behavior
const int flash_pins[] = {2, 3, 4}; // Update to real pins (if connected)
const int num_flash_pins = sizeof(flash_pins) / sizeof(flash_pins[0]);

// ========== SD Save Toggle ==========
bool store_on_sd = true;  // Change to false to disable SD logging

// ========== FSM Setup ==========
enum State { INIT, CAPTURE, WAIT };
State currentState = INIT;

unsigned long stateStartTime = 0;
const unsigned long CAPTURE_INTERVAL = 5000;  // 5 seconds

// ========== File Indexing ==========
int photo_index = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("🚀 Booting FSM Camera Logger");

  if (!initCamera()) {
    Serial.println("❌ Camera init failed");
    return;
  }

  if (store_on_sd && !initSD()) {
    Serial.println("⚠️ SD card failed. Disabling store_on_sd...");
    store_on_sd = false;
  }

  if (flash_mode) {
    for (int i = 0; i < num_flash_pins; i++) {
      pinMode(flash_pins[i], OUTPUT);
      digitalWrite(flash_pins[i], LOW);
    }
  }

  currentState = WAIT;
  stateStartTime = millis();
  Serial.println("✅ FSM Initialized");
}

void loop() {
  unsigned long now = millis();

  switch (currentState) {
    case WAIT:
      if (now - stateStartTime > CAPTURE_INTERVAL) {
        currentState = CAPTURE;
      }
      break;

    case CAPTURE:
      Serial.println("📸 Capturing image...");

      if (flash_mode) {
        for (int i = 0; i < num_flash_pins; i++) digitalWrite(flash_pins[i], HIGH);
        delay(100);
      }

      camera_fb_t *fb = esp_camera_fb_get();
      if (!fb) {
        Serial.println("❌ Camera capture failed");
      } else {
        if (store_on_sd) {
          String path = "/pic_" + String(photo_index++) + ".jpg";
          File file = SD_MMC.open(path.c_str(), FILE_WRITE);
          if (!file) {
            Serial.println("❌ Failed to open file for writing");
          } else {
            file.write(fb->buf, fb->len);
            file.close();
            Serial.print("💾 Saved to: ");
            Serial.println(path);
          }
        } else {
          Serial.println("📁 SD storage is OFF. Skipping save.");
        }
        esp_camera_fb_return(fb);
      }

      if (flash_mode) {
        for (int i = 0; i < num_flash_pins; i++) digitalWrite(flash_pins[i], LOW);
      }

      stateStartTime = millis();
      currentState = WAIT;
      break;

    case INIT:
    default:
      break;
  }

  delay(100);  // Light loop
}

// =================== Camera Init ===================
bool initCamera() {
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
  config.xclk_freq_hz = 10000000;
  config.frame_size = FRAMESIZE_VGA;
  config.pixel_format = PIXFORMAT_JPEG;
  config.grab_mode = CAMERA_GRAB_LATEST;

  if (psramFound()) {
    config.fb_count = 2;
    config.fb_location = CAMERA_FB_IN_PSRAM;
    config.jpeg_quality = 10;
  } else {
    config.fb_count = 1;
    config.fb_location = CAMERA_FB_IN_DRAM;
    config.jpeg_quality = 12;
    Serial.println("⚠️ No PSRAM found – using DRAM mode");
  }

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("❌ Camera init failed: 0x%x\n", err);
    return false;
  }

  return true;
}

// =================== SD Card Init ===================
bool initSD() {
  if (!SD_MMC.begin()) {
    Serial.println("❌ SD_MMC begin failed");
    return false;
  }

  uint8_t cardType = SD_MMC.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("❌ No SD card attached");
    return false;
  }

  Serial.print("📀 SD Card Type: ");
  if (cardType == CARD_MMC) Serial.println("MMC");
  else if (cardType == CARD_SD) Serial.println("SDSC");
  else if (cardType == CARD_SDHC) Serial.println("SDHC");
  else Serial.println("Unknown");

  uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
  Serial.printf("💾 SD Card Size: %llu MB\n", cardSize);
  return true;
}

