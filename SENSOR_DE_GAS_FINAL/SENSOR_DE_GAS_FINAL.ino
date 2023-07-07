#include <LedControl.h> 
// incluye libreria LedControl

LedControl lc = LedControl(11, 13, 10, 1); // crea objeto

#define tiempo 1000     // constante tiempo con valor de 1000


byte uno[8] = {      // array que contiene todos los elementos de las
  B00111100,        // filas necesarias por mostrar el digito cero
  B01111110,
  B11011111,
  B11111111,
  B11110000,
  B11111111,
  B01111110,
  B00111100 
};

byte dos[8] = {       // array que contiene todos los elementos de las
  B00111100,        // filas necesarias por mostrar el digito cero
  B01111110,
  B11111011,
  B11111111,
  B00001111,
  B11111111,
  B01111110,
  B00111100
};

byte tres[8] = {       // array que contiene todos los elementos de las
  B00111100,        // filas necesarias por mostrar el digito cero
  B01111110,
  B11011100,
  B11111000,
  B11110000,
  B11111000,
  B01111100,
  B00111110
};

byte cuatro[8] = {      // array que contiene todos los elementos de las
  B00111100,        // filas necesarias por mostrar el digito cero
  B01111110,
  B00111011,
  B00011111,
  B00001111,
  B00011111,
  B00111110,
  B01111100
};

byte cero[8] = {

 B10011001,
 B01011010,
 B00111100,
 B11111111,
 B11111111,
 B00111100,
 B01011010,
 B10011001
 };
int gas;
void setup() {
  lc.shutdown(0, false);    // enciende la matriz
  lc.setIntensity(0, 4);    // establece brillo
  lc.clearDisplay(0);     // blanquea matriz
  Serial.begin(9600);
}

void loop() {
  gas = analogRead(A1);
  Serial.println(gas);
  if(gas<=500){
    mostrar_0();        // llama funcion mostrar_0
    delay(tiempo);      // tiempo
    
  }

  if (gas >= 500) {
    mostrar_0();        // llama funcion mostrar_0
    delay(tiempo);      // tiempo
    mostrar_1();        // llama funcion mostrar_1
    delay(tiempo);      // tiempo
    mostrar_2();        // llama funcion mostrar_2
    delay(tiempo);      // tiempo
    mostrar_3();        // llama funcion mostrar_3
    delay(tiempo);      // tiempo
  }
  else {
    lc.clearDisplay(0);     // blanquea matriz
  }
}

void mostrar_0() {    // funcion mostrar_0
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
    lc.setColumn(0, i, cero[7 - i]); // establece fila con valor de array cero en misma posicion
  }
}

void mostrar_1() {    // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
    lc.setColumn(0, i, uno[7 - i]); // establece fila con valor de array uno en misma posicion
  }
}

void mostrar_2() {    // funcion mostrar_2
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
    lc.setColumn(0, i, dos[7 - i]); // establece fila con valor de array dos en misma posicion
  }
}

void mostrar_3() {    // funcion mostrar_3
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
    lc.setColumn(0, i, tres[7 - i]); // establece fila con valor de array tres en misma posicion
  }
}
