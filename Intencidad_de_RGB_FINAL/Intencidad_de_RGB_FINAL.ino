/* centro educativo laboral kinal
  Electronica
  Quinto A
  taller de electronica digital reparacion en computadoras
  javier ricardo vivar sanchez
  2019585
*/

//definir pines a usar  
#define Potenciometro  3
#define Red   5
#define Green  6
#define Blue  8
//definir variables 
int Tiempo;
int colores(int R, int G, int B);

void setup() {
  // empieza la comunicacio serial
  Serial.begin(9600);
//pines como salida 
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);

}

void loop() {
  //empieza todo el ciclo de la RGB con el potenciometro
  Tiempo = map(analogRead(Potenciometro), 0, 1023, 100, 1000);
  Serial.println(Potenciometro);

  colores(174, 92, 230);
  delay(Tiempo);

  colores(255, 255, 255);
  delay(Tiempo);

  colores(0, 255, 255);
  delay(Tiempo);

  colores(189, 174, 20);
  delay(Tiempo);

  colores(255,87, 35);
  delay(Tiempo);

}
int colores(int R, int G, int B) {
  analogWrite(Red, R);
  analogWrite(Green, G);
  analogWrite(Blue, B);
}
