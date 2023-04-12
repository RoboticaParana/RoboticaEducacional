/* Projeto 2: Ligando três LEDs com três resistores */

/* Definições para os pinos dos LEDs                */
#define Pin_led1 8
#define Pin_led2 9
#define Pin_led3 10

void setup() {
  /* Configura os pinos LEDs como SAÍDA.           */
  pinMode(Pin_led1, OUTPUT);
  pinMode(Pin_led2, OUTPUT);
  pinMode(Pin_led3, OUTPUT);
}
void loop() {
  /* Liga os  LEDs                                 */
  digitalWrite(Pin_led1, HIGH);
  digitalWrite(Pin_led2, HIGH);
  digitalWrite(Pin_led3, HIGH);
  /* Aguarda 1 segundo                             */
  delay(1000);
  /* Desliga os LEDs                               */
  digitalWrite(Pin_led1, LOW);
  digitalWrite(Pin_led2, LOW);
  digitalWrite(Pin_led3, LOW);
  /* Aguarda 1 segundo                             */
  delay(1000);
}
