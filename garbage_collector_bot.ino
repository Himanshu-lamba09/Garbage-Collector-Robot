#include <Servo.h>
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "YOUR_DEVICE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

// WiFi credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// Motor driver pins
#define MOTOR1_FORWARD  5
#define MOTOR1_BACKWARD 18
#define MOTOR2_FORWARD  19
#define MOTOR2_BACKWARD 21
#define MOTOR3_FORWARD  22
#define MOTOR3_BACKWARD 23
#define MOTOR4_FORWARD  25
#define MOTOR4_BACKWARD 26

// Servo motors for robotic hand and gripper
Servo servo1, servo2, servo3; // Three servos including gripper

void setup() {
    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    
    // Configure motor pins as outputs
    pinMode(MOTOR1_FORWARD, OUTPUT);
    pinMode(MOTOR1_BACKWARD, OUTPUT);
    pinMode(MOTOR2_FORWARD, OUTPUT);
    pinMode(MOTOR2_BACKWARD, OUTPUT);
    pinMode(MOTOR3_FORWARD, OUTPUT);
    pinMode(MOTOR3_BACKWARD, OUTPUT);
    pinMode(MOTOR4_FORWARD, OUTPUT);
    pinMode(MOTOR4_BACKWARD, OUTPUT);

    // Attach servos to their respective pins
    servo1.attach(14);
    servo2.attach(27);
    servo3.attach(32); // Gripper servo
}

// Blynk virtual pins for movement
BLYNK_WRITE(V1) { moveForward(); }
BLYNK_WRITE(V2) { moveBackward(); }
BLYNK_WRITE(V3) { moveLeft(); }
BLYNK_WRITE(V4) { moveRight(); }
BLYNK_WRITE(V5) { stopMovement(); }

// Blynk virtual pins for servo movement (0 to 180 degrees)
BLYNK_WRITE(V6) { servo1.write(constrain(param.asInt(), 0, 180)); }
BLYNK_WRITE(V7) { servo2.write(constrain(param.asInt(), 0, 180)); }
BLYNK_WRITE(V8) { servo3.write(constrain(param.asInt(), 0, 180)); } // Gripper control

// Movement functions
void moveForward() {
    digitalWrite(MOTOR1_FORWARD, HIGH);
    digitalWrite(MOTOR2_FORWARD, HIGH);
    digitalWrite(MOTOR3_FORWARD, HIGH);
    digitalWrite(MOTOR4_FORWARD, HIGH);
}

void moveBackward() {
    digitalWrite(MOTOR1_BACKWARD, HIGH);
    digitalWrite(MOTOR2_BACKWARD, HIGH);
    digitalWrite(MOTOR3_BACKWARD, HIGH);
    digitalWrite(MOTOR4_BACKWARD, HIGH);
}

void moveLeft() {
    digitalWrite(MOTOR1_BACKWARD, HIGH);
    digitalWrite(MOTOR2_FORWARD, HIGH);
    digitalWrite(MOTOR3_FORWARD, HIGH);
    digitalWrite(MOTOR4_BACKWARD, HIGH);
}

void moveRight() {
    digitalWrite(MOTOR1_FORWARD, HIGH);
    digitalWrite(MOTOR2_BACKWARD, HIGH);
    digitalWrite(MOTOR3_BACKWARD, HIGH);
    digitalWrite(MOTOR4_FORWARD, HIGH);
}

void stopMovement() {
    digitalWrite(MOTOR1_FORWARD, LOW);
    digitalWrite(MOTOR1_BACKWARD, LOW);
    digitalWrite(MOTOR2_FORWARD, LOW);
    digitalWrite(MOTOR2_BACKWARD, LOW);
    digitalWrite(MOTOR3_FORWARD, LOW);
    digitalWrite(MOTOR3_BACKWARD, LOW);
    digitalWrite(MOTOR4_FORWARD, LOW);
    digitalWrite(MOTOR4_BACKWARD, LOW);
}

void loop() {
    Blynk.run();
}
