#include <Servo.h>
int led = 11;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int val;
Servo myservo;  // create servo object to control a servo

int sensorPin = 0;    // The potentiometer is connected to
                      // analog pin 0

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  int sensorValue;

  sensorValue = analogRead(sensorPin);  //sensorValue is a value in ms.
  // set the brightness of pin 9:


  val = map(sensorValue, 0, 1023, 0, 255);
  Serial.print("val:");
  Serial.println(val); 
  // change the brightness for next time through the loop:
  
  //brightness = brightness + fadeAmount;
  brightness = val;
  analogWrite(led, brightness);

  // reverse the direction of the fading at the ends of the fade:
  //if (brightness == 0 || brightness == 255) {
    //fadeAmount = -fadeAmount ;
  //}
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
