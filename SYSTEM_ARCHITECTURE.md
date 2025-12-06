# System Architecture Overview

This document details the high-level architecture of the Autonomous Line Follower.

## 🛠 Hardware Architecture
The system is built on a layered architecture separating power, control, and actuation. 

```mermaid
graph TD
    Power[Power Subsystem<br>7.4V Battery] -->|Regulated 5V| MCU[Arduino Uno]
    Power -->|Direct 7.4V| Driver[L298N Driver]
    MCU -->|PWM Signals| Driver
    Driver -->|Current| Motors[DC Motors]
    Sensors[IR Sensor Array] -->|Digital Input| MCU
