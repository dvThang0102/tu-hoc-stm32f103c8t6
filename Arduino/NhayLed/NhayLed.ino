#define Led 13
int  statusled =  LOW;
unsigned long previoustime = 0;
const long internal = 1000; 
void setup() {
  // put your setup code here, to run once:
pinMode(Led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long currenttime = millis();
if((currenttime - previoustime)>internal)
{
  previoustime = currenttime;
  if(statusled == LOW)
   statusled = HIGH;
  else
   statusled = LOW;
 digitalWrite(Led,statusled);
}
}
