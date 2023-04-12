/***************************************************/
/* Aula 5  - Semáforo completo com display         */
/* Programação de um semáforo completo com botão e */
/* display com quatro dígitos contador de tempo de */
/* travessia restante para pedestres.              */
/***************************************************/
/* Baixe a biblioteca através do link abaixo       */
/*                                                 */
/* http://librarymanager/All#TM1637#I2C-Like       */
/*                                                 */
/***************************************************/

/* Inclui a biblioteca de controle do display.     */
#include <TM1637Display.h>

/* Cria a variável para armazenar a contagem.      */
int contador;

/* Definições dos pinos utilizados. O módulo aceita*/
/* pinos analógicos e digitais.                    */
#define CLK A4
#define DIO A5

/* Definição dos pinos de controle dos LEDs do    */
/* semáforo.                                       */
#define Verde_Carros 2
#define Amarelo_Carros 3
#define Vermelho_Carros 4
#define Verde_Pedestres 5
#define Vermelho_Pedestres 6

/* Definição do pino de controle do botão.        */
#define botao 1

/* Cria o objeto de controle para o display        */
/* mencionando os pinos utilizados do Arduino.     */
TM1637Display display(CLK, DIO);

/* Início das configurações.                       */
void setup() {
  /* Define o brilho do display (0 a 15).          */
  display.setBrightness(15);
  /* Garantimos que o display inicie desligado.    */
  display.clear();
  /* Definimos o pino do botão como entrada.       */
  pinMode(botao, INPUT);
  /* Definimos os pinos dos LEDs como saídas.      */
  pinMode(Verde_Carros, OUTPUT);
  pinMode(Amarelo_Carros, OUTPUT);
  pinMode(Vermelho_Carros, OUTPUT);
  pinMode(Verde_Pedestres, OUTPUT);
  pinMode(Vermelho_Pedestres, OUTPUT);
}/* Fim das configurações.                         */

/* Inicio do looping infinito.                     */
void loop() {
  /* Se o botão for pressionado, faça...           */
  if (digitalRead(botao) == 0) {
    /* Aguarda 2 segundos.                         */
    delay(2000);
    /* Desliga o LED Verde dos carros.             */
    digitalWrite(Verde_Carros, 0);
    /* Liga o LED Amarelo dos carros.              */
    digitalWrite(Amarelo_Carros, 1);
    /* Aguarda 5 segundos.                         */
    delay(5000);
    /* Inicia o contador em 15 segundos.           */
    contador = 15;
    /* Inicia a contagem até 15.                   */
    for (int count = 0; count < 16; count++) {
      /* Se o contador for maior que 5, faça...    */
      if (contador > 5) {
        /* Desliga o LED Amarelo dos carros.       */
        digitalWrite(Amarelo_Carros, 0);
        /* Liga o LED Vermelho dos carros.         */
        digitalWrite(Vermelho_Carros, 1);
        /* Liga o LED Verde dos pedestres.         */
        digitalWrite(Verde_Pedestres, 1);
        /* Desliga o LED Vermelho dos Ppedestres.  */
        digitalWrite(Vermelho_Pedestres, 0);
        /* Se o contador não for maior que 5, então*/
        /* inicia a sequência que faz o LED        */
        /* Vermelho dos pedestres piscar, indicando*/
        /* o fim do tempo de travessia.            */
      } else {
        /* Desliga o LED Verde dos pedestres.      */
        digitalWrite(Verde_Pedestres, 0);
        if (fmod(contador, 2) == 0) {
          /* Desliga o LED Vermelho dos pedestres. */
          digitalWrite(Vermelho_Pedestres, 0);
        } else {
          /* Liga o LED Vermelho dos pedestres.    */
          digitalWrite(Vermelho_Pedestres, 1);
        }
      }
      /* Mostra no display o tempo restante de     */
      /* travessia, sem os zeros à esquerda do     */
      /* número.                                   */
      display.showNumberDec(contador, false);
      /* Após, decrementa 1 do tempo restante.     */
      contador += -1;
      /* Espera 1 segundo para atualizar o contador*/
      delay(1000);
    }
    /* Limpa o display.                            */
    display.clear();
    /* Se o botão não for pressionado, mantenha os */
    /* LEDs da seguinte forma:                     */
  } else {
    /* Liga o LED Verde dos carros.                */
    digitalWrite(Verde_Carros, 1);
    /* Desliga o LED Amarelo dos carros.           */
    digitalWrite(Amarelo_Carros, 0);
    /* Desliga o LED Vermelho dos carros.          */
    digitalWrite(Vermelho_Carros, 0);
    /* Desliga o LED Verde dos pedestres.          */
    digitalWrite(Verde_Pedestres, 0);
    /* Liga o LED Vermelho dos pedestres.          */
    digitalWrite(Vermelho_Pedestres, 1);
  }
}/* Fim do looping infinito.                       */
