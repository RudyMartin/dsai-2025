# ESP32-S3 + Camera + Agentic Robotics Camp

---

## 🧭 Day 1: Setup + First Motion – "Make It Move & See"

### 🎯 Mission Objective

Build and test a basic robotic system: camera + servo-controlled robot arm.

### 🧠 Learning Objectives

* Understand ESP32-S3 and Arduino IDE setup
* Wire and control servo motors using PCA9685
* Stream live video from the onboard OV2640 camera

### 🔧 Key Activities

* Upload sample servo sweep sketch
* Test camera using Wi-Fi stream viewer
* Discuss what each component does (servo, camera, board)

### 📚 Vocabulary

* PWM (Pulse Width Modulation)
* GPIO (General Purpose Input/Output)
* ESP32 microcontroller

### 💬 Discussion Prompt

"What does it mean for a robot to ‘see’ something? What can it do with that information?"

---

## 🧭 Day 2: Classification + Action – "Sort by Sight"

### 🎯 Mission Objective

Create a basic vision-to-action loop: detect object class, move to destination.

### 🧠 Learning Objectives

* Use image classification (color or shape detection)
* Implement simple `if/else` logic to move blocks
* Control robot arm position based on camera input

### 🔧 Key Activities

* Hard-code color detection thresholds (e.g., Red, Blue, Yellow)
* Assign fixed destinations (bins A/B/C)
* Move robot arm after classification

### 📚 Vocabulary

* Inference
* Classification
* Logic gate (`if`, `else if`, `else`)

### 💬 Discussion Prompt

"If the robot sees red, how do we tell it what to do? Can we trust its decision?"

---

## 🧭 Day 3: Memory + Routing Logic – "Smarter Decisions"

### 🎯 Mission Objective

Track and adapt based on system state (e.g., deck load).

### 🧠 Learning Objectives

* Implement counters or arrays to track object counts
* Use conditional rules to reroute based on state (e.g., Deck B full)
* Simulate decision trees based on multiple conditions

### 🔧 Key Activities

* Add deck counters in code
* Modify `if/else` logic to use counters
* Print routing decisions via `Serial.println()`

### 📚 Vocabulary

* State variable
* Counter / accumulator
* Reroute logic

### 💬 Discussion Prompt

"What if the robot has to decide between two bad options? How should it choose?"

---

## 🧭 Day 4: Sensor-Aware Agents – "React to the World"

### 🎯 Mission Objective

Respond to environmental conditions: don’t just decide — adapt.

### 🧠 Learning Objectives

* Read from temp, humidity, or light sensors
* Combine sensor values with classification to inform decision
* Use sensor fusion for smarter routing

### 🔧 Key Activities

* Connect temp/humidity/light sensors
* Create compound conditions (`if temp > 30 && color == Red`)
* Simulate edge case scenarios (e.g., path too dark)

### 📚 Vocabulary

* Sensor fusion
* Threshold
* Environmental adaptation

### 💬 Discussion Prompt

"How does your robot behave differently if it’s hot, dark, or damp?"

---

## 🧭 Day 5: Multi-Agent Simulation – "Robots That Talk"

### 🎯 Mission Objective

Simulate agents sharing status and collaborating to make decisions.

### 🧠 Learning Objectives

* Simulate multiple roles (e.g., robot, forecast, deck monitor)
* Send and receive JSON-formatted messages
* Plan for distributed agent behavior

### 🔧 Key Activities

* Use `Serial.print()` to simulate messages between agents
* Design a simple message protocol (e.g., `{deck: C, status: full}`)
* Combine decisions from multiple "agents"

### 📚 Vocabulary

* Multi-agent system
* Message passing
* Coordination protocol

### 💬 Discussion Prompt

"How does your robot make a better decision when it talks to its teammates first?"

---
