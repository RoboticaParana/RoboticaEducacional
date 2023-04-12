/***************************************************************/
/* Aula 15 - Teclado Matricial de Membrana                     */
/* Programação do teclado matricial de membrana. Após carregar */
/* o código para o Arduino, você poderá acompanhar as teclas   */
/* pressionadas através do monitor Serial.                     */
/* Links para obtenção da biblioteca by Comunity https://...   */
/* http://librarymanager/All#keypad#upon                       */
/* https://github.com/Chris--A/keypad                          */
/***************************************************************/

#include <Keypad.h>
/* Define o número de linhas e colunas do teclado */
const byte qtdLinhas = 4;
const byte qtdColunas = 4;
/* Construção da matriz de caracteres */
char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
/* Pinos utilizados pelas linhas e colunas do teclado */
byte PinosqtdLinhas[qtdLinhas] = {9, 8, 7, 6};
byte PinosqtdColunas[qtdColunas] = {5, 4, 3, 2};
/* Inicializa o teclado */
Keypad meuteclado = Keypad( makeKeymap(matriz_teclas),
                            PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas);
void setup() {
  /* Define a velocidade de comunicação serial em 9600 bauds
  */
  Serial.begin(9600);
  /* Imprime no monitor serial o texto entre aspas */
  Serial.println("Aperte uma tecla...");
  /* Quebra uma linha no monitor serial */
  Serial.println();
}
void loop() {
  /* Armazena o caractere referentente a tecla pressionada */
  char tecla_pressionada = meuteclado.getKey();
  /* Se a variável "tecla_pressionada" receber um novo valor,
    faz... */
  if (tecla_pressionada) {
    /* Imprime o texto entre aspas no monitor serial */
    Serial.print("Tecla pressionada : ");
    /* Imprime o caractere no monitor serial e quebra uma
      linha */
    Serial.println(tecla_pressionada);
  }
}
