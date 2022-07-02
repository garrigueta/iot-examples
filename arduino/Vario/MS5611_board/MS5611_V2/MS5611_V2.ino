#include <MS5611.h>
MS5611 barometer;
int buzzer = 4;
float old_vario = 0;
unsigned long old_dur = 0;
unsigned int old_freq = 0;
float old_alti = 0;

void setup() {
  pinMode(buzzer,OUTPUT);
  //Serial.begin(9600);
  barometer.begin();
}

void buzz(unsigned int _freq, unsigned long _dur){
  noTone(buzzer);  
  tone(buzzer, _freq, _dur);
}

void loop() {
	float vario;
	
	unsigned long dur = 0;
	unsigned int freq = 0;
	
	float pressure = barometer.readPressure();
	float alti = barometer.getAltitude(pressure);
	
	vario = ((old_alti - alti) + old_vario)/2;
	
	old_alti = alti;
	old_vario = vario;
	
	if (vario>=-0.3 && vario<0.3){
		dur = 0;
		freq = 0;
	}else if (vario<-2) {
		dur = 0;
		freq = 30;
	}else if (vario<-0.8 && vario >=-2) {
		dur = 10;
		freq = 50;
	}else if (vario<-0.3 && vario >=-0.8) {
		dur = 10;
		freq = 100;
	}else if (vario >= 0.3 && vario<0.6) {
		dur = 250;
		freq = 440;
	}else if (vario >= 0.6 && vario<0.9) {
		dur = 200;
		freq = 470;
	}else if (vario >= 0.9 && vario<1.5) {
		dur = 170;
		freq = 500;
	}else if (vario >= 1.5 && vario<2.5) {
		dur = 130;
		freq = 650;
	}else if (vario >= 2.5 && vario<3.5) {
		dur = 100;
		freq = 730;
	}else if (vario >= 3.5) {
		dur = 80;
		freq = 790;
	}
	
	if( dur != old_dur && freq != old_freq){
		buzz(freq,dur);
	}
	
	old_dur = dur;
	old_freq = freq;
	  
	delay(200);
}
