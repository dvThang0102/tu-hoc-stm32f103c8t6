// Điều khiển servo cực chính xác với góc lệch nhỏ nhất 0.006 độ
// Chú ý: Thư viện này chỉ sử dụng cho 2 pin là ~9 (PB1) và ~10 (PB2) 
// Chú ý: (Ơ phiên bản này) Bạn sẽ không thể sử dụng thư viện <Servo.h> để điều khiển Servo ở các pin còn lại.



#include <TIMER1_SERVO.h>

void setup(){


port_attach(PB1);// chọn pin ~9
}
void loop(){
// góc : 0.000 đến 180.000
  write(PB1,90.005);// pin ~9 trên arduino  UNO R3
  // góc hiện tại 90.005 độ
delay(5000);//5s
}



