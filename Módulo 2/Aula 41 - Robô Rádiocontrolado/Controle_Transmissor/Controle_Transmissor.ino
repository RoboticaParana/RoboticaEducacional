/*******************************************************/
/* Aula 41  - Robô Rádio Controlado - Transmissor      */
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
/* Define o pino 9 do Arduino para enviar os comandos  */
/* para o Transmissor RF 433MHz.                       */
#define Pino_Transmissor 9
/* Inclui a biblioteca de controle do módulo RF433MHz. */
#include <VirtualWire.h>
/* Variáveis que armazenarão os dados da Joystick Shield*/
int JoyX;
int JoyY;
int estadoB1;
int estadoB2;
int estadoB3;
int estadoB4;
/* Função para as configurações.                       */
void setup()
{
  /* Configura o pino de transmissão de dados.         */
  vw_set_tx_pin(Pino_Transmissor);
  /* Configura a velocidade de comunicação já definida.*/
  vw_setup(velocidade);
  /* Ativa as portas dos botões como entradas e ativa  */
  /* os resistores internos.                           */
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}
/* Looping Principal.                                  */
void loop() {
  /* Chama a função auxiliar para verificar o estado   */
  /* da Joystick Shield.                               */
  checar_joystick();

  /* Se mover o eixo do joystick para a esquerda, faz */
  while (JoyX < 300) {
    /* Envie para a função auxiliar o caractere E.    */
    enviar_comando("E");
  }

  /* Se mover o eixo do joystick para a direita, faz  */
  while (JoyX > 700) {
    /* Envie para a função auxiliar o caractere D.    */
    enviar_comando("D");
  }

  /* Se mover o eixo do joystick para trás, faz...    */
  while (JoyY < 300) {
    /* Envie para a função auxiliar o caractere R.    */
    enviar_comando("R");
  }

  /* Se mover o eixo do joystick para frente, faz...  */
  while (JoyY > 700) {
    /* Envie para a função auxiliar o caractere F.    */
    enviar_comando("F");
  }

  /* Se pressionar o botão A do joystick, faz...      */
  if (estadoB1 == LOW) {
    /* Envie para a função auxiliar o número 4.       */
    enviar_comando("4");
  }

  /* Se pressionar o botão B do joystick, faz...      */
  if (estadoB2 == LOW) {
    /* Envie para a função auxiliar o número 3.       */
    enviar_comando("3");
  }

  /* Se pressionar o botão C do joystick, faz...      */
  if (estadoB3 == LOW) {
    /* Envie para a função auxiliar o número 2.       */
    enviar_comando("2");
  }

  /* Se pressionar o botão D do joystick, faz...      */
  if (estadoB4 == LOW) {
    /* Envie para a função auxiliar o número 1.       */
    enviar_comando("1");
  }
  /* Se o joystick permanecer no centro, faz...       */
  if (( 300 < JoyX < 700) && ( 300 < JoyY < 700)) {
    /* Envie para a função auxiliar o caractere N.    */
    enviar_comando("N");
  }
}

void checar_joystick() {
  /* Realiza a leitura e armazena os dados dos eixos   */
  /* e botões do joysick shield.                       */
  JoyX = analogRead(A0);
  JoyY = analogRead(A1);
  estadoB1 = digitalRead(2);
  estadoB2 = digitalRead(3);
  estadoB3 = digitalRead(4);
  estadoB4 = digitalRead(5);
}

/* Função auxiliar para envio dos caracteres.         */
void enviar_comando(const char *msg) {
  /* Enviando o caractere.                            */
  vw_send((uint8_t *)msg, strlen(msg));
  /* Aguarda até que o caractere seja enviado.        */
  vw_wait_tx();
  /* Chama a função auxiliar para verificar o estado   */
  /* da Joystick Shield.                               */
  checar_joystick();
}
