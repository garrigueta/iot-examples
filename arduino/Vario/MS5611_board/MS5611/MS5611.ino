#include <MS5611.h>
MS5611 barometer;
int buzzer = 4;

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  barometer.begin();
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

void loop() {
  float vario;
  float pressure_before = barometer.readPressure();
  float alti_before = barometer.getAltitude(pressure_before);
  float temp = barometer.readTemperature();
  delay(300);
  float pressure_after = barometer.readPressure();
  float alti_after = barometer.getAltitude(pressure_after);
  vario = alti_after - alti_before;
  
  if (vario>=-0.3 && vario<0.3){
    buzzer_play(0,0);
  }
  else if (vario<-2) {
    buzzer_play(30,0);
  }
  else if (vario<-0.8 && vario >=-2) {
    buzzer_play(50,0);
  }
  else if (vario<-0.3 && vario >=-0.8) {
    buzzer_play(100,0);
  }
  else if (vario >= 0.3 && vario<0.6) {
    buzzer_play(440,250);
  }
  else if (vario >= 0.6 && vario<0.9) {
    buzzer_play(470,200);
  }
  else if (vario >= 0.9 && vario<1.5) {
    buzzer_play(500,170);
  }
  else if (vario >= 1.5 && vario<2.5) {
    buzzer_play(650,130);
  }
  else if (vario >= 2.5 && vario<3.5) {
    buzzer_play(730,100);
  }
  else if (vario >= 3.5) {
    buzzer_play(790,80);
  }
}
