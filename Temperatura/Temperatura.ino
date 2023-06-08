/*
 * Fundacion Kinal
 * centro educativo laboral kinal
 * Electronica
 * Quinto
 * A
 * taller de electronica digital reparacion en computadoras 
 * javier ricardo vivar sanchez
 * 2019585
 * Uso de interrupciones externas iii 
 */    
       
    #include <Ticker.h>
void Temperatura(void);
Ticker Temp3s(Temperatura, 3000);
void Boton(void);
Ticker Boton6s(Boton, 6000);

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWireObjeto(6);
DallasTemperature Temp(&oneWireObjeto);

#define boton 2
#define PinTemp 6

void setup() {
  Serial.begin(9600);
  Temp.begin();
  Temp3s.start();
  Boton6s.start();
  pinMode(boton, INPUT);
}

void loop() {
  Temp3s.update();
  Boton6s.update();
}

void Temperatura(void) {
  Temp.requestTemperatures();
  int Temperatura = Temp.getTempCByIndex(0);
  Serial.print("Temperatura del cuarto: ");
  Serial.print(Temperatura);
  Serial.println("C");
}

void Boton(void) {
  delay(10);
  if (digitalRead(boton) == HIGH) {
    Serial.println("Boton precionado");
  }
  else {
    Serial.println("No se preciono el boton");
  }
}
