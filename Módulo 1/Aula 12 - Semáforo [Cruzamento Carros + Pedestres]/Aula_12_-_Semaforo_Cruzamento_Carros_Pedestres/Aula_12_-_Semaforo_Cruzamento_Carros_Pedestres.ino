/* Define as portas de todos os LEDs */
#define LED_Carro_Verde_1 2
#define LED_Carro_Amarelo_1 3
#define LED_Carro_Vermelho_1 4
#define LED_Pedestre_Verde_1 5
#define LED_Pedestre_Vermelho_1 6
#define LED_Carro_Verde_2 8
#define LED_Carro_Amarelo_2 9
#define LED_Carro_Vermelho_2 10
#define LED_Pedestre_Verde_2 11
#define LED_Pedestre_Vermelho_2 12
void setup()
{
  /* Define os pinos de todos os LEDs como SAÍDA */
  pinMode(LED_Carro_Verde_1, OUTPUT);
  pinMode(LED_Carro_Amarelo_1, OUTPUT);
  pinMode(LED_Carro_Vermelho_1, OUTPUT);
  pinMode(LED_Pedestre_Verde_1, OUTPUT);
  pinMode(LED_Pedestre_Vermelho_1, OUTPUT);
  pinMode(LED_Carro_Verde_2, OUTPUT);
  pinMode(LED_Carro_Amarelo_2, OUTPUT);
  pinMode(LED_Carro_Vermelho_2, OUTPUT);
  pinMode(LED_Pedestre_Verde_2, OUTPUT);
  pinMode(LED_Pedestre_Vermelho_2, OUTPUT);
}
void loop()
{
  /* Inicia o loop com todos os LEDs desligados */
  digitalWrite(LED_Carro_Verde_1, LOW);
  digitalWrite(LED_Carro_Amarelo_1, LOW);
  digitalWrite(LED_Carro_Vermelho_1, LOW);
  digitalWrite(LED_Pedestre_Verde_1, LOW);
  digitalWrite(LED_Pedestre_Vermelho_1, LOW);
  digitalWrite(LED_Carro_Verde_2, LOW);
  digitalWrite(LED_Carro_Amarelo_2, LOW);
  digitalWrite(LED_Carro_Vermelho_2, LOW);
  digitalWrite(LED_Pedestre_Verde_2, LOW);
  digitalWrite(LED_Pedestre_Vermelho_2, LOW);
  /* PRIMEIRO ESTÁGIO (5 SEGUNDOS).
      LED_Carro_Verde_1:       LIGADO
      LED_Carro_Amarelo_1:     DESLIGADO
      LED_Carro_Vermelho_1:    DESLIGADO
      LED_Pedestre_Verde_1:    DESLIGADO
      LED_Pedestre_Vermelho_1: LIGADO
      LED_Carro_Verde_2:       DESLIGADO
      LED_Carro_Amarelo_2:     DESLIGADO
      LED_Carro_Vermelho_2:    LIGADO
      LED_Pedestre_Verde_2:    LIGADO
      LED_Pedestre_Vermelho_2: DESLIGADO */
  digitalWrite(LED_Carro_Verde_1, HIGH);
  digitalWrite(LED_Carro_Amarelo_1, LOW);
  digitalWrite(LED_Carro_Vermelho_1, LOW);
  digitalWrite(LED_Pedestre_Verde_1, LOW);
  digitalWrite(LED_Pedestre_Vermelho_1, HIGH);
  digitalWrite(LED_Carro_Verde_2, LOW);
  digitalWrite(LED_Carro_Amarelo_2, LOW);
  digitalWrite(LED_Carro_Vermelho_2, HIGH);
  digitalWrite(LED_Pedestre_Verde_2, HIGH);
  digitalWrite(LED_Pedestre_Vermelho_2, LOW);
  delay(5000);
  /* SEGUNDO ESTÁGIO (3 SEGUNDOS).
      LED_Carro_Verde_1:       DESLIGADO
      LED_Carro_Amarelo_1:     LIGADO
     LED_Carro_Vermelho_1:    DESLIGADO
      LED_Pedestre_Verde_1:    DESLIGADO
      LED_Pedestre_Vermelho_1: LIGADO
      LED_Carro_Verde_2:       DESLIGADO
      LED_Carro_Amarelo_2:     DESLIGADO
      LED_Carro_Vermelho_2:    LIGADO
      LED_Pedestre_Verde_2:    DESLIGADO
      LED_Pedestre_Vermelho_2: PISCANDO */
  digitalWrite(LED_Carro_Verde_1, LOW);
  digitalWrite(LED_Pedestre_Verde_2, LOW);
  digitalWrite(LED_Carro_Amarelo_1, HIGH);
  for (int i = 1; i <= 3; i++) {
    digitalWrite(LED_Pedestre_Vermelho_2, HIGH);
    delay(500);
    digitalWrite(LED_Pedestre_Vermelho_2, LOW);
    delay(500);
  }
  /* TERCEIRO ESTÁGIO (5 SEGUNDOS).
      LED_Carro_Verde_1:       DESLIGADO
      LED_Carro_Amarelo_1:     DESLIGADO
      LED_Carro_Vermelho_1:    LIGADO
      LED_Pedestre_Verde_1:    LIGADO
      LED_Pedestre_Vermelho_1: DESLIGADO
      LED_Carro_Verde_2:       LIGADO
      LED_Carro_Amarelo_2:     DESLIGADO
      LED_Carro_Vermelho_2:    DESLIGADO
      LED_Pedestre_Verde_2:    DESLIGADO
      LED_Pedestre_Vermelho_2: LIGADO */
  digitalWrite(LED_Carro_Verde_1, LOW);
  digitalWrite(LED_Carro_Amarelo_1, LOW);
  digitalWrite(LED_Carro_Vermelho_1, HIGH);
  digitalWrite(LED_Pedestre_Verde_1, HIGH);
  digitalWrite(LED_Pedestre_Vermelho_1, LOW);
  digitalWrite(LED_Carro_Verde_2, HIGH);
  digitalWrite(LED_Carro_Amarelo_2, LOW);
  digitalWrite(LED_Carro_Vermelho_2, LOW);
  digitalWrite(LED_Pedestre_Verde_2, LOW);
  digitalWrite(LED_Pedestre_Vermelho_2, HIGH);
  delay(5000);
  /* QUARTO ESTÁGIO (3 SEGUNDOS).
      LED_Carro_Verde_1:       DESLIGADO
      LED_Carro_Amarelo_1:     DESLIGADO
      LED_Carro_Vermelho_1:    LIGADO
      LED_Pedestre_Verde_1:    DESLIGADO
      LED_Pedestre_Vermelho_1: PISCANDO
      LED_Carro_Verde_2:       DESLIGADO
      LED_Carro_Amarelo_2:     LIGADO
      LED_Carro_Vermelho_2:    DESLIGADO
      LED_Pedestre_Verde_2:    DESLIGADO
      LED_Pedestre_Vermelho_2: LIGADO */
  digitalWrite(LED_Carro_Verde_2, LOW);
  digitalWrite(LED_Pedestre_Verde_1, LOW);
  digitalWrite(LED_Carro_Amarelo_2, HIGH);
  for (int i = 1; i <= 3; i++) {
    digitalWrite(LED_Pedestre_Vermelho_1, HIGH);
    delay(500);
    digitalWrite(LED_Pedestre_Vermelho_1, LOW);
    delay(500);
  }
}
