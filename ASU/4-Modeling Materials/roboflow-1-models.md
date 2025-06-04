ALL Teams get an introduction to using  models


| Team | New Project Role | Roboflow Model Use | Notes on How They Will Train & Use Models |
|:---|:---|:---|:---|
| **Nova Alpha (ESP32-S3)** | Object classification + physical sorting | ✅ Yes (TFLite Micro) | Train a **lightweight 4-5 class model** to recognize LEGO objects (`human`, `robot`, `tool`, `food`, `unknown`), trigger servo gate sorting |
| **Nova Beta (ESP32-S3)**  | Full object detection dashboard | ✅ Yes (TFLite or ONNX) | Train a **full detection model** (bounding boxes) to identify objects on the platform; display class and location live |
| **Vega Alpha (ESP32-S3 + camera)** | Visual sensor dashboard | ✅ Yes (TFLite Micro) | Mount an **ESP32 camera**, **visually detect environmental states** like “too dark,” “too bright,” “motion detected,” “overheated” based on LED indicators or room lighting |
| **Vega Beta (ESP32-S3 + camera)** | Environmental gatekeeper | ✅ Yes (TFLite Micro) | Take images of object + environment; classify as **safe/unsafe** (e.g., based on brightness, color, object type); servo hatch opens/closes based on prediction |
| **Orion Alpha (Raspberry Pi 5)** | Visual messaging monitor | ✅ Yes (ONNX/TFLite) | Use camera (or screenshots) to **visually detect incoming system alerts**, dashboard states, or other team's flag signals; confirm deck readiness |
| **Orion Beta (Raspberry Pi 5)** | Visual forecasting + alert monitor | ✅ Yes (ONNX/TFLite) | Use dashboard screenshots + sensor feed snapshots; classify “normal”, “at risk”, “overloaded” deck states; trigger forecasting model updates |
