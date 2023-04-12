/* Código de operação para um Semáforo */

#define LED_Vermelho 8 /* Define o pino 8 como "LED_Vermelho" */
#define LED_Amarelo 9 /* Define o pino 9 como "LED_Amarelo" */
#define LED_Verde 10 /* Define o pino 10 como "LED_Verde" */

void setup() {
  pinMode(LED_Vermelho, OUTPUT);/* Define o Led Vermelho como  Saída */
  pinMode(LED_Amarelo, OUTPUT); /* Define o Led Amarelo como  Saída */
  pinMode(LED_Verde, OUTPUT);/* Define o Led Verde como  Saída */
}

void loop() { /* Primeiro estágio: Aberto (5 segundos) */
  digitalWrite(LED_Vermelho, LOW);
  digitalWrite(LED_Amarelo, LOW);
  digitalWrite(LED_Verde, HIGH);
  delay(5000);
  /* Segundo estágio: Atenção (3 segundos) */
  digitalWrite(LED_Vermelho, LOW);
  digitalWrite(LED_Amarelo, HIGH);
  digitalWrite(LED_Verde, LOW);
  delay(3000);
  /* Terceiro estágio: Fechado (5 segundos) */
  digitalWrite(LED_Vermelho, HIGH);
  digitalWrite(LED_Amarelo, LOW);
  digitalWrite(LED_Verde, LOW);
  delay(5000);
}
