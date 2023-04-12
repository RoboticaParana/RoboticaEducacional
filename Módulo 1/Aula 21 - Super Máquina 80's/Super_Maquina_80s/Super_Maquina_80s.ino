/*******************************************************/
/* Aula 21 - Super Máquina 80's                        */
/* Programação do efeito nos LEDs da Super Máquina     */
/* (Carro da série Super Máquina do anos 80).          */
/*******************************************************/

/* Variável do tempo em que os LEDs se alternarão.     */
/* Influenciará na velocidade do efeito.               */
int delay_milis = 30;
void setup() {
  /* Define os pinos de 2 à 6 como saídas */
  for (int i = 2; i <= 6; i++) {
    pinMode(i, OUTPUT);
  }
}
void loop() {
  /* Liga e desliga os LEDs na sequência dos pinos 2 à 6 */
  for (int i = 2; i <= 6; i++) {
    digitalWrite(i, HIGH);
    delay(delay_milis);
    digitalWrite(i, LOW);
    delay(delay_milis);
  }
  /* Liga e desliga os LEDs na sequência dos pinos 6 à 3 */
  for (int i = 6; i >= 3; i--) {
    digitalWrite(i, HIGH);
    delay(delay_milis);
    digitalWrite(i, LOW);
    delay(delay_milis);
  }
}
