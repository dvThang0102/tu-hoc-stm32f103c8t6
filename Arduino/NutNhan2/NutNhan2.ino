const int buttonPin = 5; // Chân kết nối với button trên board Iotmaker Uno X
const int ledPin = 13; // Chân kết nối với LED trên board
int ledState = LOW; // Biến lưu trạng thái hiện tại của chân kết nối đến LED
int buttonState = HIGH ; // Biến lưu trạng thái hiện của nút nhấn
int lastButtonState = HIGH; // Biến lưu trạng thái trước đó của nút nhấn.
unsigned long lastDebounceTime = 0; // Biến lưu thời gian delay chống dội phím ở lần cuối cùng.
unsigned long debounceDelay = 50; // Thời gian delay để chống dội phím nhấn
void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  digitalWrite(ledPin, ledState);
}
void loop()
{
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}
