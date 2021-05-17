#define LedGreen 8 // khai bao chan
#define LedBlue  9
#define LedRed   10
#define btn 2

boolean currentPinstatus;
boolean lastPinstatus = HIGH;
int mode = 0;
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}
boolean Nhannut(boolean lastState)
{
  boolean currentState;
  currentState = digitalRead(btn);
  if (currentState != lastState)
  {
    delay(20);
    currentState = digitalRead(btn);
  }
  return currentState;
}
void NhanNut(
void setMode(int mode)
{
  if (mode == 1)
  {
    digitalWrite(LedGreen, LOW);
    digitalWrite(LedBlue, HIGH);
    digitalWrite(LedRed, HIGH);
  }
  else if (mode == 2)
  {
    digitalWrite(LedGreen, HIGH);
    digitalWrite(LedBlue, LOW);
    digitalWrite(LedRed, HIGH);
  }
  else if (mode == 3)
  {
    digitalWrite(LedGreen, HIGH);
    digitalWrite(LedBlue, HIGH);
    digitalWrite(LedRed, LOW);
  }
}
  void loop() {
    currentPinstatus = Nhannut(lastPinstatus);
    if ((currentPinstatus == LOW) && (lastPinstatus == HIGH))
      mode++;
    lastPinstatus = currentPinstatus ;
    if (mode == 4)
      mode = 1;
      setMode(mode);
  }
