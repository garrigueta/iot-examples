#include <MS5611.h>
#include <SoftwareSerial.h>

//ports D2 and D3
SoftwareSerial Bluetooth(2,3);
char c = ' ';

void setup() {
  Serial.begin(9600);
  Serial.println("ready");
  Bluetooth.begin(115200);

}

void loop() {
  if(Bluetooth.available()){
    c=Bluetooth.read();
    Serial.write(c);
  }
  if(Serial.available()){
    c=Serial.read();
    Bluetooth.write(c);
  }
}
