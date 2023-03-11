#define VRX_PIN  34 // ESP32 pin GIOP36 (ADC0) connected to VRX pin
#define VRY_PIN  35 // ESP32 pin GIOP39 (ADC0) connected to VRY pin

int X;				// variable para almacenar valor leido del eje X
int Y;				// variable para almacenar valor leido del eje y
int LED_IZQUIERDO = 14;		// LED izquierdo a pin digital 3
int LED_DERECHO = 26;		// LED derecho a pin digital 5
int LED_ABAJO = 27;		// LED de abajo a pin digital 6
int LED_ARRIBA = 25;		// LED de arriba a pin digital 9



void setup(){
  Serial.begin(115200);

  pinMode(LED_IZQUIERDO, OUTPUT);	// LED como salida
  pinMode(LED_DERECHO, OUTPUT);		// LED como salida
  pinMode(LED_ABAJO, OUTPUT);		// LED como salida
  pinMode(LED_ARRIBA, OUTPUT);		// LED como salida
  // entradas analogicas no requieren inicializacion
}


void loop() {
  X = analogRead(VRX_PIN);			// lectura de valor de eje x
  Y = analogRead(VRY_PIN);			// lectura de valor de eje x


  if (X >= 0 && X < 1548){					// si X esta en la zona izquierda
    analogWrite(LED_IZQUIERDO, map(X, 0, 480, 255, 0));		// brillo LED proporcional
  } else {
    analogWrite(LED_IZQUIERDO, 0);				// X en zona de reposo, apaga LED
  }
  if (X > 2148 && X <= 4095){					// si X esta en la zona derecha
    analogWrite(LED_DERECHO, map(X, 520, 1023, 0, 255));	// brillo LED proporcional
  } else {
    analogWrite(LED_DERECHO, 0);				// X en zona de reposo, apaga LED
  }
  if (Y >= 0 && Y < 1548){					// si Y esta en la zona de abajo
    analogWrite(LED_ABAJO, map(Y, 0, 480, 255, 0));		// brillo LED proporcional
  } else {
    analogWrite(LED_ABAJO, 0);					// Y en zona de reposo, apaga LED
  }
  if (Y > 2148 && Y <= 4095){					// si Y esta en la zona de arriba
    analogWrite(LED_ARRIBA, map(Y, 520, 1023, 0, 255));		// brillo LED proporcional
  } else {
     analogWrite(LED_ARRIBA, 0);   				// Y en zona de reposo, apaga LED     
  }
         

  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(X);
  Serial.print(", y = ");
  Serial.println(Y);



}