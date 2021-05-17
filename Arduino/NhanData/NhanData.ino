int LED = 13;
char *data,c;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 2)
{
  data[0] = Serial.read();
  data[1] = Serial.read();
  data[2] = Serial.read();
  c = data[0] +  data[1] + data[2];
  if(c == 100)
  digitalWrite(LED, HIGH);
  else if(c == 101)
  digitalWrite(LED, LOW);
}
}
