
# 🧠 **Core Modeling Questions – AI Camp 2.0 Edition**

### 🧪 MODEL PERFORMANCE & EVALUATION

1. **What was your model’s accuracy overall — and was that good enough for your mission?**
2. **Which class had the most misclassifications — and what impact did that have on your mission?**
3. **Did you compute a confusion matrix? What did it tell you about your weak points?**
4. **Was your model biased toward certain classes? (e.g., predicted ‘tool’ too often?)**
5. **Did you observe false positives or false negatives that caused mission issues?**
6. **What confidence threshold did you use to accept predictions? Why that number?**
7. **How did model confidence vary across object types? Did any object consistently get low confidence?**
8. **What steps did you take to calibrate or improve your confidence scores (if any)?**

---

### 🧱 DATA & TRAINING LOGIC

9. **How many labeled images did you collect for each class? Was your dataset balanced?**
10. **What kind of image variability (lighting, angle, occlusion) did you include in training data?**
11. **Did you augment your dataset (e.g., flip, rotate, zoom)? How did that affect performance?**
12. **What assumptions did you make about the training environment that didn’t hold up during real flights?**
13. **What data did you exclude from your training set, and why?**
14. **Did your train/test split result in leakage or duplication errors?**

---

### 🤖 MODEL DESIGN & DEPLOYMENT

15. **What model architecture did you use? (e.g., MobileNet, custom CNN, TFLite Micro)**
16. **What tradeoffs did you make between model size and speed for your deployment (especially on ESP32)?**
17. **How did you convert/export your model for use on the device? Did you run into issues?**
18. **Did your deployed model behave differently than it did in the testing environment? Why?**
19. **If you could train it again, what would you do differently in the pipeline?**
20. **What would it take to make your model mission-critical — something astronauts could trust?**

---

### 💡 Optional Add-on: Encourage students to track

- A mini **model card** per team  
- Include metrics, class balance, training logs, and changes over time  
- Combine this with **Orion Alpha's forecasting** to simulate how imperfect models affect operations

---
