/********************************************************/
/* Aula 37  - Trena Digital                             */
/* Programação de uma trena digital que utiliza o       */
/* display LCD 16x02 para exibir o valor da             */
/* obtida do sensor ultrassônico.                       */
/* Links para obtenção da biblioteca by Erick Simões    */
/* http://librarymanager/All#minimalist#Ultrasonic      */
/* https://github.com/ErickSimoes/Ultrasonic            */
/********************************************************/

/* Inclui a biblioteca do sensor ultrassônico.          */
#include <Ultrasonic.h>
/* Define os pinos do Arduino conectados ao sensor.     */
int pino_Trig = 13;
int pino_Echo = 12;
/* Define o objeto "Sensor" para controlar o sensor.    */
Ultrasonic Sensor(pino_Trig, pino_Echo);
/* Inclui a biblioteca de controle do LCD.              */
#include <LiquidCrystal.h>
/* Define o objeto "lcd" para controlar o LCD nos pinos */
/* 2 à 7 do Arduino.                                    */
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
/* Variável que armazenará as medidas do sensor.        */
int distancia;
void setup() {
  /* Inicializa o display definindo o número de colunas */
  /* e linhas.                                          */
  lcd.begin(16, 2);
}
void loop() {
  /* Arnazena na variável "medida" a distância obtida   */
  /* do sensor.                                         */
  distancia = Sensor.read();
  /* Posiciona o cursor do display na coluna 1, linha 0 */
  lcd.setCursor(1, 0);
  /* Excreve as palavras "Trena Digital" na posição     */
  /* definida acima.                                    */
  lcd.print("Trena Digital");
  /* Posiciona o cursor do display na coluna 2, linha 1 */
  lcd.setCursor(2, 1);
  /* Escreve a palavra "Medida: " na posição definida   */
  /* acima.                                             */
  lcd.print("Medida: ");
  /* Posiciona o cursor do display na coluna 9, linha 1 */
  lcd.setCursor(9, 1);
  /* Escreve o valor da variável "distancia" na posição */
  /* definida  acima.                                   */
  lcd.print(distancia);
  /* Posiciona o cursor do display na coluna 12, linha 1*/
  lcd.setCursor(12, 1);
  /* Escreve a unidade de medida "cm" na posição        */
  /* definida  acima.                                   */
  lcd.print("cm");
  /* Aguarda meio segundo para realizar a próxima       */
  /* atualização na medida.                             */
  delay(500);
  /* Limpa o display para realizar a atualização no     */
  /* valor da medida.                                   */
  lcd.clear();
}
