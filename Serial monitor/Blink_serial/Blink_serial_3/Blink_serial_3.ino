/**** Written and compiled using Arduino IDE 1.6.5 and Uploaded to Arduino UNO ******/

// import standard library
#include <stdio.h>
// set constants
int LED = 13;

void setup() { 
 // initialise serial communications to 9600bps  
 Serial.begin(9600);

//Set PIN Mode to output  
pinMode (LED, OUTPUT);

//Set LED to LOW before starting Loop  
digitalWrite (LED, LOW);

// Display start Instructions for User
Serial.println ("You may control the LED from the keyboard.");
Serial.println ("Please press 0 to turn off the LED and 1 to turn on the LED");  }


void loop() {  
// loop runs as long as power on Arduino

//Check for data in serial monitor buffer
if (Serial.available() > 0) {
     int ByteReceived = Serial.read();
         if (ByteReceived == '0') {
            Serial.println ("You pressed 0 to turn off LED");
           digitalWrite (LED, LOW);
           Serial.println ("The LED is now off");
      }
           else if (ByteReceived == '1') {
            Serial.println ("You pressed 1 to turn on LED");
            digitalWrite (LED, HIGH);
            Serial.println ("The LED is now on"); 
      }

      else {
          Serial.println ("You must press 0 or 1 to turn LED off or on");
         Serial.println ("Please try again");
      } 
   }
  }
