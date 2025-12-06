# Core Control Logic & Algorithms

## 🧠 Decision States
The robot uses a priority-based logic system to determine movement based on 5 sensor inputs.

| Sensor Pattern | State Detected | Action Taken | Motor Speed (L/R) |
|----------------|----------------|--------------|-------------------|
| `0 0 1 0 0`    | Center Aligned | Move Forward | 100 / 100         |
| `0 1 0 0 0`    | Small Deviation| Turn Right   | 120 / 80          |
| `1 0 0 0 0`    | Sharp Turn     | Spin Right   | 150 / -150        |
| `0 0 0 1 0`    | Small Deviation| Turn Left    | 80 / 120          |
| `0 0 0 0 1`    | Sharp Turn     | Spin Left    | -150 / 150        |
| `0 0 0 0 0`    | Line Lost      | Stop         | 0 / 0             |

## ⚙️ Key Algorithms
1. **Differential Steering:** Turning is achieved by varying the speed difference between left and right motors.
2. **Error Correction:** The system calculates deviation from the center line and applies proportional correction.
3. **Priority Cascade:** The logic checks for center alignment first, then slight deviations, then extreme deviations.
---
## 💡 Key Design Principles
This system demonstrates several core engineering concepts:

### 1. Differential Steering
Instead of a mechanical steering rack, the robot turns by independently controlling the speed of the left and right motor pairs.
* **Benefit:** Simpler mechanical design and zero-radius turning capability.

### 2. Graduated Response (Non-Binary Control)
Unlike simple on/off logic, the system implements three correction levels:
* **Straight:** Equal high speed (`100`/`100`).
* **Gentle Correction:** 10-20% differential for small deviations.
* **Sharp Correction:** Maximum differential (one motor forward, one backward) for 90° turns.

### 3. Priority Cascade
The decision logic evaluates conditions in a specific order. Center alignment is checked first, followed by slight deviations, and finally extreme deviations. This prevents conflicting actions when multiple sensors trigger simultaneously.
