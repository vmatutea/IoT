/*

Author Sameer Ahmad Bhat

Date  16-Nov-2015

*/

int  LED_PIN= 13;

void setup()

{

  pinMode(LED_PIN, OUTPUT);    // Set LED_PIN as an output.

  digitalWrite(LED_PIN, LOW);    //Turn OFF LED

  Serial.begin(9600);           // Open serial port for serial data transmission at 9600 Baud rate

}

void loop()

{

  // Changing LED status only when data is received

  if (Serial.available()>0)

  {

    switch (Serial.read()) // polling input from serial monitor

    {
       case '1' :                  // 1 means to Turn ON LED

      digitalWrite(LED_PIN, HIGH); // turn the LED on (HIGH is the voltage level)

      break;

      case '0':                   // 0  means to Turn OFF LED

      digitalWrite(LED_PIN, LOW);  // turn the LED off by making the voltage LOW

      break;

      default:                    // neither 1 nor 0 is received as serial input

      digitalWrite(LED_PIN, LOW);  // turn the LED off by making the voltage LOW

      break;

    }

  }

}

