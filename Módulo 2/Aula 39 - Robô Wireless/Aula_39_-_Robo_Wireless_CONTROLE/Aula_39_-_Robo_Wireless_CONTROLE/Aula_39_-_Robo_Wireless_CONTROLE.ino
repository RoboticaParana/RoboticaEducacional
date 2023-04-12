/*************************************************************/
/* Aula 39 - Robô Wireless                                   */
/* Programação do Módulo ESP-01.                             */
/* ATENÇÃO! Nas linhas 19 e 21 você deverá criar um nome     */
/* para a sua rede WiFi e definir uma senha com no mínimo    */
/* oito caracteres.                                          */
/* Ao carregar e reiniciar, aguarde alguns segundos para     */
/* conectar seu dispositivo à rede WiFi criada e acesse,     */
/* através de um navegador o endereço http://192.168.4.1/    */
/* para ter acesso ao controle de direção do robô. Os        */
/* comandos serão: Mover para frente, mover para trás, girar */
/* no sentido horário, girar no sentido anti-horário e parar.*/
/*************************************************************/
/* Inclui as bibliotecas do Módulo WiFi.                     */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
/* Defina um nome para a sua rede.                           */
const char *nome_da_rede = "ALTERAR";
/* Defina uma senha para a sua rede (mínimo 8 caracteres).   */
const char *senha = "12345678";
/* Define o pino GPIO2 do ESP-01 para envio dos pulsos.      */
int pino_Pulsos = 2;
/* Cria um servidor web na porta 80.                         */
ESP8266WebServer servidor(80);
/* Variáveis que armazenarão os códigos da página HTML.      */
String pagina = "<html>\n"
                "\n"
                "<style>\n"
                "body {\n"
                /* Código html para a cor de fundo da página.     */
                "background: #009541; \n"
                "}\n"
                /* Código html para configuração dos botões.      */
                ".button {\n"
                "background-color: #312682;\n"
                "border: none;\n"
                "color: white;\n"
                "padding: 15px 32px;\n"
                "text-align: center;\n"
                "display: inline-block;\n"
                "font-size: 64px;\n"
                "margin: 4px 2px;\n"
                "cursor: pointer;\n"
                "border-radius: 100%;\n"
                "width: 150px;\n"
                "height: 150px;\n"
                "}\n"
                "</style>\n"
                "<section><center>\n"
                "<br><br>\n"
                /* Código html para os títulos da página.         */
                "<font size=\"6\"> \n"
                "<h1>&#129302; "
                "ROB&Oacute;TICA PARAN&Aacute; "
                "&#129302; </h1>\n"
                "<h1>&#x1F3AE; "
                "Aula 39 - Rob&ocirc; Wireless "
                "&#128246;</h1>\n"
                /* Código html para o botão Frente.               */
                "<h1>Movimento Pulsado</h1>"
                "<p><a href=\"/frente_p\">"
                "<button class=\"button button\">"
                "&#x2B06;</button></a>\n"
                /* Código html para o botão Esquerda.            */
                "<p><a href=\"/esquerda_p\">"
                "<button class=\"button button\">"
                "&#11013;</button></a>\n"
                /* Código html para o botão Pare.                */
                "<a href=\"/pare\">"
                "<button class=\"button button\">"
                "&#x1F6D1;</button></a>\n"
                /* Código html para o botão Direita.             */
                "<a href=\"/direita_p\">"
                "<button class=\"button button\">"
                "&#10145;</button></a>\n"
                /* Código html para o botão Ré.                  */
                "<p><a href=\"/re_p\">"
                "<button class=\"button button\">"
                "&#11015;</button></a>\n"
                "<BR>"
                "<BR>"
                "<h1>Movimento Cont&iacute;nuo</h1>"
                "</font>\n"
                "<p><a href=\"/frente_c\">"
                "<button class=\"button button\">"
                "&#x2B06;</button></a>\n"
                /* Código html para o botão Pare.                */
                "<p><a href=\"/pare\">"
                "<button class=\"button button\">"
                "&#x1F6D1;</button></a>\n"
                /* Código html para o botão Ré.                  */
                "<p><a href=\"/re_c\">"
                "<button class=\"button button\">"
                "&#11015;</button></a>\n";
/* Fim dos códigos da página HTML.                        */
void setup()
{
  /* Define o pino dos pulsos como saída.                   */
  pinMode(pino_Pulsos, OUTPUT);
  /* Inicia com o pino_Pulsos desligado.                    */
  digitalWrite(pino_Pulsos, LOW);
  /* Cria o ponto de acesso com o nome e a senha definida.  */
  WiFi.softAP(nome_da_rede, senha);
  /* Requisição da página principal, envia ao cliente a     */
  /* página de controle do robô.                            */
  servidor.on("/", []() {
    servidor.send(200, "text/html", pagina);
  });
  /* Requisição do botão FRENTE, envia ao Arduino           */
  /* um pulso de 10 milissegundos.                          */
  servidor.on("/frente_p", []() {
    servidor.send(200, "text/html", pagina);
    pulso(10);
  });
  /* Requisição do botão ESQUERDA, envia ao Arduino         */
  /* um pulso de 20 milissegundos.                          */
  servidor.on("/esquerda_p", []() {
    servidor.send(200, "text/html", pagina);
    pulso(20);
  });
  /* Requisição do botão PARE, envia ao Arduino             */
  /* um pulso de 30 milissegundos.                          */
  servidor.on("/pare", []() {
    servidor.send(200, "text/html", pagina);
    pulso(30);
  });
  /* Requisição do botão DIREITA, envia ao Arduino          */
  /* um pulso de 40 milissegundos.                          */
  servidor.on("/direita_p", []() {
    servidor.send(200, "text/html", pagina);
    pulso(40);
  });
  /* Requisição do botão Ré, envia ao Arduino               */
  /* um pulso de 50 milissegundos.                          */
  servidor.on("/re_p", []() {
    servidor.send(200, "text/html", pagina);
    pulso(50);
  });
  /* Requisição do botão FRENTE contínuo, envia ao          */
  /* Arduino um pulso de 60 milissegundos.                  */
  servidor.on("/frente_c", []() {
    servidor.send(200, "text/html", pagina);
    pulso(60);
  });
  /* Requisição do botão RÉ contínuo , envia ao             */
  /* Arduino um pulso de 70 milissegundos.                  */
  servidor.on("/re_c", []() {
    servidor.send(200, "text/html", pagina);
    pulso(70);
  });
  /* Inicia o servidor.                                     */
  servidor.begin();
}
void loop()
{
  /* Função que monitora se o cliente fez uma requisição   */
  /* e envia o pulso correspondente.                       */
  servidor.handleClient();
}

/* Função responsável por enviar o pulso ao Arduino com a  */
/* duração informada de acordo com a requisição:           */
/* Seguir em frente -> Pulso de 10 milissegundos.          */
/* Girar à esquerda -> Pulso de 20 milissegundos.          */
/* Parar -> Pulso de 30 milissegundos.                     */
/* Girar à direita -> Pulso de 40 milissegundos.           */
/* Ré -> Pulso de 50 milissegundos.                        */
/* Frente contínuo -> Pulso de 60 milissegundos.           */
/* Ré contínuo      -> Pulso de 70 milissegundos.          */
void pulso(int tempo) {
  /* Ativa o pino do pulso.                                */
  digitalWrite(pino_Pulsos, HIGH);
  /* Aguarda a duração do pulso.                           */
  delay(tempo);
  /* Desativa o pino do pulso.                             */
  digitalWrite(pino_Pulsos, LOW);
}
