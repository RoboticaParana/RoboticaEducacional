/*************************************************************/
/*          Aula 33 – Módulo RF 433MHz - TRANSMISSOR         */
/* Programação do Módulo RF 433MHz - Transmissor. O código   */
/* permite enviar uma informação (palavra: pressionado) por  */
/* meio do módulo transmissor RF433MHz ao pressionar o botão.*/
/*************************************************************/
/* Declara a constante do tipo char para armazenar a palavra */
/* que será utilizada como comando para acionar o LED.       */
const char *palavra = "pressionado";
/* Inclui as bibliotecas de controle do módulo RF 433MHz.    */
#include <RH_ASK.h>
#include <SPI.h>
/* Cria o objeto "radio" para a comunicação.                 */
RH_ASK radio;
/* Define o pino do Push-Button.                             */
#define pinoBotao 2

void setup() {
  /* Inicializa a comunicação do módulo RF 433MHz.           */
  radio.init();
  /*  Configura o pino do do botão como entrada ativando o   */
  /* resistor interno.                                       */
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  /* Se o botão for pressionado, faz...                      */
  if (digitalRead(pinoBotao) == LOW) {
    /* Envia a palavra para o receptor.                      */
    radio.send((uint8_t *)palavra, strlen(palavra));
    /* Aguarda o envio das informações.                      */
    radio.waitPacketSent();
    /* Intervalo para nova leitura do botão.                 */
    delay(200);
  }
}
