/* Projeto 2: Ligando três LEDs com três resistores */
int Pin_led1 = 8; /* Define o controle do LED 1 através do  pino 8. */
int Pin_led2 = 9; /* Define o controle do LED 2 através do  pino 9. */
int Pin_led3 = 10; /* Define o controle do LED 3 através do  pino 10. */
void setup() {
  pinMode(Pin_led1, OUTPUT); /* Define o pino de controle do  LED 1 como SAÍDA. */
  pinMode(Pin_led2, OUTPUT); /* Define o pino de controle do  LED 2 como SAÍDA. */
  pinMode(Pin_led3, OUTPUT); /* Define o pino de controle do  LED 3 como SAÍDA. */
}
void loop() {
  digitalWrite(Pin_led1, HIGH); /* Energiza o pino 8 (liga o  LED 1). */
  digitalWrite(Pin_led2, HIGH); /* Energiza o pino 9 (liga o  LED 2). */
  digitalWrite(Pin_led3, HIGH); /* Energiza o pino 10 (liga o  LED 3). */
  delay(1000); /* Aguarda 1 segundo. */
  digitalWrite(Pin_led1, LOW); /* Desenergiza o pino 8  (desliga o LED 1). */
  digitalWrite(Pin_led2, LOW); /* Desenergiza o pino 9  (desliga o LED 2). */
  digitalWrite(Pin_led3, LOW); /* Desenergiza o pino 10  (desliga o LED 3). */
  delay(1000); /* Aguarda 1 segundo. */
}
