/********************************************************/
/* Aula 32 - Kit Chassi 2WD com ponte H - Robô          */
/* Programação: Nesta programação controlamos dois      */
/* motores DC utilizando a placa Motor Driver L298N.    */
/* para mover o robô em todas as direções possíveis.    */
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

/* Criamos um objeto de controle dos motores.          */
L298NX2 motores(ENA, IN1, IN2, ENB, IN3, IN4);

void setup() {
  /* Inicia com os motores parados.                    */
  motores.stop();
}

void loop() {
  /* Define a velocidade em 180 (0-255).               */
  motores.setSpeed(180);
  /* Chama a função frente por 1000 milissegundos      */
  frente(1000);
  /* Pausa de meio segundo                             */
  delay(500);
  /* Chama a função ré por 1000 milissegundos          */
  re(1000);
  /* Pausa de meio segundo                             */
  delay(500);
  /* Chama a função girar em torno do centro no sentido*/
  /* antihorário por 1000 milissegundos                */
  giro_centro_antihorario(1000);
  /* Pausa de meio segundo                             */
  delay(500);
  /* Chama a função girar em torno do centro no sentido*/
  /* horário por 1000 milissegundos                    */
  giro_centro_horario(1000);
  /* Pausa de meio segundo                             */
  delay(500);
  /* Chama a função girar em torno da roda no sentido  */
  /* antihorário por 1000 milissegundos                */
  giro_roda_antihorario(1000);
  /* Pausa de meio segundo                             */
  delay(500);
  /* Chama a função girar em torno da roda no sentido  */
  /* horário por 1000 milissegundos                    */
  giro_roda_horario(1000);
  /* Pausa de cinco segundos                           */
  delay(5000);
}

/* Função que move para frente pelo tempo definido     */
void frente(int tempo)
{
  motores.forward();
  delay(tempo);
  motores.stop();
}
/* Função que move para trás pelo tempo definido       */
void re(int tempo)
{
  motores.backward();
  delay(tempo);
  motores.stop();
}
/* Função que gira em torno do centro no sentido       */
/* antihorário pelo tempo definido                     */
void giro_centro_antihorario(int tempo)
{
  motores.backwardA();
  motores.forwardB();
  delay(tempo);
  motores.stop();
}
/* Função que gira em torno do centro no sentido       */
/* horário pelo tempo definido                         */
void giro_centro_horario(int tempo)
{
  motores.backwardB();
  motores.forwardA();
  delay(tempo);
  motores.stop();
}
/* Função que gira em torno da roda no sentido         */
/* antihorário pelo tempo definido                     */
void giro_roda_antihorario(int tempo)
{
  motores.forwardB();
  delay(tempo);
  motores.stop();
}
/* Função que gira em torno da roda no sentido         */
/* horário pelo tempo definido                         */
void giro_roda_horario(int tempo)
{
  motores.forwardA();
  delay(tempo);
  motores.stop();
}
