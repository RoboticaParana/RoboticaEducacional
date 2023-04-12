/************************************************************/
/* Aula 30 - Receptor IR e Controle Remoto                  */
/* Programação do Receptor IR.                              */
/* O primeiro passo é colar, nas linhas 29, 30, 31 e 32 os  */
/* códigos capturados das teclas de seu controle remoto.    */
/* Após, ao transferir este código para seu Arduino, você   */
/* poderá acionar as três cores do LED RGB através das      */
/* teclas configuradas (1, 2, 3 e 4) do controle remoto.    */
/************************************************************/
/* Inclui a biblioteca de controle do Receptor IR. Caso     */
/* desejar instalar via arquivo zip, realize o download da  */
/* biblioteca através do link abaixo:                       */
/* https://github.com/Arduino-IRremote/Arduino-IRremote/archive/refs/heads/master.zip */

/* Links para obtenção da biblioteca by Adafruit            */
/* http://librarymanager/All#IRemote                    */
/* https://github.com/adafruit/DHT-sensor-library           */
/* https://github.com/adafruit/Adafruit_Sensor              */
/************************************************************/

#include <IRremote.h>
/* Define o pino que receberá os dados do receptor IR.      */
int Pino_receptor = 7;
/* Variável que armazenará os códigos das teclas.           */
float armazenavalor;
/* Pinos do LED RGB.                                        */
int Led_Vermelho = 8;
int Led_Azul = 9;
int Led_Verde = 10;
/* Códigos hexadecimais obtidos das teclas 1 a 4. Você      */
/* deverá alterar pelos códigos capturados de seu controle  */
/* realizado através do código anterior. Observe que os     */
/* códigos devem iniciar com o prefixo “0x” para que o      */
/* Arduino entenda que se trata de um código hexadecimal e  */
/* não simplesmente números e letras.                       */
unsigned long tecla_1 = 0xCOLE_AQUI_SEU_CÓDIGO;
unsigned long tecla_2 = 0xCOLE_AQUI_SEU_CÓDIGO;
unsigned long tecla_3 = 0xCOLE_AQUI_SEU_CÓDIGO;
unsigned long tecla_4 = 0xCOLE_AQUI_SEU_CÓDIGO;
void setup()
{
  /* Inicia o Receptor IR no pino definido.                 */
  IrReceiver.begin(Pino_receptor);
  /* Define os pinos do LED RGB como saída.                 */
  pinMode(Led_Vermelho, OUTPUT);
  pinMode(Led_Verde, OUTPUT);
  pinMode(Led_Azul, OUTPUT);
}
void loop()
{
  /* Se o Receptor receber dados.                           */
  if (IrReceiver.decode())
  {
    /* Armazena o código recebido na variável.              */
    armazenavalor = IrReceiver.decodedIRData.decodedRawData;
    /* Se a tecla 1 for acionada, faz...                    */
    if (armazenavalor == tecla_1)
    {
      /* Liga somente o LED Vermelho.                       */
      digitalWrite(Led_Vermelho, HIGH);
      digitalWrite(Led_Azul, LOW);
      digitalWrite(Led_Verde, LOW);
    }
    /* Se a tecla 2 for acionada, faz...                    */
    if (armazenavalor == tecla_2)
    {
      /* Liga somente o LED Azul.                           */
      digitalWrite(Led_Vermelho, LOW);
      digitalWrite(Led_Azul, HIGH);
      digitalWrite(Led_Verde, LOW);
    }
    /* Se a tecla 3 for acionada, faz...                    */
    if (armazenavalor == tecla_3) {
      /* Liga somente o LED Verde.                          */
      digitalWrite(Led_Vermelho, LOW);
      digitalWrite(Led_Azul, LOW);
      digitalWrite(Led_Verde, HIGH);
    }
    /* Se a tecla 4 for acionada, faz...                    */
    if (armazenavalor == tecla_4)
    {
      /* Desliga todos os LEDs.                             */
      digitalWrite(Led_Vermelho, LOW);
      digitalWrite(Led_Verde, LOW);
      digitalWrite(Led_Azul, LOW);
    }
    /* Reinicia o Receptor para a nova captura.             */
    IrReceiver.resume();
  }
}
