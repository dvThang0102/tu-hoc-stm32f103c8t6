// Điều khiển servo cực chính xác với góc lệch nhỏ nhất 0.006 độ
// Chú ý: Thư viện này chỉ sử dụng cho 2 pin là ~9 (PB1) và ~10 (PB2) 
// Chú ý: (Ơ phiên bản này) Bạn sẽ không thể sử dụng thư viện <Servo.h> để điều khiển Servo ở các pin còn lại.



#include <TIMER1_SERVO.h>

void setup(){


port_attach(PB2);// chọn pin ~10
}
void loop(){
  // một cách khác đế điều khiển chính xác (chính xác hơn hàm write)
// góc : 0.000 đến 180.000
// val: 8480 đến 38550 
  correct_write(PB2, 8480);// pin ~10 , servo quay ở góc 0.000 độ 
// góc hiện tại 0.000 độ
delay(5000);//5s
}



