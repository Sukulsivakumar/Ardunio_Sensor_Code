const int sensorPin[] = {A0,A1,A2};
float distance[3];
const int AVERAGE_OF =50;
const float MCU_VOLTAGE = 5.0;

void setup()
{
  Serial.begin(9600); 
}
void loop(){
  readDistance(0);//read sensor 1
  Serial.print("d1 =");
  Serial.print(distance[0]);
  Serial.println("cm");
  readDistance(1);//read sensor 2
  Serial.print("d1 =");
  Serial.print(distance[1]);
  Serial.println("cm");
  readDistance(2);//read sensor 3
  Serial.print("d3 =");
  Serial.print(distance[2]);
  Serial.println("cm");
  delay(300); 
}
void readDistance(int sensor){
      float voltage_temp_average=0;
      for(int i=0; i < AVERAGE_OF; i++){
      int sensorValue = analogRead(sensorPin[sensor] );
      delay(1);      
      voltage_temp_average +=sensorValue * (MCU_VOLTAGE / 1023.0);
    }
   voltage_temp_average /= AVERAGE_OF;
   distance[sensor] = 33.9 + -69.5*(voltage_temp_average) + 62.3*pow(voltage_temp_average,2) + -25.4*pow(voltage_temp_average,3) + 3.83*pow(voltage_temp_average,4);

}
