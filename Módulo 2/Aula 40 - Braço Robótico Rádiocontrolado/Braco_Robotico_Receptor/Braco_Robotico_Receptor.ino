/*******************************************************/
/* Aula 40 - Braço Robótico Rádio Controlado           */
/* Programação do receptor para o braço robótico.      */
/* O módulo irá receber os comandos enviados pelo      */
/* transmissor e a partir destes, será feito o controle*/
/* dos movimentos de cada servo motor.                 */
/*******************************************************/

/* Definição da velocidade de comunicação (em bits por */
/* segundo) entre os módulos transmissor e receptor.   */
/* Cada equipe deverá configurar uma velocidade para   */
/* evitar a interferência no controle dos seus braços. */
/* Valores recomendados: 2000, 2100, 2200, 2300, etc.  */
#define velocidade 2000
/* Define o pino digital 9 do Arduino para enviar os   */
/* comandos ao módulo transmissor RF 433MHz.           */
#define Pino_Receptor 2
/* Inclui a biblioteca de controle do módulo RF433MHz. */
/* http://www.airspayce.com/mikem/arduino/VirtualWire/VirtualWire-1.27.zip */
#include <VirtualWire.h>
/* Inclui a biblioteca de controle dos servos. Não é   */
/* utilizar a biblioteca Servo.h padrão do Arduino IDE */
/* pois ela entra em conflito com a biblioteca         */
/* VirtualWire. Uma solução é utilizar a biblioteca    */
/* ServoTimer2.h que pode ser baixada através do link: */
/* https://github.com/nabontra/ServoTimer2             */
#include <ServoTimer2.h>
/* Criando objetos de controle para cada Servo Motor.  */
ServoTimer2 servo_base;
ServoTimer2 servo_direita;
ServoTimer2 servo_esquerda;
ServoTimer2 servo_garra;
/* Variável que definirá o Servo a ser controlado.     */
char funcao_selecionada;
/* Variável de incremento da posição do Servo Motor.   */
/* Poderá alterar para 1, 2, 3, etc. Quanto maior, mais*/
/* rápido o movimento.                                 */
int incremento = 4;
/* Variável que armazenará a posição em graus do servo.*/
int posicao;
/* Posição inicial dos quatro servos. Para a biblioteca*/
/* ServoTimer2 1400 equivale a posição de 90º          */
int posicao_base = 1400;
int posicao_direita = 1400;
int posicao_esquerda = 1400;
int posicao_garra = 1400;
/* Variável utilizada para formar os comandos          */
/* recebidos via RF 433MHz.                            */
byte comando[VW_MAX_MESSAGE_LEN];
/* Variável para o tamanho dos comandos recebidos.     */
byte tamanho_comando = VW_MAX_MESSAGE_LEN;
/* Variável que armazenará o comando decodificado.     */
char recebido;
/* Função de configuração.                             */
void setup() {
  /* Função que informa à biblioteca qual o pino       */
  /* utilizado para a recepção dos dados.              */
  vw_set_rx_pin(Pino_Receptor);
  /* Função que informa à biblioteca qual a velocidade */
  /* utilizada para a recepção dos dados.              */
  vw_setup(velocidade);
  /* Função que inicializa o receptor RF 433 MHz.      */
  vw_rx_start();
  /* Define as portas digitais para cada Servo Motor.  */
  servo_base.attach(8);
  servo_direita.attach(9);
  servo_esquerda.attach(10);
  servo_garra.attach(11);
  /* Inicia com todos os Servos na posição de 90º.     */
  servo_base.write(angulo(90));
  servo_direita.write(angulo(90));
  servo_esquerda.write(angulo(90));
  servo_garra.write(angulo(90));
}
/* Função looping principal.                           */
void loop() {
  /* Chama a função auxiliar para receber os comandos. */
  /* e definir em que modo o braço será operado.       */
  receber_comando();
  /* Chama a função auxiliar para definir o modo de    */
  /* operação:                                         */
  /* No modo B será controlado o Servo da Base.        */
  /* No modo E será controlado o Servo da Esquerda.    */
  /* No modo D será controlado o Servo da Direita.     */
  /* No modo G será controlado o Servo da Garra.       */
  escolha_modo();
  /* Enquanto o modo de operação for B, faça...        */
  while (funcao_selecionada == 'B') {
    /* Se o joystick for deslocado para a direita e o  */
    /* ângulo do Servo ainda é maior que 0º, faça...   */
    if (recebido == 'X' && posicao_base > angulo(0)) {
      /* Mova o servo da base para a posição atual.    */
      servo_base.write(posicao_base);
      /* Decremente o valor da posição da base.        */
      posicao_base = posicao_base - incremento;
      /* Pequena pausa.                                */
      delay(5);
    }
    /* Se o joystick for deslocado para a esquerda e o */
    /* ângulo do Servo ainda é menor que 180º, faça... */
    if (recebido == 'x' && posicao_base < angulo(180)) {
      /* Mova o servo da base para a posição atual.    */
      servo_base.write(posicao_base);
      /* Incremente o valor da posição da base.        */
      posicao_base = posicao_base + incremento;
      /* Pequena pausa.                                */
      delay(5);
    }
    /* Recebe os comandos para atualizar o modo de     */
    /* operação.                                       */
    receber_comando();
    escolha_modo();
  }
  /* Enquanto o modo de operação for D, faça...        */
  while (funcao_selecionada == 'D') {
    /* Se o joystick for deslocado para trás e o       */
    /* ângulo do Servo ainda é maior que 50º, faça...  */
    if (recebido == 'y' && posicao_direita > angulo(50)) {
      /* Mova o servo da dieita para a posição atual.  */
      servo_direita.write(posicao_direita);
      /* Decremente o valor da posição da direita.     */
      posicao_direita = posicao_direita - incremento;
      /* Pequena pausa.                                */
      delay(5);
    }
    /* Se o joystick for deslocado para frente e o     */
    /* ângulo do Servo ainda é menor que 180º, faça... */
    if (recebido == 'Y' && posicao_direita < angulo(180)) {
      /* Mova o servo da direita para a posição atual. */
      servo_direita.write(posicao_direita);
      /* Incremente o valor da posição da direita.     */
      posicao_direita = posicao_direita + incremento;
      /* Pequena pausa.                                */
      delay(5);
    }
    /* Recebe os comandos para atualizar o modo de     */
    /* operação.                                       */
    receber_comando();
    escolha_modo();
  }
  /* Enquanto o modo de operação for E, faça...        */
  while (funcao_selecionada == 'E') {
    /* Se o joystick for deslocado para trás e o       */
    /* ângulo do Servo ainda é maior que 100º, faça... */
    if (recebido == 'y' && posicao_esquerda > angulo(100)) {
      /* Mova o servo da esquerda para a posição atual.*/
      servo_esquerda.write(posicao_esquerda);
      /* Decremente o valor da posição da esquerda.    */
      posicao_esquerda = posicao_esquerda - incremento;
      /* Pequena pausa.                                */
      delay(5);
    }
    /* Se o joystick for deslocado para frente e o     */
    /* ângulo do Servo ainda é menor que 180º, faça... */
    if (recebido == 'Y' && posicao_esquerda < angulo(180)) {
      /* Mova o servo da esquerda para a posição atual.*/
      servo_esquerda.write(posicao_esquerda);
      /* Incremente o valor da posição da esquerda.    */
      posicao_esquerda = posicao_esquerda + incremento;
      /* Pequena pausa.                                */
      delay(5);
    }
    /* Recebe os comandos para atualizar o modo de     */
    /* operação.                                       */
    receber_comando();
    escolha_modo();
  }
  /* Enquanto o modo de operação for G, faça...        */
  while (funcao_selecionada == 'G') {
    /* Se o joystick for deslocado para a esquerda e o */
    /* ângulo do Servo ainda é maior que 60º, faça...  */
    if (recebido == 'x' && posicao_garra > angulo(60)) {
      /* Mova o servo da garra para a posição atual.   */
      servo_garra.write(posicao_garra);
      /* Decremente o valor da posição da garra.       */
      posicao_garra = posicao_garra - incremento;
      /* Pequena pausa.                                */
      delay(5);
    }
    /* Se o joystick for deslocado para a direita e o  */
    /* ângulo do Servo ainda é menor que 90º, faça...  */
    if (recebido == 'X' && posicao_garra < angulo(90)) {
      /* Mova o servo da garra para a posição atual.   */
      servo_garra.write(posicao_garra);
      /* Incremente o valor da posição da garra.       */
      posicao_garra = posicao_garra + incremento;
      /* Pequena pausa.                                */
      delay(5);
    }
    /* Recebe os comandos para atualizar o modo de     */
    /* operação.                                       */
    receber_comando();
    escolha_modo();
  }
}
/* Função auxiliar de captura dos comandos recebidos.  */
void receber_comando() {
  vw_get_message(comando, &tamanho_comando);
  for (int i = 0; i < tamanho_comando; i++)
  {
    /* Armazena na variável o comando recebido.       */
    recebido = comando[i];
  }
}
/* Função auxiliar que define o modo de operação.     */
void escolha_modo() {
  /* Se receber B, então faça...                      */
  if (recebido == 'B') {
    /* Defina a função controle do Servo da Base.     */
    funcao_selecionada = recebido;
  }
  /* Se receber D, então faça...                      */
  if (recebido == 'D') {
    /* Defina a função controle do Servo da Direita.  */
    funcao_selecionada = recebido;
  }
  /* Se receber E, então faça...                      */
  if (recebido == 'E') {
    /* Defina a função controle do Servo da Esquerda. */
    funcao_selecionada = recebido;
  }
  /* Se receber G, então faça...                      */
  if (recebido == 'G') {
    /* Defina a função controle do Servo da Garra.    */
    funcao_selecionada = recebido;
  }
}
/* Função auxiliar que converte o angulo de grau para */
/* largura de pulsos em milissegundos. A biblioteca   */
/* utilizada (ServoTimer2.h) controla os Servos a     */
/* partir dessa informação ao invés de ângulos.       */
int angulo(int grau) {
  posicao = map(grau, 0, 180, 600, 2400);
  return posicao;
}
