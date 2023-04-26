/* Código de Funcionamento para um Semáforo de Cruzamento */
/* Define as portas dos LED’s do semáforo 1 */
#define LED_Vermelho_1 2
#define LED_Amarelo_1 3
#define LED_Verde_1 4
/* Define as portas dos LED’s do semáforo 2 */
#define LED_Vermelho_2 5
#define LED_Amarelo_2 6
#define LED_Verde_2 7


void setup() {
  /* Define todos os pinos dos LED’s como SAÍDA */
  pinMode(LED_Vermelho_1, OUTPUT);
  pinMode(LED_Amarelo_1, OUTPUT);
  pinMode(LED_Verde_1, OUTPUT);
  pinMode(LED_Vermelho_2, OUTPUT);
  pinMode(LED_Amarelo_2, OUTPUT);
  pinMode(LED_Verde_2, OUTPUT);
}
void loop() {
  /* Primeiro estágio: Semáforo 1 ABERTO e Semáforo 2 FECHADO (5 segundos) */
  digitalWrite(LED_Vermelho_1, LOW);
  digitalWrite(LED_Amarelo_1, LOW);
  digitalWrite(LED_Verde_1, HIGH);
  digitalWrite(LED_Vermelho_2, HIGH);
  digitalWrite(LED_Amarelo_2, LOW);
  digitalWrite(LED_Verde_2, LOW);
  delay(5000);
  /* Segundo estágio: Semáforo 1 ATENÇÃO E Semáforo 2 FECHADO (3 segundos) */
  digitalWrite(LED_Vermelho_1, LOW);
  digitalWrite(LED_Amarelo_1, HIGH);
  digitalWrite(LED_Verde_1, LOW);
  digitalWrite(LED_Vermelho_2, HIGH);
  digitalWrite(LED_Amarelo_2, LOW);
  digitalWrite(LED_Verde_2, LOW);
  delay(3000);
  /* Terceiro estágio: Semáforo 1 Fechado e Semáforo 2 Aberto (5 segundos) */
  digitalWrite(LED_Vermelho_1, HIGH);
  digitalWrite(LED_Amarelo_1, LOW);
  digitalWrite(LED_Verde_1, LOW);
  digitalWrite(LED_Vermelho_2, LOW);
  digitalWrite(LED_Amarelo_2, LOW);
  digitalWrite(LED_Verde_2, HIGH);
  delay(5000);
  /* Quarto estágio: Semáforo 1 FECHADO e Semáforo 2 ATENÇÃO (3 segundos) */
  digitalWrite(LED_Vermelho_1, HIGH);
  digitalWrite(LED_Amarelo_1, LOW);
  digitalWrite(LED_Verde_1, LOW);
  digitalWrite(LED_Vermelho_2, LOW);
  digitalWrite(LED_Amarelo_2, HIGH);
  digitalWrite(LED_Verde_2, LOW);
  delay(3000);
}
