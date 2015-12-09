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
int sum=0;
int space_count=0;
int value=0;
byte value_r;
int add_int_val[10];
int val_int_val[10];
int add_int =0;
int val_int =0;
int dec_count= 0;
int dec_count_val=0;
 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  Serial.println("Hi!"); 
  for (int y=0;y<10;y ++){
  add_int_val[y]=0;
  val_int_val[y]=0;
  }
  
  Serial.println("Please,when reading, introduce a space when you are done introducing the address.");
  Serial.println("Please,when writing, introduce a space when you are done introducing the address.");

}

// the loop function runs over and over again forever
void loop() {
 
  
  //1. Serial
  int incomingByte;
  
          if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                //Serial.print("I received: ");
                //Serial.println(incomingByte, DEC);
            if (incomingByte > 65){ //letters
                sum += incomingByte;
            } 
           
            if (incomingByte==32){space_count += 1;}//count spaces. 
            
            if (incomingByte>32 && incomingByte<65 && space_count==1){ // accumulating the decimals for the address
             
              address =incomingByte;
              add_int_val[dec_count]= address - '0';            
              dec_count +=1;
              
            }
            
             
             if (incomingByte>32 && incomingByte<65 && space_count==2){// accumulating the decimals for the value of writing
             
              value =incomingByte;
              val_int_val[dec_count_val]= value - '0';            
              dec_count_val +=1;
              
            }
            
            if ( incomingByte==32&& space_count==2){//transforming the address into integer
              add_int=add_int_val[1] +  add_int_val[0]*10;
            }
            
            if ( incomingByte==32&& space_count==3){ // transforming the value into integer
              val_int=val_int_val[1] +  val_int_val[0]*10;
            }
            
            
              if (sum == 412 && add_int!=0 ){//read and the address is already integer...

                
                  value_r = EEPROM.read(add_int);

            Serial.print("Reading: ");
            Serial.print(add_int);
            Serial.print("\t");
            Serial.print(value_r, DEC);
            Serial.println();
    
            delay(500);
          }
            
               if (sum == 555 && add_int!=0 && val_int!=0){//write and address and value are already integer...

                 
                     EEPROM.write(add_int, val_int);
    
             Serial.print("Writing: ");
                     Serial.print(add_int);
                     Serial.print("\t");
                     Serial.print(val_int);
                     Serial.println();

                     delay(500);
                 
          }          
          }  
 
}
