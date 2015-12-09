void setup() {  // initialize digital pin 13 as an output.  
  pinMode(13, OUTPUT);
  }
void loop() { 
  int ss = 500/2; 
  int ll = 2000/2;
  int times = 5; 
  for(int i = 0; i < times; i ++){
    blink(ss); 
    }    
    for(int i = 0; i < times; i ++){ 
      blink(ll); 
      }   
  }

void blink(int duration){  digitalWrite(13 , HIGH);     delay(duration);                digitalWrite(13, LOW);     delay(duration); }
