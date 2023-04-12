/* Projeto 3: Ligando três LEDs com um resistor     */

/* Definições para os pinos dos LEDs                */
#define Pin_led1 8
#define Pin_led2 9
#define Pin_led3 10

void setup() {
  /* Configura os pinos LEDs como SAÍDA.            */
  pinMode(Pin_led1, OUTPUT);
  pinMode(Pin_led2, OUTPUT);
  pinMode(Pin_led3, OUTPUT);
}
void loop() {
  /* Liga o LED 1                                   */
  digitalWrite(Pin_led1, HIGH);
  /* Aguarda 0,2 segundos                           */
  delay(200);
  /* Desliga o LED 1                                */
  digitalWrite(Pin_led1, LOW);
  /* Liga o LED 2                                   */
  digitalWrite(Pin_led2, HIGH);
  /* Aguarda 0,2 segundos                           */
  delay(200);
  /* Desliga o LED 2                                */
  digitalWrite(Pin_led2, LOW);
  /* Liga o LED 3                                   */
  digitalWrite(Pin_led3, HIGH);
  /* Aguarda 0,2 segundos                           */
  delay(200);
  /* Desliga o LED 3                                */
  digitalWrite(Pin_led3, LOW);
  /* Aguarda 0,2 segundos                           */
  delay(200);
}
