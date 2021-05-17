#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservo;
const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04
int RedLight = 10;
int GreenLight = 11;

LiquidCrystal lcd (A0, A2, A3, A4, A5,2);

void setup() {
  Serial.begin(9600);// khai bao LCD
  lcd.begin(16, 2);

  pinMode(RedLight, OUTPUT);// Den canh bao
  pinMode(GreenLight, OUTPUT);

  pinMode(trig, OUTPUT);// cam bien sieu am
  pinMode(echo, INPUT);
  setlock(1);
  myservo.attach(9);// Servo
}
int Distance()
{
  unsigned long duration; //biến đo thời gian
  int distance;           //biến lưu khoảng cách
  /* Phát xung từ chân trig */
  digitalWrite(trig, 0);  //tắt chân trig
  delayMicroseconds(2);   //chờ 2ms
  digitalWrite(trig, 1);  //phát xung từ chân trig
  delayMicroseconds(5);   //xung có độ dài 5 microSeconds
  digitalWrite(trig, 0);  //tắt chân trig

  /* Tính toán thời gian */
  duration = pulseIn(echo, HIGH); // Đo độ rộng xung HIGH ở chân echo.
  distance = int(duration / 2 / 29.412); // Tính khoảng cách đến vật.
  return distance;
}
void loop() {
  // LCD
  lcd.setCursor(0, 0);
  lcd.print("   Welcome");
  Serial.println(Distance());
  //delay(1000);
  if(Distance() < 5)
  {
  myservo.write(180);  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    Correct");
  lcd.setCursor(0, 1);
  lcd.print("   We're ready ");
  setlock(0);
  delay(3000);
  lcd.clear();
  myservo.write(0);  
}
delay(100);
}
void setlock(int locked)
{
  if (locked)
  {
    digitalWrite(RedLight, HIGH);
    digitalWrite(GreenLight, LOW);
  }
  else
  {
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, HIGH);
  }
}
