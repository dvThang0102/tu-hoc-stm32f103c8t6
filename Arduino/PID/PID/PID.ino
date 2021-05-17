float Kp=15,Ki=0,Kd=0.05;
float error = 0, P = 0,I = 0,D = 0,PID_value = 0;
float previous_error = 0;
int sensor[7]={0,0,0,0,0,0,0};
unsigned char pins[6]={A0,A1,A2,A3,A4,A5};
int gia_tri_ban_dau = 200;
int PID_phai,PID_trai;



#define In1 12 
#define In2 13
#define In3 7
#define In4 8
#define ENA 11
#define ENB 6
#define trig 9
#define echo 10



void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);
float GetDistance();


void setup()
{
  Serial.begin(9600);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
 
}
void loop()
{
  read_sensor_values();// đọc cảm biến
  calculate_pid();// tính toán Pid
  motor_control();// dieu khien 

    
}
void read_sensor_values()
{ 
  int i;
  for(i = 0; i< 6; i++)
  {
    if(analogRead(pins[i])>=255)
     sensor[i+1]=1;
     else 
     sensor[i+1]=0;
  }

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
float GetDistance()
{
  long duration, distanceCm;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH,5000);
  distanceCm = duration/2/29.1;
  Serial.println(distanceCm);
  return(distanceCm); 
 
}
void motor_control()
{
  long distance = GetDistance();
  if (distance <= 25)
  {
      analogWrite(ENB,100);
      analogWrite(ENA,255);
      delay(1000);
  }
  else
  {   
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
    digitalWrite(In3,HIGH);
    digitalWrite(In4,LOW); 
    PID_phai = constrain(gia_tri_ban_dau + PID_value,0 ,255);
    PID_trai = constrain(gia_tri_ban_dau - PID_value,0 ,255);
    analogWrite(ENB,PID_phai);
    analogWrite(ENA,PID_trai);
  }
  
}
