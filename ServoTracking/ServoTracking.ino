#include <ESP32Servo.h>

#define Sensor 5
#define servo 4

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(servo);
  pinMode(Sensor, INPUT);
}

void loop() {
  bool value = digitalRead(Sensor);
  Serial.println(value);

  if(value == 0){
    myservo.write(100);
  }else{
    myservo.write(0);
  }

}
