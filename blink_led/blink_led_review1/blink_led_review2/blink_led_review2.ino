void setup(){  
pinMode(13, OUTPUT);
}
void loop() {
  int i=0;
  while (i<5){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);  
    delay(500);
    i++;
  }
  i=0;
  while (i<5){
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
    delay(2000);
    i++;
  }
 }
