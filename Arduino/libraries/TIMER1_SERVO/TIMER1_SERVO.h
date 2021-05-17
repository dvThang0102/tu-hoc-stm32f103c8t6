
// Tác giả thư viện : Phùng Thái Sơn - Hà Nam
// Trang web: http://arduino.vn/tutorial/1416-avr-xuat-xung-voi-tan-so-va-do-rong-theo-y-muon
// Bản quyền thư viện : Phùng Thái Sơn.
// Ngày hoàn thiện : 11:10pm- 1/1/2017
// Ngày xuất bản: 8/1/2017 trên arduino.vn
// Thư viện sử dụng TIMER1 để điều khiển Servo có góc lệch nhỏ nhất là 0.006 độ
// Chú ý: Thư viện này chỉ sử dụng cho 2 pin là ~9 (PB1) và ~10 (PB2) 
// Chú ý: (Ở phiên bản này) Bạn sẽ không thể sử dụng thư viện <Servo.h> để điều khiển Servo ở các pin còn lại.
// Thư viện này có đi kèm với các Code ví dụ.
uint8_t thanh_ghi_1_A=0, thanh_ghi_1_B=0;// lưu trạng thái 2 thanh ghi
bool called_set=false;//  gọi hàm set_timer1(); hay chưa
void set_timer1(){
//TCCR1A =	|COM1A1	| COM1A0|	COM1B1|	COM1B0|	 -	 |   -	 |  WGM11 |	 WGM10 |
//TCCR1B =	|ICNC1	| ICES1	|    -    |  WGM13|	WGM12|	CS12 |	 CS11 |	 CS10  |
    //reset
    TCCR1A &= B01011100;
    TCCR1B &= B11100000;
   TCCR1A |= (1 << WGM11);
    TCCR1B |= (1 << WGM12)|(1 << WGM13);
    // chọn Fast PWM, chế độ chọn TOP_value tự do  ICR1 
    TCCR1B |= (1 << CS10);
    // P_clock=16mhz
    // mỗi P_clock bằng 1/16mhz= 0.0625 us
// Hay 16  (P_clock ) bằng  1 us.
// F_pwm=p_clock/50001=319.993hz
    ICR1 = 65534;
    // xung răng cưa tràn sau 65536 P_clock, tương đương (6,5 ms)
called_set=true;//gọi hàm set_timer1();  này (1 lần)
}
void port_attach( uint8_t select_port){
if( called_set==false){
  //nếu chưa gọi hàm này bao giờ thì phải gọi 1 lần (1 lần duy nhất thôi nhé)
  set_timer1();
}
switch( select_port){
case PB1:
// pin ~9

    DDRB |= (1 << PB1);
    // Đầu ra PB1 là OUTPUT ( pin 9)
    TCCR1A |= (1 << COM1A1);
    // So sánh thường( none-inverting) 
    OCR1A=8480;//góc 0
break;
case PB2:
// pin ~10

    DDRB |= (1 << PB2);
    // Đầu ra PB2 là OUTPUT ( pin ~10)
    TCCR1A |= (1 << COM1B1);
    // So sánh thường( none-inverting) 
    OCR1B=8480;//góc 0
break;


  
}
  thanh_ghi_1_A=TCCR1A;
thanh_ghi_1_B=TCCR1B;
// lưu lại thông tin thanh ghi
}


void correct_write(uint8_t select_port, uint16_t val){
  // val : 8480 - 38550
  //Độ rộng: 0.53ms - 2.41 ms
  // Góc lệch: 0 ->180 độ
  if( (thanh_ghi_1_A != TCCR1A)&&( thanh_ghi_1_B !=TCCR1B)){
    // Nếu thanh ghi bị đổi thông tin (do bị truy cập bởi thư viện Servo.h) thì phải cài lại
  called_set=false;
  port_attach(select_port);
}
switch(select_port){

case PB1:
// pin ~9
if(OCR1A!=val){
OCR1A=val;
}
break;

case PB2:
// pin ~10
if(OCR1B!=val){
OCR1B=val;
}
break;
default:
break;


}
}
void write(uint8_t select_port,float goc){
//goc 0.000 đến 180.000
// tỷ số goc/x=180.000/30070.  Với 30070=38550-8480;
// Value=8480+x.
double x=((30070.0 * goc)/180.0);
double Value=x+8480.0;

correct_write( select_port, (long) (Value) );
// ép về kiểu số nguyên 
  // GÓC : 0.000 đến 180.000 độ
  //Độ rộng: 0.53ms - 2.41 ms
  // Góc lệch: 0 ->180 độ

}

