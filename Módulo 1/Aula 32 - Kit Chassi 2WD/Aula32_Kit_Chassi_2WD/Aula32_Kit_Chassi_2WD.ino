/*************************************************************/
/* Aula 32 - Kit Chassi 2WD                                  */
/* Programação: Nesta programação é utilizados oscomandos    */
/* para controlar até quatro motores DC utilizando a placa   */
/* Motor Shield L293D e a biblioteca AFMotor.                */
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
/* Define o valor da velocidade. (0-255).              */
#define velocidade 180
/* Função de configurações.                            */
void setup() {
  /* Inicia com os motores parados.                    */
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
void loop() {
  /* Define a potência para os motores.                */
  motor2.setSpeed(velocidade);
  motor3.setSpeed(velocidade);
  /* Chama a função auxiliar para mover o chassi para  */
  /* frente por 1000 milissegundos (1 segundo).        */
  frente(1000);
  /* Aguarda 0,5 segundo.                              */
  delay(500);
  /* Chama a função auxiliar para mover o chassi para  */
  /* trás por 1000ms = 1s.                             */
  re(1000);
  /* Aguarda 0,5 segundo.                              */
  delay(500);
  /* Chama a função auxiliar para girar em torno do seu*/
  /* centro no sentido anti-horário por 1000ms = 1s.   */
  giro_centro_antihorario(1000);
  /* Aguarda 0,5 segundo.                              */
  delay(500);
  /* Chama a função auxiliar para girar em torno do seu*/
  /* centro no sentido horário por 1000ms = 1s.        */
  giro_centro_horario(1000);
  /* Aguarda 0,5 segundo.                              */
  delay(500);
  /* Chama a função auxiliar para girar em torno da sua*/
  /* roda no sentido anti-horário por 1000ms = 1s.     */
  giro_roda_antihorario(1000);
  /* Aguarda 0,5 segundo.                              */
  delay(500);
  /* Chama a função auxiliar para girar em torno da sua*/
  /* roda no sentido horário por 1000ms = 1s.          */
  giro_roda_horario(1000);
  /* Aguarda 5 segundos.                               */
  delay(5000);
}
/* Função auxiliar que move para frente pelo tempo     */
/* definido.                                           */
void frente(int tempo)
{
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  delay(tempo);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
/* Função auxiliar que move para trás pelo tempo      */
/* informado.                                         */
void re(int tempo)
{
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  delay(tempo);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
/* Função auxiliar que gira em torno do seu centro,   */
/* no sentido anti-horário pelo tempo informado.      */
void giro_centro_antihorario(int tempo)
{
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  delay(tempo);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
/* Função auxiliar que gira em torno do seu centro,   */
/* no sentido horário pelo tempo informado.           */
void giro_centro_horario(int tempo)
{
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  delay(tempo);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
/* Função auxiliar que gira em torno da roda no      */
/* sentido anti-horário pelo tempo informado.        */
void giro_roda_antihorario(int tempo)
{
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  delay(tempo);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
/* Função auxiliar que gira em torno da roda no      */
/* sentido horário pelo tempo informado.             */
void giro_roda_horario(int tempo)
{
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  delay(tempo);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}
