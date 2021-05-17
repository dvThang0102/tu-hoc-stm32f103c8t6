#include <Wire.h>
char x;
char data[6] = {'0', '1', '2', '3', '4', '5'};
void Receive();
void Request();
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);
  Wire.begin(1);// khai bao la slave
  Wire.onReceive(Receive);// uu tien ngat truoc
  Wire.onRequest(Request);//....
}

void loop() {
  // put your main code here, to run repeatedly:
  if (x == '1')
    digitalWrite(13, 1);
  else if (x == '0')
    digitalWrite(13, 0);
}

void Receive(int howmany)
{
  x = Wire.read();// nhan tin hieu 1 byte
}
void Request()
{
  Wire.write(data);
}
