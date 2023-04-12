/*************************************************************/
/* Aula 31 - Controle Motor DC                               */
/* Programação: Nesta programação é utilizados os            */
/* comandos para controlar até quatro motores DC             */
/* utilizando a placa Motor Shield L293D e a                 */
/* biblioteca AFMotor.                                       */
/* Links para obtenção da biblioteca by Adafruit             */
/* http://librarymanager/All#Adafruit#Motor#V1               */
/* https://github.com/adafruit/Adafruit-Motor-Shield-library */
/*************************************************************/

/* Inclui a Biblioteca AFMotor para controle do motor. */
#include <AFMotor.h> 
/* Cria os objetos de controle para os motores         */
/* conectados nas saídas M2 e M3 da Motor Shield.      */
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
/* Função de configurações.                            */
void setup() {
  /* Inicia com os motores parados.                    */
  motor2.run(RELEASE); 
  motor3.run(RELEASE);
}
/* Função looping principal.                           */
void loop() {
  /* Define as velocidades dos   motores (0-255).      */
  motor2.setSpeed(255); 
  motor3.setSpeed(255);
  /* Aciona os Motores para frente.                    */
  motor2.run(FORWARD); 
  motor3.run(FORWARD);
  /* Aguarda 3 segundos.                               */
  delay(3000); 
  /* Para os Motores.                                  */
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  /* Aguarda 0,5 segundos.                             */
  delay(500);
  /* Aciona os Motores para trás.                      */ 
  motor3.run(BACKWARD);
  motor3.run(BACKWARD);
  /* Aguarda 3 segundos.                               */
  delay(3000);
  /* Para os Motores.                                  */
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  /* Aguarda 0,5 segundos.                             */
  delay(500);
  /* Define as velocidades para 130.                   */
  motor2.setSpeed(200); 
  motor3.setSpeed(200);
  /* Aciona os Motores para frente.                    */
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  /* Aguarda 3 segundos.                               */
  delay(3000);
  /* Para os Motores.                                  */
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  /* Aciona os Motores para trás.                      */ 
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  /* Aguarda 3 segundos.                               */
  delay(3000);
  /* Para os Motores.                                  */
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  /* Aguarda 0,5 segundos.                             */
  delay(500);
}
