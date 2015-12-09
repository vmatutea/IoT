/*
  Blink_serial
  Turns on an LED on for one second, then off for one second, repeatedly.

  Write a program that allows the user to control the LED connected to 
  pin 13 of the Arduino. When the program is started, the LED should be 
  off. The user should open the serial monitor to communicate with the Arduino.
  If the user sends the character '1' through the serial monitor then the LED 
  should turn on. If the user sends the character '0' through the serial monitor 
  then the LED should turn off.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int bval;
  //Serial.println("hello");
  if (Serial.available() > 0){
    Serial.println("Printing");  
    bval=Serial.read();
    if (bval==49){ // 49 is character '1'
      digitalWrite(13, HIGH);
      delay(1000);
    }
    if (bval==48){ //48 is character '0'
      digitalWrite(13, LOW);
      delay(1000);
    }
}
}
