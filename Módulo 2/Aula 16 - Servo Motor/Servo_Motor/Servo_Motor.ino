/************************************************************/
/* Aula 16 - Servo Motor                                    */
/* Programação do servo motor.                              */
/* Ao transferir o código abaixo para seu Arduino, o Servo  */
/* Motor será controlado, permanecendo por 1 segundo em três*/
/* posições (0º, 90º e 180º).                               */
/************************************************************/
/* Inclui a bliblioteca de controle do Servo Motor.         */
#include <Servo.h>
/* Cria o objeto de controle do Servo Motor.                */
Servo meuservo;
/* Define o pino de controle para o Servo Motor.            */
#define Pino_Servo 7

void setup() {
  /* Endereça o objeto de controle ao pino definido para    */
  /* controle do Servo Motor.                               */
  meuservo.attach(Pino_Servo);
}
void loop() {
  /* Posiciona o servo para a posição 0°.                   */
  meuservo.write(0);
  /* Aguarda 1 segundo nesta posição.                       */
  delay(1000);
  /* Posiciona o servo para a posição 90°.                  */ 
  meuservo.write(90); 
  /* Aguarda 1 segundo nesta posição.                       */          
  delay(1000);  
  /* Posiciona o servo para a posição 180°.                 */                
  meuservo.write(180); 
  /* Aguarda 1 segundo nesta posição.                       */         
  delay(1000);                  
}
