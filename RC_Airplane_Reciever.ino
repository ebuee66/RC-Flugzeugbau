#include <Servo.h>

// Using Hardware Serial (Pins 0 and 1)

Servo kvMotor;
Servo leftServo;
Servo rightServo;

const int pinKV = 9;    // ESC Signal Pin
const int pinLeft = 5;  // Left Wing Servo
const int pinRight = 6; // Right Wing Servo

// Variables for Data Parsing
String incomingData = "";
bool startDetected = false;
bool dataComplete = false;

// Variables for Anti-Jitter Filter
int oldLeftAngle = 90;
int oldRightAngle = 90;

void setup() {
  // Initialize Serial at 9600 baud
  Serial.begin(9600);

  kvMotor.attach(pinKV);
  leftServo.attach(pinLeft);
  rightServo.attach(pinRight);

  // ESC INITIALIZATION (Safety Boot)
  kvMotor.writeMicroseconds(1000); 
  delay(3000); // Wait 3 seconds for ESC to arm
}

void loop() {
  // Check Serial Buffer
  while (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '<') {
      startDetected = true;
      incomingData = ""; 
    } 
    else if (c == '>') {
      startDetected = false;
      dataComplete = true; 
    } 
    else if (startDetected) {
      incomingData += c;
    }
  }

  // Process Completed Packet
  if (dataComplete) {
    int v1 = incomingData.indexOf(',');
    int v2 = incomingData.indexOf(',', v1 + 1);

    if (v1 > 0 && v2 > 0) {
      int throttle = incomingData.substring(0, v1).toInt();
      int pitch = incomingData.substring(v1 + 1, v2).toInt();
      int roll = incomingData.substring(v2 + 1).toInt();

      // 1. Control Brushless Motor
      kvMotor.writeMicroseconds(throttle);

      // 2. Elevon Mixing Algorithm
      int p = pitch - 90; // Pitch Deviation
      int r = roll - 90;  // Roll Deviation

      int targetLeft = 90 + p + r;
      int targetRight = 90 + p - r;

      // Constrain within physical limits
      targetLeft = constrain(targetLeft, 0, 180);
      targetRight = constrain(targetRight, 0, 180);

      // 3. Anti-Jitter Filter (Threshold: 2 degrees)
      if (abs(targetLeft - oldLeftAngle) > 2) {
        leftServo.write(targetLeft);
        oldLeftAngle = targetLeft;
      }
      if (abs(targetRight - oldRightAngle) > 2) {
        rightServo.write(targetRight);
        oldRightAngle = targetRight;
      }
    }
    dataComplete = false;
    incomingData = ""; 
  }
}
