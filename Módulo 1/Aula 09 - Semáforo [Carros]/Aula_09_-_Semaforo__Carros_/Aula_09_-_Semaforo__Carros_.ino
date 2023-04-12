/* Código de operação para um Semáforo    */

/* Definições para os pinos dos LEDs      */
#define LED_Vermelho 8
#define LED_Amarelo 9
#define LED_Verde 10

void setup() {
  /* Configura os pinos LEDs como SAÍDA.  */
  pinMode(LED_Vermelho, OUTPUT);
  pinMode(LED_Amarelo, OUTPUT);
  pinMode(LED_Verde, OUTPUT);
}

void loop() { 
  /* Primeiro estágio: Aberto (5 segundos) */
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
