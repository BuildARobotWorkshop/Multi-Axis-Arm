#include <Servo.h> //include the servo library
Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(8);//Main arm servo left
  servo2.attach(9);//Main arm servo right
  servo3.attach(11);//Rotation Servo
  servo4.attach(10);//Top Arm servo
}

void loop() {
  //place your servo commands and delays here
  //servo#.write(servo position)
}