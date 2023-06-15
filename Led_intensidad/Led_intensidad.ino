/* centro educativo laboral kinal
  Electronica
  Quinto A
  taller de electronica digital reparacion en computadoras
  javier ricardo vivar sanchez
  2019585
*/
//variables 
const int led = 3;
const int potenciometro = 0;
int Intencidad;

void setup(){
//Definir los leds como salida 
  
pinMode(led, OUTPUT);
}

void loop(){

//Toda la secuencia del potenciometro para el leds
Intencidad = analogRead(potenciometro) / 4; 
analogWrite(led, Intencidad);

}
