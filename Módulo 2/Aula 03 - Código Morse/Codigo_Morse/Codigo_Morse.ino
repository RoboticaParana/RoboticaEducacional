/****************************************************/
/* Aula 03 - Código Morse.                          */
/* Essa programação faz com que um buzzer emita som */
/* enquanto um Push-Button estiver sendo pressionado*/
/* e também um LED permaneça ligado.                */
/* Este dispositivo pode ser utilizado como         */
/* comunicador através de código morse.             */
/****************************************************/

/* Definição das portas do buzzer, botão e LED      */
#define buzzer  2
#define botao 3
#define LED 4

void setup() {
  /* Configura as portas do LED e buzzer como saída.*/
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  /* Configura a porta do botão como entrada e ativa*/
  /* o resistor interno da placa.                   */
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  /* Se presionar o botão, ligue o LED e emita som. */
  if (digitalRead(botao) == LOW) {
    digitalWrite(LED, HIGH);
    tone(buzzer, 800);
  }
  /* Senão, desligue o LED e pare o som.           */
  else {
    digitalWrite(LED, LOW);
    noTone(buzzer);
  }
}
