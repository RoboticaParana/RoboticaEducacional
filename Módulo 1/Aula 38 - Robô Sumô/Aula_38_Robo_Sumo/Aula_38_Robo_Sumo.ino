/********************************************************/
/* Aula 38 - Robô Sumô                                  */
/* Programação do robô sumô. O robô conta com dois      */
/* sensores de obstáculo InfraVermelho que o permite    */
/* permanecer dentro do dojô e um sensor de distância   */
/* ultrassônico que o ajudará a detectar o adversário.  */
/* Links para obtenção da biblioteca by Erick Simões    */
/* http://librarymanager/All#minimalist#Ultrasonic      */
/* https://github.com/ErickSimoes/Ultrasonic            */
/********************************************************/

/* Inclui a Biblioteca AFMotor para controle do motor. */
#include <AFMotor.h>
/* Inclui a Biblioteca do sensor ultrassônico.         */
#include <Ultrasonic.h>
/* Definição dos pinos para os sensores.               */
#define pino_Trig 9
#define pino_Echo 10
/* O pino 14 equivale ao pino analógico A0.            */
#define pino_IR_traseiro 14
/* O pino 15 equivale ao pino analógico A1.            */
#define pino_IR_dianteiro 15
/* Definindo as variáveis utilizadas no código.        */
int distancia;
int sensor_dianteiro;
int sensor_traseiro;

/* Define a distância para ataque. (cm).               */
int distancia_ataque = 15;
/* Define a velocidade do robô. (0-255).               */
int velocidade = 200;

/* Cria o objeto Sensor para realizar a leitura.       */
Ultrasonic ultrassonico(pino_Trig, pino_Echo);
/* Cria os objetos de controle para os motores         */
/* conectados nas saídas M2 e M3 da Motor Shield.      */
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);

void setup() {
  /* Aguarda 3 segundos para iniciar a disputa.        */
  delay(3000);
  /* Seta a velocidade dos motores.                    */
  motor2.setSpeed(velocidade);
  motor3.setSpeed(velocidade);
}

void loop() {
  /* Chama a função criada para a leitura dos sensores.*/
  ler_sensores();
  /* Se o sensor dianteiro detectar a linha, faça...   */
  if (sensor_dianteiro == 1) {
    Pare();
    Re();
    Pare();
    Manobre();
    Pare();
  }
  /* Se o sensor traseiro detectar a linha, faça...    */
  if (sensor_traseiro == 1) {
    Pare();
    Ataque();
    delay(500);
    motor2.setSpeed(velocidade);
    motor3.setSpeed(velocidade);
  }
  /* Se o sensor ultassônico detectar o adversário,    */
  /* faça...                                           */
  if (distancia <= distancia_ataque) {
    /*  Enquanto o sensor dianteiro não chegar até a   */
    /* linha, faça...                                  */
    while (sensor_dianteiro == 0) {
      Ataque();
    }
  }
  /* Chama a função que move o robô par frente.        */
  Frente();
}

/* Funções criadas para operação do robô sumô.         */

/* Função ára leitura dos sensores.                    */
void ler_sensores() {
  distancia = ultrassonico.read();
  sensor_dianteiro = digitalRead(pino_IR_dianteiro);
  sensor_traseiro = digitalRead(pino_IR_traseiro);
}

/* Função mover robô para frente.                      */
void Frente() {
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  delay(1);
}

/* Função mover robô para trás.                        */
void Re() {
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  delay(500);
}

/* Função parar o robô.                                */
void Pare() {
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(1);
}

/* Função ataque do robô.                              */
void Ataque() {
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  delay(1);
}

/* Função parar manobrar o robô.                       */
void Manobre() {
  if (random(1, 3) == 1) {
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    delay(1);
  } else {
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
  }
  delay(250);
}
