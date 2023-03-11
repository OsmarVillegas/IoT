#include <Stepper.h>

const int stepsPerRevolution = 2048;

#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

int shocksensor = 15;
bool shocksensorstate = 0;

Stepper myStepper(stepsPerRevolution, IN1, IN2, IN3, IN4);

void setup() {
  myStepper.setSpeed(5);
  Serial.begin(115200);
  pinMode(shocksensor, INPUT);
  shocksensorstate = digitalRead(shocksensor);
}

void loop() {
  Serial.print("Valor: " + shocksensorstate);
  shocksensorstate = digitalRead(shocksensor);

  if(shocksensorstate == 1){
    myStepper.step(stepsPerRevolution);
  }else{
    myStepper.step(-stepsPerRevolution);
  }

}
