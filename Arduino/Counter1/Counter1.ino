#include <TimerOne.h>
#include <LiquidCrystal.h>
#define led 6
int ledState;
volatile unsigned long blinkCount = 0;

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Timer1.initialize(1500000); //Khởi động ngắt Timer1 tràn mỗi 0.15s
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 0.15 seconds
  setupLCD();
}
void blinkLED(void)
{
  if (ledState == LOW)
  {
    ledState = HIGH;
    blinkCount = blinkCount + 1;
  }
  else ledState = LOW;
  digitalWrite(led, ledState);
}
void setupLCD(void)
{
  lcd.begin(16, 2);
}

void loop() {
  unsigned long blinkCopy; // biến linkCopy được dùng để copy số lần LED từ biến blinkCount
  //tắt ngắt nhằm tránh trường hợp biến blinkCount thay đổi (do ngắt timer xảy ra) trong quá trình copy.
  noInterrupts();
  blinkCopy = blinkCount;
  interrupts();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.println("So Lan Sang:" + String(blinkCopy));
  //lcd.display();
  delay(1000);
}
