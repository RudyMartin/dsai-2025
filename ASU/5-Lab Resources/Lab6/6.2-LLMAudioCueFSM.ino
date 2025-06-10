/**********************************************************************
 * File       : 6.2-LLMAudioCueFSM.ino
 * Title      : FSM – Play audio cues for LLM prompt categories (Lab 6)
 * Author     : Rudy Martin / Next Shift Consulting
 * Description: Waits for keywords on Serial (OK, WARN, FAIL, HELLO)
 *              and plays corresponding WAV clips from SPIFFS
 **********************************************************************/

#include "AudioFileSourceSPIFFS.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"

// ─── I²S pins (same as debug sketch) ────────────────────────────────
constexpr int I2S_BCLK = 36;
constexpr int I2S_LRC  = 35;
constexpr int I2S_DOUT = 34;

// ─── Map keywords to filenames ──────────────────────────────────────
const char* fileFor(const String& cmd) {
  if      (cmd == "OK")   return "/ok.wav";
  else if (cmd == "WARN") return "/warn.wav";
  else if (cmd == "FAIL") return "/fail.wav";
  else if (cmd == "HELLO")return "/hello.wav";
  return nullptr;
}

// ─── FSM states ─────────────────────────────────────────────────────
enum State { WAIT_CMD, LOAD_FILE, PLAY_FILE, IDLE };
State currentState = WAIT_CMD;

// ─── Audio objects ──────────────────────────────────────────────────
AudioFileSourceSPIFFS* file = nullptr;
AudioGeneratorWAV*      wav  = nullptr;
AudioOutputI2S*         out  = nullptr;
String                  pendingCmd;

void setupAudio() {
  out = new AudioOutputI2S(I2S_BCLK, I2S_LRC, I2S_DOUT);
  out->SetGain(0.9);
}

void setup() {
  Serial.begin(115200);
  SPIFFS.begin(true);
  setupAudio();
  Serial.println("=== LLMAudioCueFSM (Lab 6) ready ===");
  Serial.println("Send: OK | WARN | FAIL | HELLO");
}

void loop() {

  switch (currentState) {

  case WAIT_CMD:
    if (Serial.available()) {
      pendingCmd = Serial.readStringUntil('\n');
      pendingCmd.trim();
      pendingCmd.toUpperCase();
      const char* f = fileFor(pendingCmd);
      if (f) {
        currentState = LOAD_FILE;
      } else {
        Serial.println("Unrecognized cmd – try OK/WARN/FAIL/HELLO");
      }
    }
    break;

  case LOAD_FILE: {
      const char* fname = fileFor(pendingCmd);
      if (!SPIFFS.exists(fname)) {
        Serial.printf("File %s not found\n", fname);
        currentState = WAIT_CMD;
        break;
      }
      if (wav) { wav->stop(); delete wav; wav = nullptr; }
      if (file){ delete file; file = nullptr; }

      file = new AudioFileSourceSPIFFS(fname);
      wav  = new AudioGeneratorWAV();
      wav->begin(file, out);
      Serial.printf("> Playing %s\n", fname);
      currentState = PLAY_FILE;
    }
    break;

  case PLAY_FILE:
    if (wav && wav->isRunning()) {
      if (!wav->loop()) {
        wav->stop();
      }
    } else {
      currentState = WAIT_CMD;
      Serial.println("> Done");
    }
    break;

  case IDLE:
    break;
  }
}
