#include <MS5611.h>
#include <SoftwareSerial.h>

//ports D2 and D3
SoftwareSerial Bluetooth(2,3);
char c = ' ';

MS5611 MS5611(0x77);
int buzzer = 7;
float old_vario;
const float sea_press = 1013.25;
uint32_t start, stop;

float getAltitude(float pressure, float temp) {
  return ((pow((sea_press / pressure), 1/5.257) - 1.0) * (temp + 273.15)) / 0.0065;
}

void setup() {
  Serial.begin(9600);
  Serial.println("ready");
  Bluetooth.begin(115200);
  pinMode(buzzer,OUTPUT);
  if (!MS5611.begin()) {
    Serial.println("MS5611 not found, check wiring!");
    while (1);
  }
  old_vario = 0;
  Serial.println("setup() done!");

}

void loop() {   
  MS5611.read();  
  float pressure_before = MS5611.getPressure();  
  float temp = MS5611.getTemperature(); 
  float alti_before = getAltitude(pressure_before, temp);
  delay(500);  
  MS5611.read();
  float pressure_after = MS5611.getPressure();  
  float temp_after = MS5611.getTemperature();  
  float alti_after = getAltitude(pressure_after, temp_after);
  float vario = ((alti_after - alti_before) + old_vario)/2;
  old_vario = vario;
  
  if (vario>=-0.5 && vario<0.5){
    tone(buzzer,0);
    delay(400);
  }  
  else if (vario >= 0.5 && vario<1) {
    tone(buzzer,200);
    delay(350);
  }
  else if (vario >= 1 && vario<1.5) {
    tone(buzzer,400);
    delay(300);
  }
  else if (vario >= 1.5 && vario<2.5) {
    tone(buzzer,650);
    delay(250);
  }
  else if (vario >= 2.5 && vario<3.5) {
    tone(buzzer,800);
    delay(200);
  }
  else if (vario >= 3.5 && vario<4.5) {
    tone(buzzer,900);
    delay(150);
  }
  else if (vario >= 4.5) {
    tone(buzzer,1000);
    delay(50);
  }
  else if (vario<-2) {
    tone(buzzer,300);
    delay(500);
  }
  else if (vario<-0.5 && vario >=-2) {
    tone(buzzer,200);
    delay(600);
  }
  else if (vario<-0.3 && vario >=-0.5) {
    tone(buzzer,100);
    delay(700);
  }
  
  noTone(buzzer);
  
  if(Bluetooth.available()){
    c=Bluetooth.read();
    Serial.write(c);
  }
  if(Serial.available()){
    c=Serial.read();
    Bluetooth.write(c);
  }
}
