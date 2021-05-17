#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer sv(80);
int count=0;
void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("TTT", "123456789");
  WiFi.begin("WIFI CHUA", "haimuoitrieu");
  while (WiFi.waitForConnectResult() != WL_CONNECTED)
    delay(100);
  Serial.begin(115200);
  Serial.println(WiFi.localIP());
  sv.on("/",[]{
    Serial.println(String("Co nguoi truy cap: ")+ count++);
    sv.send(200,"text/plain","xin chao, day la Hoc Co Dien Tu Channel !!");
    });
  sv.on("/count",[]{
    Serial.println(String("Co nguoi truy cap: ")+ count++);
    sv.send(200,"text/plain",String("so truy cap: ") + count);
    });
  sv.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  sv.handleClient();
}
