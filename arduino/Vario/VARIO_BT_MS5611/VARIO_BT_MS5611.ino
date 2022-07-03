#include <MS5611.h>

#include <SoftwareSerial.h>

//ports D2 and D3
SoftwareSerial Bluetooth(2,3);
char c = ' ';

MS5611 MS5611(0x77);
uint32_t start, stop;

void setup() {
  Serial.begin(9600);
  Serial.println("ready");
  Bluetooth.begin(115200);
  if (MS5611.begin() == true)
  {
    Serial.println("MS5611 found.");
  }
  else
  {
    Serial.println("MS5611 not found. halt.");
    while (1);
  }

  start = micros();
  MS5611.read();   // uses default OSR_ULTRA_LOW  (fastest)
  stop = micros();
  Serial.print( (uint8_t) MS5611.getOversampling());
  Serial.print("\t");
  Serial.println(stop - start);
  delay(10); // to flush serial.
  
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
