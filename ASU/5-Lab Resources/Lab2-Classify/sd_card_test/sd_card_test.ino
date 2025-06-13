/**********************************************************************
 * File       : sd_card_test.ino
 * Title      : ESP32 SD Card Diagnostics Utility
 * Author     : Rudy Martin / Next Shift Consulting
 * Description: Mounts the SD card, verifies access, prints capacity,
 *              writes a test file, and confirms FAT32 formatting.
 **********************************************************************/

#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define SD_CS_PIN 10  // ⚠️ Change to your board’s SD CS pin

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("📂 SD Card Diagnostic Starting...");

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("❌ SD card mount failed");
    Serial.println("🔍 Make sure the card is formatted as FAT32 (not exFAT)");
    return;
  }

  Serial.println("✅ SD card mounted");

  // Card type check
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("❌ No SD card detected");
    return;
  }

  Serial.print("📦 Card type: ");
  switch (cardType) {
    case CARD_MMC:  Serial.println("MMC"); break;
    case CARD_SD:   Serial.println("SD"); break;
    case CARD_SDHC: Serial.println("SDHC"); break;
    default:        Serial.println("Unknown"); break;
  }

  // Print card size
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("💾 Card size: %llu MB\n", cardSize);

  // Print used and available space
  uint64_t totalBytes = SD.totalBytes() / (1024 * 1024);
  uint64_t usedBytes = SD.usedBytes() / (1024 * 1024);
  Serial.printf("📊 Total space reported: %llu MB\n", totalBytes);
  Serial.printf("📊 Used space: %llu MB\n", usedBytes);

  // Test write
  Serial.println("📝 Writing test file...");
  File testFile = SD.open("/test_sd.txt", FILE_WRITE);
  if (!testFile) {
    Serial.println("❌ Failed to open file for writing");
    Serial.println("⚠️ If your card is >32GB, reformat as FAT32");
  } else {
    testFile.println("✅ SD card test file created successfully!");
    testFile.close();
    Serial.println("✅ Test file written: /test_sd.txt");
  }

  // List root directory
  Serial.println("📁 SD card contents:");
  listDir(SD, "/", 1);
}

void loop() {
  // Nothing to do
}

void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  File root = fs.open(dirname);
  if (!root) {
    Serial.println("❌ Failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println("❌ Not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    Serial.print("📄 ");
    Serial.print(file.name());
    if (file.isDirectory()) {
      Serial.println("/");
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("\t\t");
      Serial.print(file.size());
      Serial.println(" bytes");
    }
    file = root.openNextFile();
  }
}

