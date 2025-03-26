Garbage Collector Robot

Project Overview

This project is a Garbage Collector Robot that moves in all directions using four gear motors and picks up objects using a robotic hand with three servo motors. The robot is controlled via the Blynk IoT app, enabling remote operation for efficient waste collection.

Hardware Components Used

ESP32 - Microcontroller for control and communication.

4 Gear Motors - For omnidirectional movement.

L298N Motor Driver - To control the motors.

3 Servo Motors - For robotic hand movement and gripper control.

Gripper - To pick and drop objects.

Battery (LiPo or 12V) - Power source.

Jumper Wires - For circuit connections.

Software Dependencies

Ensure the following libraries are installed in your Arduino IDE:

ESP32 Board Package (for programming ESP32)

Blynk Library (for IoT control)

Servo Library (to control servo motors)

How to Set Up and Run the Project

1. Install Required Libraries

Open Arduino IDE

Go to Library Manager and install:

Blynk

Servo

WiFi (pre-installed in ESP32 board package)

2. Hardware Setup

Connect ESP32 to Motor Driver for motor control.

Connect Gear Motors to motor driver outputs.

Connect Servo Motors to ESP32 PWM pins.

Connect Gripper to one of the servo motors.

Power the circuit with an appropriate LiPo battery.

3. Blynk App Configuration

Download Blynk App (iOS/Android)

Create a new project and select ESP32

Add buttons/sliders for motor and servo control

Copy Auth Token from the app

4. Upload Code to ESP32

Replace placeholders in the code:

YOUR_WIFI_SSID

YOUR_WIFI_PASSWORD

YOUR_BLYNK_AUTH_TOKEN

Compile and upload the code using Arduino IDE.

5. Control the Robot

Open the Blynk App

Use buttons/sliders to move the robot and control the gripper.

Future Improvements

Implement AI-based object detection for automation.

Add Ultrasonic Sensors for obstacle avoidance.

Improve battery efficiency for longer operation.

Contribution

Feel free to contribute to this project! Fork the repository, make improvements, and submit a pull request.

License

This project is open-source and available under the MIT License.
