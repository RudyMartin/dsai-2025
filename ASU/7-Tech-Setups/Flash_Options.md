Below are **three equally “install-free” paths** your students can follow to get the single-file helper bundle (`helpers.py`) onto their ESP32-S3 boards.  Choose the one that best matches what software is already allowed on the school laptops.

---

## Option A Teacher pre-loads every board  *(fastest in class)*

1. **On your own computer (once):**

   * Flash MicroPython .bin
   * Copy `helpers.py` to `/flash` with any tool you like (`mpremote`, Thonny, etc.).
2. **Dump the golden image:**

   ```bash
   esptool.py --chip esp32s3 read_flash 0 0x400000 golden.bin
   ```
3. **Just before class:**

   ```bash
   esptool.py --chip esp32s3 --port <COMx> write_flash -z 0 golden.bin
   ```

   Do this for every board.
4. In class the helpers are already present; students jump straight to coding.

---

## Option B Browser-only WebREPL upload  *(no extra apps at all)*

> Works even if the laptops have **nothing but a web browser**.

**Teacher enables WebREPL once per board**

```python
# via serial REPL
import webrepl_setup          # set password “camp2025”, enable on boot
```

**Student steps**

| Step                     | What to click / type                                                                                                                                                  |
| ------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1. Join Wi-Fi            | Network: **ESP32-AP** (the board)                                                                                                                                     |
| 2. Open WebREPL page     | [https://micropython.org/webrepl/](https://micropython.org/webrepl/)                                                                                                  |
| 3. Connect               | URL: `ws://192.168.4.1:8266/` – password `camp2025`                                                                                                                   |
| 4. Download `helpers.py` | [https://raw.githubusercontent.com/YourOrg/YourRepo/main/helpers.py](https://raw.githubusercontent.com/YourOrg/YourRepo/main/helpers.py) → right-click → **Save As…** |
| 5. Upload                | WebREPL ▸ **Choose File** → select `helpers.py` ▸ Destination: `helpers.py` ➜ **Send to device**                                                                      |
| 6. Verify                | In the WebREPL console type `>>> import helpers` → no error = success                                                                                                 |

Total class time: \~2 minutes per student once WebREPL is enabled.

---

## Option C Thonny Files-pane upload  *(if Thonny is already on the laptops)*

| Step                | Action                                                   |
| ------------------- | -------------------------------------------------------- |
| 1. Download file    | Same Raw link → Save as `helpers.py`                     |
| 2. Plug board in    | Thonny ▸ Interpreter: *MicroPython (ESP32-S3)*           |
| 3. View ▸ **Files** | Left pane = PC, right pane = board                       |
| 4. Upload           | Drag `helpers.py` from PC pane to board pane (top level) |
| 5. Test             | In Thonny shell: `>>> import helpers`                    |

No additional installs beyond Thonny, which many schools allow because it’s a pure zip-app.

---

### Where students get the file

Give them the Raw link:

```
https://raw.githubusercontent.com/<owner>/<repo>/main/helpers.py
```

*(Replace `<owner>` and `<repo>` with your GitHub path.)*
Right-click → **Save As…** ensures they download plain text, not an HTML page.

---

### After upload – first lines the student writes

```python
import helpers                       # one import brings in everything
from helpers import EdgeInfer, capture_rgb

# quick smoke test
rgb = capture_rgb()
idx, conf = EdgeInfer().classify(rgb)
print("Label index:", idx, "Confidence:", conf)
```

If that prints numbers instead of errors, they’re ready to integrate Wi-Fi, MQTT, and servos in the next lab.
