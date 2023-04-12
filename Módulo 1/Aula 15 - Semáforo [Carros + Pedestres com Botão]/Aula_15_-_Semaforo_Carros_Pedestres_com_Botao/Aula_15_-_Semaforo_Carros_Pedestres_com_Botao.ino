/* Programa de controle de semáforo interativo. */

/* Definições dos pinos para os LEDs e botão.   */
#define PIN_BOTAO 2
#define PIN_LED_VERDE_PED 6
#define PIN_LED_VERMELHO_PED 7
#define PIN_LED_VERDE_CAR 8
#define PIN_LED_AMARELO_CAR 9
#define PIN_LED_VERMELHO_CAR 10

/* Variável que seleciona o modo de operação do semáforo 
   0: Modo aberto para carros 
   1: Modo aberto para pedestres                         */
int modo = 0;
 
void setup()
{
  /* Configura os pinos de ENTRADA e SAÍDA.              */
  pinMode(PIN_BOTAO, INPUT);
  pinMode(PIN_LED_VERDE_PED, OUTPUT);
  pinMode(PIN_LED_VERMELHO_PED, OUTPUT);
  pinMode(PIN_LED_VERDE_CAR, OUTPUT);
  pinMode(PIN_LED_AMARELO_CAR, OUTPUT);
  pinMode(PIN_LED_VERMELHO_CAR, OUTPUT);
  /* Ativa a função de interrupção no pino que o botão está ligado.        */
  attachInterrupt(digitalPinToInterrupt(PIN_BOTAO),botaoAcionado, FALLING);
}
void loop()
{
  switch (modo) {
    case 0:
      /* Estágio Aberto para carros                  */
      digitalWrite(PIN_LED_VERDE_PED, LOW);
      digitalWrite(PIN_LED_VERMELHO_PED, HIGH);
      digitalWrite(PIN_LED_VERDE_CAR, HIGH);
      digitalWrite(PIN_LED_AMARELO_CAR, LOW);
      digitalWrite(PIN_LED_VERMELHO_CAR, LOW);
      break;
    case 1:
      /* Aguarda 1 segundo após pressionar o botão  */
      delay(1000);
      /* Aciona o amarelo do semáforo dos carros    */
      digitalWrite(PIN_LED_VERDE_CAR, LOW);
      digitalWrite(PIN_LED_AMARELO_CAR, HIGH);
      delay(3000);
      /* Abre o semáforo de pedestres.              */
      digitalWrite(PIN_LED_VERDE_PED, HIGH);
      digitalWrite(PIN_LED_VERMELHO_PED, LOW);
      digitalWrite(PIN_LED_AMARELO_CAR, LOW);
      digitalWrite(PIN_LED_VERMELHO_CAR, HIGH);
      delay(5000);
      /* Apaga o verde dos pedestres e começa piscar o
        vermelho indicando que o tempo de travessia está acabando.
      */
      digitalWrite(PIN_LED_VERDE_PED, LOW);
      for (int i = 0; i <= 5; i++)
      {
        digitalWrite(PIN_LED_VERMELHO_PED, HIGH);
        delay(300);
        digitalWrite(PIN_LED_VERMELHO_PED, LOW);
        delay(300);
      }
      modo = 0; /* Após a travessia de pedestre, altera
  para o modo de passagem de carros: 0. */
      break;
  }
}
/* Após pressionar o botão, será executada essa função, ela
  altera o modo de operação do semáforo. */
void botaoAcionado() {
  modo = 1;
}
