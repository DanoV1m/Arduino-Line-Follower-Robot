/**
 * ----------------------------------------------------------------------------
 * Project: Autonomous Line Follower Robot (5-Sensor Array)
 * Author:  Idan Vimenetz
 * Date:    December 2025
 * * Description:
 * This system implements a differential steering algorithm for high-precision 
 * line tracking. It utilizes a prioritized state machine logic to handle 
 * straight lines, slight curves, and sharp 90-degree turns.
 * * Hardware Reference: See HARDWARE_SPECIFICATIONS.md
 * ----------------------------------------------------------------------------
 */

// --- Configuration & Tuning ---
// Set to true to see sensor values in Serial Monitor (slows down robot!)
#define DEBUG_MODE false 

// Motor Speed Settings (PWM: 0-255)
const int SPEED_BASE        = 100; // Normal forward speed
const int SPEED_FAST        = 140; // Boost speed for turns
const int SPEED_SLOW        = 80;  // Slow wheel during gentle turn
const int SPEED_REVERSE     = -120;// Reverse speed for sharp turns (Spin)

// --- Pin Definitions ---
// Motor A (Right)
const int PIN_MotorA_ENA = 10; 
const int PIN_MotorA_IN1 = 9;
const int PIN_MotorA_IN2 = 8;

// Motor B (Left)
const int PIN_MotorB_ENB = 5;  
const int PIN_MotorB_IN3 = 7;
const int PIN_MotorB_IN4 = 6;

// Sensors (From Far Left to Far Right)
const int PIN_SENSOR_FAR_L = A0;
const int PIN_SENSOR_L     = A1;
const int PIN_SENSOR_MID   = A2;
const int PIN_SENSOR_R     = A3;
const int PIN_SENSOR_FAR_R = A4;

void setup() {
  // Motor Pins
  pinMode(PIN_MotorA_ENA, OUTPUT);
  pinMode(PIN_MotorA_IN1, OUTPUT);
  pinMode(PIN_MotorA_IN2, OUTPUT);
  pinMode(PIN_MotorB_ENB, OUTPUT);
  pinMode(PIN_MotorB_IN3, OUTPUT);
  pinMode(PIN_MotorB_IN4, OUTPUT);

  // Sensor Pins
  pinMode(PIN_SENSOR_FAR_L, INPUT);
  pinMode(PIN_SENSOR_L,     INPUT);
  pinMode(PIN_SENSOR_MID,   INPUT);
  pinMode(PIN_SENSOR_R,     INPUT);
  pinMode(PIN_SENSOR_FAR_R, INPUT);
  
  Serial.begin(9600);
  if(DEBUG_MODE) Serial.println("System Initialized - Waiting for line...");
}

void loop() {
  // --- 1. SENSING ---
  // Read sensors. Inverting logic (!) assuming Low (0) is Black Line.
  bool s_far_l = !digitalRead(PIN_SENSOR_FAR_L);
  bool s_l     = !digitalRead(PIN_SENSOR_L);
  bool s_mid   = !digitalRead(PIN_SENSOR_MID);
  bool s_r     = !digitalRead(PIN_SENSOR_R);
  bool s_far_r = !digitalRead(PIN_SENSOR_FAR_R);

  if (DEBUG_MODE) printSensorStatus(s_far_l, s_l, s_mid, s_r, s_far_r);

  // --- 2. DECISION LOGIC (Priority Cascade) ---
  
  // CASE A: Center Aligned (Go Forward)
  if (s_mid && !s_l && !s_r) {
    moveRobot(SPEED_BASE, SPEED_BASE);
  }
  // CASE B: Slight Left Deviation -> Correct Right
  else if (s_l && !s_far_l) {
    moveRobot(SPEED_SLOW, SPEED_FAST); 
  }
  // CASE C: Slight Right Deviation -> Correct Left
  else if (s_r && !s_far_r) {
    moveRobot(SPEED_FAST, SPEED_SLOW);
  }
  // CASE D: Extreme Left (90 degree turn) -> Spin Left
  else if (s_far_l) {
    // Left motor backwards, Right motor fast forward
    moveRobot(SPEED_REVERSE, SPEED_FAST);
  }
  // CASE E: Extreme Right (90 degree turn) -> Spin Right
  else if (s_far_r) {
    // Left motor fast forward, Right motor backwards
    moveRobot(SPEED_FAST, SPEED_REVERSE);
  }
  // CASE F: Line Lost or All White -> Stop (Safety)
  else if (!s_mid && !s_l && !s_r && !s_far_l && !s_far_r) {
    stopRobot();
  }
  // CASE G: All Black (Intersection) -> Go Forward (Optional)
  else {
    moveRobot(SPEED_BASE, SPEED_BASE);
  }
}

// --- 3. ACTUATION (Helper Functions) ---

/**
 * Controls both motors. 
 * Positive speed = Forward, Negative speed = Backward
 * speedLeft: -255 to 255
 * speedRight: -255 to 255
 */
void moveRobot(int speedLeft, int speedRight) {
  controlMotor(speedLeft, PIN_MotorB_IN3, PIN_MotorB_IN4, PIN_MotorB_ENB);
  controlMotor(speedRight, PIN_MotorA_IN1, PIN_MotorA_IN2, PIN_MotorA_ENA);
}

// Low-level motor controller handles direction
void controlMotor(int speed, int pinIn1, int pinIn2, int pinPWM) {
  if (speed > 0) {
    digitalWrite(pinIn1, HIGH);
    digitalWrite(pinIn2, LOW);
    analogWrite(pinPWM, speed);
  } 
  else if (speed < 0) {
    digitalWrite(pinIn1, LOW);
    digitalWrite(pinIn2, HIGH);
    analogWrite(pinPWM, abs(speed)); // Convert -100 to 100 for PWM
  } 
  else {
    digitalWrite(pinIn1, LOW);
    digitalWrite(pinIn2, LOW);
    analogWrite(pinPWM, 0);
  }
}

void stopRobot() {
  moveRobot(0, 0);
}

// Debugging Helper
void printSensorStatus(bool fl, bool l, bool m, bool r, bool fr) {
  Serial.print(fl); Serial.print(" ");
  Serial.print(l);  Serial.print(" ");
  Serial.print(m);  Serial.print(" ");
  Serial.print(r);  Serial.print(" ");
  Serial.println(fr);
}
