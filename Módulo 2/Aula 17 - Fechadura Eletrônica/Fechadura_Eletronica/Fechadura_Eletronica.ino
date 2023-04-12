/***************************************************************/
/* Aula 17 - Fechadura Eletrônica                              */
/* Programação da Fechadura Eletrônica.                        */
/* Ao transferir o código abaixo para seu Arduino, vocêpoderá  */
/* utilizar o protótipo da fechadura eletrônica do seguinte    */
/* modo: ao digitar uma sequência de caracteres, através do    */
/* teclado matricial de membrana, o Arduino irá comparar com a */
/* senha definida na linha 26 deste sketch.                    */
/* Caso a senha não coincidir, a fechadura será mantida        */
/* trancada (LED Vermelho aceso e Servo Motor na posição 90º), */
/* caso os caracteres coincidam, a fechadura será destrancada  */
/* (LED Verde aceso e Servo Motor na posição 180º). Para       */
/* trancar novamente, basta pressionar as teclas * ou #.       */
/* O estado da fechadura também pode ser acompanhadao através  */
/* do Monitor Serial do Arduino IDE.                           */
/* Links para obtenção da biblioteca by Comunity https://...   */
/* http://librarymanager/All#keypad#upon                       */
/* https://github.com/Chris--A/keypad                          */
/***************************************************************/
#include <Keypad.h>
/* Inclui a bliblioteca de controle do Servo Motor.         */
#include<Servo.h>
/* Cria o objeto de controle do Servo Motor.                */
Servo servo;
/* Define a senha para destravar a fechadura.               */
char* password = "123";
/* Quantidade de caracteres que a senha possui.             */
int caracteres = 3;
/* Define os pinos dos LEDs e Servo Motor.                  */
#define ledVermelho 12
#define ledVerde 11
#define Pin_Servo 10
/* Variável de controle.                                    */
int posicao = 0;
/* Define o número de linhas e colunas do teclado matricial */
/* de membrana.                                             */
#define qtdLinhas 4
#define qtdColunas 4
/* Construção da matriz de caracteres.                      */
char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
/* Define os pinos de controle de linhas e colunas.         */
byte PinosqtdLinhas[qtdLinhas] = {9, 8, 7, 6};
byte PinosqtdColunas[qtdColunas] = {5, 4, 3, 2};
/* Cria o objeto de controle do teclado.                    */
Keypad meuteclado = Keypad( makeKeymap(matriz_teclas), PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas);
void setup() {
  /* Configura os pinos dos LEDs como saída.                */
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  /* Endereça o objeto de controle ao pino definido para    */
  /* controle do Servo Motor.                               */
  servo.attach(Pin_Servo);
  /* Inicia a comunicação Serial em 9600 bauds.             */
  Serial.begin(9600);
  /* Imprime a frase no Monitor Serial.                     */
  Serial.println("Entre com a senha...");
  /* Pula uma linha no Monitor Serial.                      */
  Serial.println();
  /* Inicia com a fechadura trancada */
  trancada();
}
void loop() {
  /* Armazena na variável key a tecla pressionada.          */
  char key = meuteclado.getKey();
  /* Se a tecla pressionada for "*" ou "#" reinicia a       */
  /* tentativa com a fechadura trancada.                    */
  if (key == '*' || key == '#') {
    posicao = 0;
    trancada();
  }
  /* Se as teclas pressionadas coincidirem com a senha,     */
  /* destranque a fechadura.                                */
  if (key == password[posicao]) {
    posicao ++;
  }
  if (posicao == caracteres) {
    destrancada();
  }
  /* Pequena pausa para retomar a leitura.                  */
  delay(100);
}
/* Função que mantém a fechadura trancada.                  */
void trancada()
{
  /* LED Vermelho acende.                                   */
  digitalWrite(ledVermelho, HIGH);
  /* LED Verde apaga.                                       */
  digitalWrite(ledVerde, LOW);
  /* Servo na posição trancada.                             */
  servo.write(90);
  /* Imprime a palavra no Monitor Serial.                   */
  Serial.println("TRANCADA");
}
/* Função que mantém a fechadura destrancada.               */
void destrancada()
{
  /* LED Verde acende.                                      */
  digitalWrite(ledVerde, HIGH);
  /* LED Vermelho apaga.                                    */
  digitalWrite(ledVermelho, LOW);
  /* Servo na posição destrancada.                          */
  servo.write(180);
  /* Imprime a palavra no Monitor Serial.                   */
  Serial.println("ABERTA");
}
