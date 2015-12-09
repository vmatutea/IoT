#include <EEPROM.h>

void setup() {
   Serial.begin(9600);

    // Erase all of the EEPROM addresses
    for (int i = 0; i < EEPROM.length(); i++) {
      EEPROM.write(i, 0);
  }
}

void loop() {
  int address;
  String command = Serial.readString();
  if(command.startsWith("read ")) {
      address = command.substring(5).toInt();
      Serial.print("Reading from address ");
      Serial.print(address);
      Serial.print(" Value: "); 
      Serial.println(EEPROM.read(address));
  } else if(command.startsWith("write ")) {
      int secondSpace = command.substring(6).indexOf(" ");
      if (secondSpace == -1) {
        Serial.println("Invalid command. Try 'write a d' to write value d in address a or 'read a' to read the contents of address a");
      } else {
        address = command.substring(6, 6 + secondSpace).toInt();
        int data = command.substring((6 + secondSpace) + 1).toInt();
        String text = "Writing " + data;
        Serial.print("Writing ");
        Serial.print(data);
        Serial.print(" to address " );
        Serial.println(address);
        text += " to address " + address;
        //Serial.println(text);
        EEPROM.write(address, data); 
      }
  } else {
    //Serial.println("Invalid command. Try 'write a d' to write value d in address a or 'read a' to read the contents of address a");
  }
}
