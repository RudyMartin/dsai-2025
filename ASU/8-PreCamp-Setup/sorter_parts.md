# LEGO Sorter Parts List with ESP32

| Item                              | Quantity | Source        | Unit Price | Subtotal | Notes                                                      |
|----------------------------------|----------|---------------|------------|----------|------------------------------------------------------------|
| ESP32-CAM Board (with OV2640)    | 1        | Adafruit / Amazon | $10.00    | $10.00   | Core controller with built-in camera for detection         |
| FTDI USB-to-Serial Adapter       | 1        | Adafruit / Amazon | $8.00     | $8.00    | Needed for programming ESP32-CAM (no native USB port)      |
| Micro Servo - TowerPro SG92R     | 4        | Adafruit      | $5.95      | $23.80   | Actuates sorting arm/gates; enough torque for LEGO pieces  |
| LEGO-Compatible Servo Mount/Adapter | 4     | Adafruit / 3D print | $1.75     | $7.00    | Mounts servos to LEGO beams for modular arm construction   |
| 28BYJ-48 Stepper Motor + ULN2003 Driver (optional) | 1 | Amazon / eBay | $5.00     | $5.00    | For motorized conveyor; budget-friendly and easy to control|
| External 5V Power Supply (USB or barrel jack) | 1 | Adafruit / Amazon | $7.50     | $7.50    | Powers servos and motors reliably; separate from ESP32 power|
| Jumper Wires (Male-Female, Female-Female) | 1 set | Adafruit / Amazon | $4.00     | $4.00    | For all signal and power connections                        |
| Hook-up Wire Spool Set (22AWG)   | 1        | Adafruit      | $7.95      | $7.95    | For custom wiring and permanent connections                 |
| Breadboard (optional)            | 1        | Adafruit / Amazon | $5.00     | $5.00    | Useful for prototyping and testing                          |

---

**Estimated Total (without optional stepper motor):** $67.25  
**Estimated Total (with optional stepper motor):** $72.25

---

### Notes:
- Prices are approximate and may vary by supplier and availability.
- You can reduce costs by sourcing compatible clones or bulk parts from other suppliers.
- Ensure all grounds (ESP32, servos, power supply) are connected together for stable operation.
- The number of servos depends on your sorting arm design; 4 is a typical starting point.
- The 28BYJ-48 stepper motor and driver are optional if you want a motorized conveyor.
