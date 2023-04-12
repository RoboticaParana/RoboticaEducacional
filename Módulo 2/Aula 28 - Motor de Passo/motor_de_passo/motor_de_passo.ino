/************************************************************/
/* Aula 28 - Motor de Passo                                 */
/* Programação do Motor de Passo.                           */
/* Ao transferir o código abaixo para seu Arduino, o Motor  */
/* de passo será controlado da seguinte maneira:            */
/* Gira o motor com velocidade 15, no sentido horário por 4 */
/* vezes, em ângulos de 90º.                                */
/* Gira o motor com velocidade 5, no sentido anti-horário   */
/* por 3 vezes, em ângulos de 120°.                         */
/* Gira o motor aumentando a velocidade gradativamente de 1 */
/* a 15.                                                    */
/************************************************************/
/* Inclui a biblioteca de controle do Motor de Passo.       */
#include <Stepper.h>
/* Número de passos por revolução do Motor de Passo.        */
const int PassosPorRevolucao = 2050;
/* Cria o objeto de controle para o Motor informando os     */
/* pinos digitais do Arduino que está conectado.            */
Stepper meuMotor(PassosPorRevolucao, 11, 9, 10, 8);
void setup() {
  /* Este código não exige nenhuma configuração.            */
}
void loop() {
  /* Gira o motor com velocidade 15, no sentido horário por */
  /* 4 vezes, em ângulos de 90°.                            */
  for (int i = 1; i <= 4; i++)
  {
    angulo(15, -90);
    delay(2000);
  }
  for (int i = 1; i <= 3; i++)
  {
  /* Gira o motor com velocidade 5, no sentido anti-horário */
  /* por 3 vezes, em ângulos de 120°.                       */
    angulo(5, 120);
    delay(2000);
  }
  /* Gira o motor aumentando a velocidade gradativamente de */
  /* 1 a 15.                                                */
  for (int i = 1; i <= 15; i++)
  {
    meuMotor.setSpeed(i);
    meuMotor.step(PassosPorRevolucao/15);
  }
  delay(2000);
}
/* Função que controla o movimento do Motor de Passo.      */
void angulo(int velocidade, float angulo)
{
  /* Define a velocidade que o motor.                      */
  meuMotor.setSpeed(velocidade);
  /* Faz o motor girar no ângulo informado.                */
  meuMotor.step(angulo * PassosPorRevolucao / 360);
}
