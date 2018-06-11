#include <Servo.h>
Servo servo1;  // create servo object to control a servo
Servo servo2;


void setup() {
  servo1.attach(8); //attach servo orange wire to pin 8
  servo2.attach(9); //attach servo orange wire to pin 9

}

void loop() {
  servo1.write(0);
  servo2.write(180);

}