/*******************************************************/
/* Aula 35 - Sensor de Estacionamento                  */
/* Programação: Nesta aula, programamos o módulo sensor*/
/* ultrassônico HC - SR04 para simular um sensor de    */
/* estacionamento. Conforme um obstáculo se aproxima   */
/* do sensor um aviso sonoro será emitido através do   */
/* buzzer, aumentando a intensidade dos bips quanto    */
/* menor a distância.                                  */
/* Links para obtenção da biblioteca by Erick Simões   */
/* http://librarymanager/All#minimalist#Ultrasonic     */
/* https://github.com/ErickSimoes/Ultrasonic           */
/*******************************************************/

#include <Ultrasonic.h>

int pino_Trig = 3,pino_Echo = 4, distancia;

Ultrasonic meusensor(pino_Trig, pino_Echo);

int pino_buzzer = 2, frequencia = 3500;

void setup() {
  pinMode(pino_buzzer, OUTPUT);
}//setup

void loop() {
 
  distancia = Sensor.read();

  if (distancia < 80 && distancia > 50) {
    tone(pino_buzzer, frequencia, 100);
    delay(1000);
  }//if

  if (distancia < 50 && distancia > 30) {
    tone(pino_buzzer, frequencia, 100);
    delay(700);
  }//if

  if (distancia < 30 && distancia > 20) {
    tone(pino_buzzer, frequencia, 100);
    delay(300);
  }//if
 
  if (distancia < 20 && distancia > 10) {
    tone(pino_buzzer, frequencia, 100);
    delay(150);
  }//if
 
  if (distancia < 10) {
    tone(pino_buzzer, frequencia);
  }//if

}//loop
