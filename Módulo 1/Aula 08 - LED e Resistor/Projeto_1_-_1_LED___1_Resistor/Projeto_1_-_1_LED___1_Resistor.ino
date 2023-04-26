/* Projeto 1: Ligando um LED com resistor */
int Pin_led = 7; /* Define o controle do LED através do pino 7. */
void setup() {
  pinMode(Pin_led, OUTPUT); /* Define o pino de controle do LED como SAÍDA. */
}
void loop() {
  digitalWrite(Pin_led, HIGH); /* Energiza o pino 7 (liga o  LED). */
  delay(1000); /* Aguarda 1 segundo. */
  digitalWrite(Pin_led, LOW); /* Desenergiza o pino 7 (desliga o LED). */
  delay(1000); /* Aguarda 1 segundo. */
}
