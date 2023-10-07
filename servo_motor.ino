#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  int value= random(10,25);
  
  if(value>=15){
    myservo.write(90);
    Serial.println(value);
  }
  else if(value >= 18){
    myservo.write(120);
    Serial.println(value);
  }
 else if(value >=22){
  myservo.write(180);
  Serial.println(value);
 }
 else{
  myservo.write(0);
  Serial.println(value);
 }
  delay(2000);
}
