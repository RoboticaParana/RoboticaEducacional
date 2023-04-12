/****************************************************/
/* Aula 36 - Display OLED 128x64 - I2C              */
/* Programação para escrita com efeito scoll no     */
/* display OLED 128x64 - I2C.                       */
/****************************************************/
/* Baixe as bibliotecas através dos links           */
/*                                                  */
/* http://librarymanager/All#SSD1306#Adafruit       */
/* Biblioteca: Adafuit SSD1306 by Adafruit          */
/*                                                  */
/* http://librarymanager/All#GFX#class#that         */
/* Biblioteca: Adafuit GFX Library by Adafruit      */
/*                                                  */
/****************************************************/
/* Inclui as bibliotecas para o controle do display.*/
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

/* Cria o objeto de controle para o display OLED.   */
Adafruit_SSD1306 display(128, 64, &Wire, -1);

/* Configurações.                                   */
void setup() {
  /* Inicia o display OLED, através de seu endereço */
  /* físico 0X3C.                                   */
  display.begin(SSD1306_SWITCHCAPVCC, 0X3C);
  /* Limpa o display ao iniciar.                    */
  display.clearDisplay();
  /* Define o tamanho da fonte como o dobro da padrão.*/
  display.setTextSize(2);
  /* Posiciona o cursor na coordenada x e y informada.*/
  display.setCursor(0, 18);
  /* Define a cor da fonte: Claro (1) - Escuro (0).   */
  display.setTextColor(1);
  /* Imprime a palavra Robotica no display.           */
  display.print("Robotica");
  /* Posiciona o cursor na coordenada x e y informada.*/
  display.setCursor(0, 34);
  /* Imprime a palavra Parana no display.             */
  display.print("Parana");
  /* Atualiza o display  para aplicar as escritas.    */
  display.display();
}/* Fim das configurações.                            */
/* Looping infinito.                                  */
void loop() {
  /* Inicia a rolagem para a direita.                 */
  display.startscrollright(0x00, 0x0F);
  /* Aguarda a rolagem por 2,1 segundos.              */
  delay(2100);
  /* Inicia a rolagem para a esquerda.                */
  display.startscrollleft(0x00, 0x0F);
  /* Aguarda a rolagem por 2,1 segundos.              */
  delay(2100);
} /* Fim do looping infinito.                         */
