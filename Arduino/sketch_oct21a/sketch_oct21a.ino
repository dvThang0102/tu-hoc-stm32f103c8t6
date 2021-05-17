int sensor[7];
int ss1 = 8;
int ss2 = 9;
int ss3 = 10;
int ss4 = 11;
int ss5 = 12;
int ss6 = 13;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor[1]=digitalRead(ss1);
  sensor[2]=digitalRead(ss2);
  sensor[3]=digitalRead(ss3);
  sensor[4]=digitalRead(ss4);
  sensor[5]=digitalRead(ss5);
  sensor[6]=digitalRead(ss6);
 Serial.print(sensor[1]);
 Serial.print(sensor[2]);
 Serial.print(sensor[3]);
 Serial.print(sensor[4]);
 Serial.print(sensor[5]);
 Serial.print(sensor[6]);
 Serial.print(sensor[7]);
 Serial.println();
 delay(500);
 
 
}
