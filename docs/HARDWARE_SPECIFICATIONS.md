# Hardware Specifications & Pinout

## 🔌 Wiring & Connections Overview
The following diagram illustrates the high-level wiring between the Power Unit, MCU, Motor Driver, and Sensors.

Historical diagram omitted because it has not been reconciled with the code. Verify physical wiring against the code-derived table below before connecting hardware.

## 🛠 Component List
| Component | Model/Specs | Quantity | Function |
|-----------|-------------|:--------:|----------|
| **MCU** | Arduino Uno R3 | 1 | Main processing unit |
| **Driver** | L298N Dual H-Bridge | 1 | Controls motor direction & speed |
| **Motors** | DC Gearbox Motor (TT) | 2 | Drive system (3-6V) |
| **Sensors** | TCRT5000 5-CH Array | 1 | Line detection (IR reflection) |
| **Power** | 7.4V Li-ion (18650 x2) | 1 | Main power source |
| **Chassis** | Acrylic 2WD Platform | 1 | Structural base |

## 📌 Pinout Configuration (Arduino Mapping)
This mapping defines how the code interacts with the physical hardware.

### Motor Driver (L298N)
| Arduino Pin | L298N Pin | Function |
|:-----------:|:---------:|----------|
| `10` | ENA | PWM Speed Control (Right) |
| `5` | ENB | PWM Speed Control (Left) |
| `9` | IN1 | Right Motor Direction A |
| `8` | IN2 | Right Motor Direction B |
| `7` | IN3 | Left Motor Direction A |
| `6` | IN4 | Left Motor Direction B |

### Sensor Array (Left to Right)
| Arduino Pin | Sensor Position | Variable Name |
|:-----------:|:---------------:|---------------|
| `A0` | Far Left | `s_far_l` |
| `A1` | Near Left | `s_l` |
| `A2` | Center | `s_mid` |
| `A3` | Near Right | `s_r` |
| `A4` | Far Right | `s_far_r` |

## 🔋 Power Management
* **Voltage Regulation:** Do not feed a 5 V output into Vin. Verify regulator mode, battery and motor ratings and the correct Arduino supply connection before applying power. Use USB for initial logic-only testing with motor power disconnected; verify common ground and wiring before enabling motors.
* **Safety:** A master switch is installed between the battery positive terminal and the driver input.
