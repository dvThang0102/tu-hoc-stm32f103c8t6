/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
String data="";// tao mang de nhan


Servo myservo;  // create servo object to control a servo

byte val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
{
  char c = Serial.read();
  if(c =='\n')
  {
    val = data.toInt();// chuyển chuỗi thành số
    data = "";
  }
  else
  {
    data = data + c;
  }
}
  myservo.write(val);                  // sets the servo position according to the scaled value
  Serial.println(val);
  delay(15); 
}
