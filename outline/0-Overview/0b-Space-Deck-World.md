A **real-world systems thinking layer** is added to the camp.

This “**Space Deck**” scenario lets you simulate:

- **Resource constraints** (space, air, power)  
- **Classification** of object types (human, robot, tool, etc.)  
- **Condition requirements** (oxygen, temp, light)  
- **Prediction modeling** (capacity planning, prioritization)  

And it ties **ALL TEAMS TOGETHER** in a shared mission state.

---

## 🚀 🧱 THE SPACE DECK MODEL

> Your LEGO structure represents a **modular space habitat**, with **multiple decks** or zones:
- **Deck A – Life Support** (for astronauts / minifigs)
- **Deck B – Robotics Bay** (for droids or mechanical items)
- **Deck C – Storage** (for tools, food, spare parts)

But:  
- Each deck has **limited space**, **limited oxygen**, or **thresholds** (light/temp/sound)
- Objects must be **routed correctly based on type AND conditions**
- Students must **detect, classify, and plan placement dynamically**

---

## 🔢 Object Types (from Nova Teams)

| Class | Description | Requirement |
|-------|-------------|-------------|
| 🧍 **Human (minifig)** | Needs oxygen, cool temperature, not too bright | Deck A only |
| 🤖 **Robot** | Tolerates heat/light, but must avoid Deck A | Deck B only |
| 🧰 **Tool** | Can be stored anywhere, but must be tracked | Deck C (or buffer) |
| 🍎 **Food/Supplies** | Temp-sensitive; no heat or excessive light | Deck C (low light preferred) |

---

## 📊 System Modeling Requirement

> Teams must **track inventory + conditions per deck**, and **predict whether a new item can be safely added**.

Add a **small decision model**, e.g.:

```
if deck_A.humans + 1 > deck_A.capacity:
    route_to_emergency_hatch
```

Or:

```
if detected_object == 'food' and light_level > 70:
    reject or reclassify
```

---

## 🧪 Team Interactions in Space Deck System

| Team | Role |
|------|------|
| **Nova Alpha/Beta** | Detect the object (human, robot, tool, food) |
| **Vega Alpha/Beta** | Monitor deck conditions (light, temp, oxygen simulation via sensors) |
| **Orion Alpha/Beta** | Log inventory, update capacity model, predict if object should be accepted or rerouted |
| **All Teams** | Must **communicate state** and act accordingly — or trigger **automated reject/accept responses**

---

## 🧱 LEGO Implementation Ideas

| Build | Description |
|-------|-------------|
| Deck A | Sealed module with dark bricks, LED strip turns red if too many people |
| Deck B | Robot bay with gears and open access |
| Deck C | Cooler zone with sliding storage bins |
| Elevator / tube | NXT-controlled gate or servo rail that drops items to the correct deck |
| Warning Flag | NXT arm or LEGO flag that raises if capacity is exceeded

---

## 🧠 Prediction Modeling Ideas for Orion Teams

| Metric | Example |
|--------|---------|
| Deck capacity | Max 3 humans, 2 robots, 5 tools per deck |
| Forecast | “Based on past detections, we’ll exceed oxygen budget in 2 more uploads” |
| Visual display | Dashboard shows predicted capacity or a red light for deck overfill |
| Route optimization | Suggest alternate deck or reject item if full

---

## ✨ Design Constraints (Reinforced)

- Each team’s decision must consider both:
  - **What type the object is**
  - **Whether the destination deck is ready**
- Systems must **communicate or trigger** physical and digital outcomes across LEGO/NXT + code

