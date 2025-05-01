# Flight Overvie:

### **Flight 1: Basic Object Detection & Initial System Testing**  
**Concepts Covered:**
- **Signal Labeling and Data Collection**:  
  Students manually label data (images, sensor readings) and organize it for **object detection** tasks. They will learn the importance of accurate **data labeling** to build high-quality datasets.
  
- **Basic Object Detection**:  
  Introduction to **object detection** models like **YOLO** (You Only Look Once) for identifying objects in images. Students will focus on **basic classification** tasks to test the system’s ability to detect objects in a controlled, low-complexity environment.
  
- **Model Evaluation (Basic)**:  
  Students will evaluate the **model performance** using basic metrics like **accuracy** and **precision**. The goal is to understand how well the system detects objects and how to improve it based on evaluation results.
  
- **Initial System Testing**:  
  Students test their initial builds, running simulations and evaluating whether their system detects objects correctly and can trigger actions (e.g., moving forward if an object is detected).
  
- **Basic Action/Decision Making**:  
  Students apply simple **if-then rules** for actions. For example: **"If object detected, move forward."** This will help set the stage for more advanced decision-making logic later.

---

### **Flight 2: Handling Mission Constraints & Adaptive Decision Making**  
**Concepts Covered:**
- **Handling Constraints in Missions**:  
  Students will simulate different **mission constraints** (e.g., an offline sensor or a limited power supply) and test their models under real-world conditions. This exercise demonstrates how to adapt AI systems to work in **resource-constrained environments** like space missions.
  
- **Model Re-training & Fine-tuning**:  
  Teams will **fine-tune** their models to handle unexpected mission constraints, such as when an important sensor becomes unavailable or if a model needs to operate under **time restrictions**. This process helps students understand how to improve AI models by adjusting their parameters (e.g., learning rate, epochs).
  
- **Model Evaluation (Advanced)**:  
  Teams will assess model performance using **advanced metrics** like **recall** and **F1-score**. They will focus on improving the system's ability to accurately detect objects while minimizing errors or false positives.
  
- **Dynamic Decision-Making**:  
  Students will update their **decision-making logic** to account for real-time data and changes in system conditions. For example, **"If an object is detected, but the temperature is too high, activate cooling system before moving forward."**
  
- **Real-time System Integration**:  
  Teams will integrate their models with **robotic systems** (e.g., **LEGO Mindstorms** or **ESP32**). They will test whether their object detection models can trigger real-time actions based on the mission’s constraints.

---

### **Flight 3: Full System Integration, Performance Optimization & Final Testing**  
**Concepts Covered:**
- **Full System Integration**:  
  This is the final simulation where **all components** (object detection models, decision-making logic, sensors, robotics systems) are integrated into a **fully functional system**. Students will test how well their entire mission pipeline works together.
  
- **Prediction and Resource Management**:  
  Students will use **prediction models** (e.g., forecasting system states like resource consumption or mission outcomes) and incorporate them into their **final system integration**. For example: **"If system predicts resources will run low, trigger an alert and adjust the flight plan accordingly."**
  
- **Model Optimization**:  
  Students will apply advanced techniques like **hyperparameter tuning** to optimize their models. They will focus on improving system performance in areas like **latency** and **accuracy**.
  
- **Final Evaluation**:  
  Teams will assess their system using **all evaluation metrics** learned during the camp (accuracy, precision, recall, F1-score, etc.) to ensure the system meets performance requirements.
  
- **Decision-Making Logic at Scale**:  
  Teams will apply **complex decision-making** logic, where their models and actions are fully autonomous based on the input data. For example: **"If object detected and environmental conditions change, adjust mission path accordingly."**

- **Final Testing and Debugging**:  
  Students will conduct a **final round of testing** and **debugging** to ensure that all systems (data collection, modeling, decision-making, and action) work seamlessly together.

---

### **Summary of Concepts Covered per Flight**:

1. **Flight 1 (Basic Object Detection & Initial System Testing)**:
   - Signal labeling and data collection
   - Basic object detection and model evaluation
   - Initial system testing and basic decision-making

2. **Flight 2 (Handling Mission Constraints & Adaptive Decision Making)**:
   - Mission constraints and adaptive system behavior
   - Model re-training and fine-tuning for better performance
   - Advanced model evaluation
   - Dynamic decision-making with real-time data
   - Real-time system integration and testing

3. **Flight 3 (Full System Integration, Performance Optimization & Final Testing)**:
   - Full system integration and predictive modeling
   - Model optimization techniques (hyperparameter tuning)
   - Complex decision-making logic
   - Final testing, debugging, and performance evaluation

---

This structure gives students a **clear progression** of **learning**, from basic model training to advanced system integration, and ensures they **apply AI** concepts in a mission-based context. Each flight will push them to think critically about how to adapt and optimize their models, decision-making, and system integration based on the constraints they face.
