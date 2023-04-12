/*******************************************************/
/* Aula 18 - Portas PWM                                */
/* Programação da intensidade do brilho de um LED      */
/* utilizando uma porta PWM.                           */
/*******************************************************/

/* Define a porta PWM 11 como pino do LED.             */
int pinoLed = 11; 

void setup() {
  /* Define o pino do LED como saída. */
  pinMode(pinoLed, OUTPUT);
}
void loop() {
  /* Alterna o brilho do LED com as intensidades       */
  /* definidas (0 à 255) em intervalos de 1 segundo.   */
  analogWrite(pinoLed, 5);
  delay(1000);
  analogWrite(pinoLed, 50);
  delay(1000);
  analogWrite(pinoLed, 100);
  delay(1000);
  analogWrite(pinoLed, 255);
  delay(1000);
}
