Here’s the expanded spec for **Team Orion Alpha**, incorporating the **optional camera** to enhance system monitoring, alert tracking, or time-lapse visualization.

---

## 🖥️ **Team Orion Alpha – Network Alert Dashboard + Messaging (Raspberry Pi 5)**  
**Now with Optional Camera for Visual Logging**

---

### 🎯 **Mission Role**  
Act as the **central dashboard** and messaging station for the mission.  
Receive alerts from Vega/Nova teams, display system state on a web interface (Flask), and optionally **log dashboard status visually** via time-lapse or motion-based capture.

---

### 🧱 LEGO Build Purpose

Construct a **command station** console with:

- Mounted **Raspberry Pi + screen**
- LED alert panel (3-color)
- Optional camera mount to watch the dashboard or alert lights
- Optional: message board for crew notifications

---

### 🧰 Key Hardware + Additions

| Type             | Qty | Purpose                                                     |
|------------------|-----|-------------------------------------------------------------|
| Raspberry Pi 5   | 1   | Host Flask app, process incoming messages/logs             |
| LED indicators   | 3   | Red, Yellow, Green for alert status                         |
| Optional OLED    | 1   | Additional display for message readout                      |
| USB/CSI camera   | 1   | Visual record of dashboard status or alert light behavior   |
| Wi-Fi connected  | 1   | Required to receive status feeds from Nova/Vega             |

---

### 🧪 AI + System Logic

| Component     | Task                                                                  |
|---------------|-----------------------------------------------------------------------|
| Flask server  | Receives POSTs or socket signals from Nova/Vega                       |
| LED outputs   | Displays current system status                                        |
| Logger        | Tracks all status messages with timestamps                            |
| Camera (opt.) | Captures image every X minutes or on alert change                    |
| NAS Sync      | Store log and snapshots in shared folder for instructor review        |

---

### 🔁 **Interaction Flow (with Camera)**

1. Vega triggers an alert: “Deck B Overheating”  
2. Orion Alpha dashboard receives alert → LED = Red  
3. Flask UI updates with message: “🔥 Deck B – Temp = 31°C”  
4. Optional camera records snapshot of dashboard/light state  
5. Log entry created:  
   `{timestamp, source: Vega Alpha, alert: High Temp, image: alert_031.jpg}`  
6. Used by Orion Beta to forecast and correlate with object flows

---

### ⏱️ **Feasibility Timeline with Camera**

| Day       | Activities                                                                |
|-----------|----------------------------------------------------------------------------|
| **Day 1** | Flask server setup + test message reception from dummy sender             |
| **Day 2** | LED alerts connected to Flask actions; UI shows simulated logs            |
| **Day 3** | Camera setup: time-lapse or trigger-based image capture                   |
| **Day 4** | Validate incoming messages from Vega/Nova; capture alert snapshots         |
| **Day 5** | Polish dashboard interface, review alert logs, prep presentation           |

---

### 🛠️ **Design Constraints**
- **Real-time alerts** must be visible via LEDs  
- **Log must match** alert events (even if no camera is used)  
- If camera used, **files must be labeled with alert name + timestamp**

---

### 💡 Optional Upgrades
- Include a **text-to-speech alert** using speakers  
- Sync a shared message queue that displays the last 3 active alerts  
- Use the camera for **motion-based trigger** (e.g., when someone approaches dashboard)

---

Would you like **Orion Beta** next, or a combined printable version of all teams reviewed so far?

old_stuff__>
## 📡 Team Orion Alpha – Peer-to-Peer Messaging + Mission Sync (ESP32 or Pi)

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
