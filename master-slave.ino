#include <Servo.h>

Servo servo1; // main arm servo left
Servo servo2; // mairn arm servo right
Servo servo3; // rotation servo
Servo servo4; // top arm servo

int potpin3 = 3; // analog pin used to connect the servo1 & 2 potentiometer
int potpin2 = 2; // analog pin used to connect the servo3 potentiometer
int potpin1 = 1; // analog pin used to connect the servo4 potentiometer

int val;  // variable to read the value from the base analog pin
int val1; // variable to read the value from the shoulder analog pin
int val2; // variable to read the value from the elbow analog pin

void setup()
{
    servo1.attach(8);     // servo1 to pin 8 on arduino
    servo2.attach(9); // servo2 to pin 9 on arduino
    servo3.attach(11);    // servo3 to pin 11 on arduino
    servo4.attach(10);  // servo4 to pin 10 on arduino
}

void loop()
{
    val = analogRead(potpin3);       // reads the value of the base potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 179); // scale it to use it with the base servo (value between 0 and 180)
    servo1.write(val);
    servo2.write(180-val);// sets the base servo position according to the scaled value
    delay(15);                       // waits for the base servo to get there

    val1 = analogRead(potpin2);        // reads the value of the shoulder potentiometer (value between 0 and 1023)
    val1 = map(val1, 0, 1023, 0, 179); // scale it to use it with the shoulder servo (value between 0 and 180)
    servo3.write(180-val1);              // sets the shoulder servo position according to the scaled value
    delay(15);                         // waits for the shoulder servo to get there

    val2 = analogRead(potpin1);        // reads the value of the elbow potentiometer (value between 0 and 1023)
    val2 = map(val2, 0, 1023, 0, 179); // scale it to use it with the elbow servo (value between 0 and 180)
    servo4.write(180-val2);                 // sets the elbow servo position according to the scaled value
    delay(15);                         // waits for the elbow servo to get there
}