| Component            | ESP32 Pin    | Description                   |
| -------------------- | ------------ | ----------------------------- |
| **Buzzer (+)**       | GPIO 14      | Sounds when collision happens |
| **Buzzer (–)**       | GND          | Common ground                 |
| **LED (+)**          | GPIO 25      | Blinks on collision           |
| **LED (–)**          | GND          | Common ground                 |
| **Start Wire Pad**   | GPIO 16      | Begins timer when touched     |
| **Middle Path Wire** | GPIO 17      | Detects collisions            |
| **End Wire Pad**     | GPIO 19      | Stops timer                   |
| **Ring Probe**       | GND          | Connected to copper ring      |
| **OLED (VCC)**       | 3.3 V        | Power                         |
| **OLED (GND)**       | GND          | Ground                        |
| **OLED (SDA/SCL)**   | GPIO 21 / 22 | I²C interface                 |
| **Reset Button**     | EN → GND     | Hardware reset shortcut       |
