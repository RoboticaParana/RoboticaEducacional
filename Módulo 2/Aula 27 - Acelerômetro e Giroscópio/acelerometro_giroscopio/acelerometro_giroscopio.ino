/************************************************************/
/* Aula 27 - Acelerômetro e Giroscópio                      */
/* Programação do Módulo Acelerômetro e Giroscópio MPU6050  */
/* que visa controlar dois Servos Motores através da        */
/* inclinação do Módulo nas direções dos eixos X e Y.       */
/************************************************************/
/* Inclusão de bibliotecas. Para instalar a biblioteca de   */
/* controle do Módulo Acelerômetro e Giroscópio, faça o     */
/* download do arquivo zip através do link:                 */
/* https://github.com/fred-corp/GY6050/archive/refs/heads/master.zip */
#include <GY6050.h>
#include <Servo.h>
/* Cria os objetos de controle para cada servo motor.       */
Servo servo_1;
Servo servo_2;
/* Variáveis para definir as posições dos Servos Motores.   */
int eixo_X, eixo_Y;
/* Cria o objeto de controle do Módulo em seu endereço I2C  */
GY6050 giroscopio(0X68);
void setup() {
  /* Inicializa o Módulo.                                   */
  giroscopio.initialisation();
  /* Pequena pausa para estabilização do Módulo.            */
  delay(100);
  /* Define as portas digitais de controle para cada Servo. */
  servo_1.attach(7);
  servo_2.attach(8);
}
void loop() {
  /* Coleta os dados do Módulo e converte em ângulos entre  */
  /* 0° e 180° e atualiza as variáveis de posição dos Servos*/
  eixo_X = map(giroscopio.refresh('A', 'eixo_X'), -90, 90, 0, 180);
  eixo_Y = map(giroscopio.refresh('A', 'eixo_Y'), -90, 90, 0, 180);
  /* Posiciona cada servo no ângulo atual.                  */
  servo_1.write(eixo_X);
  servo_2.write(eixo_Y);
  /* Pequena pausa para atualizar as posições.              */
  delay(15);
}
