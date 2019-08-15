/*
  Multi-Axis Arm Serial Command Sketch
  Sketch used to move servos on the Multi-Axis Arm Robot to a specific locations
  Created by: Paul Qua
  Last modified: 8-15-19
*/

String readString;
#include <Servo.h> //include servo library
Servo servo1;  // create servo objects to control servos
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(9600); //set servo baud rate in the to 9600
  servo1.attach(7); //Main arm servo left
  servo2.attach(8); //Main arm servo right
  servo3.attach(9); //Top arm servo
  servo4.attach(10); //Swivel servo
  Serial.println("Serial successfully connected!"); //serial successfully connected alert
  Serial.println("Enter a number between 0 - 180"); //enter servo location here alert
}

void loop() {

  while (Serial.available()) {
    char c = Serial.read(); //gets one byte from serial buffer
    readString += c; //turns readString into a string of characters
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
    Serial.println(readString);  //prints the input characters or string
    int n = readString.toInt();  //converts readString into numbers
    servo1.write(n); //turns main arm left servo
    servo2.write(180-n); //turns main arm right servo in opposite direction
    servo3.write(n); //turns top arm servo
    servo4.write(n); //turns swivel servo
    readString=""; //turn readString back to an empty string
  }

}
