
## 📡 Team Orion Beta – Peer-to-Peer Messaging + Mission Sync (ESP32 or Pi)

---

### 1. 🎯 **Mission Role**  
> Coordinate and synchronize the entire mission in **real-time** by sending and receiving peer-to-peer messages (via MQTT, UDP, or REST).  
Trigger system-wide **alerts** (e.g., “Deck B offline”), issue **go/no-go commands**, and **relay mission state updates** between Nova and Vega teams.

They are the **radio room and network relay** of the mission.

---

### 2. 🧱 **LEGO Build Purpose**  
Construct a **communication tower or relay station**:
- LED lights or flags show when messages are sent/received  
- Optional LEGO “alert beacons” that turn on when a signal is received  
- LEGO console with buttons or switches to simulate mission commands

No sensors, no object detection — just **communication, timing, and signal processing**

---

### 3. 🧰 **Required Hardware + LEGO Parts**

| Type | Qty | Purpose |
|------|-----|---------|
| LEGO baseplate | 1 | Tower or console base |
| Bricks + beams | 10–15 | Tower or control panel build |
| ESP32 or Raspberry Pi | 1 | Handles messaging protocol |
| LED array or RGB LEDs | 1+ | Visually indicate message receipt or error |
| Buttons or switches | Optional | Trigger test messages or commands |
| Buzzer or speaker | Optional | Audible alert when message received |
| MQTT broker or UDP server (Pi or local) | 1 | Message handler |
| Wi-Fi network (AX5400 router) | 1 | Enables local comms

---

### 4. 🧪 **System + Messaging Logic**

| Component | Task |
|----------|------|
| **Listen for incoming messages** | “Object detected: tool → Deck C” |
| **Display or log message** | LED flashes or alert dashboard updates |
| **Relay signals** | Vega sends: “Unsafe” → Relay to Orion Alpha |
| **Health check pings** | Ping other systems, report downtime |
| **Simulate broadcast alerts** | Send “Abort flight” or “Docking now” messages |
| **Log all comms** | Track when/who sends/receives what for Orion Alpha sync

---

### 5. 🔁 **Interaction Flow (As Messaging Hub)**

```plaintext
Nova Beta sends object detection signal →
Orion Beta receives + displays status (LED) →
Vega Alpha sends unsafe alert →
Orion Beta relays to Orion Alpha →
Orion Alpha logs and forecasts →
Orion Beta sends “Docking: Confirmed” message back to teams
```

- Keeps everything **in sync without human shouting across the room**
- If a team fails to report in time, Orion Beta can issue a retry signal

---

### 6. ⏱️ **Feasibility in 5-Day Camp**

✅ Yes — and ideal for a student who likes code, messaging, or networks:
- Day 1: ESP32/Pi messaging test (UDP/MQTT)
- Day 2: Build LEGO tower + LED alerts
- Day 3: Connect message flow to Nova/Vega test messages
- Day 4: Integrate live flight comms
- Day 5: Log messages + live demo

---

### 🛠️ **Design Constraint: Real-Time Messaging + Logging Required**

> ✨ “Your system must send and receive mission-critical messages in real time — and display a visible status.  
You must log or relay messages between teams, helping Orion Alpha make decisions.  
Without you, the mission flies blind and disconnected.”

---
