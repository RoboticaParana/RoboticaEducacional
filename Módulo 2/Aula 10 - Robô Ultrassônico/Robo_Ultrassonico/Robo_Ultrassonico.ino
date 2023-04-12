/*************************************************************/
/* Aula 10 - Robô Ultrassônico                               */
/* Programação do projeto robô ultrassônico.                 */
/* Ao transferir o código abaixo para seu Arduino, o robô    */
/* será capaz de de mover para frente e ao se aproximar de   */
/* obstáculo, irá realizar uma manobra para desviá-lo.       */
/* Links para obtenção da biblioteca by Adafruit             */
/* http://librarymanager/All#Adafruit#Motor#V1               */
/* https://github.com/adafruit/Adafruit-Motor-Shield-library */
/* Links para obtenção da biblioteca by Erick Simões         */
/* http://librarymanager/All#minimalist#Ultrasonic           */
/* https://github.com/ErickSimoes/Ultrasonic                 */
/*************************************************************/

#include <AFMotor.h>
#include <Ultrasonic.h>
/* Define os pinos para o sensor ultrassônico.              */
#define pino_Trig 10
#define pino_Echo 9
/* Define a potência dos motores: 0 à 255.                  */
int potencia = 200;
/* Define as portas da Motor Shield que estão sendo         */
/* utilizadas.                                              */
AF_DCMotor Motor_Esquerda(2);
AF_DCMotor Motor_Direita(3);
/* Cria o objeto Sensor que realizará a leitura do sensor.  */
Ultrasonic Sensor(pino_Trig, pino_Echo);
/* Variável que armazenará as medidas.                      */
int distancia;
void setup() {
  /* Inicia com os motores parados.                         */
  Motor_Esquerda.run(RELEASE);
  Motor_Direita.run(RELEASE);
  /* Espera 3 segundos para iniciar o movimento do robô.    */
  delay(3000);
}
/* Função que move o robô para Frente.                      */
void frente(int potencia)
{
  Motor_Esquerda.setSpeed(potencia);
  Motor_Direita.setSpeed(potencia);
  Motor_Esquerda.run(FORWARD);
  Motor_Direita.run(FORWARD);
}
/* Função que manobra o robô com 60% de sua velocidade.     */
void manobra(int potencia)
{
  Motor_Esquerda.setSpeed(potencia * 0.6);
  Motor_Direita.setSpeed(potencia * 0.6);
  Motor_Esquerda.run(RELEASE);
  Motor_Direita.run(RELEASE);
  delay(500);
  Motor_Esquerda.run(FORWARD);
  Motor_Direita.run(BACKWARD);
  delay(1000);
  Motor_Esquerda.run(RELEASE);
  Motor_Direita.run(RELEASE);
  delay(500);
}
void loop() {
  /* Armazena a distância na variável "distancia".          */
  distancia = Sensor.read();
  /* Se a distância for menor ou igual a 40cm, realize a    */
  /* manobra do robô.                                       */
  if (distancia <= 40)
  {
    /* Chama a função responsável pela manobra.             */
    manobra(potencia);
  }
  /* Senão siga em frente.                                  */
  else
  {
    /* Chama a função mover para frente.                    */
    frente(potencia);
  }
}
