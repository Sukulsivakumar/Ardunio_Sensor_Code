#define MQ2_Pin A0 
void setup() {
  Serial.begin(9600); 
}
void loop() {
  int sensorValue = analogRead(MQ2_Pin); 
  float voltage = sensorValue * (5.0 / 1023.0); 

  //Serial.print("Voltage: ");
  //Serial.print(voltage);
  Serial.print("Ethylene Concentration: ");
  float ppm=(voltage - 0.5) * 50.0;
  //Serial.print((voltage - 0.5) * 50.0); 
  Serial.print(ppm);
  Serial.println(" ppm");
  delay(1000);
}
