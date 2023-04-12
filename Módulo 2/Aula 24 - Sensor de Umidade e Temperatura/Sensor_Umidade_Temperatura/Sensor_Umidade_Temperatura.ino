/************************************************************/
/* Aula 24 - Sensor de Umidade e Temperatura                */
/* Programação do Sensor de Umidade e Temperatura.          */
/* Ao transferir o código abaixo para seu Arduino, o sensor */
/* de Umidade e Temperatura DHT11 irá monitorar as condições*/
/* do ambiente e enviará dados analógicos ao Arduino, e com */
/* o auxílio da bibliteca DHT, obterá as informações de     */
/* umidade e temperatura que serão exibidas no Monitor      */
/* Serial do Arduino IDE.                                   */
/* Links para obtenção da biblioteca by Adafruit            */
/* http://librarymanager/All#DHT11#DHT22                    */
/* https://github.com/adafruit/DHT-sensor-library           */
/* https://github.com/adafruit/Adafruit_Sensor              */
/************************************************************/

#include <DHT.h>
/* Cria o objeto dht para controle do Sensor DHT11 através  */
/* da porta analógica A0.                                   */
DHT dht(A0, DHT11);
void setup()
{
  /* Inicia a comunicação Serial com velocidade 9600 bauds. */
  Serial.begin(9600);
  /* Inicia o objeto de controle do Sensor DHT11.           */
  dht.begin();
}
void loop()
{
  /* Realiza a leitura do Sensor e armazena os dados nas    */
  /* variáveis h e t.                                       */
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  /* Elimina as casas decimais da umidade.                  */
  String H = String(h, 0);
  /* Define a temperatura com uma casa decimal.             */
  String T = String(t, 1);
  /* Escreve no Monitor Serial os valores lidos de Umidade  */
  /* e Temperatura.                                         */
  Serial.print("Umidade: ");
  Serial.print(H);
  Serial.print("%");
  Serial.print("\t");
  Serial.print("Temperatura: ");
  Serial.print(T);
  Serial.println("°C");
  /* Aguarda 2 segundos para a nova leitura.                */
  delay(2000);
}
