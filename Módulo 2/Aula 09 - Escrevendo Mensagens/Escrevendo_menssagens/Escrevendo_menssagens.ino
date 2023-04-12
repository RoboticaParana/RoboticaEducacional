/************************************************************/
/* Aula 09 - Enviando Mensagens                             */
/* Programação do projeto enviando mensagens.               */
/* Ao transferir o código abaixo para seu Arduino, será     */
/* possível, através do monitor serial do Arduino IDE,      */
/* enviar mensagens de texto para o display LCD.            */
/************************************************************/
/* Inclui a biblioteca do LCD 16X2.                         */
#include <LiquidCrystal.h>
/* Cria o objeto de controle informando à biblioteca os     */
/* pinos do Arduino que estão conectados ao LCD.            */
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
void setup() {
  /* Inicia a comunicação serial na velocidade de 9600 bauds.*/
  Serial.begin(9600);
  /* Inicia o display LCD com 16 colunas e 2 linhas.         */
  lcd.begin(2, 16);
  /* Limpa a tela do LCD.                                    */
  lcd.clear();
  /* Posiciona o cursor na primeira coluna e primeira linha. */
  lcd.setCursor(0, 0);
  /* Escreve a mensagem.                                     */
  lcd.print("Envie sua");
  /* Posiciona o cursor na primeira coluna e segunda linha.  */
  lcd.setCursor(0, 1);
  /* Escreve a mensagem.                                     */
  lcd.print("menssagem...");
}
void loop()
{
  /* Se a porta serial receber dados, faça...                */
  if (Serial.available())
  {
    /* Armazena os caracteres recebido na variável cr.       */
    char cr = Serial.read();
    /* Se receber o caractere "%" limpe a tela do LCD.       */
    if (cr == '%')
    {
      lcd.clear();
    }
    /* Se receber o caractere ">", posicione o cursor na     */
    /* primeira coluna e segunda linha.                      */
    else if (cr == '>')
    {
      lcd.setCursor(0, 1);
    }
    /* Senão, envie os caracteres recebido para o display    */
    /* LCD.                                                  */
    else
    {
      lcd.write(cr);
    }
  }
}
