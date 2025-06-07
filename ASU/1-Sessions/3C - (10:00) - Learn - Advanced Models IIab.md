## Day 3 – **Advanced Models II**

*Track 3: “Training → Inference → Tuning”*

| **Time**        | **Step & Purpose**                                     | **Instructor Demo / Prompt**                                                                                                                                               | **Student Action**           | **MCP / FSM Anchor**                                               |
| --------------- | ------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------- | ------------------------------------------------------------------ |
| **00 – 05 min** | **Recap yesterday**<br>“We used someone else’s brain.” | 3-slide deck:<br>1️⃣ Borrowed model → ACT<br>2️⃣ Today: build your own → PLAN<br>3️⃣ PM: make it faster / smaller                                                          | Listen & recall Lab 2 flow   | Borrowed brain = **ACT**; today they author **PLAN**               |
| **05 – 15 min** | **Platform intro**                                     | • Live sign-up Ultralytics HUB (free)<br>• Drag-drop dataset<br>• Kick off YOLOv8-nano (≤ 3 min ETA)                                                                       | Click along on their screens | Upload images = **LOG**; training loop = “meta-PLAN”               |
| **15 – 25 min** | **Key concepts (HS math)**                             | Whiteboard: weights → loss → gradient (“hot-/cold” game)                                                                                                                   | Q\&A                         | Shows why hyper-params matter for tuning                           |
| **25 – 45 min** | **Colab code-along (DIY)**                             | Open `Train_YOLOv8_BlockDetector.ipynb` →<br>`!pip install ultralytics -q`<br>`model = YOLO('yolov8n.pt')`<br>`model.train(data='datasets/blocks/blocks.yaml', epochs=25)` | Run cells, watch loss curve  | Training loop sits outside FSM; finished weights feed **CLASSIFY** |
| **45 – 55 min** | **Export + quick test**                                | `model.export(format='tflite', quantize=True)`<br>Run one test image                                                                                                       | Same steps                   | Int8 TFLite file = portable **PLAN** module                        |
| **55 – 60 min** | **Break + reflection prompt**                          | Ask:<br>1️⃣ Which hyper-param sped things up?<br>2️⃣ Where does training live in MCP?                                                                                      | Jot notes for discussion     | —                                                                  |

> **PM Block (60 min)** – *Tuning & Benchmarking*
> *Quantization demo → Latency challenge with `timing_test.ino` → Hyper-param sweep (`sweeps/*.yaml`) → Fill out `model_card.md`*

---

### 📦 Resources for Day 3

Visit: [https://github.com/RudyMartin/esp32-ai-agents/tree/main/Cookbook/block_detector](https://github.com/RudyMartin/esp32-ai-agents/tree/main/Cookbook/block_detector)

| Item               | Path                                                   | Notes                                    |
| ------------------ | ------------------------------------------------------ | ---------------------------------------- |
| **Colab notebook** | `Train_YOLOv8_BlockDetector.ipynb`                     | Minimal cells, Ultralytics pre-installed |
| **Dataset config** | `datasets/blocks/blocks.yaml`                          | 12 classes, ready to train               |
| **Timing sketch**  | `arduino/ESP32/timing_test.ino`                        | Prints ms / inference on ESP32-S3        |
| **Sweep configs**  | `sweeps/fast.yaml` · `balanced.yaml` · `accuracy.yaml` | Speed ↔ accuracy trade-offs              |
| **Model card**     | `model_card.md`                                        | Record size, mAP, latency                |

---

### 🔑 How This Flow Works

1. **Lab 2** gave instant success with borrowed weights.
2. **Morning (60 min)** — students fully own the training loop and finish a working model inside class time.
3. **Afternoon (60 min)** — students tune the very same model for size & speed, logging metrics back into MCP/FSM (`RETRAIN`, `LOG_METRICS`).
4. **Artifacts** — quantized weights + filled `model_card.md` become plug-and-play assets for future mission labs and FAISS governance demos.
