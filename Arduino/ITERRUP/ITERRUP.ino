int ledPin = 13;
int btnNgat = 2;
int ledstatus = LOW;

void Blink(void)
{
  ledstatus = ! ledstatus;
  digitalWrite(ledPin, ledstatus);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(btnNgat),Blink,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:

}
