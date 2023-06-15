/* centro educativo laboral kinal
  Electronica
  Quinto A
  taller de electronica digital reparacion en computadoras
  javier ricardo vivar sanchez
  2019585
*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C LCD_JV(0x27,16,2);

int   PIN = 0;
int   Medidor = 0;
int   Vin = 5;
float Vout = 0;
float R2 = 10000;
float R1 = 0;
float Const = 0;

void setup(){
  // Inicializar el LCD
  LCD_JV.init();
  //Encender la luz de fondo.
  LCD_JV.backlight();
}

void loop(){
  Medidor = analogRead(PIN);
  if(Medidor){
    Const = Medidor * Vin;
    Vout = (Const)/1024.0;
    Const = (Vin/Vout) - 1;
    R1 = R2 * Const;

    LCD_JV.setCursor(0,1);
    LCD_JV.print("R1=");
    LCD_JV.setCursor(3,1);
    LCD_JV.print(R1);
    LCD_JV.setCursor(0,0);
    LCD_JV.print("Vout=");
    LCD_JV.setCursor(5,0);
    LCD_JV.print(Vout);
    
    delay(500);
  }
}
