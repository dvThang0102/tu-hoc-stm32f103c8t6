#include <LiquidCrystal.h>
#include <Keypad.h>

char* password =  "2222";
int possition = 0;
int RedLight = 10;
int GreenLight = 11;
const byte row = 4;
const byte col = 4;
char keymap [row][col] = { '7', '8', '9', 'A',
                           '4', '5', '6', 'B',
                           '1', '2', '3', 'C',
                           '*', '0', 'E', 'D' };
 byte  rowPins[row] = {1, 2, 3, 4}; 
 byte colPins[col] = {5, 6, 7, 8};
Keypad mykeypad = Keypad(makeKeymap(keymap), rowPins, colPins, row, col);
LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); 

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(RedLight, OUTPUT);
  pinMode(GreenLight, OUTPUT);
  setlock(1);
}

void loop() {
  // put your main code here, to run repeatedly:

  char Whichkey = mykeypad.getKey();
  lcd.setCursor(0, 0);
  lcd.print("   Welcome");
  lcd.setCursor(0, 1);
  lcd.print("  Enter passWord");
  if (Whichkey == '*' || Whichkey == 'A' || Whichkey == 'B' || Whichkey == 'C' || Whichkey == 'D' || Whichkey == 'E')
  {
    lcd.clear();
    possition = 0;
    setlock(1);
    lcd.setCursor(0, 0);
    lcd.print("   Invailid key");
    delay(500);
    lcd.clear();
    delay(200);
  }
  if(Whichkey == password[possition])
  {
    possition++;
  }
  if(possition==4)
  {
    setlock(0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    Correct");
    lcd.setCursor(0,1);
    lcd.print("   We're ready ");
    delay(7000);
    lcd.clear();
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
