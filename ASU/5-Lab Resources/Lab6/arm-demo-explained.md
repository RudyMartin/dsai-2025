Here’s what the **ASCII-only “queue demo” sketch** does, step by step.

---

## 1.  Starts by defining everything up front

| Code line(s)                        | Purpose                                                                               |
| ----------------------------------- | ------------------------------------------------------------------------------------- |
| `#define DOF_MOTORS 6`              | Tells the sketch how many servos (2–6) you actually have.                             |
| `struct Pose`                       | Holds one *pose*: up to 6 pulse-widths **plus** a “hold” time in ms.                  |
| `enum ActID { WAVE, POINT, RESET }` | Simple IDs for three demo actions.                                                    |
| Function **prototypes**             | Listed before the first `#include` so Arduino’s auto-prototyper can’t mis-order them. |

---

## 2.  Includes libraries and sets up the PCA9685

* `Wire.h` – I²C driver
* `Adafruit_PWMServoDriver.h` – library for the PCA9685 16-channel PWM board
* `SERVO_CH[]` maps each degree of freedom to a PCA9685 output (0-5).
* `writeUS()` converts a micro-second pulse to PCA9685 “ticks”.

---

## 3.  Builds *poses* and *action sequences*

```cpp
REST  = all servos 1500 µs (neutral)
WAVE  = [left pose] -> [right pose] -> [left] -> REST
POINT = [arm out]   -> REST
```

Each pose array entry also has a *hold time* (400 ms or 600 ms).

---

## 4.  Implements an **action queue**

A 10-slot circular buffer holds upcoming `ActID`s:

```cpp
qEnq(WAVE);         // add to tail
id = qDeq();        // remove from head
```

This lets you type a **comma list** of actions and the sketch will run them
one after another.

---

## 5.  FSM variables

* `running`  – whether we are in the middle of an action
* `curAct`   – pointer to the current `ActionDef` (sequence + length)
* `poseIdx`  – which pose in that sequence we’re on
* `poseStart` – `millis()` timestamp when the current pose began

---

## 6.  `setup()`

* Initializes I²C, starts the PCA9685 at 50 Hz.
* Sends every servo to the **REST** pose.
* Prints a help line:

  ```
  Enter comma list: wave, point, reset
  ```

---

## 7.  `loop()` – the MCP pattern

| MCP step   | Code                                                                                          | What happens                |
| ---------- | --------------------------------------------------------------------------------------------- | --------------------------- |
| **SENSE**  | Reads a line from Serial, splits on commas                                                    | Builds a queue of `ActID`s  |
| **PLAN**   | If not already running, take the next ID from the queue                                       | Chooses an action to run    |
| **ACT**    | `loadPose()` writes pulses for the next pose; after the hold time expires, advances `poseIdx` | Physically moves servos     |
| **LOG**    | Once per second prints queue length                                                           | Optional runtime info       |
| **REPEAT** | `loop()` just repeats                                                                         | Continues until queue empty |

When an action’s last pose finishes:

1. `running` is set `false`
2. If the queue isn’t empty, it immediately starts the next action.

---

## 8.  What you see in Serial

```
>> WAVE
Queue length: 2
Queue length: 1
>> POINT
Queue length: 0
>> RESET
Queue length: 0
```

* `>>` lines show which action just began.
* “Queue length” shows how many actions remain waiting.

---

### In short

* **Type**: `wave,point,reset`
* The sketch **queues** those three actions.
* Each action plays its **pose sequence** smoothly, pausing the requested
  milliseconds at each pose.
* When the queue empties, the robot returns to REST and waits.

All pulses, holds, and the number of servos are hard-coded in one file, with
no emojis or special characters—so it compiles cleanly on any Arduino/ESP32
toolchain.
