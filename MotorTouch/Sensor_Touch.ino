int IN1 = 4;
int IN2 = 5;

int count = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(21, INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.print(count%2 == 1);

  if(digitalRead(21) == 1){
    delay(350);
    count++;
  }
  if(count%2 == 1){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

}
