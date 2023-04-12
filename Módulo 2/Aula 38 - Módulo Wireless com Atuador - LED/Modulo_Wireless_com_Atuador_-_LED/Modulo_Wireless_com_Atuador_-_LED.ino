/************************************************************/
/* Aula 38 – Módulo Wi-Fi com Atuadores (LED) */
/* Programação do Módulo ESP-01 no modo servidor. */
/* Ao programá-lo e reiniciá-lo, conecte seu dispositivo */
/* à rede WiFi criada e acesse, através de um navegador */
/* o endereço http://192.168.4.1/ para ter acesso ao seu */
/* interruptor wireless do LED. */
/************************************************************/
/* Inclui as bibliotecas do Módulo WiFi. */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
/* Defina um nome para a sua rede. */
const char *nome_da_rede = "ROBOTICA";
/* Defina uma senha para a sua rede (mínimo 8 caracteres). */
const char *senha = "12345678";
/* Define o pino GPIO2 do ESP-01 para controlar o LED. */
int pino_LED = 2;
/* Cria um servidor web na porta 80. */
ESP8266WebServer servidor(80);
/* Variáveis que armazenarão os códigos da página HTML. */
String page = "";
String ligado = "";
String desligado = "";
void setup()
{
  /* Página HTML. */
  page = "<html>\n"
         "\n"
         "<style>\n"
         "body {\n"
         "background: #009541; \n"
         "}\n"
         ".button {\n"
         "background-color: #312682;\n"
         "border: none;\n"
         "color: white;\n"
         "padding: 15px 32px;\n"
         "text-align: center;\n"
         "display: inline-block;\n"
         "font-size: 48px;\n"
         "margin: 4px 2px;\n"
         "cursor: pointer;\n"
         "border-radius: 12px;\n"
         "width: 450px;\n"
         "}\n"
         "\n"
         ".disabled {\n"
         "opacity: 0.5;\n"
         "color: black;\n"
         "}\n"
         "</style>\n"
         "<section><center>\n"
         "<br><br>\n"
         "<font size=\"6\"> \n"
         "<h1>&#129302; "
         "ROB&Oacute;TICA PARAN&Aacute; "
         "&#129302; </h1>\n"
         "<h1>Aula 38 - IoT com Atuadores</h1>\n"
         "<p><h1>&#128246; "
         "Controle Wireless do LED&#128161;</h1>\n"
         "</font>\n";
  /* Código HTML do botão LIGADO. */
  ligado = "<p><a href=\"/desligar\">"
           "<button class=\"button button\">"
           "LIGADO</button></a>\n"
           "</center></section>\n"
           "</html>";
  /* Código HTML do botão DESLIGADO. */
  desligado = "<p><a href=\"/ligar\">"
              "<button class=\"button disabled\">"
              "DESLIGADO</button></a>\n"
              "</center></section>\n"
              "</html>";
  /* Fim dos códigos da página HTML. */
  /* Define o pino do LED como saída. */
  pinMode(LED_BUILTIN, OUTPUT);
  /* Inicia com o LED desligado. */
  digitalWrite(pino_LED, LOW);
  /* Cria o ponto de acesso com o nome e a senha definida. */
  WiFi.softAP(nome_da_rede, senha);
  /* Requisição da página principal, envia ao cliente a */
  /* página com o botão DESLIGADO. */
  servidor.on("/", []() {
    servidor.send(200, "text/html", page + desligado);
  });
  /* Requisição do botão DESLIGADO, envia ao cliente a */
  /* a página com o botão LIGADO e liga o LED. */
  servidor.on("/ligar", []() {
    servidor.send(200, "text/html", page + ligado);
    digitalWrite(pino_LED, HIGH);
  });
  /* Requisição do botão LIGADO, envia ao cliente a */
  /* página com o botão DESLIGADO e desliga o LED. */
  servidor.on("/desligar", []() {
    servidor.send(200, "text/html", page + desligado);
    digitalWrite(pino_LED, LOW);
  });
  /* Inicia o servidor. */
  servidor.begin();
}
void loop()
{
  /* Função que monitora se o cliente requisitou uma página */
  /* e direciona para a requisição correspondente. */
  servidor.handleClient();
}
