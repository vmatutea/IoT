#include <EEPROM.h>
String addr = "";  // Address of EEPROM
String data = "";  // Data to be writen in EEPROM
int count = 0;
char endMarker = '\n';
char rc;
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = true;

void setup(){  
       Serial.begin(9600);
       Serial.println("User 'r' or 'w' to 'read' or 'write'");
       for (int i = 0 ; i < EEPROM.length() ; i++) {
         EEPROM.write(i, 0);
       }
} 
void loop(){  
       if ((Serial.available()>0) && (newData == true)) {   
            rc = Serial.read(); 
                 
            if (rc != endMarker) {
                  receivedChars[count] = rc;
                  count++;
                  
                  if (count >= numChars) {
                     count = numChars - 1;
                  }
            }

           else {
               receivedChars[count] = '\0'; // terminate the string
               count = 0;
               newData = false;
           }
          
       }

  if (newData == false) {
       // Get de Address from Serial Input      
       addr = "";
       int i = 2;    //define the position of the first character of the address
       while (receivedChars[i] != ' '){
          addr = addr + receivedChars[i];
          i++;
       } 
       // Get the Data from Serial Input. Obs.: i+1 define the begining of Data position on Serial input
       data = "";
       while (receivedChars[i+1] != endMarker){
          data = data + receivedChars[i+1];
          i++;
       } 
       // Get the Data to write in EEPROM
        if ((addr.toInt() < EEPROM.length()) && (data.toInt() < 255)){
           if (receivedChars[0] == 'w')     { 
                Serial.print("Address ");
                Serial.println(addr.toInt());     
                Serial.print("Data ");
                Serial.println((byte)data.toInt());
                EEPROM.write(addr.toInt(), (byte)data.toInt());    
                newData = true;
           } 
        }
       if (addr.toInt() < EEPROM.length())     
          if (receivedChars[0] == 'r')    {   
               
                Serial.print("endereco");
                Serial.println(addr.toInt());
                Serial.print(EEPROM.read(addr.toInt()),DEC);    
                newData = true;
          }  
  }   
}
