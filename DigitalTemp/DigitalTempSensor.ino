int led = 13;
int digitalPin = 4;
int analogPin = 3;
int digitalVal;
int analogVal;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalVal = digitalRead(digitalPin);
  analogVal = digitalRead(analogPin);
  Serial.println(analogVal);
  Serial.println(digitalVal);

  if(analogVal >= 500){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }

}
