#include <Arduino.h>
#include <WiFi.h>

// constants
const char *ssid = "MIWIFI_2G_KqRx";
const char *password = "VIENA2017";
// put function declarations here:
void initWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}
// int myFunction(int, int);
void setup()
{
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  Serial.begin(9600);
  // Serial.begin(115200);

  initWiFi();
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  // Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
// int myFunction(int x, int y) {
//  return x + y;
//}