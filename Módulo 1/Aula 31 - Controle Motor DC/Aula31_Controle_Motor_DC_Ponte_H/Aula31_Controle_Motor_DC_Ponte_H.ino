/********************************************************/
/* Aula 31 - Controle Motor DC                          */
/* Programação: Nesta programação controlamos dois      */
/* motores DCutilizando a placa Motor Driver L298N.     */
/* Links para obtenção da biblioteca by Andrea Lombardo */
/* http://librarymanager/All#L298N#EASY                 */
/* https://github.com/AndreaLombardo/L298N              */
/********************************************************/

/* Inclui a Biblioteca para controle da ponte H.        */
#include <L298NX2.h>

#define ENA 10 // ENA precisa estar em uma porta PWM
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5  // ENB precisa estar em uma porta PWM

/* Criamos um objetro de controle dos motores.         */
L298NX2 motores(ENA, IN1, IN2, ENB, IN3, IN4);

void setup() {
  /* Inicia com os motores parados.                    */
  motores.stop();
}

void loop() {
  /* Define a velocidade em 255 (0-255).               */
  motores.setSpeed(255);
  /* Aciona os Motores para frente.                    */
  motores.forward();
  /* Aguarda 3 segundos.                               */
  delay(3000);
  /* Para os Motores.                                  */
  motores.stop();
  /* Aguarda 0,5 segundos.                             */
  delay(500);
  /* Define a velocidade em 180 0-255).                */
  motores.setSpeed(180);
  /* Aciona os Motores para trás.                      */
  motores.backward();
  /* Aguarda 3 segundos.                               */
  delay(3000);
  /* Para os Motores.                                  */
  motores.stop();
  /* Aguarda 0,5 segundos.                             */
  delay(500);
  /* Define a velocidade em 100 (0-255).               */
  motores.setSpeed(100);
  /* Gira no sentido horário.                          */
  motores.forwardA();
  motores.backwardB();
  /* Aguarda 3 segundos.                               */
  delay(3000);
  /* Para os Motores.                                  */
  motores.stop();
  /* Aguarda 0,5 segundos.                             */
  delay(500);
  /* Gira no sentido atihorário.                       */
  motores.forwardB();
  motores.backwardA();
  /* Aguarda 3 segundos.                               */
  delay(3000);
  /* Para os Motores.                                  */
  motores.stop();
  /* Aguarda 0,5 segundos.                             */
  delay(500);


}
