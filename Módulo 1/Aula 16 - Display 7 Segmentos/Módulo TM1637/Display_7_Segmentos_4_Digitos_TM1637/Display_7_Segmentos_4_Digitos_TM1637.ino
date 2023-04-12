/**********************************************/
/* Aula 16 - Display 7 Segmentos              */
/* Programação de um contador com o display   */
/* de 7 segmentos com 4 dígitos.              */
/**********************************************/
/* Baixe a biblioteca através do link abaixo  */
/*                                            */
/* http://librarymanager/All#TM1637#I2C-Like  */
/*                                            */
/**********************************************/
/* Inclui a biblioteca de controle do display */
#include <TM1637Display.h>

/* Definições dos pinos utilizados. O módulo  */
/* aceita pinos analógicos e digitais.        */
#define CLK A4
#define DIO A5

/* Cria o objeto de controle para o display   */
/* mencionando os pinos utilizados do Arduino.*/
TM1637Display display(CLK, DIO);

/* Configurações do programa                  */
void setup() {
  /* Define o brilho do display (0 a 15)      */
  display.setBrightness(15);
}
/* Looping infinito                           */
void loop() {
  /* Loop para a contagem de 0 a 9999         */
  for (int i = 0; i <= 9999; i++) {
    /* Mostra o número atual armazenado na    */
    /* variável (false: sem zeros a esquerda  */
    /* ou true: com zeros a esquerda).        */
    display.showNumberDec(i, false);
    /* Aguarda 1 segundo para o próximo dígito*/ 
    delay(1); 
  }/* Fim do looping da contagem              */
}/* Fim do looping infinito                   */
