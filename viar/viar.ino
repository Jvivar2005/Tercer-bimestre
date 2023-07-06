/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: javier ricardo vivar sanchez
 * Nombre:  Eliezer Denilson Gsitán Corado
 * 
  */


  //Librerias
#include <Wire.h>
#include <SoftwareSerial.h>
#include <PCF8574.h>

//Directivas
#define PHIGH LOW  
#define PLOW HIGH  
#define buzz 2
#define rx 3
#define tx 4
#define altaV 5
#define bajaV 6
#define chimaltenango 7
#define chiquimula 8
#define guatemala 9
#define elprogreso 10
#define escuintla 11
#define huehuetenango 12
#define izabal 13
#define jalapa  A0
#define jutiapa A1
#define peten A2
#define quetzaltenango A3
#define quiche A4
#define retalhuleu A5
#define sacatepequez A6
#define sanmarcos A7
#define santarosa 2
#define solola 3
#define suchitepequez 4
#define totonicapan 5
#define zacapa 6

  #define Do 262
  #define Dosos 277
  #define Re 294
  #define Resos 311
  #define Mi 330
  #define Fa 349
  #define Fasos 370
  #define Sol 392
  #define Solsos 415
  #define La 440
  #define Lasos 466
  #define Si 494


  //Constructores
SoftwareSerial bt(rx, tx);
PCF8574 expansor(0x27);


//Variables
bool iniciar = false;
String respuesta;
int aleatorio;

//Funciones
void apagarLed ();
void fallo();
void quiz();
void pinn();

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  Wire.begin();
  expansor.begin();
  pinn();
  Serial.println("El Mapa de Guatemala");  
  Serial.println("Para iniciar Escriba (Iniciar) ");  
  Serial.println("Para terminar Escriba (final) ");
  delay(500);   
}

void loop() {
  

 if(Serial.available()>0){
    String comenzar = Serial.readStringUntil('\n');
  if ( comenzar == String("Iniciar")){
     aleatorio = random(0, 21);
  quiz();
  Serial.println("Primera pregunta");
     
  iniciar = true;
    delay(100);
  }
  }

  if (iniciar == true){
  aleatorio = random(0, 21);
 quiz();
  delay(500);
  Serial.println("Siguiente pregunta"); 
    


  }
  }

 void quiz(){
  if(aleatorio == 0){
    Serial.println("Cabecera departamental de Petén");
      if(respuesta == String("Flores")){    //Respuesta correcta
        apagarLed();        
        digitalWrite(peten, HIGH);   
      }
      else{
       fallo();
       }
      }
           
      if(aleatorio == 1){
    Serial.println("Cabecera departamental de Izabal");
      if(respuesta == String("Puerto Barrios")){    //Respuesta correcta
        apagarLed();
        digitalWrite(izabal, LOW);  
      }
      else{
       fallo();
       }
      }
      
 }
  
