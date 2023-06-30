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

// Librerias a usar
// Librerias para usar el modulo BT
#include <SoftwareSerial.h>
SoftwareSerial bt(11, 10);

// Interrupciones
#include <Ticker.h>
void Temp_bt(void);
Ticker Temp_bt10s(Temp_bt, 10000);

// Libreria de temperatura
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWireObjeto(6); // Pin de coneccion 6 de temperatura
DallasTemperature Temp(&oneWireObjeto);

#define Led 3
int temp; // Variable de temperatura

void setup() {
  Temp.begin();
  bt.begin(38400); // Velocidad de comunicacion 
  Temp_bt10s.start();
  pinMode(Led, OUTPUT);
}

void loop() {
  Temp_bt10s.update();
  if (bt.available() > 0) {
    int numb = bt.parseInt();
    switch (numb) {
      case 1:
        digitalWrite(Led, HIGH);
        break;
      case 2:
        digitalWrite(Led, LOW);
        break;
    }
  }
}

void Temp_bt(void) {
  temp = Temp.getTempCByIndex(0);
  bt.print("Temperatura del cuarto: ");
  bt.print(temp);
  bt.println("C");
}
