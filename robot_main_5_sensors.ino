/**
 * Autonomous Line Follower Robot (5-Sensor Version)

 * This project implements an autonomous robot capable of following a black line
 * on a white surface using a 5-channel IR sensor array for high-precision navigation.
 * * Hardware:
 * - Arduino Uno R3
 * - L298N Motor Driver
 * - 4x DC Motors (4WD Chassis)
 * - 5-Channel IR Line Tracking Module (e.g., TCRT5000 array)
 * * Author: Idan Vimenetz
 * Year: 2024 */

// --- Pin Definitions ---
// Motor A (Right Side)
const int ENA = 10; // PWM Speed Control
const int IN1 = 9;
const int IN2 = 8;

// Motor B (Left Side)
const int ENB = 5;  // PWM Speed Control
const int IN3 = 7;
const int IN4 = 6;

// 5-Channel IR Sensors
const int SENSOR_FAR_LEFT  = A0;
const int SENSOR_LEFT      = A1;
const int SENSOR_MID       = A2;
const int SENSOR_RIGHT     = A3;
const int SENSOR_FAR_RIGHT = A4;

// --- Speed Constants ---
const int SPEED_FORWARD = 100;    // Base speed
const int SPEED_TURN_SLIGHT = 90; // Gentle turn speed
const int SPEED_TURN_SHARP = 130; // Sharp turn speed

void setup() 
{
// Motor Pins Setup
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

// Sensor Pins Setup (Using Analog pins as Digital Inputs)
  pinMode(SENSOR_FAR_LEFT, INPUT);
  pinMode(SENSOR_LEFT, INPUT);
  pinMode(SENSOR_MID, INPUT);
  pinMode(SENSOR_RIGHT, INPUT);
  pinMode(SENSOR_FAR_RIGHT, INPUT);
  
  Serial.begin(9600); 
}

void loop() 
{
// Read Sensors
// Assumption: 0 (LOW) = Line Detected (Black), 1 (HIGH) = Surface (White)
// If your sensors work the opposite way, add '!' before digitalRead.
  bool fl = !digitalRead(SENSOR_FAR_LEFT); // Far Left
  bool l  = !digitalRead(SENSOR_LEFT);     // Left
  bool m  = !digitalRead(SENSOR_MID);      // Middle
  bool r  = !digitalRead(SENSOR_RIGHT);    // Right
  bool fr = !digitalRead(SENSOR_FAR_RIGHT);// Far Right

// --- Logic Control ---
  
// 1. Center: Go Forward
  if (m == 1 && l == 0 && r == 0) 
  {
    moveRobot(SPEED_FORWARD, SPEED_FORWARD);
  }
  // 2. Slight Left Deviation: Turn Left gently
  else if (l == 1 && m == 0) {
    moveRobot(SPEED_TURN_SLIGHT, SPEED_FORWARD); // Slow down left motor
  }
// 3. Sharp Left Deviation: Turn Left sharply
  else if (fl == 1) 
  {
    moveRobot(0, SPEED_TURN_SHARP); // Stop left motor, boost right
  }
// 4. Slight Right Deviation: Turn Right gently
  else if (r == 1 && m == 0) {
    moveRobot(SPEED_FORWARD, SPEED_TURN_SLIGHT); // Slow down right motor
  }
// 5. Sharp Right Deviation: Turn Right sharply
  else if (fr == 1) {
    moveRobot(SPEED_TURN_SHARP, 0); // Stop right motor, boost left
  }
// 6. Intersection or Stop (All sensors black or all white)
  else if (fl == 0 && l == 0 && m == 0 && r == 0 && fr == 0)
   {
  // Stop if line is lost
    stopRobot();
  }
}

// --- Movement Helper Function ---
// leftSpeed and rightSpeed: 0 to 255
void moveRobot(int leftSpeed, int rightSpeed) 
{
  // Motor A (Right)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, rightSpeed);

  // Motor B (Left)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, leftSpeed);
}

void stopRobot() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}