/************************************************************/
/* Aula 18 - Controlando Servos Motores                     */
/* Programação do controle de Servos Motores.               */
/* Ao transferir o código abaixo para seu Arduino, você     */
/* poderá controlar, através de um Potenciômetro, 4 Servos  */
/* Motores. Utilize o Push-Button para selecionar o Servo   */
/* Motor a ser controlado.                                  */
/************************************************************/
/* Inclui a bliblioteca de controle do Servo Motor.         */
#include <Servo.h>
/* Cria os objetos de controle dos Servos Motores.          */
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
/* Define os pinos dos Servos, Potenciômetro e Botão.       */
#define Pino_Servo1 5
#define Pino_Servo2 9
#define Pino_Servo3 12
#define Pino_Servo4 13
#define Pot A3
#define Pino_Botao 2
/* Variável para selecionar o servo para controle.          */
int seletor = 1;
void setup() {
  /* Endereça os objetos de controle aos pinos definidos    */
  /* para controle dos Servos Motores.                      */
  servo1.attach(Pino_Servo1);
  servo2.attach(Pino_Servo2);
  servo3.attach(Pino_Servo3);
  servo4.attach(Pino_Servo4);
  /* Configura o pino do botão como entrada ativando o      */
  /* resistor interno.                                      */
  pinMode(Pino_Botao, INPUT_PULLUP);
  /* Ativa a interrupção no pino do botão e chama a função  */
  /* "seleciona" para alterar o servo a ser controlado.     */
  attachInterrupt(digitalPinToInterrupt(Pino_Botao), seleciona, FALLING);
}
void loop() {
  /* Switch de seleção do Servo a ser controlado.           */
  switch (seletor) {
    /* Caso seletor = 1, operará o Servo1.                  */
    case 1:
      Servo1();
      break;
    /* Caso seletor = 2, operará o Servo2.                  */
    case 2:
      Servo2();
      break;
    /* Caso seletor = 3, operará o Servo3.                  */
    case 3:
      Servo3();
      break;
    /* Caso seletor = 4, operará o Servo4.                  */
    case 4:
      Servo4();
      break;
  }
}
/* Função que altera a variáver seletor.                    */
void seleciona() {
  seletor++;
  if (seletor > 4)
  {
    seletor = 1;
  }
}
/* Função de controle do Servo1 através dos dados do Potenciômetro. */
void Servo1()
{
  servo1.write(map(analogRead(Pot), 0, 1023, 0, 180));
}
/* Função de controle do Servo2 através dos dados do Potenciômetro. */
void Servo2()
{
  servo2.write(map(analogRead(Pot), 0, 1023, 0, 180));
}
/* Função de controle do Servo3 através dos dados do Potenciômetro. */
void Servo3()
{
  servo3.write(map(analogRead(Pot), 0, 1023, 0, 180));
}
/* Função de controle do Servo4 através dos dados do Potenciômetro. */
void Servo4()
{
  servo4.write(map(analogRead(Pot), 0, 1023, 0, 180));
}
