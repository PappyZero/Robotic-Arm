#include <Servo.h>

// L298N control pins
#define ENA 10
#define ENB 11
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// Create servo objects
Servo servos[6];  // Array to hold all servos

void setup() {
  Serial.begin(9600);
  
  // Setup L298N pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Attach servos to L298N outputs
  servos[0].attach(IN1);  // Base
  servos[1].attach(IN2);  // Shoulder
  servos[2].attach(IN3);  // Elbow
  servos[3].attach(IN4);  // Wrist Pitch
  servos[4].attach(ENA);  // Wrist Roll
  servos[5].attach(ENB);  // Gripper
  
  // Enable L298N outputs
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  // Initialize all servos to middle position
  for(int i = 0; i < 6; i++) {
    servos[i].write(90);
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
      servos[servo].write(angle);
    }
  }
}

// Example movement sequence
void demoSequence() {
  // Base movement
  servos[0].write(45);
  delay(1000);
  
  // Shoulder and elbow coordinated movement
  servos[1].write(120);
  servos[2].write(60);
  delay(1000);
  
  // Wrist adjustments
  servos[3].write(90);
  servos[4].write(90);
  delay(500);
  
  // Gripper operation
  servos[5].write(180); // Open
  delay(500);
  servos[5].write(0);   // Close
  delay(500);
}