/*
Zero Arm servos
This sketch is used to zero out the servos for the main arm and the grapple
attachment. One side will go to the zero position and the other will go to the
180 position.
Author: Paul Qua
Updated: August 29, 2019
*/

#include <Servo.h> // import servo library

Servo part7Servo; //Left side servo connected to part 7
Servo part8Servo; //Right side servo connected to part8

void setup() {
  part7Servo.attach(8); // attach servo orange wire to pin 8
  part8Servo.attach(9); // attach servo orange wire to pin 9

}

void loop() {
  part7Servo.write(0); // set servo to the 0 position
  part8Servo.write(180); // set servo to the 180 position

}
