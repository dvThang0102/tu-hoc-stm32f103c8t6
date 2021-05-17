#include <LiquidCrystal.h>
#include <Servo.h>

#define Trig 6
#define Echo 7
Servo myservo;
int servoPin = 8;
int servoPos = A0;
int distance,val;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  myservo.attach(servoPin);
  lcd.begin(16, 2); 
  Serial.begin(9600);
 lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(servoPos);
  val = map(val,0,1023,0,180);
  myservo.write(val);
  delay(15);
  Distance();
  lcd.setCursor(0,0);
  lcd.print("KC la: ");

  lcd.print(Distance());
  delay(2000);
  
 
}
int Distance()
{
  int  Time;
  delay(2);
  digitalWrite(Trig, HIGH);
  delay(5);
  digitalWrite(Trig, LOW);
  Time = pulseIn(Echo, HIGH);
  distance = Time * 0.034 / 2;
  return distance;
}
