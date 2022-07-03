#include "MS5611.h"

MS5611 MS5611(0x77);
const int buzzer = 7;
float old_vario;
const float sea_press = 1013.25;

void setup() {
  pinMode(buzzer,OUTPUT);
  
  Serial.begin(9600);
  if (!MS5611.begin()) {
    Serial.println("MS5611 not found, check wiring!");
    while (1);
  }
  old_vario = 0;
  Serial.println("setup() done!");
}

void buzzer_play(int freq,int duraction){
  noTone(buzzer);
  if (freq==0 && duraction==0){
    noTone(buzzer);
    delay(200);
    }
  else if (duraction==0 && freq != 0){
    tone(buzzer,freq);
    delay(duraction);
    }
  else {
    tone(buzzer,freq);
    delay(duraction);
    noTone(buzzer);
    }
}

float getAltitude(float pressure, float temp) {
  return ((pow((sea_press / pressure), 1/5.257) - 1.0) * (temp + 273.15)) / 0.0065;
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

  Serial.println(vario);
  
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
    delay(1000);
  }
  else if (vario<-0.5 && vario >=-2) {
    tone(buzzer,200);
    delay(1500);
  }
  else if (vario<-0.3 && vario >=-0.5) {
    tone(buzzer,100);
    delay(2000);
  }
  
  noTone(buzzer);
}
