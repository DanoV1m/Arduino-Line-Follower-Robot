#pragma once
#include "control_logic.h"

class LinePid {
  float kp, ki, kd, integral = 0, previous = 0;
  bool ready = false;
  static float clamp(float x, float low, float high) {
    return x < low ? low : (x > high ? high : x);
  }
public:
  LinePid(float p, float i, float d): kp(p), ki(i), kd(d) {}
  void reset() { integral = 0; previous = 0; ready = false; }
  DriveCommand update(bool fl, bool l, bool m, bool r, bool fr, float dt) {
    int count = fl + l + m + r + fr;
    if (!count || !(dt > 0 && dt <= 0.2f)) { reset(); return {0,0}; }
    if (count == 5) { reset(); return {100,100}; }
    // A symmetric pattern without a center signal is ambiguous.
    if (!m && fl == fr && l == r) { reset(); return {0,0}; }
    float error = (-2.0f*fl-l+r+2.0f*fr)/count;
    float derivative = ready ? (error-previous)/dt : 0;
    float candidate = clamp(integral+error*dt,-10,10);
    float raw = kp*error+ki*candidate+kd*derivative;
    // Conditional integration prevents windup under output saturation.
    if ((raw >= -100 && raw <= 100) || (raw > 100 && error < 0) || (raw < -100 && error > 0))
      integral = candidate;
    float correction = clamp(kp*error+ki*integral+kd*derivative,-100,100);
    previous = error; ready = true;
    return {static_cast<int>(100+correction),static_cast<int>(100-correction)};
  }
};
