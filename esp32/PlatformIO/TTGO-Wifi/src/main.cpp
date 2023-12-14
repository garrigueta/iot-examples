#include <Arduino.h>
#include <WiFi.h>
#include <credentials.h>
// HTTP requests
#include <HTTPClient.h>
#include <ArduinoJson.h>
// #include <NTPClient.h>

// constants
String url_timestamp = "http://worldtimeapi.org/api/timezone/Europe/Madrid";
// String result = doc["included"][0]["attributes"]["values"][0]["value"];
//  put function declarations here:
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

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

DynamicJsonDocument jsonRequest(String url)
{
  DynamicJsonDocument doc(1024);
  HTTPClient http;
  http.begin(url.c_str());
  int httpResponse = http.GET();
  if (httpResponse > 0)
  {
    String payload = http.getString();
    DeserializationError error = deserializeJson(doc, payload);
    if (error)
    {
      Serial.print("Deserialization failure");
      Serial.println(error.f_str());
    }
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponse);
  }
  http.end();
  return doc;
}
// int myFunction(int, int);
//
void setup()
{
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  Serial.begin(9600);
  // Serial.begin(115200);

  initWiFi();
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  // Serial.begin(115200);
  if (WiFi.status() == WL_CONNECTED)
  {
    // Canviar string dia per variables
    //

    DynamicJsonDocument jsonTimestamp = jsonRequest(url_timestamp);
    String data = jsonTimestamp["datetime"];
    String data_avui = data.substring(0, data.indexOf("T"));
    Serial.print(data_avui);
    String url_precios = "https://apidatos.ree.es/es/datos/mercados/precios-mercados-tiempo-real?start_date=" + data_avui + "T00:00&end_date=" + data_avui + "T23:59&time_trunc=hour";
    // DynamicJsonDocument preus = jsonRequest(url_hora);
    jsonTimestamp = jsonRequest(url_precios);
    String result = jsonTimestamp["included"][0]["attributes"]["values"][0]["value"];
    // String result = doc["included"][0]["attributes"]["values"][0]["value"];
    Serial.print(result);

    // Hora actual
  }
  else
  {
    Serial.println("WiFi Disconnected");
  }
}

void loop()
{
  if ((millis() - lastTime) > timerDelay)
  {
    // put your main code here, to run repeatedly:
    jsonRequest("");
    lastTime = millis();
  }
}
// put function definitions here:
// int myFunction(int x, int y) {
//  return x + y;
//}