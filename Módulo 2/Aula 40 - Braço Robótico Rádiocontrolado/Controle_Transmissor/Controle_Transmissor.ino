/*******************************************************/
/* Aula 40 - Braço Robótico Rádio Controlado           */
/* Programação do controle do braço robótico.          */
/* Os quatro botões selecionam o movimento dos quatro  */
/* servos motores e os eixos do joystick, enviam os    */
/* comandos para movê-los.                             */
/*******************************************************/

/* Definição da velocidade de comunicação (em bits por */
/* segundo) entre os módulos transmissor e receptor.   */
/* Cada equipe deverá configurar uma velocidade para   */
/* evitar a interferência no controle dos seus braços. */
/* Valores recomendados: 2000, 2100, 2200, 2300, etc.  */
#define velocidade 2000
/* Define o pino digital 9 do Arduino para enviar os   */
/* comandos ao módulo transmissor RF 433MHz.           */
#define Pino_Transmissor 9
/* Inclui a biblioteca de controle do módulo RF433MHz. */
#include <VirtualWire.h>
/* Criando as variáveis que armazenarão os dados dos   */
/* eixos do joystick e dos quatro botões.              */
  int JoyX;
  int JoyY;
  int estadoBotaoA;
  int estadoBotaoB;
  int estadoBotaoC;
  int estadoBotaoD;
/* Função para configurações.                          */
void setup()
{
  /* Função que informa à biblioteca qual o pino       */
  /* utilizado para a transmissão.                     */
  vw_set_tx_pin(Pino_Transmissor);
  /* Função que informa à biblioteca qual a velocidade */
  /* utilizada para a transmissão dos dados.           */
  vw_setup(velocidade);
  /* Configura as portas digitais de cada botão como   */
  /* entradas ativando os resistores internos.         */
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}
/* Looping Principal.                                  */
void loop() {
  /* Chama a função auxiliar que realiza a leitura da  */
  /* Joystick Shield.                                  */
  checar_joystick();
  /* Enquanto o eixo do joystick for deslocado para a  */
  /* esquerda, faça...                                 */
  while (JoyX < 300) {
    /* Chame a função auxiliar para enviar o comando x.*/
    enviar_comando("x");
  }
  /* Enquanto o eixo do joystick for deslocado para a  */
  /* direita, faça...                                  */
  while (JoyX > 700) {
    /* Chame a função auxiliar para enviar o comando X.*/
    enviar_comando("X");
  }
  /* Enquanto o eixo do joystick for deslocado para    */
  /* trás, faça...                                     */
  while (JoyY < 300) {
    /* Chame a função auxiliar para enviar o comando y.*/
    enviar_comando("y");
  }
  /* Enquanto o eixo do joystick for deslocado para    */
  /* frente, faça...                                   */
  while (JoyY > 700) {
    /* Chame a função auxiliar para enviar o comando Y.*/
    enviar_comando("Y");
  }
  /* Enquanto o botão A do joystick for pressionado,   */
  /* faça...                                           */
  while (estadoBotaoA == LOW) {
    /* Chame a função auxiliar para enviar o comando G.*/
    enviar_comando("G");
  }
  /* Enquanto o botão B do joystick for pressionado,   */
  /* faça...                                           */
  while (estadoBotaoB == LOW) {
    /* Chame a função auxiliar para enviar o comando D.*/
    enviar_comando("D");
  }
  /* Enquanto o botão C do joystick for pressionado,   */
  /* faça...                                           */
  while (estadoBotaoC == LOW) {
    /* Chame a função auxiliar para enviar o comando B.*/
    enviar_comando("B");
  }
  /* Enquanto o botão D do joystick for pressionado,   */
  /* faça...                                           */
  while (estadoBotaoD == LOW) {
    /* Chame a função auxiliar para enviar o comando E.*/
    enviar_comando("E");
  }
  /* Se não houver interação com o joystick shield,    */
  /* chame a função auxiliar para enviar o comando N.  */
    enviar_comando("N");
}

/* Função auxiliar para envio dos comandos.            */
void enviar_comando(const char *msg) {
  /* Enviando o comando.                               */
  vw_send((uint8_t *)msg, strlen(msg));
  /* Aguarda até que o comando seja enviado.           */
  vw_wait_tx();
  /* Chame a função auxiliar para checar o joystick.   */
  checar_joystick();
}
/* Função auxiliar para realizar a leitura do joystick.*/
void checar_joystick() {
  JoyX = analogRead(A0);
  JoyY = analogRead(A1);
  estadoBotaoA = digitalRead(2);
  estadoBotaoB = digitalRead(3);
  estadoBotaoC = digitalRead(4);
  estadoBotaoD = digitalRead(5);
}
