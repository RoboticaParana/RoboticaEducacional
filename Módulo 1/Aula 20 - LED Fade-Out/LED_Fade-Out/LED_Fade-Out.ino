/*******************************************************/
/* Aula 20 - LED Fade-Out                              */
/* Programação da alteração do brilho de um LED com    */
/* efeito Fade-Out, utilizando uma porta PWM.          */
/*******************************************************/

/* Define a porta PWM 11 como pino do LED.             */
int pinoLed = 11;
int decremento = 5; /* Decremento do brilho do LED.    */
int brilho = 255; /* Variável do brilho do LED.        */
void setup() {
  /* Define o pino do LED como saída.                  */
  pinMode(pinoLed, OUTPUT);
}
void loop() {
  /* Decrementa o brilho do LED de 255 à 0.             */
  for (brilho; brilho >= -1; brilho -= decremento) {
    /* Ajusta a intensidade do brilho a cada decremento.*/
    analogWrite(pinoLed, brilho);
    /* Aguarda 50 milissegundos para diminuir o brilho. */
    delay(50);
  }
}
