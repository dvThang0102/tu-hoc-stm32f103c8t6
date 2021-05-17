#include <Servo.h>

#define bientro A0
#define ServoPin 9
Servo myservo;

void setup()
{
 myservo.attach(ServoPin);
 Serial.begin(9600);
}
void loop()
{
 int value = analogRead(bientro);
 int Servos = map(value,0,1023,0,180);
 myservo.write(Servos);
 delay(500);
}
