/*
 * 
 * Blink
 * 
 * The LED should blink alternating between fast blinks and slow blinks. 
 * The LED should blink 5 times, once every half second, 
 * and then it should blink 5 more times, once every two seconds. 
 * The LED should continue to blink in this alternating fashion for 
 * as long as the Arduino receives power.
 * 
 * @vicma
 */


void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{


//Blink every half a second
int i_fast;
for (i_fast=0;i_fast<5;i_fast++){
  digitalWrite(13, HIGH);   // Turn on the LED
  
  delay(500);              // Wait for one second
  
  digitalWrite(13, LOW);    // Turn off the LED
  
  delay(500);              // Wait for one second
}

//Blink every 2 seconds
int i_slow;
for (i_slow=0;i_slow<5;i_slow++){
  digitalWrite(13, HIGH);   // Turn on the LED
  
  delay(2000);              // Wait for one second
  
  digitalWrite(13, LOW);    // Turn off the LED
  
  delay(2000);              // Wait for one second
}
}

