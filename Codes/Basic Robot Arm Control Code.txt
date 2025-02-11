#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Initialize servo driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define servo channels
#define BASE_SERVO 0
#define SHOULDER_SERVO 1
#define ELBOW_SERVO 2
#define WRIST_PITCH 3
#define WRIST_ROLL 4
#define GRIPPER 5

// Servo pulse lengths
#define SERVOMIN 150  // Minimum pulse length count (out of 4096)
#define SERVOMAX 600  // Maximum pulse length count (out of 4096)

// Current positions
int currentPositions[] = {90, 90, 90, 90, 90, 90};

void setup() {
  Serial.begin(9600);
  
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  
  // Initialize all servos to middle position
  for(int i = 0; i < 6; i++) {
    setServoAngle(i, 90);
    delay(100);
  }
}

void loop() {
  if (Serial.available() > 0) {
    // Format: "servo_number angle"
    String input = Serial.readStringUntil('\n');
    int servo = input.substring(0, input.indexOf(' ')).toInt();
    int angle = input.substring(input.indexOf(' ') + 1).toInt();
    
    if (servo >= 0 && servo < 6 && angle >= 0 && angle <= 180) {
      setServoAngle(servo, angle);
      currentPositions[servo] = angle;
    }
  }
}

void setServoAngle(uint8_t servoNum, int angle) {
  // Convert angle (0-180) to pulse length
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoNum, 0, pulse);
}

// Example movement sequence
void demoSequence() {
  // Base movement
  setServoAngle(BASE_SERVO, 45);
  delay(1000);
  
  // Shoulder and elbow coordinated movement
  setServoAngle(SHOULDER_SERVO, 120);
  setServoAngle(ELBOW_SERVO, 60);
  delay(1000);
  
  // Wrist adjustments
  setServoAngle(WRIST_PITCH, 90);
  setServoAngle(WRIST_ROLL, 90);
  delay(500);
  
  // Gripper operation
  setServoAngle(GRIPPER, 180); // Open
  delay(500);
  setServoAngle(GRIPPER, 0);   // Close
  delay(500);
}