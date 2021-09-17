//author: Carlos Daniel Miranda Viloria
// Diplomado CodigoIoT Samsung

#include "DHT.h"
#define DHTPIN 2   
#define DHTTYPE DHT11  
#define LED_OK 13
#define LED_WARNING 14
#define LED_FATAL 15
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("Funcionando!"));
  //Dentro de pinMode se selecciona el led y se establece si es output o input.
  pinMode (LED_OK, OUTPUT);
  pinMode (LED_WARNING, OUTPUT);
  pinMode (LED_FATAL, OUTPUT);
  dht.begin();
}

void loop() {
  delay(5000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  //Se verifica que las lecutras sean correctas.
  if (isnan(h) || isnan(t)) {
    Serial.println(F("ERROR AL REGISTRAR LOS DATOS DEL SENSOR!"));
    return;
  }
  if (t<30){
      digitalWrite(LED_OK,HIGH);        //Recordar que HIGH es señal de encendido
      digitalWrite(LED_WARNING,LOW);    //LOW por otra parte es apagado
      digitalWrite(LED_FATAL,LOW);
  }
  if (t>=30 && t<40) {
      digitalWrite(LED_WARNING,HIGH);
      digitalWrite(LED_FATAL,LOW);
      digitalWrite(LED_OK,LOW);
  }
  else {
      digitalWrite(LED_OK,LOW);
      digitalWrite(LED_WARNING,LOW);
      digitalWrite(LED_FATAL,HIGH);
  }
  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("% Temperatura: "));
  Serial.print(t);
  Serial.print(F("°C \n"));
}