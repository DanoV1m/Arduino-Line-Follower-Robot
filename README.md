# Autonomous Line Follower Robot 🤖

This project documents an autonomous navigation system built with Arduino. The documentation below covers the complete system design, from hardware specifications to control algorithms.

## 📘 System Design and Architecture
High-level overview of how the hardware and software components interact.

* ➡️ [**View Full System Architecture Document**](./SYSTEM_ARCHITECTURE.md)
* ➡️ [**View Core Control Logic & Algorithms**](./CONTROL_LOGIC.md)

## ⚙️ Hardware and Electronics
Detailed specifications of the physical components and wiring diagrams.

* ➡️ [**View Hardware Specifications & Pinout**](./HARDWARE_SPECIFICATIONS.md)

## 🚀 Getting Started
Instructions for setting up the robot and running the code.

* **Prerequisites:** Arduino IDE, standard USB cable.
* **Installation:** Clone the repo and upload `robot_main_5_sensors.ino`.

---
### 📂 Repository Contents
```mermaid
graph TD
    subgraph Artifacts["Repository Artifacts"]
        Code[robot_main_5_sensors.ino<br>Source Code]
        Docs[README.md<br>Documentation]
        Video[Finale_round.MOV<br>Demo Video]
    end

    subgraph Purpose["System Context"]
        Impl[Implementation<br>5-Sensor Logic]
        Design[Design Specs<br>Architecture]
        Perf[Performance<br>Real-world Test]
    end

    Code -->|Implements| Impl
    Docs -->|Documents| Design
    Video -->|Demonstrates| Perf

    style Artifacts fill:#f9f9f9,stroke:#333,stroke-dasharray: 5 5
This repository is organized as follows:
* `src/` - Main source code files.
* `docs/` - Detailed documentation files (linked above).
* `videos/` - Demonstration footage.

> *Designed and implemented by [Idan Vimenetz]*

