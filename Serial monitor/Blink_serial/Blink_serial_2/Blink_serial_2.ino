int ledpin = 13;
void setup()
{  
 pinMode(ledpin, OUTPUT);      // initialize digital pin ledpin as an output. 
 digitalWrite(ledpin, LOW);    // turn the LED off by making the voltage LOW.  
 Serial.begin(9600); // opens serial port, sets data rate to 9600 bps.   
 Serial.println("Press 1 to turn ON LED");   
 Serial.println("Press 0 to turn OFF LED");
}
void loop()
{  // Changing LED status only when data is received
  if (Serial.available()>0)
  {    
        switch (Serial.read()) // Checking the value of Serial input  
            {      case '1' :                  // 1 is received as serial input   
                             digitalWrite(ledpin, HIGH); // turn the LED on (HIGH is the voltage level)     
                             Serial.println("LED is turned ON");    
                             break;  
                   case '0':                   // 0 is received as serial input  
                            digitalWrite(ledpin, LOW);  // turn the LED off by making the voltage LOW   
                            Serial.println("LED is turned OFF");    
                            break;     
                   default:                    // neither 1 nor 0 is received as serial input     
                         digitalWrite(ledpin, LOW);  // turn the LED off by making the voltage LOW      
                         Serial.println("Invalid Input");     
                         break; 
              } 
    }
}
