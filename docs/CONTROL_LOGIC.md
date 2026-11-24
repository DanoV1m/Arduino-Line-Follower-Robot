# Control logic

Five active-low sensors feed a host-testable decision function. All-white stops, all-black continues straight, symmetric ambiguous patterns without center stop. Single-sided outer detections have priority. Motor commands mirror left to right and are constrained to PWM range.

Run the host regression:
```sh
g++ -std=c++11 -Wall -Wextra -Werror tests/control_logic_test.cpp -o /tmp/robot-test
/tmp/robot-test
```

PID is a future experimental mode. Validate wiring and motor polarity with wheels lifted and measure repeated runs before enabling new control modes. Physical behavior is not yet verified.
