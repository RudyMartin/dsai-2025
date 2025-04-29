
# ✅ Roboflow Modeling Checklist  
**Build and deploy your own image classifier or object detector step-by-step**

---

## 🧩 Part 1: Set Up Your Project
- [ ] Create a free Roboflow account at [roboflow.com](https://roboflow.com)  
- [ ] Click **“Create New Project”**  
- [ ] **Name:** `SpaceCamp Object Classifier` (or your custom name)  
- [ ] **Project Type:**  
  - 🟢 *Image Classification* → for ESP32 use  
  - 🔲 *Object Detection* → for bounding boxes on Pi  
- [ ] **Annotation Type:** Single-label  
- [ ] Upload **5–10+ images per class**  
  - Suggested classes: `human`, `robot`, `tool`, `food`, `unknown`  
- [ ] Organize uploads using folders or drag-and-drop

---

## 🎯 Part 2: Label and Annotate
- [ ] Open each image and assign a label  
  - **Classification:** Select class from dropdown  
  - **Detection:** Draw bounding boxes  
- [ ] Double-check for any mislabels or missing annotations  
- [ ] Click **“Save”** after each annotation  

---

## 🧪 Part 3: Generate Dataset with Augmentations
- [ ] Click **“Generate New Version”**  
- [ ] Choose **Image Size**  
  - 224x224 for classification  
  - 416x416 for detection  
- [ ] Select Augmentations (optional but helpful):  
  - [ ] Rotation  
  - [ ] Flip  
  - [ ] Brightness / Contrast  
  - [ ] Blur / Noise  
- [ ] Click **“Generate”** to create your dataset version

---

## 🤖 Part 4: Train Your Model
- [ ] Click **“Train Model”**  
- [ ] Use **Roboflow-hosted training** (cloud training is easiest)  
- [ ] Wait ~5–15 minutes while model trains  
- [ ] Review output:  
  - Accuracy  
  - Confusion matrix  
  - Sample predictions  

---

## 🚀 Part 5: Export for Your Hardware
- [ ] Click **“Export Model”**  
  - For **ESP32-S3 (Nova Alpha)** → choose **TFLite Micro**  
  - For **Raspberry Pi (Nova Beta)** → choose **TFLite / ONNX / PyTorch**  
- [ ] Download **model file** and **labels**  
- [ ] Integrate with project code using example scripts

---

## 📊 Part 6: Test and Improve
- [ ] Test predictions using Roboflow's **"Deploy" → "Test"** tab  
- [ ] Add new images if predictions are incorrect  
- [ ] Re-label and re-train as needed  
- [ ] Repeat until accuracy is satisfactory

---

