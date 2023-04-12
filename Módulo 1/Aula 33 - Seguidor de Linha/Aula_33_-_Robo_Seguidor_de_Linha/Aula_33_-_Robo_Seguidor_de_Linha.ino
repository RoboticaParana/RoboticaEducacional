/*************************************************************/
/* Aula 33 - Robô Seguidor de Linha                          */
/* Programação: Nesta programação é realizado o              */
/* controle dos motores a partir das informações obtidas dos */
/* dois sensores de obstáculos IR.                           */
/* Quando os dois sensores não detectarem a linha, enviarão  */
/* o nível lógico 0 para o Arduino, o qual fará os dois      */
/* motores seguirem em frente. Quando os dois sensores       */
/* detectarem a linha, enviarão o nível lógico 1 para o      */
/* Arduino, o qual fará os motores pararem. Quando apenas um */
/* sensor (direita ou esquerda) detectar a linha, enviará 
/* níveis lógicos alternados 0 e 1 ou 1 e 0 ao Arduino, o    */
/* qual fará o controle da direção que o robô deverá tomar   */
/* para centralizar o chassi à linha.                        */
/* Links para obtenção da biblioteca by Adafruit             */
/* http://librarymanager/All#Adafruit#Motor#V1               */
/* https://github.com/adafruit/Adafruit-Motor-Shield-library */
/*************************************************************/

/* Inclui a Biblioteca AFMotor para controle do motor. */
#include <AFMotor.h>
/* Variáveis que armazenam a leitura dos sensores de
  obstáculo IR. */
int Sensor_Direita;
int Sensor_Esquerda;
int velocidade = 150;
/* Define os pinos 9 e 10 para os sensores IR */
#define Pin_Sensor_Direita 9
#define Pin_Sensor_Esquerda 10
/* Define Motor_Esquerda como posição 2 de controle para motor */
AF_DCMotor Motor_Esquerda(4); 
/* Define Motor_Direita como posição 3 de controle para motor */
AF_DCMotor Motor_Direita(3); 
void setup() {
  /* Inicia com os motores parados */
  Motor_Esquerda.run(RELEASE); 
  Motor_Direita.run(RELEASE);
}
void loop() {
  /* Sensores realizam a leitura */
  Sensor_Direita = digitalRead(Pin_Sensor_Direita);
  Sensor_Esquerda = digitalRead(Pin_Sensor_Esquerda);
  /* Nenhum sensor detectou a linha */
  if ((Sensor_Esquerda && Sensor_Direita) == 0) {
    /* Define as velocidades dos motores */
    Motor_Esquerda.setSpeed(velocidade);
    Motor_Direita.setSpeed(velocidade);
    /* Robô move para frente */
    Motor_Esquerda.run(FORWARD);
    Motor_Direita.run(FORWARD);
  }
  /* Sensor da direita detectou a linha */
  if ((Sensor_Esquerda == 1) && (Sensor_Direita == 0)) {
    /* Define as velocidades dos motores */
    Motor_Esquerda.setSpeed(velocidade);    
    Motor_Direita.setSpeed(velocidade);
    /* Robô vira à direita */
    Motor_Esquerda.run(FORWARD); 
    Motor_Direita.run(BACKWARD);
  }
  /* Sensor da esquerda detectou a linha */
  if ((Sensor_Esquerda == 0) && (Sensor_Direita == 1)) {
    /* Define as velocidades dos motores */
    Motor_Esquerda.setSpeed(velocidade);    
    Motor_Direita.setSpeed(velocidade);
    /* Robô vira à esquerda */
    Motor_Esquerda.run(BACKWARD); 
    Motor_Direita.run(FORWARD);
  }
  /* Os dois sensores detectaram a linha */
  if ((Sensor_Esquerda && Sensor_Direita) == 1) {
    /* Robô permanece parado */
    Motor_Esquerda.run(RELEASE); 
    Motor_Direita.run(RELEASE);
  }
}
