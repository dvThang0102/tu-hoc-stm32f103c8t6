int col[4];
int row[4];
int ButtonMatrix[3][3] = { 1, 2, 3,
                           4, 5, 6,
                           7, 8, 9
                         };
void setup() {
  // put your setup code here, to run once:
  col[1] = 10;
  col[2] = 9;
  col[3] = 8;
  row[1] = 13;
  row[2] = 12;
  row[3] = 11;
  pinMode(col[1], OUTPUT);
  pinMode(col[2], OUTPUT);
  pinMode(col[3], OUTPUT);
  pinMode(row[1], INPUT);
  pinMode(row[2], INPUT);
  pinMode(row[3], INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(ButtonTouch());

}
int ButtonTouch()
{
  int colpress = 0;
  int rowpress = 0;
  digitalWrite(col[1], HIGH);
  digitalWrite(col[2], HIGH);
  digitalWrite(col[3], HIGH);
  for (int i = 1; i <= 3; i++)
  {
    digitalWrite(col[i],LOW);
    for(int k = 1;k<=3 ; k++)
    {
      if(digitalRead(row[k])==0)
       {
        colpress = i;
        rowpress = k;
       }
    }
    digitalWrite(col[i],HIGH);
  }
  return ButtonMatrix[rowpress-1][colpress-1];
}
