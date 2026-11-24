#include "control_logic.h"
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
#define DEBUG_MODE false

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
  
  stopRobot();
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

  const DriveCommand command = decideDrive(s_far_l, s_l, s_mid, s_r, s_far_r);
  moveRobot(command.left, command.right);
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
  speed = constrain(speed, -255, 255);
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
