/*******************************************************/
/* Aula 02 - Arduino: Bibliotecas e Funções.           */
/* Nessa programação criamos uma função para tocar sons*/
/* através de um buzzer.                               */
/*******************************************************/

/* Pino ligado ao buzzer.                              */
int buzzer = 8;

/* Função para tocar o buzzer através de parâmentros   */
/* informados (pino do buzzer, frequeência e duração). */
void toca_buzzer(int pino_buzzer, int frequencia, int duracao)
{
  tone(pino_buzzer, frequencia);
  delay(duracao);
  noTone(pino_buzzer);
}

void setup() {
  /* Define o pino conectado ao buzzer como saída.       */
  pinMode(buzzer, OUTPUT);
}

void loop() {
  /* Aciona o buzzer na frequência da nota Dó por 200 ms */
  toca_buzzer(buzzer, 261, 200);
  /* Aciona o buzzer na frequência da nota Ré por 200 ms */
  toca_buzzer(buzzer, 293, 200);
  /* Aciona o buzzer na frequência da nota Mi por 200 ms */
  toca_buzzer(buzzer, 329, 200);
  /* Aciona o buzzer na frequência da nota Fá por 200 ms */
  toca_buzzer(buzzer, 349, 200);
  /* Aciona o buzzer na frequência da nota Ré por 200 ms */
  toca_buzzer(buzzer, 392, 200);
}
