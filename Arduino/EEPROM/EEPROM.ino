#include <EEPROM.h>


void setup() {
  // put your setup code here, to run once:
pinMode(11,INPUT);
pinMode(12,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(12)==0) EEPROM.write(1,EEPROM.read(1)+1);
if(digitalRead(11)==0) EEPROM.write(1,0);
Serial.println(EEPROM.read(1));
delay(200);
}
