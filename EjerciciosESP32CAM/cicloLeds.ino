//author: Carlos Daniel Miranda Viloria
//Diplomado CodigoIoT Samsung

#include <dummy.h>
#define LED_BUILTIN 4

void setup() {
  Serial.begin(9600);
  pinMode (LED_BUILTIN, OUTPUT);
}

void loop() {
  for(int i=0;i<10;i++){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.write("LED encendido");
    delay(20);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.write("LED Apagado");
  }
}