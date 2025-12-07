<div align="center">

# 🤖 Autonomous Line Follower Robot

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B)
![Platform](https://img.shields.io/badge/Platform-Arduino_Uno-00979D?style=for-the-badge&logo=arduino)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

<p align="center">
  <strong>A high-precision autonomous navigation system using 5-channel IR sensing and differential steering logic.</strong>
</p>

</div>

---

## 📚 Documentation Hub
Explore the detailed engineering documentation:

| 📘 Architecture & Logic | ⚙️ Hardware & Specs |
| :--- | :--- |
| ➡️ [**System Architecture Overview**](./SYSTEM_ARCHITECTURE.md)<br>_High-level diagrams, HW/SW breakdown_ | ➡️ [**Hardware Specifications**](./HARDWARE_SPECIFICATIONS.md)<br>_Pinout, components, and wiring_ |
| ➡️ [**Control Logic & Algorithms**](./CONTROL_LOGIC.md)<br>_Decision states, state machine, and flow_ | 📄 [**Source Code**](./robot_main_5_sensors.ino)<br>_Main Arduino implementation_ |

---

## ⚡ Key Capabilities
* **Precision Sensing:** 5-channel TCRT5000 IR array for granular line position detection.
* **Smart Navigation:** Differential steering logic handling straight paths, curves, and 90° turns.
* ** robust Control:** Prioritized state machine preventing sensor conflict.
* **Power Management:** Split 7.4V distribution for high-current motors and sensitive logic.

---

## 🚀 Getting Started
1.  **Prerequisites:** Arduino IDE, Standard USB Cable (Type-B).
2.  **Setup:** Clone this repo and open `robot_main_5_sensors.ino`.
3.  **Upload:** Connect Arduino Uno and upload the sketch.
4.  **Run:** Place robot on a black-line track and power on.
5.  
---

# Repository Structure

![Repository Structure](./repo_structure.png)

---

## 📸 Project Gallery

### 1. Lab Testing Environment
Testing signal integrity using an oscilloscope during development.
![Lab Test](./assets/lab_test.jpg)

### 2. Top View - Wiring & Components
Complete assembly showing cable management and component placement.
![Top View](./assets/top_view.jpg)

### 3. Side View - Power & Chassis
Side profile showing the double-deck chassis and battery placement.
![Side View](./assets/side_view.jpg)

## 🔮 Future Roadmap (PID Control)

While the current system uses specific logic states, the next engineering step is implementing **PID Control** (Proportional-Integral-Derivative):

* **Proportional (P):** Steer harder as the error increases.
* **Integral (I):** Correct accumulated errors over time.
* **Derivative (D):** Predict future errors based on rate of change to reduce oscillation.
  
This repository is organized as follows:
 *  `src/` - Main source code files.
 *  `docs/` - Detailed documentation files (linked above).
 *  `videos/` - Demonstration footage.

*Designed and implemented by [Idan Vimenetz]*











