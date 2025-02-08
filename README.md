# This project aims to blend mechanical engineering principles with programming and electronics to build a robotic arm capable of completing complex tasks autonomously or semi-autonomously. The robotic arm will mimic the functionality of a human arm, with several degrees of freedom provided by multiple joints, enabling it to handle objects with precision and adapt to diverse operational environments.
# Objectives
The primary objective of this project is to develop a robotic arm that:
● Demonstrates accuracy and control in its movements.
● Performs repetitive or complex tasks reliably, with minimal human intervention.
● Can be easily customized and scaled to suit specific applications or modified to add more features, such as sensors or grippers.
● Incorporates programmability and flexibility to allow for various control options, from manual joystick control to automated sequences via programming.

#Technical Specifications

Specification       Value
Total Height        - 400mm
Reach               - 350mm
Base Diameter       - 100mm
Joint Clearance     - 20mm
Material Thickness  - To be specified

Arm Segments:
● Upper Arm Length: 200mm
● Forearm Length: 150mm
● Wrist Gripper Length: 50mm

# System Architecture
The robotic arm system architecture is composed of two primary sections: Power System and Control System.
Power System
  Components:
    ○ 18650 Batteries: Provides power for the entire system.
    ○ Power Switch: Allows control over power flow to the system.
    ○ Voltage Regulator: Stabilizes the voltage supplied to ensure safe operation.
Control System
  Components:
    ○ Arduino UNO: Acts as the main controller, handling commands and sending signals to the servo driver.
    ○ PCA9685 Servo Driver: Enables control of multiple servo motors, facilitating coordinated arm movement.
    ○ Servo Motors:
      ■ Base Servo: Controls the rotation of the base.
      ■ Shoulder Servo: Responsible for the shoulder movement.
      ■ Elbow Servo: Controls the elbow joint for forearm positioning.
      ■ Wrist Pitch and Wrist Roll: Allows wrist rotation and bending.
      ■ Gripper Servo: Enables grasping and releasing of objects.

![alt text](https://github.com/PappyZero/Robotic-Arm/blob/main/Images/'Robotic Arm System Architecture'.png?raw=true)

