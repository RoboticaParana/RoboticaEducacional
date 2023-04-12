/************************************************************/
/* Aula 30 - Receptor IR e Controle Remoto                  */
/* Programação do Receptor IR.                              */
/* Ao transferir o código abaixo para seu Arduino, abra o   */
/* Monitor Serial do Arduino IDE. Será solicitado que você  */
/* pressione as 4 teclas númericas do controle remoto (1, 2,*/
/* 3 e 4), uma de cada vez. Ao executar essa ação, será     */
/* exibido na tela, os códigos hexadecimais correspondente a*/
/* cada tecla. Anote-os para posteriormente inseri-los no   */
/* outro código fonte desta aula.                           */
/* Links para obtenção da biblioteca by Adafruit            */
/* http://librarymanager/All#IRremote#Apple                 */
/* https://github.com/Arduino-IRremote/Arduino-IRremote     */
/************************************************************/

#include <IRremote.h>
/* Define o pino que receberá os dados do Receptor IR.      */
int Pino_receptor = 7;
void setup()
{
  /* Inicia a comunicação serial na velocidade 9600 bauds.  */
  Serial.begin(9600);
  /* Inicia o Receptor IR no pino definido.                 */
  IrReceiver.begin(Pino_receptor);
  /* Imprime as instruções a serem seguidas.                */
  Serial.println("Pressione as teclas 1, 2, 3 e 4, nessa ordem, ");
  Serial.println("caso cometa algum erro, feche e abra novamente ");
  Serial.println("o Monitor Serial para reiniciar a operação.");
  /* Pula uma linha.                                        */
  Serial.println("");
  /* Loop para repetir 4 vezes a captura de tecla.          */
  for (int tecla = 1; tecla <= 4; tecla++) {
    /* Aguarda uma tecla ser pressionada.                   */
    while (!IrReceiver.decode()) {}
    /* Imprime o código hexadecimal da tecla pressionada.   */
    Serial.print("Código hexadecimal da tecla ");
    Serial.print(tecla);
    Serial.print(": ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    /* Pequena pausa.                                       */
    delay(600);
    /* Reinicia o Receptor IR para a nova captura.          */
    IrReceiver.resume();
  }
  /* Mensagem de FIM e orientação do próximo passo.         */
  Serial.println("");
  Serial.println("FIM...");
  Serial.println("Insira os valores no próximo código-fonte ");
  Serial.println("de programação.");
}
/* Como a coleta de dados é realizada apenas uma vez, os    */
/* comandos foram inseridos dentro da função setup(), sendo */
/* assim, a função loop() permanecerá vazia.                */
void loop () {}
