unsigned char data = 0x02;
int i = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

//Serial.print(100);
//delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(data);
delay(2000);
}
