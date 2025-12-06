# Hardware Specifications & Pinout

## 🔌 Pin Configuration Reference
Quick reference for hardware connections based on `robot_main_5_sensors.ino`.

| Component | Arduino Pin | Variable Name | Function |
|-----------|-------------|---------------|----------|
| Left Sensor| A0 | `SENS_L` | Input |
| Center Sensor| A1 | `SENS_MID` | Input |
| Right Sensor| A2 | `SENS_R` | Input |
| Far Left Sensor| A3 | `SENS_FAR_L`| Input |
| Far Right Sensor| A4 | `SENS_FAR_R`| Input |
| **Motor A Enable**| 10 | `ENA` | PWM Speed Control |
| **Motor A In1** | 9 | `IN1` | Direction Control |
| **Motor A In2** | 8 | `IN2` | Direction Control |

## 🛠️ Component List
* **MCU:** Arduino Uno R3 (ATmega328P)
* **Sensors:** 5x TCRT5000 IR Modules
* **Motors:** 4x Yellow DC Gear Motors (1:48 ratio)
* **Driver:** L298N Dual H-Bridge Motor Driver
* **Power:** 2x 18650 Li-ion Batteries (7.4V)
