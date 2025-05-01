 **Baseline Video Test Plan** to run **across all teams**, using your assigned cameras. 
 
 This ensures:

- All cameras are working  
- Frame positions are practical  
- File storage/logging works before mission integration

---

## 🎥 **Baseline Video Test – All Teams**

### ✅ **Goal:**  
Ensure every team can **capture a short video or image sequence** using their assigned camera, store or preview it, and understand its purpose in their system.

---

### 📋 **Unified Test Procedure (Day 1 Afternoon)**

| Step | Task                                                                  | Output                        |
|------|-----------------------------------------------------------------------|-------------------------------|
| 1    | Connect and mount camera (USB or CSI)                                | Live preview or stable mount |
| 2    | Capture a 5–10 second video or 3 still frames                         | Saved video or image files    |
| 3    | Store file locally or print to console (confirm access)              | Filenames with timestamps     |
| 4    | Write log entry: `{team, timestamp, file_path, test_status}`         | Validated logging             |
| 5    | Share 1 image or clip with instructor / TA                           | Checked for orientation/use   |

---

### 🧪 **What to Evaluate**

- Is the camera **physically stable** and well-angled?  
- Do images/video **clearly show** the subject (object, deck, dashboard)?  
- Can the **filename or path** be reused later for logging/syncing?  
- Can team **access file** via code to integrate into logs or alerts?

---

### 🧱 Example Use Per Team

| Team         | Test Subject                   | Output Goal                         |
|--------------|--------------------------------|-------------------------------------|
| Nova Alpha   | Object on deck before sort     | Snapshot for prediction             |
| Nova Beta    | Object classification screen   | Image for log file                  |
| Vega Alpha   | Deck sensor reading zone       | Still image of alert state          |
| Vega Beta    | Gate activation moment         | Frame showing entry + open gate     |
| Orion Alpha  | Alert LED dashboard            | Image on alert change               |
| Orion Beta   | Forecast dashboard             | Still image of prediction chart     |

---

### 🛠️ **Follow-Up Integration**
On **Day 2**, each team should:
- Refactor this into their **actual mission log**
- Begin capturing real entries (e.g., gate open with image, alert with image)

---

