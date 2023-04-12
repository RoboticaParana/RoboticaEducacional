/*******************************************************/
/* Aula 19 - LED Fade-In                               */
/* Programação da alteração do brilho de um LED com    */
/* efeito Fade-In, utilizando uma porta PWM.           */
/*******************************************************/

/* Define a porta PWM 11 como pino do LED.             */
int pinoLed = 11;
int incremento = 1; /* Incremento do brilho do LED.    */
int brilho = 0; /* Variável do brilho do LED.          */
void setup() {
  /* Define o pino do LED como saída.                  */
  pinMode(pinoLed, OUTPUT);
}
void loop() {
  /* Incrementa o brilho do LED de 0 a 255. */
  for (brilho; brilho <= 256; brilho += incremento) {
    /* Ajusta a intensidade do brilho a cada incremento. */
    analogWrite(pinoLed, brilho);
    /* Aguarda 100 milissegundos para aumentar o brilho. */
    delay(100);
  }
}
