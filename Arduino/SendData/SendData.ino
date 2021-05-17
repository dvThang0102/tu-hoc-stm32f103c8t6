
int var = 100;

void setup()
{
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
Serial.begin(9600); // Khai báo sử dụng Serial với tốc độ baud = 9600

}
void loop()
{
  int ON =digitalRead(4);
  int OFF =digitalRead(5);
  if(ON==0)
  Serial.print(var);
  if(OFF==0)
  Serial.print('101');
  
 }
