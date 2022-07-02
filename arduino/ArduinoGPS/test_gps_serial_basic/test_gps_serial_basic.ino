void setup(){
  //Initialize Serial Monitor
  Serial1.begin(9600);
  Serial1.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
}

void loop(){
  //Write data from HC06 to Serial Monitor
  //if (Serial1.available() > 0){
  //  Serial.write(Serial1.read());
  //}
  
  //Write from Serial Monitor to HC06
  //if (Serial.available() > 0){
  //  Serial1.write(Serial.read());
  //}  
}
