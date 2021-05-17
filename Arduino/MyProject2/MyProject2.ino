int number[10][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {0, 1, 0, 0, 1, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1, 0, 0, 1}
};
int RL = 10;
int YL = 11;
int GL = 12;
void Number(int i)
{
  for (int pin = 2; pin < 10; pin++)
  {
    digitalWrite(pin, number[i][pin - 2]);
  }
}

void setup() {
  // put your setup code here, to run once:
  for (int pin = 2; pin < 10 ; pin++)
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  for (int i = 10; i <= 12; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(10, HIGH);
  for (int j = 0; j < 10; j++) {
    Number(j);
    for (int i = 0 ; i < 100; i++) {
      delay(5);
    }
  }
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  for (int j = 0; j < 10; j++) {
    Number(j);
    for (int i = 0 ; i < 100; i++) {
      delay(5);
    }
  }
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  for (int j = 0; j < 10; j++) {
    Number(j);
   delay(1000);
  }
  digitalWrite(12, LOW);
}
