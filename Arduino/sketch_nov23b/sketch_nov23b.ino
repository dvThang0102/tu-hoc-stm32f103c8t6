#define Led 13
#define Button 5
int buttonstatus ;
int lastbuttonstatus = HIGH;
int ledstatus = LOW;
const int DebounceDelay = 50;
unsigned long lastDebounce = 0;

void setup() {
  pinMode(Button, INPUT);
  pinMode(Led, OUTPUT);
  digitalWrite(Led,ledstatus);
}

void loop() {
  int Reading = digitalRead(Button);
  if (Reading != lastbuttonstatus)
  {
    lastDebounce = millis();
  }
  if ((millis() - lastDebounce) > DebounceDelay)
  {
    if (Reading != buttonstatus)
    {
      buttonstatus = Reading;
      if (buttonstatus == LOW)
      {
        ledstatus != ledstatus;
      }
    }
  }
    digitalWrite(Led , ledstatus);
    lastbuttonstatus = Reading;
}
