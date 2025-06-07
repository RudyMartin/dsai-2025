### Two–Hour Lesson Plan (Track 3 “Training → Inference → Tuning”)

| **Time**      | **Step & Purpose**                                                          | **What You Show / Do**                                                                                                                                                                                                                          | **Student Action**                                     | **MCP / FSM Tie-In**                                                                    |
| ------------- | --------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------ | --------------------------------------------------------------------------------------- |
| **0-5 min**   | **Recap yesterday**<br>Remind them they’ve already *used* a model (Lab 2).  | 3-slide mini-deck:<br>1. “We borrowed a brain.”<br>2. Today: “Build your own.”<br>3. Later: “Make it faster/smaller.”                                                                                                                           | Listen                                                 | Links “Borrowed brain” = **ACT** step; today they write **PLAN** logic themselves.      |
| **5-15 min**  | **Platform intro**<br>Pick **Ultralytics HUB** (fast) **+ Colab fallback**. | • Live sign-up (free tier)<br>• Show drag-drop dataset upload<br>• Start a YOLOv8-nano 30-epoch job (visible ETA < 3 min).                                                                                                                      | Follow on screens                                      | Sense → Upload = **LOG**; training loop ≈ “meta-PLAN” (the model learning how to plan). |
| **15-25 min** | **Key concepts, high-school math**                                          | Whiteboard: weights, loss, gradient = “hot/cold game”.                                                                                                                                                                                          | Ask/answer questions                                   | Clarifies *why* later hyper-params matter during tuning.                                |
| **25-45 min** | **Colab code-along** (DIY path)                                             | Open `Train_YOLOv8_BlockDetector.ipynb`:<br>`python<br>!pip install ultralytics -q<br>from ultralytics import YOLO<br># ✍️ students edit these paths<br>model = YOLO('yolov8n.pt')<br>results = model.train(data='blocks.yaml', epochs=25)<br>` | Students duplicate Colab, run cells, watch loss curve. | Training loop sits outside FSM; finished weights drop back into `CLASSIFY` state.       |
| **45-55 min** | **Export & quick test**                                                     | `model.export(format='tflite')` → download; in Colab run one test image.                                                                                                                                                                        | Do the same                                            | Show that TFLite file = “portable PLAN unit.”                                           |
| **55-60 min** | **Break & reflection prompt**                                               | Pose two Qs to discuss after break: 1) Which hyper-parameter sped things up? 2) Where does training live in MCP?                                                                                                                                | Students jot answers                                   | —                                                                                       |

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

