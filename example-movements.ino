/*
  Multi-Axis Arm Basic Movements
  Sketch used to move the robot on level 1 after completion of robot
  Created by: Paul Qua
  Last modified: 8-18-19
*/

#include <Servo.h> //include servo library
Servo servo1;  // create servo objects to control servos
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(7); //Main arm servo left
  servo2.attach(8); //Main arm servo right
  servo3.attach(9); //Top arm servo
  servo4.attach(10); //Swivel servo
}

void loop() {

  servo1.write(90);
  servo2.write(180-90);
  servo3.write(5);
  servo4.write(90);
  delay(1000);
  servo1.write(10);
  servo2.write(180-10);
  servo3.write(80);
  delay(1000);
  servo1.write(90);
  servo2.write(180-90);
  servo3.write(5);
  servo4.write(90);
  delay(1000);
  servo4.write(0);
  delay(1500);
  servo1.write(10);
  servo2.write(180-10);
  servo3.write(80);
  delay(1000);
  servo1.write(90);
  servo2.write(180-90);
  servo3.write(5);
  delay(1000);
  servo4.write(180);
  delay(1500);
  servo1.write(10);
  servo2.write(180-10);
  servo3.write(80);
  delay(1000);
}
