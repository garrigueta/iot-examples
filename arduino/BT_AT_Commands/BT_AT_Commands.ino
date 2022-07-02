#include <SoftwareSerial.h>

SoftwareSerial hc06(10,11);

void setup(){
  //Initialize Serial Monitor
  Serial1.begin(9600);
  Serial1.println("ENTER AT Commands:");
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
}

void loop(){
  //Write data from HC06 to Serial Monitor
  if (hc06.available()){
    Serial1.write(hc06.read());
    Serial.write(hc06.read());
  }
  
  //Write from Serial Monitor to HC06
  if (Serial1.available()){
    hc06.write(Serial1.read());
  }  
  if (Serial.available()){
    hc06.write(Serial.read());
  }  
}
