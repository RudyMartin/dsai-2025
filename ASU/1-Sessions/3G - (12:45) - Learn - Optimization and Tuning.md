## Day 3 - Optimization & Tuning
# Slide 1: What is Tuning?
- Tuning = adjusting settings to improve results.
- Common in models: learning rate, threshold, etc.

# Slide 2: Try This!
- Example: Show a poor model vs tuned model on a test image.
- Ask: What changed?

# Slide 3: Slider Demo
- Add slider: adjust threshold from 0.2 to 0.9
- Show accuracy or confusion matrix update live.

---

#### **Hour 2 – Tuning & Optimization Lab**

| **Time**      | **Step & Purpose**                          | **Show / Do**                                                                                          | **Student Action**                                                         | **MCP / FSM Tie-In**                                                          |
| ------------- | ------------------------------------------- | ------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| **0-5 min**   | **Kick-off**                                | Return to questions; highlight LR, batch size, frozen layers.                                          | Share answers                                                              | —                                                                             |
| **5-15 min**  | **Quantization demo**                       | In Colab:<br>`from ultralytics.utils.torch_utils import quantize`<br>Make int8 model; print size diff. | Run snippet, note `.tflite` file shrank \~75 %.                            | Smaller PLAN → quicker **ACT** on ESP32.                                      |
| **15-35 min** | **Mini-challenge: Beat instructor latency** | Provide ESP32-S3 timing script (in serial monitor prints ms/inference).                                | Teams flash nano vs quantized; record times; upload to shared sheet.       | Adds metric logging to **LOG** state (`{"latency_ms": …}`).                   |
| **35-45 min** | **Hyper-parameter sweep**                   | Give starter YAML with `epochs`, `imgsz`, `augment`.                                                   | Each team edits one param, retrains 5 epochs (Colab GPU ≈4 min), logs mAP. | Shows cyclical MCP: if `mAP < 0.8` => return to `RETRAIN` state (FSM branch). |
| **45-55 min** | **Discuss cost vs. accuracy graph**         | Plot (provided) showing diminishing returns.                                                           | Interpret where “sweet spot” lies.                                         | Teaches design trade-off thinking.                                            |
| **55-60 min** | **Commit to repo**                          | Push best weights + `model_card.md` to camp GitHub.                                                    | Do it.                                                                     | Versioned PLAN modules ready for future labs.                                 |

---

### Resources You Give Them

| Item                               | Link / Location                                | Notes                                        |
| ---------------------------------- | ---------------------------------------------- | -------------------------------------------- |
| `Train_YOLOv8_BlockDetector.ipynb` | Colab template (shared via class Google Drive) | Minimal cells, pre-installed Ultralytics.    |
| `blocks.yaml`                      | In repo `/datasets/blocks/`                    | Ready-formatted dataset config.              |
| ESP32 timing script                | `timing_test.ino`                              | Reads one frame, prints inference latency.   |
| Hyper-param sweep YAMLs            | `sweeps/` folder (3 presets)                   | “Fast”, “Balanced”, “Accuracy-push”.         |
| Model card template                | `model_card.md`                                | Students fill name, size, accuracy, latency. |

---

### Why This Fits Your Flow

1. **Lab 2** borrowed weights → quick success.
2. **Morning of Lab 3 (Hour 1)** students *own* the training loop and see it finish inside class time.
3. **Afternoon of Lab 3 (Hour 2)** they manipulate the same model for speed & size, linking back to MCP/FSM (`RETRAIN`, `LOG_METRICS`).
4. Outputs are portable weights + documented trade-offs—fuel for later mission integration and for the governance lessons you run with FAISS.

