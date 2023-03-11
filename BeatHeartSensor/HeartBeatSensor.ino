int PULSADOR = 34;
int led13 = 13;

int Signal;
int Threshold = 550;

void setup() {
  pinMode(led13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Signal = analogRead(PULSADOR);

  if(Signal > Threshold){
    digitalWrite(led13,HIGH);
  }else {
    digitalWrite(led13,LOW);
  }

  delay(50);
}
