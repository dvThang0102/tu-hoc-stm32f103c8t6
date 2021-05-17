float Kp=15,Ki=0,Kd=0.05;
float error = 0, P = 0,I = 0,D = 0,PID_value = 0;
float previous_error = 0;
int sensor[8]={0,0,0,0,0,0,0,0};
int gia_tri_ban_dau = 100;
int PID_phai,PID_trai;

#define In1 2 
#define In2 4
#define In3 5 
#define In4 7
#define ENA 3 
#define ENB 6

void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

void setup()
{
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
Serial.begin(9600);
}
void loop()
{
  read_sensor_values();// đọc cảm biến
  calculate_pid();// tính toán Pid
  motor_control();// dieu khien 
}
void read_sensor_values()
{
  //sensor[0]=digitalRead(A5);
  sensor[1]=digitalRead(8);
  sensor[2]=digitalRead(9);
  sensor[3]=digitalRead(10);
  sensor[4]=digitalRead(11);
  sensor[5]=digitalRead(12);
  sensor[6]=digitalRead(13);
 // sensor[7]=digitalRead(13);

  if((sensor[6]== 0)&&(sensor[5]==0)&&(sensor[4]==0)&&(sensor[3]==1)&&(sensor[2]==1)&&(sensor[1]==1))
     error = 5;
  else if((sensor[6]== 0)&&(sensor[5]==0)&&(sensor[4]==0)&&(sensor[3]==0)&&(sensor[2]==0)&&(sensor[1]==1))
     error = 4;
  else if((sensor[6]== 0)&&(sensor[5]==0)&&(sensor[4]==0)&&(sensor[3]==0)&&(sensor[2]==1)&&(sensor[1]==1))
     error = 3;
  else if((sensor[6]== 0)&&(sensor[5]==0)&&(sensor[4]==0)&&(sensor[3]==1)&&(sensor[2]==1)&&(sensor[1]==0))
     error = 2;
  else if((sensor[6]== 0)&&(sensor[5]==0)&&(sensor[4]==1)&&(sensor[3]==1)&&(sensor[2]==1)&&(sensor[1]==0))
     error = 1;
  else if((sensor[6]== 0)&&(sensor[5]==0)&&(sensor[4]==1)&&(sensor[3]==1)&&(sensor[2]==0)&&(sensor[1]==0))
     error = 0;
  else if((sensor[6]== 0)&&(sensor[5]==1)&&(sensor[4]==1)&&(sensor[3]==1)&&(sensor[2]==0)&&(sensor[1]==0))
     error = -1;
   if((sensor[6]== 0)&&(sensor[5]==1)&&(sensor[4]==1)&&(sensor[3]==0)&&(sensor[2]==0)&&(sensor[1]==0))
     error = -2;
  else if((sensor[6]== 1)&&(sensor[5]==1)&&(sensor[4]==0)&&(sensor[3]==0)&&(sensor[2]==0)&&(sensor[1]==0))
     error = -3;
  else if((sensor[6]== 1)&&(sensor[5]==0)&&(sensor[4]==0)&&(sensor[3]==0)&&(sensor[2]==0)&&(sensor[1]==0))
     error = -4;
  else if((sensor[6]== 1)&&(sensor[5]==1)&&(sensor[4]==1)&&(sensor[3]==0)&&(sensor[2]==0)&&(sensor[1]==0))
     error = -5;
  else if((sensor[6]== 0)&&(sensor[5]==0)&&(sensor[4]==0)&&(sensor[3]==0)&&(sensor[2]==0)&&(sensor[1]==0))
     error = 6;   
      
  
}
void calculate_pid()
{
  P = error;
  I = I + error;// sai so truoc cong sai so hien tai
  D = error - previous_error;// sai so hien tai tru sai so truoc
  PID_value = (Kp * P)+(Ki * I)+(Kd * D);
  previous_error = error;
}
void motor_control()
{
  digitalWrite(In1,HIGH);
  digitalWrite(In2,LOW);
  digitalWrite(In3,LOW);
  digitalWrite(In4,HIGH);
  PID_phai = gia_tri_ban_dau - PID_value;
  PID_trai = gia_tri_ban_dau + PID_value;
  PID_phai = constrain(gia_tri_ban_dau - PID_value,0 ,150);
  PID_trai = constrain(gia_tri_ban_dau + PID_value,0 ,150);
  analogWrite(ENB,PID_phai);
  analogWrite(ENA,PID_trai);
  Serial.println(PID_phai);
  Serial.println(PID_trai);
}
