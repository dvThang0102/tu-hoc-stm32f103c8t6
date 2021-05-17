// Master
#include <Wire.h>
#define button 4
char data[6];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin();// khai bao la master
pinMode(button,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(button)==0)
{
  Wire.beginTransmission(1);
  Wire.write('1');
 Wire.endTransmission();
}
else if(digitalRead(button)==1)
{
  Wire.beginTransmission(1);
  Wire.write('0');
  Wire.endTransmission();
}
Wire.requestFrom(1,6);// nhan tu salve 1 6
if(Wire.available()>0)
{
  for(int i = 0;i<6;i++)
  {
    data[i] = Wire.read();
    Serial.print(data[i]-48);
  }
}
delay(500);
}
