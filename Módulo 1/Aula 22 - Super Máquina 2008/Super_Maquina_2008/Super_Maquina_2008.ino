/*******************************************************/
/* Aula 22 - Super Máquina 2008                        */
/* Programação do efeito nos LEDs da Super Máquina     */
/* (Carro da série Super Máquina do anos 2008).        */
/*******************************************************/

/* Variável para a velocidade do efeito */
int velocidade = 20;
void setup() {
  /* Inicia as portas PWM do Arduino como saída.       */
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}
void loop() {
  /* Loop da sequência frames */
  for (int frame = 1; frame <= 13; frame++) {
    switch (frame) { /* Executa o frame atual.         */
      case 1: /* Frame com todos LEDs desligados.      */
        analogWrite(3, 0);
        analogWrite(5, 0);
        analogWrite(6, 0);
        analogWrite(9, 0);
        analogWrite(10, 0);
        break;
      case 2:
        analogWrite(3, 255); /* LED com brilho alto.   */
        analogWrite(5, 0); /* LED desligado. */
        analogWrite(6, 0); /* LED desligado. */
        analogWrite(9, 0); /* LED desligado. */
        analogWrite(10, 0); /* LED desligado. */
        break;
      case 3:
        analogWrite(3, 100); /* LED com brilho moderado alto. */
        analogWrite(5, 255); /* LED com brilho alto. */
        analogWrite(6, 0); /* LED desligado. */
        analogWrite(9, 0); /* LED desligado. */
        analogWrite(10, 0); /* LED desligado. */
        break;
      case 4:
        analogWrite(3, 50); /* LED com brilho moderado baixo. */
        analogWrite(5, 100); /* LED com brilho moderado alto. */
        analogWrite(6, 255); /* LED com brilho alto. */
        analogWrite(9, 0); /* LED desligado. */
        analogWrite(10, 0); /* LED desligado. */
        break;
      case 5:
        analogWrite(3, 5); /* LED com brilho baixo. */
        analogWrite(5, 50); /* LED com brilho moderado baixo. */
        analogWrite(6, 100); /* LED com brilho moderado alto. */
        analogWrite(9, 255); /* LED com brilho alto. */
        analogWrite(10, 0); /* LED desligado. */
        break;
      case 6:
        analogWrite(3, 0); /* LED desligado. */
        analogWrite(5, 5); /* LED com brilho baixo. */
        analogWrite(6, 50); /* LED com brilho moderado baixo. */
        analogWrite(9, 100); /* LED com brilho moderado alto. */
        analogWrite(10, 255); /* LED com brilho alto. */
        break;
      case 7:
        analogWrite(3, 0); /* LED desligado. */
        analogWrite(5, 0); /* LED desligado. */
        analogWrite(6, 5); /* LED com brilho baixo. */
        analogWrite(9, 255); /* LED com brilho alto. */
        analogWrite(10, 100); /* LED com brilho moderado alto. */
        break;
      case 8:
        analogWrite(3, 0); /* LED desligado. */
        analogWrite(5, 0); /* LED desligado. */
        analogWrite(6, 255); /* LED com brilho alto. */
        analogWrite(9, 100); /* LED com brilho moderado alto. */
        analogWrite(10, 50); /* LED com brilho moderado baixo. */
        break;
      case 9:
        analogWrite(3, 0); /* LED desligado. */
        analogWrite(5, 255); /* LED com brilho alto. */
        analogWrite(6, 100); /* LED com brilho moderado alto. */
        analogWrite(9, 50); /* LED com brilho moderado baixo. */
        analogWrite(10, 5); /* LED com brilho baixo. */
        break;
      case 10:
        analogWrite(3, 255); /* LED com brilho alto. */
        analogWrite(5, 100); /* LED com brilho moderado alto. */
        analogWrite(6, 50); /* LED com brilho moderado baixo. */
        analogWrite(9, 5); /* LED com brilho baixo. */
        analogWrite(10, 0); /* LED desligado. */
        break;
      case 11:
        analogWrite(3, 100); /* LED com brilho moderado alto. */
        analogWrite(5, 50); /* LED com brilho moderado baixo. */
        analogWrite(6, 5); /* LED com brilho baixo. */
        analogWrite(9, 0); /* LED desligado. */
        analogWrite(10, 0); /* LED desligado. */
        break;
      case 12:
        analogWrite(3, 50); /* LED com brilho moderado baixo. */
        analogWrite(5, 5); /* LED com brilho baixo. */
        analogWrite(6, 0); /* LED desligado. */
        analogWrite(9, 0); /* LED desligado. */
        analogWrite(10, 0); /* LED desligado. */
        break;
      case 13:
        analogWrite(3, 5); /* LED com brilho baixo. */
        analogWrite(5, 0); /* LED desligado. */
        analogWrite(6, 0); /* LED desligado. */
        analogWrite(9, 0); /* LED desligado. */
        analogWrite(10, 0); /* LED desligado. */
        break;
    }
    /* Determina o delay em função da velocidade informada */
    delay(1000 / velocidade);
  }
}
