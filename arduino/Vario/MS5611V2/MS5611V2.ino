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
  
  if (vario>=-0.3 && vario<0.3){
    buzzer_play(0,0);
  }
  else if (vario<-2) {
    buzzer_play(30,300);
  }
  else if (vario<-0.8 && vario >=-2) {
    buzzer_play(50,200);
  }
  else if (vario<-0.3 && vario >=-0.8) {
    buzzer_play(40,250);
  }
  else if (vario >= 0.3 && vario<0.6) {
    buzzer_play(300,250);
  }
  else if (vario >= 0.6 && vario<0.9) {
    buzzer_play(400,200);
  }
  else if (vario >= 0.9 && vario<1.5) {
    buzzer_play(500,150);
  }
  else if (vario >= 1.5 && vario<2.5) {
    buzzer_play(650,100);
  }
  else if (vario >= 2.5 && vario<3.5) {
    buzzer_play(730,50);
  }
  else if (vario >= 3.5) {
    buzzer_play(790,30);
  }
}
