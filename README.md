# 🎯 ESP32 Buzz Wire Game

A portable **Buzz Wire Game** built using an **ESP32**, a **buzzer**, **LED**, **OLED display**, and **copper wire path**.  
The project measures **time taken**, **number of collisions**, and provides **visual + sound feedback**.  
It can be used as a fun hand steadiness test or for medical tremor evaluation.

---

## 🧠 Features

- 🕒 **Timer Start/Stop**  
  Starts automatically when touching the **Start pad** and stops at the **End pad**.

- 🚨 **Collision Detection**  
  Every time the ring touches the copper wire, the **buzzer beeps** and the **LED blinks**.

- 📟 **OLED Display**  
  Shows real-time **time** and **collision count**, and displays final results.

- 🔄 **Restart Easily**  
  Hold the **Start pad** for 2 seconds to restart or use the **EN–GND reset button**.

- 🔋 **Portable Design**  
  Works on a battery (Li-ion + TP4056 + boost converter) — ideal for portable testing setups.

---

## ⚙️ Components Used

| Component | Quantity | Description |
|------------|-----------|-------------|
| **ESP32 DevKit** | 1 | Main microcontroller |
| **Active Buzzer** | 1 | Audio alert for collisions |
| **LED** | 1 | Blinks on collision |
| **0.96" OLED Display (SH1106 I2C)** | 1 | Shows timer and results |
| **Copper Wire / Rod** | 1 | Shaped path for the ring |
| **Copper Pads / Strips** | 2 | Start and End points |
| **Metal Ring Probe** | 1 | Connected to GND, used by player |
| **Resistors (Optional)** | few | For signal protection (if needed) |
| **Reset Push Button** | 1 | Between EN and GND for hardware reset |
| **Zero PCB** | 1 | For assembling circuit |
| **Battery + TP4056 + Boost Module** | 1 set | Portable 5V power source |

---

## 🧩 Pin Configuration

| Function | ESP32 Pin |
|-----------|------------|
| **Buzzer** | GPIO 14 |
| **LED (Blink)** | GPIO 25 |
| **Start Contact** | GPIO 16 |
| **Middle Wire (Main Path)** | GPIO 17 |
| **End Contact** | GPIO 19 |
| **OLED SDA** | GPIO 21 |
| **OLED SCL** | GPIO 22 |
| **Ring Probe** | GND |
| **Reset Button** | EN ↔ GND |

---

## 🔌 Circuit Overview

- The **Start**, **Middle**, and **End** wires are connected as **INPUT_PULLUP** pins.  
- The **Metal Ring** is connected to **GND**.  
- When the ring touches a wire pad, the circuit completes (logic LOW).  
- The **OLED** connects via **I²C** (SDA = 21, SCL = 22).  
- A push button between **EN** and **GND** resets the ESP32.

---

## 🧾 How It Works

1. **Touch Start Pad** → Timer starts.  
2. **Move Ring Along Path** →  
   - If ring touches wire → Buzzer + LED flash.  
   - Each touch adds to **collision count**.  
3. **Touch End Pad** → Timer stops.  
4. **Result** (Time + Hits) shown on OLED.  
5. **Hold Start Pad (2s)** → Game resets.  

---

## 🛠️ Libraries Required

Install these from **Arduino Library Manager**:

- `Adafruit GFX`
- `Adafruit SH110X`

---

## ⚡ Power Supply Options

- 🔋 3.7V Li-ion (via TP4056 + Boost to 5V)
- 🔌 USB Power (5V)

---

## 🧰 Future Enhancements

- Store best score/time in EEPROM or Flash.
- Add Bluetooth module to send results to mobile app.
- Add difficulty levels (different wire shapes).
- Create 3D printed enclosure for professional look.

---

## 🧑‍💻 Author

**Project:** ESP32 Buzz Wire Game  
**Developer:** Sasidhar Varada.  
**Purpose:** Hand stability tester  for patients.  
**Version:** 1.0  
**Platform:** Arduino IDE with ESP32 Board Package  

---

## 📸 Example Setup (Concept)

