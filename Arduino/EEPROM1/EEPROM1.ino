/*
 * EEPROM Write
 * Example by Espace.edu.vn
 */
  
#include <EEPROM.h>
  
/** the current address in the EEPROM **/
int addr = 0;
  
void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
  Serial.println("Start");
}
  
void loop()
{
  /*
    Need to divide by 4 because analog inputs range from
    0 to 1023 and each byte of the EEPROM can only hold a value from 0 to 255.
  */
  int val = analogRead(0) / 4;
  
  /*
    Write the value to fthe EEPROM.
  */
  EEPROM.write(addr, val);
  delay(100);
  Serial.print("Gia tri A0:");Serial.println(val);
  Serial.print("Dia chi EEPROM:");Serial.println(addr);
  Serial.print("Gia tri EEPROM:");Serial.println(EEPROM.read(addr));
  Serial.print("EEPROM:");Serial.println(EEPROM.length());
  /*
    Advance to the next address, when at the end restart at the beginning.
  */
  addr = addr + 1;
  if (addr == EEPROM.length()) {
    addr = 0;
  }
  delay(1000);
}
