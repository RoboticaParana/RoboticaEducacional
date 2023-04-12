/* Projeto 1: Ligando um LED com resistor      */

/* Define o controle do LED através do pino 7  */
#define Pin_led 7

void setup() {
  /* Configura o pino LED como SAÍDA           */
  pinMode(Pin_led, OUTPUT);
}
void loop() {
  /* Liga o  LED                               */
  digitalWrite(Pin_led, HIGH);
  /* Aguarda 1 segundo                         */
  delay(1000);
  /* Desliga o LED                             */
  digitalWrite(Pin_led, LOW);
  /* Aguarda 1 segundo                         */
  delay(1000);
}
