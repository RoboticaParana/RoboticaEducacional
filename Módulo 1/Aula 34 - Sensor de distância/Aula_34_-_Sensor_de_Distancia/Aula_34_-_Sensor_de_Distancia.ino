/*******************************************************/
/* Aula 34 - Sensor de distância                       */
/* Programação: Nesta aula, programamos o módulo sensor*/
/* ultrassônico HC - SR04 para realizar a medida da    */
/* distância de obstáculos a sua frente. A distância   */
/* é acompanhada através do monitor serial do software */
/* Arduino IDE.                                        */ 
/* Links para obtenção da biblioteca by Erick Simões   */
/* http://librarymanager/All#minimalist#Ultrasonic     */
/* https://github.com/ErickSimoes/Ultrasonic           */
/*******************************************************/

/* Inclui a Biblioteca de controle do sensor.          */
#include <Ultrasonic.h>
/* Definição dos pinos para o sensor.                  */
int pino_Trig = 2;
int pino_Echo = 3;
/* Cria o objeto Sensor para realizar a leitura.       */
Ultrasonic Sensor(pino_Trig, pino_Echo);
/* Variável que armazenará as medidas.                 */
int distancia;
void setup() {
/* Inicia a comunicação serial na velocidade 9600.     */
Serial.begin(9600);
}
void loop() {
/* Realiza a medição e armazena na variável “distancia” */
distancia = Sensor.read();
/* Imprime no Monitor Serial os valores das medidas a   */
/* cada 0,5 segundos.                                   */
Serial.print("Distância: ");
Serial.print(distancia);
Serial.println("cm");
delay(500);
}
