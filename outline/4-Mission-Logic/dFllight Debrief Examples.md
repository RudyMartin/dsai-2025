# **Fllight Debrief Examples.md**

## 🛰️ **Nova Teams** (AI Model + Sorting)

| Rule / Issue | Storytelling Layer |
|--------------|--------------------|
| **Model flip-flopping predictions** | “Our object was a red wrench. The model said ‘tool’, then ‘food’, then ‘tool’ again — why?” Was it lighting? Motion blur? Object too close? |
| **Low confidence threshold triggered rejection** | “We trained with clean data, but in flight the camera angle was off — confidence dropped under 40%.” |
| **Wrong object class, right action** | “It thought the minifig was a robot, but sent it to Deck B anyway — by accident, it worked.” |
| **Physical failure (NXT gate stuck or misfired)** | “The prediction was correct, but our servo hadn’t reset. We had to delay the next object.” |
| **Manual insertions messed up the log** | “We inserted an object without triggering the camera. Orion flagged us for missing data.”

🎯 **TA Tip**: Ask teams to **video their prediction behavior** during a flight. Let them observe if the model **“waffles”** — a GREAT conversation starter.

---

## 🌡️ **Vega Teams** (Sensors + Gating)

| Rule / Issue | Storytelling Layer |
|--------------|--------------------|
| **Sensors needed calibration** | “Our light sensor was too close to the LED — it always read 100%.” |
| **DHT temp reading lagged** | “We moved the object in, but temp hadn’t updated — we let in unsafe food.” |
| **Environmental noise** | “Sunlight from a window skewed our readings for Flight 2 — we had to shade the sensor.” |
| **Sensor unplugged = silent fail** | “Everything looked good... but we weren’t logging any light values.” |
| **Alert didn’t trigger due to logic bug** | “Our LED only lit up if *both* temp and light were bad. That hid edge cases.”

🎯 **TA Tip**: Suggest students tape or label “safe zones” near sensors. Let them **physically test calibration** by blocking light or heating the sensor (e.g., hand warmth).

---

## 📡 **Orion Teams** (Logs + Forecasting + Alerts)

| Rule / Issue | Storytelling Layer |
|--------------|--------------------|
| **Deck overload went unnoticed** | “Deck C had 6 food objects. No one noticed until we graphed it.” |
| **Flight failure logic too strict or too loose** | “We flagged a flight as failed just because one object was delayed.” |
| **Ping not returned before action** | “We triggered docking even though all sensors were online — premature logic.” |
| **Walk-by alerts** | “As a teammate leaned in, our proximity sensor tripped. We had to figure out what caused it.” |
| **No logs from Nova → Orion stuck** | “We couldn’t complete our report — Nova Beta didn’t push any files to the NAS.”

🎯 **TA Tip**: Let Orion teams use **printed logs** if live feeds aren’t working. Ask them to simulate a “walk-by” alert by **waving their hand** or using a prop near the deck. Have them respond as if it were real.

---
