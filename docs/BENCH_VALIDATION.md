# Bench validation and PID calibration

**Status:** physical testing not performed. The firmware pin table is code-derived, not a verified physical wiring diagram. Keep the experimental PID disabled until the following checks pass.

1. With battery and motor power disconnected, compare every connection to the code pin table; verify the board, driver, motor voltage ratings and common-ground scheme. Do not feed 5 V into Vin or connect conflicting power sources.
2. Power logic only. Check sensor order and polarity on white and black surfaces using DEBUG_MODE; record each of the five readings.
3. With wheels lifted and a current-limited suitable motor supply, verify emergency power cutoff, forward motor polarity, stop and left/right commands. Stop if unexpected behavior or heating occurs.
4. Use the existing state-machine mode on a short clear track. Record line losses, completion time, and trial conditions.
5. Enable experimental PID only after confirming the above. Begin at reduced base speed with integral and derivative gains zero; increase proportional gain gradually, then evaluate small derivative and integral adjustments independently. Stop on oscillation, line loss or motor overheating.
6. Compare at least five repeated runs per configuration on the same track. Record mean and variability without claiming improvement until measured.

| Trial | Mode | Kp | Ki | Kd | Sample period | Completion time | Line losses | Notes |
|---|---|---|---|---|---|---|---|---|
| 1 | | | | | | | | |

The nominal sample period is 20 ms minimum; measure actual intervals before reporting a control frequency. A digital five-sensor array gives discrete position estimates, not a calibrated continuous position.
