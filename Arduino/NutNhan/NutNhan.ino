const int LED = 13;
const int btn = 6;
int ledstatus = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  digitalWrite(LED, ledstatus);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//int button = digitalRead(btn);
 if(digitalRead(btn) == 0)
  {
    delay(20);
    if(digitalRead(btn) == 0)
    {
      if(ledstatus == 0)
       ledstatus = 1;
      else
       ledstatus = 0;
      digitalWrite(LED,ledstatus);
    }
    while(digitalRead(btn) == 0 );
  }
}
