/************************************************************/
/* Aula 36 - Comunicação do Módulo Wireless em HTML         */
/* Programação do Módulo ESP-01 no modo servidor.           */
/* ATENÇÃO! Nas linhas 18 e 20 você deverá criar um nome    */
/* para a sua rede WiFi e definir uma senha com no mínimo   */
/* oito caracteres.                                         */
/* Ao carregar e reiniciar, aguarde alguns segundos para    */
/* conectar seu dispositivo à rede WiFi criada e acesse,    */
/* através de um navegador o endereço http://192.168.4.1/   */
/* para ter acesso à página HTML criada nesta programação.  */
/************************************************************/
/* Inclui as bibliotecas do Módulo WiFi.                    */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
/* Defina um nome para a sua rede.                          */
const char *nome_da_rede = "ALTERAR";
/* Defina uma senha para a sua rede (mínimo 8 caracteres).  */
const char *senha = "12345678";
/* Cria um servidor web na porta 80.                        */
ESP8266WebServer servidor(80);
void setup()
{
  /* Cria o ponto de acesso com o nome e a senha definida.  */
  WiFi.softAP(nome_da_rede, senha);
  /* Quando o cliente requisitar a página válida é chamada a*/
  /* função "Pagina_Requisitada".                           */
  servidor.on("/", Pagina_Requisitada);
  /* Quando o cliente requisitar a página inválida é chamada*/
  /* a função "Pagina_Inexistente".                         */
  servidor.onNotFound(Pagina_Inexistente);
  /* Inicia o servidor.                                     */
  servidor.begin();
}
void loop()
{
  /* Função que monitora se o cliente requisitou a página e */
  /* direciona às funções: "Pagina_Requisitada" ou          */
  /* "Pagina_Inexistente".                                  */
  servidor.handleClient();
}
/* Função que direciona à página HTML.                      */
void Pagina_Requisitada() {
  /* Envia para o cliente, chamando a função "Monta_HTML"   */
  servidor.send(200, "text/html", Monta_HTML());
}
/* Função que direciona à página Inexistente.               */
void Pagina_Inexistente() {
  servidor.send(404, "text/html",
                "<H1><!DOCTYPE html><html>"
                "P&aacute;gina n&atilde;o encontrada"
                "</H1></html>");
}
/* Função que monta a página HTML a ser enviada ao cliente. */
String Monta_HTML() {
  String ptr = "";
  ptr += "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" "
         "content=\"width=device-width, initial-scale=1.0,"
         "user-scalable=no\">\n";
  ptr += "<title>ROB&Oacute;TICA PARAN&Aacute;</title>\n";
  ptr += "<style>html { font-family: Helvetica; "
         "display: inline-block; margin: 0px auto; "
         "text-align: center;}\n";
  ptr += "body{margin-top: 50px; background: #009541;} "
         "h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr += "p {font-size: 24px;color: "
         "#444444;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";
  ptr += "<h1>&#129302; ROB&Oacute;TICA PARAN&Aacute; "
         "&#129302;</h1>\n";
  ptr += "<h2>Aula 36 - Comunica&ccedil;&atilde;o do "
         "M&oacute;dulo WI-FI em HTML</h1>\n";
  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
