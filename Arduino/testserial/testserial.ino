
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.write("on\n");
delay(200);
Serial.write("off\n");
delay(200);
}
