## Day 3 – **Advanced Models III**

*Track 3: “Training → Inference → Tuning”*

### 🕘 **Afternoon Session (60 min) – Optimization & Tuning**

| Time            | Step & Purpose                                 | Instructor Demo / Prompt                                                                                                                      | Student Action                                                        | MCP / FSM Anchor                                      |
| --------------- | ---------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------- | ----------------------------------------------------- |
| **00 – 05 min** | **Kick-off** – surface answers to break prompt | Summarise key knobs: **learning-rate, batch-size, frozen layers**                                                                             | Share reflections                                                     | —                                                     |
| **05 – 15 min** | **Quantization demo**                          | `python\nfrom ultralytics.utils.torch_utils import quantize\nquantize('runs/detect/baseline/weights/best.pt')\n`<br>Show size shrink (\~75 %) | Run snippet locally; note file sizes                                  | Smaller **PLAN** ⇒ faster **ACT** on ESP32            |
| **15 – 35 min** | **Mini-challenge: “Beat My Latency”**          | Provide `arduino/ESP32/timing_test.ino`<br>(nano vs int8)                                                                                     | Teams flash both, record `ms/inference`, log to shared sheet          | Add `{"latency_ms": …}` to **LOG** state              |
| **35 – 45 min** | **Hyper-parameter sweep**                      | Hand out starter YAML (epochs, imgsz, augment)                                                                                                | Each team tweaks **one** param, retrains 5 epochs (\~4 min), logs mAP | Cyclical MCP: if `mAP < 0.80` ➜ branch to **RETRAIN** |
| **45 – 55 min** | **Cost vs Accuracy graph**                     | Show provided plot of image-size ↔ mAP ↔ latency                                                                                              | Debate “sweet-spot” point                                             | Builds design trade-off mindset                       |
| **55 – 60 min** | **Commit & push**                              | `git add best_int8.tflite model_card.md` → push                                                                                               | Do it live                                                            | Versioned **PLAN** ready for later labs               |

---

### 📦 Resources for Day 3

| Item           | Path                                                 | Notes                                    |
| -------------- | ---------------------------------------------------- | ---------------------------------------- |
| Colab notebook | `Train_YOLOv8_BlockDetector.ipynb`                   | Minimal cells, Ultralytics pre-installed |
| Dataset config | `datasets/blocks/blocks.yaml`                        | 12 classes, ready to train               |
| Timing sketch  | `arduino/ESP32/timing_test.ino`                      | Prints `ms / inference` on ESP32-S3      |
| Sweep configs  | `sweeps/fast.yaml`, `balanced.yaml`, `accuracy.yaml` | Speed ↔ accuracy trade-offs              |
| Model card     | `model_card.md`                                      | Record size, mAP, latency                |

> **Repo link:** [https://github.com/RudyMartin/esp32-ai-agents/tree/main/Cookbook/block\_detector](https://github.com/RudyMartin/esp32-ai-agents/tree/main/Cookbook/block_detector)

---

### 🔑 How This Flow Works

* **Lab 2** → instant success with borrowed weights.
* **Morning (60 min)** → students own the training loop and finish a working model inside class.
* **Afternoon (60 min)** → students tune the *same* model for size & speed, logging metrics back into MCP/FSM (**RETRAIN**, **LOG\_METRICS**).
* **Artifacts** → quantized weights + filled `model_card.md` become plug-and-play assets for later mission integration and FAISS governance demos.
