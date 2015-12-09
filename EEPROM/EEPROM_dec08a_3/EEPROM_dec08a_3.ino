#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  int addr ; 
  Serial.begin(9600);
}

int b1 , b2 , b3 , b4;
int digit;
char buffer[5];
char buffer2[4];

void loop() {
  buffer[0] = buffer[1] = buffer[2] = buffer[3] = -1;
  buffer2[0] = buffer2[1] = buffer2[2] = -1;
  // put your main code here, to run repeatedly:
  
  // to determin read or write
  int data = Serial.read();
  
  // read
  if ( data == 114 ){
    /* e */ Serial.read() ; 
    /* a */ Serial.read() ;
    /* d */ Serial.read() ;
    /* <> */ Serial.read() ;
    //Serial.readBytes(buffer,4);
  
  
    int index = 0;
    while( (data = Serial.read()) != -1){
      buffer[index++] = data ;
    }
    buffer[index] = '\0';
    //Serial.println(atoi(buffer));
    
    Serial.println(EEPROM.read( atoi(buffer) ) , DEC);
  } else if (data == 119) {
    // write 
    /* r */ Serial.read() ; 
    /* i */ Serial.read() ;
    /* t */ Serial.read() ;
    /* e */ Serial.read() ;
    /* <> */ Serial.read() ;

    int index = 0;
    while( (data = Serial.read()) != 32){
      buffer[index++] = data ;
      //Serial.println(data);
    }
    
    index = 0;
    while( (data = Serial.read()) != -1){
      buffer2[index++] = data ;
    }
    buffer2[index] = '\0';
    //Serial.readBytes(buffer2,3);
    Serial.println(atoi(buffer2));
    
    EEPROM.write( atoi(buffer) ,atoi(buffer2) );
  }
  
  


  delay(2000);
}
