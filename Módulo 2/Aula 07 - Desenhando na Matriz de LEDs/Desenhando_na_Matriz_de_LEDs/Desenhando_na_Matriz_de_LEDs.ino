/************************************************************/
/* Aula 07 - Desenhando na Matriz de LEDs                   */
/* Programação do Módulo Matriz de LED 8x8.                 */
/* Ao transferir o código abaixo para seu Arduino, será     */
/* apresentado no Display 8x8, uma imagem de um coração     */
/* pulsante.                                                */
/* Links para obtenção da biblioteca by Eberhard Fahle      */
/* http://librarymanager/All#LedControl#well                */
/* https://github.com/danidask/MatrizLed                    */
/************************************************************/

#include <LedControl.h>
/* Declaramos os pinos: (DIN, CLK, CS,nº de displays          */
/*conectados em série).                                       */
LedControl lc = LedControl(8, 10, 9, 1);
/* Pausa entre os batimentos do coração.                      */
int tempo = 500;
/* Codigo binário dos corações (0 = desligado e 1 = ligado)   */
/* Coração pequeno.                                           */
byte Coracao_Peq[] = {
  B00001100,
  B00011110,
  B00111110,
  B01111100,
  B01111100,
  B00111110,
  B00011110,
  B00001100
};
/* Coração grande.                                            */
byte Coracao_Gra[] = {
  B00011110,
  B00111111,
  B01111111,
  B11111110,
  B11111110,
  B01111111,
  B00111111,
  B00011110
};
void setup() {
  /* Inicia a matriz de LED. O número zero representa o      */
  /* endereço da primeira matiz de LED conectada ao Arduino. */
  /* Podemos conectar até um máximo de 5 matrizes em série   */
  /* endereçadas de 0 a 4.                                   */
  lc.shutdown(0, false);
  /* Define o brilho dos LEDs na matriz de endereço 0 para   */
  /* o valor 10. (A intensidade varia de 0 a 15).            */
  lc.setIntensity(0, 10);
  /* Desliga todos os LEDs da matriz de endereço 0.          */
  lc.clearDisplay(0);
}
void loop() {
  /* Chama a função que gera a imagem do coração pequeno.    */
  mostra_coracao_peq();
  /* Pausa entre os pulsos do coração.                       */
  delay(tempo);
  /* Chama a função que gera a imagem do coração grande.     */
  mostra_coracao_gra();
  /* Pausa entre os pulsos do coração.                       */
  delay(tempo);
}
/* Função para gerar o coração pequeno.                      */
void mostra_coracao_peq()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, Coracao_Peq[i]);
  }
}
/* Função para gerar o coração grande.                       */
void mostra_coracao_gra()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, Coracao_Gra[i]);
  }
}
