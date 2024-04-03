#include <AFMotor.h>
#include <Servo.h>
#define motor 10
#define Speed 170
#define spoint 103
char value;
int distance;
int Left;
int Right;
int L = 0;
int R = 0;
int L1 = 0;
int R1 = 0;
Servo servo;
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);
void setup() {
 Serial.begin(9600);
 servo.attach(motor);
 M1.setSpeed(Speed);
 M2.setSpeed(Speed);
 M3.setSpeed(Speed);
 M4.setSpeed(Speed);
}
void loop() {
 Bluetoothcontrol();
}
void Bluetoothcontrol() {
 if (Serial.available() > 0) {
 value = Serial.read();e
 Serial.println(value);
 }
 if (value == 'F') {
 forward();
 } else if (value == 'B') {
 backward();
 } else if (value == 'L') {
 left();
 } else if (value == 'R') {
 right();
 } else if (value == 'S') {
 Stop();
 }
}
void forward() {
M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
}
void backward() {
 M1.run(BACKWARD);
 M2.run(BACKWARD);
 M3.run(BACKWARD);
 M4.run(BACKWARD);
}
void right() {
 M1.run(BACKWARD);
 M2.run(BACKWARD);
 M3.run(FORWARD);
 M4.run(FORWARD);
}
void left() {
M1.run(FORWARD);
 M2.run(FORWARD);
 M3.run(BACKWARD);
 M4.run(BACKWARD);
}
void Stop() {
 M1.run(RELEASE);
 M2.run(RELEASE);
 M3.run(RELEASE);
 M4.run(RELEASE);
}

