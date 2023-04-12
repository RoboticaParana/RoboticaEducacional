/************************************************************/
/* Aula 37 - Módulo Wi-Fi - IoT com Sensor                  */
/* Programação do Módulo ESP-01 no modo servidor.           */
/* ATENÇÃO! Nas linhas 26 e 28 você deverá criar um nome    */
/* para a sua rede WiFi e definir uma senha com no mínimo   */
/* oito caracteres.                                         */
/* Ao carregar e reiniciar, aguarde alguns segundos para    */
/* conectar seu dispositivo à rede WiFi criada e acesse,    */
/* através de um navegador o endereço http://192.168.4.1/   */
/* para ter acesso ao monitor da estação meteorológica.     */
/************************************************************/

/* Inclui as bibliotecas do Módulo Wi-Fi.                   */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
/* Inclui a biblioteca do sensor DHT.                       */
/* Links para obtenção da biblioteca by Adafruit            */
/* http://librarymanager/All#DHT11#DHT22                    */
/* https://github.com/adafruit/DHT-sensor-library           */
/* https://github.com/adafruit/Adafruit_Sensor              */
#include "DHT.h"
/* Define o modelo do sensor DHT11.                         */
#define Modelo DHT11
/* Defina um nome para a sua rede.                          */
const char *nome_da_rede = "ALTERAR";
/* Defina uma senha para a sua rede (mínimo 8 caracteres).  */
const char *senha = "12345678";
/* Cria um servidor web na porta 80. */
ESP8266WebServer servidor(80);
/* Define o pino GPIO2 do ESP-01 para dados do sensor.      */
uint8_t Pino_Sensor = 2;
/* Cria o objeto dht para leitura do sensor.                */
DHT dht(Pino_Sensor, Modelo);
/* Variáveis que armazenam dados do Sensor.                 */
float Temp;
float Umid;
void setup()
{
  /* Ativa o modo entrada de dados no pino do Módulo WI-FI. */
  pinMode(Pino_Sensor, INPUT);
  /* Inicializa o sensor.                                   */
  dht.begin();
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
/* Função que direciona à página da Estação Meterológica.   */
void Pagina_Requisitada() {
  /* Armazena os valores de temperatura e umidade lidas pelo*/
  /* sensor DHT11.                                          */
  Temp = dht.readTemperature();
  Umid = dht.readHumidity();
  /* Envia para o cliente, chamando a função "Monta_HTML"   */
  /* informando os valores lidos pelo sensor.               */
  servidor.send(200, "text/html",
                Monta_HTML(Temp, Umid));
}
/* Função que direciona à página Inexistente.               */
void Pagina_Inexistente() {
  servidor.send(404, "text/html",
                "<H1><!DOCTYPE html>"
                "<html>P&aacute;gina n&atilde;o encontrada"
                "</H1></html>");
}
/* Função que monta a página HTML a ser enviada ao cliente  */
/* atualizando os valores de temperatura e umidade.         */
String Monta_HTML(float temp, float umid) {
  String ptr = "";
  ptr += "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" "
         "content=\"width=device-width, initial-scale=1.0, "
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
  ptr += "<script>\n";
  ptr += "setInterval(loadDoc,200);\n";
  ptr += "function loadDoc() {\n";
  ptr += "var xhttp = new XMLHttpRequest();\n";
  ptr += "xhttp.onreadystatechange = function() {\n";
  ptr += "if (this.readyState == 4 && "
         "this.status == 200) {\n";
  ptr += "document.getElementById(\"webpage\")"
         ".innerHTML =this.responseText}\n";
  ptr += "};\n";
  ptr += "xhttp.open(\"GET\", \"/\", true);\n";
  ptr += "xhttp.send();\n";
  ptr += "}\n";
  ptr += "</script>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";
  ptr += "<h1>ROB&Oacute;TICA PARAN&Aacute;</h1>\n";
  ptr += "<h2>Aula 37 - M&oacute;dulo WI-FI IoT "
         "com Sensor</h2>\n";
  ptr += "<h2>&#127781; Esta&ccedil;&atilde;o "
         "Meteorol&oacute;gica &#127781;</h2>\n";
  ptr += "<p>&#127777; Temperatura: ";
  ptr += (int)Temp;
  ptr += "°C</p>";
  ptr += "<p>&#x1F4A7; Umidade: ";
  ptr += (int)Umid;
  ptr += "%</p>";
  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
