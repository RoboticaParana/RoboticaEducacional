/****************************************************/
/* Aula 9 - Enviando Mensagens no display OLED      */
/* Programação do projeto enviando mensagens.       */
/* Ao transferir o código abaixo para seu Arduino,  */
/* será possível, através do monitor  serial do     */
/* Arduino IDE, enviar mensagens de texto para o    */
/* display OLED.                                    */
/****************************************************/
/* Se necessário, baixe as bibliotecas através dos  */
/* links abaixo.                                    */
/*                                                  */
/* http://librarymanager/All#SSD1306#Adafruit       */
/* Biblioteca: Adafuit SSD1306 by Adafruit          */
/*                                                  */
/* http://librarymanager/All#GFX#class#that         */
/* Biblioteca: Adafuit GFX Library by Adafruit      */
/***************************************************/
/* Inclusão das duas bibliotecas necessárias.      */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/* Variável para armazenar a mensagem              */
String msg;
/* Variável para controlar a linha do display      */
int linha;
/* Cria o objeto de controle para o display OLED.  */
Adafruit_SSD1306 display(128, 64, &Wire, -1);

/* Início das configurações.                       */
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(300); /* Tempo que o Arduino irá esperar para recever a msg. */
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Inicializa o display OLED com o endereço 0x3C
  display.clearDisplay(); // Limpa o display
  tela_inicial();
}

void loop() {
  if (Serial.available()) { // Verifica se há dados disponíveis na porta serial
    
    msg = Serial.readString(); // Lê o próximo caractere da porta serial
    
    if (msg == "%") { // Se o caractere for %, limpa o display
      display.clearDisplay();
      linha = 0;
    }
    else if (msg == ">") { // Se o caractere for %, limpa o display
      linha += 8;
    }
    else {
      display.setCursor(0, linha);
      display.print(msg);
    }
  }
  display.display();
}

void tela_inicial() {
  display.drawRect(0, 0, 128, 64, 1);
  display.drawFastHLine(0, 14, 128, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(4, 4);
  display.print("ESCREVA SUA MENSAGEM");
  display.setCursor((128-6*8)/2, 20);
  display.setTextSize(1);
  display.print("Aten");
  display.write(135);
  display.write(126);
  display.write(111);
  display.write(19);
  display.setCursor(70, 20);
  display.write(97);
  display.setCursor(4, 30);
  display.setTextSize(1);
  display.print(" Utilize o comando % para nova mensagem e > para nova linha.");
  display.display();
  linha = 0;
}
