/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int led = 11;           // the PWM pin the LED is attached to
int val=0;    // variable to read the value from the analog pin
int deg=0;
int brigt=0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  Serial.print("val:");
  Serial.println(val);      
  myservo.write(val);                  // sets the servo position according to the scaled value
  deg=myservo.read();             
  Serial.print("deg:");
  Serial.println(deg);      
  brigt = map(deg, 0, 180, 0, 255);     // scale it to use it with the servo (value between 0 and 180)
  Serial.print("brigt :");
  Serial.println(brigt);      
  analogWrite(led, brigt);
  
  delay(30);                           // waits for the servo to get there
}
