#include <DHT.h>

#define DHT_Pin 12 // DHT11 is connected to digital pin 7
#define DHT_Type DHT11 // Specifying the type of DHT sensor

DHT dht(DHT_Pin, DHT_Type);

void setup() {
  Serial.begin(9600); // start serial communication
  dht.begin(); // initialize the DHT sensor
}

void loop() {
  float temperature = dht.readTemperature(); // read the temperature
  float humidity = dht.readHumidity(); // read the humidity

  // check if there was an error reading the data
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Error reading data from DHT sensor");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature); // print the temperature
  Serial.println("°C");
  Serial.print("Humidity: ");
  Serial.print(humidity); // print the humidity
  Serial.println("%");

  delay(1000); // wait for 1 second
}
