/***********************************************/
/* Aula 8  - Painel de Senhas com display OLED */
/*                                             */
/* Programação do projeto Painel de Senhas.    */
/* Ao transferir o código abaixo para seu      */
/* Arduino, será apresentado no Display OLED a */
/* senha requisitada. Ao pressionar os botões, */
/* a senha é atualizada para mais ou para      */
/* menos, sempre acompanhada por um sinal sonoro. */
/***********************************************/
/* Baixe a biblioteca através do link abaixo   */
/*                                             */
/* http://librarymanager/All#SSD1306#Adafruit  */
/* Biblioteca: Adafuit SSD1306 by Adafruit     */
/*                                             */
/* http://librarymanager/All#GFX#class#that    */
/* Biblioteca: Adafruit GFX Library by Adafruit*/
/***********************************************/
/* Inclusão das duas bibliotecas necessárias.  */
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

/* Cria o objeto de controle para o display.   */
Adafruit_SSD1306 display(128, 64, &Wire, -1);

/* Cria a variável que armazenará a senha.     */
int senha = 0;

/* Define os pinos dos botões e buzzer.        */
#define botaoUp 3
#define botaoDown 2
#define buzzer 1

/* Início das configurações.                   */
void setup() {
  /* Inicia o display OLED, através de seu     */
  /* endereço físico 0X3C.                     */
  display.begin(SSD1306_SWITCHCAPVCC, 0X3C);
  /* Define os pinos dos botões como entrada e */
  /* ativa os resistores internos.             */
  pinMode(botaoUp , INPUT_PULLUP);
  pinMode(botaoDown , INPUT_PULLUP);
  /* Define o pino do buzzer como saída.       */
  pinMode(buzzer, OUTPUT);
  /* Define a cor da fonte: Claro(1)|Escuro(0).*/
  display.setTextColor(1);
}/* Fim das configurações.                     */

/* Início do looping infinito.                 */
void loop() {
  /*Posiciona o cursor na coordenada informada.*/
  display.setCursor(18, 0);
  /* Define o tamanho da fonte.                */
  display.setTextSize(1);
  /* Imprime a palavra PAINEL DE SENHAS        */
  display.print("PAINEL DE SENHAS");
  /* Desenha um retângulo sem preenchimento,   */
  /* com origem na coordenada (0, 10), com     */
  /* dimensões 128x47 pixels, raios dos cantos */
  /* arredondados 10 pixels na cor clara.      */
  display.drawRoundRect(0, 10, 128, 47, 10, WHITE);
  /*Posiciona o cursor na coordenada informada.*/
  display.setCursor(20, 57);
  /* Imprime a palavra Rob                     */
  display.print("Rob");
  /* Imprime o caracter ASCII ó                */
  display.write(162);
  /* Imprime a palavra tica Paran              */
  display.print("tica Paran");
  /* Imprime o caracter ASCII á                */
  display.write(160);
  /*Posiciona o cursor na coordenada informada.*/
  display.setCursor(35, 15);
  /* Define o tamanho da fonte.                */
  display.setTextSize(2);
  /* Imprime a palavra SENHA                   */
  display.print("SENHA");
  /*Posiciona o cursor na coordenada informada.*/
  display.setCursor(48, 35);
  /* Se a senha for menor que 10, faça...      */
  if (senha < 10) {
    /* Imprima a senha acrescentando 00        */
    display.print(String("00") + senha);
  }
  /* Se a senha for maior que 9 e menor que    */
  /* 100, faça...                              */
  if ((senha > 9)  &&  (senha < 100)) {
    /* Imprima a senha acrescentando 0         */
    display.print(String("0") + senha);
  }
  /* Se a senha for maior que 99, faça...      */
  if (senha > 99) {
    /* Imprima a senha.                        */
    display.print(senha);
  }
  /* Se o botaoUP for pressionado, faça...     */
  if (digitalRead(botaoUp) == 0) {
    /* Incremente 1 no valor da senha.         */
    senha += 1;
    /* Se a senha for maior que 999, faça...   */
    if (senha > 999) {
      /* Defina o valor da senha para 999.     */
      senha = 999;
    }
    /* Toque no buzzer, a melodia abaixo .     */
    tone(buzzer, 262, 250);
    delay(250);
    tone(buzzer, 2093, 400);
    delay(400);
  }
  /* Se o botaoDown for pressionado, faça...   */
  if (digitalRead(botaoDown) == 0) {
    /* Decremente 1 no valor da senha.         */
    senha += -1;
    /* Se a senha for menor que 0, faça...     */
    if (senha < 0) {
      /* Defina o valor da senha para 0.       */
      senha = 0;
    }
    /* Toque no buzzer, a melodia abaixo .     */
    tone(buzzer, 262, 250);
    delay(250);
    tone(buzzer, 2093, 400);
    delay(400);
  }
  /* Atualiza as informações no display.       */
  display.display();
  /* Limpa o display para a próxima atualização*/
  display.clearDisplay();
}/* Fim do looping infinito.                   */
