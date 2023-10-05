/* centro educativo laboral kinal
  Electronica
  Quinto A
  taller de electronica digital reparacion en computadoras
  javier ricardo vivar sanchez
  2019585
  Examen Final Multimetro Digital
*/
#include <SoftwareSerial.h>
const int Punta1 = 7;         // Pin positivo
const int Punta2 = 6;         // Pin negativo
int sensorValue;                // Variable que almacena el valor raw (0 a 1023)
float Variable_voltaje;         // Variable que almacena el voltaje (0.0 a 25.0)

float Sensibilidad = 0.185;

int RESISTOR = A2;
int Medidor = 0;
int Vin = 5;
float Vout = 0;
float R2 = 10000;
float R1 = 0;
float Const = 0;
SoftwareSerial Modulo_Bluetooth(4, 5);
void setup() {
  pinMode(Punta1, OUTPUT);  // Configurar el pin positivo como salida
  pinMode(Punta2, OUTPUT);  // Configurar el pin negativo como salida
  Serial.begin(9600);        // Iniciar la comunicación serial
  Modulo_Bluetooth.begin(9600);
}
char recep;

void loop() {
  if (Modulo_Bluetooth.available()) {
    recep = Modulo_Bluetooth.read();
    Serial.println(recep);

    if (recep == 'A') {
      digitalWrite(Punta1, LOW);
      digitalWrite(Punta2, LOW);
      while (recep == 'A') {
        sensorValue = analogRead(A1);               // Realizar la lectura
        Variable_voltaje = map(sensorValue, 0, 1023, 0, 250) / 10.0;  // Escalar a 0.0 - 25.0
        Serial.print("Voltaje: ");
        Serial.println(Variable_voltaje);          // Mostrar el valor por serial
        Modulo_Bluetooth.print(Variable_voltaje);
        Modulo_Bluetooth.print(";");
        if (Modulo_Bluetooth.available()) {
          recep = Modulo_Bluetooth.read();
        }
      }
    }

    if (recep == 'B') {
      digitalWrite(Punta1, HIGH);
      digitalWrite(Punta2, HIGH);
      while (recep == 'B') {
        Medidor = analogRead(RESISTOR);
        if (Medidor) {
          Const = Medidor * Vin;
          Vout = (Const) / 1024.0;
          Const = (Vin / Vout) - 1;
          R1 = R2 * Const;
        }
        Serial.print("Resistencia: ");
        Serial.println(R1);
        Modulo_Bluetooth.print(R1);
        Modulo_Bluetooth.print(";");
        if (Modulo_Bluetooth.available()) {
          recep = Modulo_Bluetooth.read();
        }
      }
    }

    if (recep == 'C') {
      while (recep == 'C') {
        float Corriente = calculo(500);
        Serial.print("Corriente: ");
        Serial.println(Corriente, 3);
        Modulo_Bluetooth.print(Corriente, 3);
        Modulo_Bluetooth.print(";");
        if (Modulo_Bluetooth.available()) {
          recep = Modulo_Bluetooth.read();
        }
      }
    }
  }

  if (Serial.available()) {
    Modulo_Bluetooth.write(Serial.read());
  }
}

float calculo(int numeroMuestral) {
  float LeerSenso = 0;
  float inten = 0;
  for (int i = 0; i < numeroMuestral; i++) {
    LeerSenso = analogRead(A0) * (5.0 / 1023.0);
    inten = inten + (LeerSenso - 2.5) / Sensibilidad;
  }
  inten = inten / numeroMuestral;
  return (inten);
}
