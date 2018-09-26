#include <Servo.h> // import servo library

Servo mainArmLeft; // create servo object to control a servo
Servo mainArmRight;

  // void setup function only runs once
void setup() {
  mainArmLeft.attach(8); // attach servo orange wire to pin 8
  mainArmRight.attach(9); // attach servo orange wire to pin 9

}

  // void loop function runs continuously on a loop
void loop() {
  mainArmLeft.write(0); // set mainArmServo to the 0 position
  mainArmRight.write(180); // set mainArmServo to the 180 position

}