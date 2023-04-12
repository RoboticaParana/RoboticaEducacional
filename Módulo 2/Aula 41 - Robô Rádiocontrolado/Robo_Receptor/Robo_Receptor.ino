/*******************************************************/
/* Aula 41  - Robô Rádio Controlado - Receptor         */
/* Programação do robô constituído pelo chassi 2WD e   */
/* controlado através dos módulos RF 433MHz e joystick */
/* shield.                                             */
/*******************************************************/

/* Define a velocidade de comunicação (em bits por     */
/* segundo) entre os módulos transmissor e receptor.   */
/* Cada equipe deverá configurar uma velocidade para   */
/* evitar a interferência no controle dos seus robôs.  */
/* Valores recomendados: 2000, 2100, 2200, 2300, etc.  */
#define velocidade 2000
/* Define o pino 9 do Arduino para receber os comandos */
/* do receptor RF 433MHz.                              */
#define Pino_Receptor 9
/* Inclui a biblioteca de controle do módulo RF433MHz. */
#include <VirtualWire.h>
/* Inclui a biblioteca de controle da motor shield.    */
#include <AFMotor.h>

/* Variável que armazenará o comando completo.         */
char recebido;

/* Cria o objeto de controle do motor da direita na    */
/* saída 2 da motor shield.                            */
AF_DCMotor Motor_Direita(2);
/* Cria o objeto de controle do motor da esquerda na   */
/* saída 3 da motor shield.                            */
AF_DCMotor Motor_Esquerda(3);
/* Define 4 velocidades para o robô.                  */
int vel_1 = 150;
int vel_2 = 190;
int vel_3 = 220;
int vel_4 = 255;

/* Função das configurações.                           */
void setup() {

  /* Configura o pino de entrada de dados do receptor. */
  vw_set_rx_pin(Pino_Receptor);
  /* Configura a velocidade de comunicação já definida.*/
  vw_setup(velocidade);
  /* Inicializa o receptor RF.                         */
  vw_rx_start();
  Motor_Direita.setSpeed(255);
  Motor_Esquerda.setSpeed(255);
}

/* Looping Principal.                                  */
void loop() {
  /* Chama a função auxiliar que receberá os comandos. */
  receber();
  /* Se o comando recebido for "R", faça...            */
  if (recebido == 'y') {
    mover_para_tras();
  }
  /* Se o comando recebido for "F", faça...            */
  if (recebido == 'Y') {
    mover_para_frente();
  }
  /* Se o comando recebido for "E", faça...            */
  if (recebido == 'x') {
    virar_a_esquerda();
  }
  /* Se o comando recebido for "D", faça...            */
  if (recebido == 'X') {
    virar_a_direita();
  }
  /* Se o comando recebido for "N", faça...            */
  if (recebido == 'N') {
    permanecer_parado();
  }
  /* Se o comando recebido for "1", faça...            */
  if (recebido == '1') {
    /* Defina a potência dos motores para 150.         */
    Motor_Direita.setSpeed(vel_1);
    Motor_Esquerda.setSpeed(vel_1);
  }
  /* Se o comando recebido for "2", faça...            */
  if (recebido == '2') {
    /* Defina a potência dos motores para 190.         */
    Motor_Direita.setSpeed(vel_2);
    Motor_Esquerda.setSpeed(vel_2);
  }
  /* Se o comando recebido for "3", faça...            */
  if (recebido == '3') {
    /* Defina a potência dos motores para 220.         */
    Motor_Direita.setSpeed(vel_3);
    Motor_Esquerda.setSpeed(vel_3);
  }
  /* Se o comando recebido for "4", faça...            */
  if (recebido == '4') {
    /* Defina a potência dos motores para 255.         */
    Motor_Direita.setSpeed(vel_4);
    Motor_Esquerda.setSpeed(vel_4);
  }
}

/* Função auxiliar de captura dos comandos recebidos.  */
void receber() {
  /* Variável utilizada para formar os comandos          */
  /* recebidos via RF 433MHz.                            */
  byte comando[VW_MAX_MESSAGE_LEN];
  /* Variável para o tamanho dos comandos recebidos.     */
  byte tamanho_comando = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(comando, &tamanho_comando)) {

    for (int i = 0; i < tamanho_comando; i++) {
      /* Armazena na variável o comando recebido.      */
      recebido = comando[i];
    }
  }
}
/* Função auxiliar para o robô mover para frente.      */
void mover_para_frente() {
  Motor_Direita.run(FORWARD);
  Motor_Esquerda.run(FORWARD);
}
/* Função auxiliar para o robô permanecer parado.      */
void permanecer_parado() {
  Motor_Direita.run(RELEASE);
  Motor_Esquerda.run(RELEASE);
}
/* Função auxiliar para o robô mover para trás.        */
void mover_para_tras() {
  Motor_Direita.run(BACKWARD);
  Motor_Esquerda.run(BACKWARD);
}
/* Função auxiliar para o robô virar à direita.        */
void virar_a_direita() {
  Motor_Direita.run(FORWARD);
  Motor_Esquerda.run(BACKWARD);
}
/* Função auxiliar para o robô virar à esquerda.       */
void virar_a_esquerda() {
  Motor_Direita.run(BACKWARD);
  Motor_Esquerda.run(FORWARD);
}