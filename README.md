# Autonomous Line Follower Robot 🤖

An Arduino-based autonomous robot designed to navigate a predefined track by detecting contrast distinctions (black line on white surface). Developed as a first-year engineering project.

## 🛠 Hardware Architecture

The robot is built on a 4WD chassis and utilizes the following components:
* **Microcontroller:** Arduino Uno R3
* **Motor Driver:** L298N Dual H-Bridge
* **Sensors:** 3-Channel IR Line Tracking Module (TCRT5000 based)
* **Actuators:** 4x DC Gear Motors (Yellow)
* **Power:** 2x 18650 Li-ion Batteries (7.4V)

## ⚙️ How It Works

1.  **Sensing:** The infrared sensors continuously emit IR light and measure the reflection. Black surfaces absorb light (Low reflection), while white surfaces reflect it (High reflection).
2.  **Processing:** The Arduino processes the boolean signals from the 3 sensors (Left, Center, Right) in real-time.
3.  **Actuation:** A control algorithm adjusts the motor speeds and direction to keep the center sensor aligned with the line.
    * *Center detected:* Move Forward.
    * *Left detected:* Correct trajectory to the Left.
    * *Right detected:* Correct trajectory to the Right.

## 🔌 Wiring Pinout

| Component | Arduino Pin |
|-----------|-------------|
| Motor A (Right) Enable | 10 |
| Motor A In1 | 9 |
| Motor A In2 | 8 |
| Motor B (Left) Enable | 5 |
| Motor B In3 | 7 |
| Motor B In4 | 6 |
| Left Sensor | A0 |
| Center Sensor | A1 |
| Right Sensor | A2 |

## 🚀 Future Improvements

* Integration of PID control for smoother navigation.
* Adding ultrasonic sensors for obstacle avoidance.
* Bluetooth module for manual override control.