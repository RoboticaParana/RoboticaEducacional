/* Código de Funcionamento para um Semáforo de Pedestres  */

/* Definições para os pinos dos LEDs                      */
#define led_vermelho_ped 3
#define led_verde_ped 4
#define led_vermelho_car 5
#define  led_amarelo_car 6
#define led_verde_car 7

void setup() {
  /* Configura os pinos LEDs como SAÍDA                  */
  pinMode(led_vermelho_ped, OUTPUT);
  pinMode(led_verde_ped, OUTPUT);
  pinMode(led_vermelho_car, OUTPUT);
  pinMode(led_amarelo_car, OUTPUT);
  pinMode(led_verde_car, OUTPUT);
}

void loop() {
  /* Primeiro estágio: Aberto para os carros e fechado para os pedestres */
  digitalWrite(led_vermelho_ped, 1);
  digitalWrite(led_verde_car, 1);
  delay(5000);
  /* Atenção para os carros (LED amarelo ligado por 1 segundo)           */
  digitalWrite(led_amarelo_car, 1);
  digitalWrite(led_verde_car, 0);
  delay(1000);
  /* Segundo estágio: Aberto para os pedestres e fechado para os carros  */
  digitalWrite(led_vermelho_car, 1);
  digitalWrite(led_amarelo_car, 0);
  digitalWrite(led_vermelho_ped, 0);
  digitalWrite(led_verde_ped, 1);
  delay(5000);
  /* Desliga o LED verde dos pedestres para iniciar o fechamento do sinal */
  digitalWrite(led_verde_ped, 0);
  /* Atenção para os pedestres (LED vermelho pisca indicando que irá fechar) */
  for (int count = 0; count < 5; count++) {
    digitalWrite(led_vermelho_ped, 1);
    delay(250);
    digitalWrite(led_vermelho_ped, 0);
    delay(250);
  }
  /* Apaga o LED vermelho dos carros e repete a sequência */
  digitalWrite(led_vermelho_car, 0);
}
