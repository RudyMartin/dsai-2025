

##  Day 1 Camera Allocation Summary (With Models)

### 📦 Inventory Breakdown (by model type)

| Camera Type         | Quantity | Notes                                |
|---------------------|----------|--------------------------------------|
| **ESP32-CAM**       | 2        | Generic AI Thinker or clone modules  |
| **ESP32-S3 (with cam onboard)** | 2        | Dev boards with onboard camera         |
| **USB webcams (for Pi)** | 2        | Compatible with Raspberry Pi 4/5     |

📊 **Total camera-capable devices**: **6** → Perfect match for 6 teams.

---

### 🎯 Team-Level Camera Assignment Table

```markdown
| Team         | Mission Role                             | Camera Model Assigned      | Reason                            |
|--------------|-------------------------------------------|-----------------------------|------------------------------------|
| Nova Alpha   | Object detection, servo sorting           | ESP32-CAM                   | Needs real-time classification     |
| Nova Beta    | Object detection, dashboard display       | ESP32-S3 (with cam onboard) | LED/OLED overlay + onboard cam     |
| Vega Alpha   | Sensor monitoring, visual deck feedback   | ESP32-CAM (spare)           | For baseline time-lapse test       |
| Vega Beta    | Airlock servo + condition logging         | ESP32-S3 (with cam onboard) | Logs object entry at airlock       |
| Orion Alpha  | Alert dashboard & message relay           | USB Webcam #1               | Logs dashboard state transitions   |
| Orion Beta   | Forecast & docking prediction display     | USB Webcam #2               | Logs forecast charts or dashboards |
```

