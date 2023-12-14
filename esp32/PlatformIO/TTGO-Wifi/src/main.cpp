#include <Arduino.h>
#include <WiFi.h>

// constants
const char *ssid = "MIWIFI_5G_KqRx";
// const char* ssid = "Lowi3570";
const char *password = "VIENA2017";
// const char* password = "ZLB758SL2KL4YW";

// put function declarations here:
// int myFunction(int, int);
void initWifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connectant a la wifi...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void setup()
{
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  // Serial.begin(9600);
  Serial.begin(115200);
  initWifi();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
// int myFunction(int x, int y) {
//  return x + y;
//}