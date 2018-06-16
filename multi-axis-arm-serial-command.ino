String readString;
#include <Servo.h>
Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(9600); //set servo baud rate in the to 9600 for a good in the middle range
  servo1.attach(8); //Main arm servo left
  servo2.attach(9); //Main arm servo right
  servo3.attach(12); //Rotation Servo
  servo4.attach(10); //Top Arm servo
  Serial.println("Serial successfully connected!"); //serial successfully connected alert
}

void loop() {
  // put your main code here, to run repeatedly:

  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the String readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
    Serial.println(readString);  //so you can see the captured String
    int n = readString.toInt();  //convert readString into number
    servo1.write(n);
    servo2.write(180-n); //turns opposide servo in desired direction
    //servo3.write(n); un-comment this for servo3 and comment out all other servos
    //servo4.write(n); un-comment this for servo4 and comment out all other servos
    readString=""; //makes readString back to an empty string
  }

}