/********************************************************/
/* Aula 29 - Sensor de Umidade e Temperatura - DHT11    */
/* Nesta programação é realizada a leitura dos dados do */
/* sensor de umidade e temperatura DHT11 alocando-os em */
/* variáveis do tipo String. Na sequência é impresso    */
/* esses dados no monitor serial.                       */
/* Links para obtenção da biblioteca by Adafruit        */
/* http://librarymanager/#DHT11                         */
/* Instalar as duas biblioitecas abaioxo:               */
/* https://github.com/adafruit/DHT-sensor-library       */
/* https://github.com/adafruit/Adafruit_Sensor          */
/********************************************************/

/* Inclui a biblioteca de controle do sensor.           */
#include <DHT.h>
/* Cria o objeto para o sensor no pino A0 do Arduino.   */
DHT sensor(A0, DHT11);
/* Variáveis para armazenar os dados do sensor.         */
String H, T;

void setup(){
  /* Inicia a comunicação serial.                       */
  Serial.begin(9600);
  /* Inicia o sensor.                                   */
  sensor.begin();
}

void loop(){
float  Temp = float(88);
  Serial.println(Temp);
  
//  /* Armazena os dados de umidade convertendo para      */
//  /* String sem casas decimais.                         */
//  H = String(sensor.readHumidity(), 0);
//  /* Armazena os dados de temperatura convertendo para  */
//  /* String com uma casa decimal.                       */
//  T = String(sensor.readTemperature(), 1);
//  /* Imprime os dados no monitor serial.                */
//  Serial.print("Umidade: ");
//  Serial.print(H);
//  /* \t serve para dar um espaço após o símbolo %.      */
//  Serial.print("% \t");
//  Serial.print("Temperatura: ");
//  Serial.print(T);
//  Serial.println("°C");
//  /* Aguarda 2 segundos para a nova leitura.            */
//  delay(2000);
}
