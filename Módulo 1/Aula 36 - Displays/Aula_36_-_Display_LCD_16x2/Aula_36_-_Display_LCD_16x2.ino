/*******************************************************/
/* Aula 36 - Display LCD 16x2                          */
/* Programação: Nesta aula, programamos uma tela de LCD*/
/* composta por 16 colunas e duas linhas.              */
/* Na tela aparecerá as palavras "Robotica Parana" e   */
/* "Display LCD 16X2", deslizando de um lado para outro*/
/* sobre o efeito de rolagem (scroll).                 */
/*******************************************************/

/* Inclui a Biblioteca de controle do LCD.             */
#include <LiquidCrystal.h>
/* Cria um objeto de controle lcd definindo seus pinos;*/
/* RS = 12, E = 11, D4 = 5, D5 = 4, D6 = 3 e D7 = 2.   */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  /* inicializa o objeto de controle do LCD;           */
  lcd.begin(16, 2);
}

void loop()
{
  /* Posiciona o cursor na coluna 4, linha 0;          */
  lcd.setCursor(4, 0);
  /* Envia o texto entre aspas para o LCD;             */
  lcd.print("Robotica");
  /* Posiciona o cursor na coluna 5, linha 1;          */
  lcd.setCursor(5, 1);
  /* Envia o texto entre aspas para o LCD;             */
  lcd.print("Parana");
  delay(2000);
  lcd.clear();
  /* Posiciona o cursor na coluna 3, linha 0;          */
  lcd.setCursor(3, 0);
  /* Envia o texto entre aspas para o LCD;             */
  lcd.print("Display");
  /* Posiciona o cursor na coluna 3, linha 1;          */
  lcd.setCursor(3, 1);
  /* Envia o texto entre aspas para o LCD;             */
  lcd.print("LCD 16X2");
  delay(2000);
  lcd.clear();
}
