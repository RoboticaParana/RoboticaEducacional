/************************************************************/
/* Aula 08 - Painel de Senhas com display LCD 16x2          */
/* Programação do projeto Painel de Senhas.                 */
/* Ao transferir o código abaixo para seu Arduino, será     */
/* apresentado no Display LCD a senha requisitada. Ao       */
/* pressionar os botões, a senha é atualizada para mais ou  */
/* para menos, sempre indicada por um sinal sonoro.         */
/************************************************************/
/* Carrega a biblioteca de controle do LCD                  */
#include <LiquidCrystal.h>
/* Cria o objeto de controle do display LCD definindo os    */
/* pinos do Arduino que serão utilizados para a conexão com */
/* o display LCD.                                           */
/* Sintaxe:                                                 */
/* LiquidCrystal nome_objeto(RS, E, D4, D5, D6, D7);        */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/*  Definições das portas utilizadas.                       */
#define botao_DOWN 6
#define botao_UP 7
#define buzzer 8
/* Variável que armazenará a senha.                         */
int senha = -1;
void setup() {
  /* Inicia o controle do display LCD defindo o número de   */
  /* colunas e linhas.                                      */
  lcd.begin(16, 2);
  /* Configura ospinos de controle dos botões como entrada  */
  /* ativando os resistores internos.                       */
  pinMode(botao_UP, INPUT_PULLUP);
  pinMode(botao_DOWN, INPUT_PULLUP);
  /* Configura o pino de controle do buzzer como saída.     */
  pinMode(buzzer, OUTPUT);
  /* Inicia com a senha zero.                               */
  chamar(+1);
}
void loop() {
  /* Se pressionar o botão UP, chama a função "chamar"      */
  /* incrementando a o  valor da senha.                     */
  if (senha > -1 && digitalRead(botao_UP) == 0) {
    chamar(+1);
  }
  /* Se pressionar o botão DOWN, chama a função "chamar"    */
  /* decrementando o valor da senha.                        */
  if (senha > 0 && digitalRead(botao_DOWN) == 0) {
    chamar(-1);
  }
}
/* Função responsável por imprimir a senha no display.      */
void chamar(int botao)
{
  tone(buzzer, 262, 250);
  delay(250);
  tone(buzzer, 2093, 400);
  delay(400);
    senha = senha + botao;
  lcd.clear();
  /* Posiciona o cursor na coluna 0 e linha 0.              */
  lcd.setCursor(0, 0); 
  lcd.print("Painel de Senhas");
  /* Posiciona o cursor na coluna 0 e linha 1.              */
  lcd.setCursor(0, 1); 
  lcd.print("Senha: " + String(senha));
}
