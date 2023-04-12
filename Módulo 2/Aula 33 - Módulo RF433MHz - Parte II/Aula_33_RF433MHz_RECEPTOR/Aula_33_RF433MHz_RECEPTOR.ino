/*************************************************************/
/*          Aula 33 – Módulo RF 433MHz - RECEPTOR            */
/* Programação do Módulo RF 433MHz - Receptor. O código      */
/* permite o protótipo aguardar por uma informação (uma      */
/* palavra) enviada pelo módulo Transmissor, para ligar ou   */
/* desligar um LED.                                          */
/*************************************************************/
/* A dupla (Transmissor e Receptor) deverão definir na       */
/* programação (na linha 12) qual a palavra que servirá de   */
/* comando para seus protótipos, evitando interferência com  */
/* os demais protótipos da turma.                            */
/* Links para obtenção da biblioteca.                        */
/* http://www.airspayce.com/mikem/arduino/RadioHead/RadioHead-1.41.zip */
/***********************************************************************/

const String palavra = "pressionado";
/* Inclui as bibliotecas de controle do módulo RF 433MHz.    */
#include <RH_ASK.h>
#include <SPI.h>
/* Cria o objeto "radio" para a comunicação.                 */
RH_ASK radio;
/* Define o pino do LED.                                     */
#define pinoLed 2
/* Variável que armazena o estado do LED:                    */
/* 0 = desligado | 1 = Ligado                                */
int statusLed = 0;
/* Variável que armazenará a palavra recebida.               */
String palavra_recebida = "";

void setup() {
  /* Inicializa a comunicação do módulo RF 433MHz.           */
  radio.init();
  /* Define o pino do LED como saída.                        */
  pinMode(pinoLed, OUTPUT);
  /* Inicia com o LED desligado.                             */
  digitalWrite(pinoLed, LOW);
}
void loop() {
  /* Recebe a mensagem do transmissor.                       */
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  /* Determina o comprimento da mensagem recebida.           */
  uint8_t buflen = sizeof(buf);
  /* Se o receptor recebeu corretamente a mensagem, faz...   */
  if (radio.recv(buf, &buflen)) {
    /* Limpa a variável para receber a mensagem.             */
    palavra_recebida = "";
    /* Faz um loop para montar a palavra letra por letra.    */
    for (int i = 0; i < buflen; i++) {
      palavra_recebida += (char)buf[i];
    }
    /* Verifica se a palavra recebida é a correta e se o LED */
    /* está desligado, então faz...                          */
    if ((palavra_recebida == palavra) && (statusLed == 0)) {
      /* Atualiza o status do LED para ligado (1).           */
      statusLed = 1;
      /* Liga o LED.                                         */
      digitalWrite(pinoLed, HIGH);
      /* senão, faz...                                       */
    } else {
    /* Verifica se a palavra recebida é a correta e se o LED */
    /* está ligado, então faz...                             */
    if ((palavra_recebida == palavra) && (statusLed == 1)) {
      /* Atualiza o status do LED para desligado (0).        */
      statusLed = 0;
      /* Desliga o LED.                                      */
      digitalWrite(pinoLed, LOW);
      }
    }
  }
}
