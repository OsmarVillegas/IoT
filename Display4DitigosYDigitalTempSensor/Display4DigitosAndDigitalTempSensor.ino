#include <TM1637.h>

int digitalPin = 4;
int analogPin = 34;
int digitalVal;
int analogVal;

#define CLK 13
#define DIO 12

TM1637Display display(CLK, DIO);

void setup() {
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  displayVal = digitalRead(digitalPin);
  display.setBrightness(0x0f);

  display.showNumberDec(analogVal);

  analogVal = analogRead(analogPin);
  Serial.println(analogVal);
  Serial.println(digitalVal);
  delay(100);
}
