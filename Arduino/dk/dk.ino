int button = 9;
unsigned char DK;
unsigned char onoff = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  DK = digitalRead(button);
  if (DK == 0)
  {
    delay(20);
    if (DK == 0)
    {
      if (onoff == 0)
      {
        onoff = 1;
        digitalWrite(4, HIGH);
      }
      else
      {
        onoff = 0;
        digitalWrite(4, LOW);
      }

    }
    while (DK == 0);
  }
}
