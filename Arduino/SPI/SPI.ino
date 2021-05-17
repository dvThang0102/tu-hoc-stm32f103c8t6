#include <SPI.h>
#include <bitBangedSPI.h>
#include <MAX7219_Dot_Matrix.h>

MAX7219_Dot_Matrix display (1, 10); // Chân D10 là chân SS của board Iotmaker Uno X
const byte chip = 1; // Số chip MAX7219 được sử dụng
const char message [] = "IOT MAKER VN"; // Nội dung được hiển thị
unsigned long lastMoved = 0;
unsigned long MOVE_INTERVAL = 100; // Thời gian chạy chữ đơn vị (ms)
int messageOffset;
void updateDisplay ()
{
// Hiển thị chữ của mảng message, bắt đầu từ pixel mesageOffset
display.sendSmooth (message, messageOffset);
// Mỗi thời gian hiển thị một pixel từ phải qua trái
if (messageOffset++ >= (int) (strlen (message) * 8))
messageOffset = -1 * 8;
}
void setup ()
{
display.begin (); // Khởi tạo hiển thị
}
void loop ()
{
// Nội dung được hiển thị lại sau khi chạy
if (millis() - lastMoved >= MOVE_INTERVAL) {
updateDisplay ();
lastMoved = millis();
}
}
