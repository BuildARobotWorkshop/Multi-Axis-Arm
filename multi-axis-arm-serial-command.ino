/*
  Multi-Axis Arm Serial Command Sketch
  Sketch used to move servos on the Multi-Axis Arm Robot to a specific locations
  Created by: Paul Qua
  Last modified: 10-22-19
*/

String readString;
#include <Servo.h> //include servo library
Servo servo1;  // create instances of servo class or objects to control servos
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(9600); //set servo baud rate to 9600
  servo1.attach(7); //Main arm servo left
  servo2.attach(8); //Main arm servo right
  servo3.attach(9); //Top arm servo
  servo4.attach(10); //Swivel servo
  Serial.println("Serial successfully connected!"); //serial successfully connected alert
  Serial.println("Enter either a, b or c and then a number between 0 - 180 to move that axis. Example: a90");
  Serial.println("a is for the Main Arm");
  Serial.println("b is for the Top Arm");
  Serial.println("c is for the Swivel");
}
void loop() {
  while (Serial.available()) {
    char c = Serial.read(); //gets one byte from serial buffer
    readString += c; //turns readString into a string of characters
    delay(2);  //slow looping to allow buffer to fill with next character
  }
    if (readString.length() >0 && readString.charAt(0) == 'a') {
      Serial.println(readString);  //prints the input characters or string
      readString.remove(0, 1); //removes the zero character so only numbers are left
      int n = readString.toInt();  //converts readString into numbers
      servo1.write(n); //turns main arm left servo
      servo2.write(180-n); //turns main arm right servo in opposite direction
      readString="";  //clears out the string for new characters
    }

    if (readString.length() >0 && readString.charAt(0) == 'b') {
      Serial.println(readString);  //prints the input characters or string
      readString.remove(0, 1);  //removes the zero character so only numbers are left
      int n = readString.toInt();  //converts readString into numbers
      servo3.write(n); //turns top arm servo
      readString="";  //clears out the string for new characters
    }

    if (readString.length() >0 && readString.charAt(0) == 'c') {
      Serial.println(readString);  //prints the input characters or string
      readString.remove(0, 1);  //removes the zero character so only numbers are left
      int n = readString.toInt();  //converts readString into numbers
      servo4.write(n); //turns swivel servo
      readString="";  //clears out the string for new characters
    } else {
      readString="";
    }

}
