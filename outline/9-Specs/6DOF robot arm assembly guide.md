

# 🔧 6DOF Robot Arm Assembly Guide (v1)

Welcome to the 6DOF robotic arm installation tutorial!
If you're assembling a multi-jointed robotic arm for the first time, this guide will walk you through each step with helpful tips and screw specifications.

---

## ⚠️ Important Notes Before You Begin

* **Common issues to avoid**:

  * Using the wrong screw sizes.
  * Incorrect servo alignment (rudder angles).

* **Screw usage guide**:

  | Screw Type | Usage                               |
  | ---------- | ----------------------------------- |
  | **M3×6**   | For installing servo wheels (horns) |
  | **M3×8**   | For mounting servos and brackets    |
  | **M3×10**  | For securing flange bearings        |

> ⚠️ Use only the screws provided. Avoid substitutions.

---

## 🧭 Servo Centering Is Critical

Before mounting any servo, **center it** at its midpoint:

* For **180° servos**:

  * Midpoint ≈ **1500ms** (this corresponds to \~90°)
  * 0° ≈ 500ms; 180° ≈ 2500ms PWM signal

* **How to center**:

  * Use a servo tester, your own microcontroller code, or a dedicated controller.
  * Turn the servo wheel by hand *before* powering on. If it **locks at an angle**, it's likely a servo with internal limits.
  * If it **spins freely**, it has *no mechanical limit* and must be centered via software.

---

## 🔩 Step-by-Step Assembly Instructions

---

### **Step 1: Assemble Two U-Shaped Beams**

* 🪛 M3×8 screw × 8
* 🔩 M3 nut × 8

---

### **Step 2: Attach Multi-Function Bracket to Bottom Beam**

* Identify the **bracket mounting holes** (red circles in diagram).

* **Fix the bracket first, then the servo**.

* Use screws **with washers** for servo.

* **Tip**: The servo direction is opposite to what’s shown in the figure (double-check orientation).

* 🪛 M3×6 screw × 5

* 🪛 M3×8 (spacer) screw × 4

* 🪛 M3×8 screw × 4

* 🔩 M3 nut × 8

---

### **Step 3: Attach Convex Lift to L-Shaped Bracket**

* Install **symmetrically** (left and right).
* 🪛 M3×6 screw × 8

---

### **Step 4: Install Left & Right Multi-Function Brackets**

* 🪛 M3×8 screw × 8
* 🔩 M3 nut × 8

---

### **Step 5: Assemble Long U-Shaped Brackets**

* Connect them to the structure from Step 4.
* 🪛 M3×10 screw × 1
* 🪛 M3×8 screw × 4
* 🔩 M3 nut × 5

---

### **Step 6: Mount Servo on U-Shaped Bracket + Add Servo Wheel**

* Insert servo screws from **bottom to top**.
* 🪛 M3×6 screw × 1
* 🪛 M3×8 screw × 4
* 🔩 M3 nut × 4

---

### **Step 7: Connect Servo Assembly to Bracket from Step 5**

* Align and secure the servo-mounted bracket to the multifunction structure.

---

### **Step 8: Install Additional Servos**

* 🪛 M3×6 screw × 10
* 🪛 M3×8 (washer) screw × 8
* 🔩 M3 nut × 8

---

### **Step 9: Mount Servo to Gripper + Attach to Main Structure**

* 🪛 M3×6 washer screw × 4 (highlighted in red)
* 🪛 M3×6 screw × 5
* 🔩 M3 nut × 4

---

### **Step 10: Final Arm Mounting**

* Attach the fully assembled arm onto the multifunction bracket (from Step 2).

* 🎉 Assembly complete!

* 🪛 M3×6 screw × 5

* 🪛 M3×8 spacer screw × 4

* 🪛 M3×10 screw × 1

* 🔩 M3 nut × (as needed)

---

## ✅ Final Checklist

* [ ] All servos properly centered before installation
* [ ] Correct screw lengths used at each stage
* [ ] Brackets installed symmetrically and securely
* [ ] Arm moves freely through intended range of motion


