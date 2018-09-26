#include <Servo.h> // import servo library

Servo mainArmLeft; // main arm servo left
Servo mainArmRight; // main arm servo right
Servo topArm; // top arm servo
Servo rotation; // rotation servo or base servo

int analogPin3 = 3; // analog pin used to connect the main arm potentiometer
int analogPin2 = 2; // analog pin used to connect the rotation potentiometer
int analogPin1 = 1; // analog pin used to connect the topArm potentiometer

  // pot is short for potentiometer
int potValue3; // variable to store the value from the main arm potentiometer
int potValue2; // variable to store the value from the rotation potentiometer
int potValue1; // variable to store the value from the top arm potentiometer


void setup()
{
    mainArmLeft.attach(8); // connect mainArmLeft servo to pin 8 on arduino
    mainArmRight.attach(9); // connect mainArmRight servo to pin 9 on arduino
    topArm.attach(10); // connect topArmServo to pin 10 on arduino
    rotation.attach(11); // connect rotation servo to pin 11 on arduino


}

void loop()
{
    potValue3 = analogRead(analogPin3); // reads the analog value of the main arm potentiometer (value between 0 and 1023)
    potValue3 = map(potValue3, 0, 1023, 0, 180); // convert, scale anaolog value to digital servo value for main arm servos (value between 0 and 180)
    mainArmLeft.write(potValue3); // sets the mainArmLeft servo position according to the converted, scaled value
    mainArmRight.write(180-potValue3); // reverses mainArmRight servo
    delay(15); // waits for the main arm servos to get to position

    potValue2 = analogRead(analogPin2); // reads the analog value of the rotation potentiometer (value between 0 and 1023)
    potValue2 = map(potValue2, 0, 1023, 0, 180); // convert, scale anaolog value to digital servo value for rotation servo (value between 0 and 180)
    rotation.write(potValue2); // sets the rotation servo position according to the converted, scaled value
    delay(15); // waits for the rotation servo to get to position

    potValue1 = analogRead(analogPin1); // reads the analog value of the topArm potentiometer (value between 0 and 1023)
    potValue1 = map(potValue1, 0, 1023, 0, 180); // convert, scale anaolog value to digital servo value for topArm servo (value between 0 and 180)
    topArm.write(potValue1); // sets the topArm servo position according to the converted, scaled value
    delay(15); // waits for the topArm servo to get to position
}