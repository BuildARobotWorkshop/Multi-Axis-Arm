#include <Servo.h> //include the servo library
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;

void setup() {
  myservo1.attach(8);//Main arm servo left
  myservo2.attach(9);//Main arm servo right
  myservo3.attach(11);//Rotation Servo
  myservo4.attach(10);//Top Arm servo
}

void loop() {
  //place your servo commands and delays here
  //myservo#.write(servo position)
}