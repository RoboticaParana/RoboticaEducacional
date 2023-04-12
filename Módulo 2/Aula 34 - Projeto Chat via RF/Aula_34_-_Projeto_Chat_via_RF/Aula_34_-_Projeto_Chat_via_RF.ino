/************************************************************/
/* Aula 34 – Projeto Chat via RF                            */
/* Programação do Módulo RF 433MHz.                         */
/* Nessa programação criaremos um chat via RF.              */
/* IMPORTANTE!: Para que não ocorra interferência entre     */
/* os prototipos de outras duplas, você e seu amigo deverão */
/* informar na linha 20 deste código, a mesma velocidade de */
/* comunicação: 2000, 2100, 2200, 2300, ...                 */
/* Links para obtenção da biblioteca.                       */
/* http://www.airspayce.com/mikem/arduino/VirtualWire/VirtualWire-1.27.zip */
/***************************************************************************/

/* Inclui a biblioteca de controle do módulo RF.            */
#include <VirtualWire.h>
/* Variável que armazena a mensagem a ser enviada, neste
  caso, com o máximo de 500 caracteres.                     */
char mensagem_a_enviar[500];
/* Variável de controle: (0 - não enviar) e (1 - enviar)    */
int nova_mensagem = 0;
void setup() {
  /* Define a velocidade de comunicação em bits por segundo.
    Deve ser igual nas placas que irão se comunicar.        */
  vw_setup(2000);
  /* Define a porta para o transmissor.                     */
  vw_set_tx_pin(12);
  /* Define a porta para o receptor.                        */
  vw_set_rx_pin(11);
  /* Inicializa o receptor. */
  vw_rx_start();
  /* Inicia a comunicação serial com velocidade de 9600 bauds.*/
  Serial.begin(9600);
}
void loop() {
  /***********************************************************/
  /* Comandos para formar a mensagem a ser enviada.          */
  /***********************************************************/
  /* Variável para os caracteres da mensagem.                        */
  char caracteres_da_mensagem;
  /* Variável para a posição dos caracteres da mensagem.             */
  byte posicao_do_caracter = 0;
  /* Enquanto o monitor serial estiver recebendo 1 ou mais           */
  /* caracteres, faz...                                              */
  while (Serial.available() >= 1) {
    /* Checa se a mensagem não ultrapassou o máximo de caracteres.   */
    if (posicao_do_caracter < 499) {
      delay(10);
      /* Forma a mensagem, unindo caracter por caracter recebido.    */
      caracteres_da_mensagem = Serial.read();
      mensagem_a_enviar[posicao_do_caracter] = caracteres_da_mensagem;
      posicao_do_caracter++;
      mensagem_a_enviar[posicao_do_caracter] = '\0';
    }
    /* Ao terminar de formar a mensagem, altera o estado da variável
      para 1, indicando que a mensagem já pode ser enviada.          */
    nova_mensagem = 1;
  }
  /*******************************************************************/
  
  /*******************************************************************/
  /* Comandos para enviar a mensagens                                */
  /*******************************************************************/
  /* Checa, através do estado da variável, se já pode iniciar o envio*/
  /* da mensagem.                                                    */
  if (nova_mensagem == 1) {
    /* Variável que recebe a mensagem a ser enviada.                 */
    char mss;
    /* Prepara a mensagem para ser enviada.                          */
    sprintf(mss, "%s", mensagem_a_enviar);
    /* Envia a mensagem.                                             */
    vw_send((uint8_t *)mss, strlen(mss));
    /* Aguarda a mensagem ser enviada.                               */
    vw_wait_tx();
    /* Imprime na tela a mensagem que você enviou.                   */
    Serial.print("Você: ");
    Serial.println(mss);
    /* Pequena pausa.                                                */
    delay(600);
    /* Reseta o status da variável de controle.                      */
    nova_mensagem = 0;
  }
  /*******************************************************************/
  
  /*******************************************************************/
  /* Comandos para receber mensagens.                                */
  /*******************************************************************/
  /* Armazena na variável a mensagem recebida.                       */
  byte mensagen_recebida[VW_MAX_MESSAGE_LEN];
  /* Calcula o tamanho da mensagem recebida.                         */
  byte tamanho_mensagen_recebida = VW_MAX_MESSAGE_LEN;
  /* Se a mensagem foi recebida corretamente, faz...                 */
  if (vw_get_message(mensagen_recebida, &tamanho_mensagen_recebida)) {
    /* Imprime na tela a mensagem recebida do seu amigo.             */
    Serial.print("Amigo: ");
    for (int i = 0; i < tamanho_mensagen_recebida; i++) {
      Serial.write(mensagen_recebida[i]);
    }
    Serial.println();
  }
  /*******************************************************************/
}
