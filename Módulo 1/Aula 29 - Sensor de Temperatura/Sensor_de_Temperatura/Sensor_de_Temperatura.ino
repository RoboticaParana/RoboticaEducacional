/****************************************************************/
/* Aula 29 - Sensor de Temperatura                              */
/* Programação: Realiza a leitura da temperatura nas escalas    */
/* Celsius, Fahrenheit e Kelvin através do sensor LM35.         */
/* Links para obtenção da biblioteca LM35 by WILMOUTH Steven    */
/* http://librarymanager/All#allows#lm35                        */
/* https://github.com/wilmouths/LM35                            */
/****************************************************************/

/* Inclui a biblioteca LM35 Sensor                              */
#include <LM35.h>
/* Cria o objeto "sensor" conectado à porta analógica A0.       */
LM35 sensor(A0);
/* Cria as variáveis que armazenarão as temperaturas.           */
float Temp_Cel;
float Temp_Fah;
float Temp_Kel;

void setup() {
  /* Inicia a comunicação serial com velocidade de 9600 bauds.  */
  Serial.begin(9600);
}

void loop() {
  /* Realiza a leitura das temperaturas.                        */
  Temp_Cel = sensor.getTemp(CELCIUS);
  Temp_Fah = sensor.getTemp(FAHRENHEIT);
  Temp_Kel = sensor.getTemp(KELVIN);
  /* Escreve no monitor serial as temperaturas obtidas.         */
  Serial.println(String("Temperatura: ")+Temp_Cel+String("°C"));
  Serial.println(String("Temperatura: ")+Temp_Fah+String("°F"));
  Serial.println(String("Temperatura: ")+Temp_Kel+String("K"));
  Serial.println("");
  /* Aguarda 3 segundos para realizar a nova leitura.           */
  delay(3000);
}
