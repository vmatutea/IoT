/*
Write a sketch that allows a user to access data 
in EEPROM using the serial monitor. In the serial
monitor the user should be able to type one of two
commands: “read” and “write. "Read" takes one argument,
an EEPROM address. "Write" takes two arguments, an EEPROM 
address and a value.

For example, if the user types “read 3” then the contents 
of EEPROM address 3 should be printed to the serial monitor.
If the user types “write 3 10” then the value 10 should be written
into address 3 of the EEPROM.

Victoria Matute Arribas
 6 December 2015
 
 */
#include <EEPROM.h>

int address = 0;
String command;
 
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  
      // Erase the content of the EEPROM addresses
  for (int i = 0; i < EEPROM.length(); i++) {
      EEPROM.write(i, 0);
  }
}

// the loop function runs over and over again forever
void loop() {
 command= Serial.readString();

 if (command.startsWith("read ")){
  address = command.substring(5).toInt();//read from position 5 in the String
  byte value_r = EEPROM.read(address);
  Serial.print("Reading address:");
  Serial.print(address);
  Serial.print(". value: "); 
  //Serial.println(EEPROM.read(address));
   Serial.println(value_r, DEC);
 }else if (command.startsWith("write ")){
     int endAdress = command.substring(6).indexOf(" ");//get end position of address
     address= command.substring(6, 6 + endAdress).toInt();//substring from position 6 to end of address
     int value_w = command.substring((6 + endAdress) + 1).toInt();
     Serial.print("Writing ");
     Serial.print(value_w);
     Serial.print(" to address " );
     Serial.println(address);
     EEPROM.write(address, value_w); 
 }
}
