#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);
  myservo.writeMicroseconds(10000);  // set servo to mid-point
} 

void loop() {} 
