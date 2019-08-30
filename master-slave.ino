/* Multi-Axis Arm Master Slave control
This sketch allows the builders to control the multi-axis arm via the master controller.
Author: Paul Qua
Updated: August 30, 2019
*/

#include <Servo.h> // import servo library

Servo mainArmLeft; // main arm servo left
Servo mainArmRight; // main arm servo right
Servo topArm; // top arm servo
Servo swivel; // swivel servo

int topArmAnalog = 1; // analog pin used to connect the topArm potentiometer
int swivelAnalog = 2; // analog pin used to connect the swivel potentiometer
int mainArmAnalog = 3; // analog pin used to connect the main arm potentiometer

  // pot is short for potentiometer
int topArmValue; // variable to store the value from the top arm potentiometer
int swivelValue; // variable to store the value from the swivel potentiometer
int mainArmValue; // variable to store the value from the main arm potentiometer




void setup()
{
    mainArmLeft.attach(7); // connect mainArmLeft servo to pin 7 on arduino
    mainArmRight.attach(8); // connect mainArmRight servo to pin 8 on arduino
    topArm.attach(9); // connect topArmServo to pin 9 on arduino
    swivel.attach(10); // connect swivel servo to pin 10 on arduino


}

void loop()
{
    mainArmValue = analogRead(mainArmAnalog); // reads the analog value of the main arm potentiometer (value between 0 and 1023)
    mainArmValue = map(mainArmValue, 0, 1023, 0, 180); // convert, scale analog value to digital servo value for main arm servos (value between 0 and 180)
    mainArmLeft.write(mainArmValue); // sets the mainArmLeft servo position according to the converted, scaled value
    mainArmRight.write(180-mainArmValue); // reverses mainArmRight servo
    delay(15); // waits for the main arm servos to get to position

    swivelValue = analogRead(swivelAnalog); // reads the analog value of the swivel potentiometer (value between 0 and 1023)
    swivelValue = map(swivelValue, 0, 1023, 0, 180); // convert, scale analog value to digital servo value for swivel servo (value between 0 and 180)
    swivel.write(swivelValue); // sets the swivel servo position according to the converted, scaled value
    delay(15); // waits for the swivel servo to get to position

    topArmValue = analogRead(topArmAnalog); // reads the analog value of the topArm potentiometer (value between 0 and 1023)
    topArmValue = map(topArmValue, 0, 1023, 0, 180); // convert, scale analog value to digital servo value for topArm servo (value between 0 and 180)
    topArm.write(topArmValue); // sets the topArm servo position according to the converted, scaled value
    delay(15); // waits for the topArm servo to get to position
}
