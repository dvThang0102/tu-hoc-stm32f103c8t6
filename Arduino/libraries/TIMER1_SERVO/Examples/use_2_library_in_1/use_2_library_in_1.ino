// Điều khiển servo cực chính xác với góc lệch nhỏ nhất 0.006 độ
// Chú ý: Thư viện này chỉ sử dụng cho 2 pin là ~9 (PB1) và ~10 (PB2) 
// Chú ý: (Ơ phiên bản này) Bạn sẽ không thể sử dụng thư viện <Servo.h> để điều khiển Servo ở các pin còn lại.


#include <Servo.h>

Servo myservo;  

#include <TIMER1_SERVO.h>
void setup(){
pinMode(13,1);//led 
port_attach(PB2);// chọn pin ~10
 myservo.attach(3); // pin 3 (Servo khác)
}
void loop(){
  
 // điều khiển servo pin ~10, vô hiệu hóa thư viện " Servo.h"  
  correct_write(PB2,8800 );// pin ~10 , servo quay ở góc 0.000 độ 
  digitalWrite(13,1);
  delay(5000);
  // điều khiển Servo pin ~3
  
 // điều khiển servo pin ~3, vô hiệu hóa thư viện " TIMER1_SERVO.h"  
 myservo.attach(3); // đặt
myservo.write(90);
  digitalWrite(13,0);
  delay(5000);
  myservo.detach();// gỡ
// Đây là cách duy nhất để sử dụng cùng lúc 2 thư viện 
// do có sự tranh chấp TIMER 1 nên ta cần phải đặt lại attach/detach mỗi lần sử dụng 
  

}



