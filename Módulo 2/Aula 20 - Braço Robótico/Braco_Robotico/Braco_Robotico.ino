/************************************************************/
/* Aula 20 - Braço Robótico                                 */
/* Programação do Braço Robótico com Joystick Shield.       */
/* Ao transferir o código abaixo para seu Arduino, você     */
/* poderá controlar o Braço Robótico através da Joystick    */
/* Shield.                                                  */
/* Os quatro botões A, B, C e D selecionam o Servo          */
/* Motor a ser controlado através do Joystick.              */
/* Botão A: O Joystick controlará o Servo da Garra.         */
/* Botão B: O Joystick controlará o Servo da Direita.       */
/* Botão C: O Joystick controlará o Servo da Base.          */
/* Botão D: O Joystick controlará o Servo da Esquerda.      */
/************************************************************/
/* Inclui a biblioteca ServoTimer2. Link para download:     */
/* https://github.com/nabontra/ServoTimer2/archive/refs/heads/master.zip */
#include <ServoTimer2.h>
/* Define os pinos digitais para cada botão.                */
#define Pino_bt_A 2
#define Pino_bt_B 3
#define Pino_bt_C 4
#define Pino_bt_D 5
/* Variáveis que armazenarão os dados do Joystick.          */
int JoyX;
int JoyY;
/* Variáveis que armazenarão os estados dos botões.         */
int Estado_bt_A;
int Estado_bt_B;
int Estado_bt_C;
int Estado_bt_D;
/* Variável que armazenará o modo de operação.              */
char Escolha;
/* Variáveis que armazenarão os ângulos dos servos.         */
int angBase;
int angDir;
int angEsq;
int angGuarra;
/* Cria os objetos de controle para cada servo.             */
ServoTimer2 servo_base;
ServoTimer2 servo_esquerda;
ServoTimer2 servo_direita;
ServoTimer2 servo_garra;

void setup() {
  /* Configura os pinos dos botões como entradas            */
  /* ativando os resistores internos da placa.              */
  pinMode(Pino_bt_A, INPUT_PULLUP);
  pinMode(Pino_bt_B, INPUT_PULLUP);
  pinMode(Pino_bt_C, INPUT_PULLUP);
  pinMode(Pino_bt_D, INPUT_PULLUP);
  /* Atribuição das portas de operação dos servos.          */
  servo_base.attach(9);
  servo_esquerda.attach(10);
  servo_direita.attach(11);
  servo_garra.attach(12);
  /* Atribui como posição inicial em 90º para todos os      */
  /* servos, chamando a função auxiliar angulo() que irá    */
  /* converter o ângulo para duração de pulsos, já que a    */
  /* biblioteca ServoTimer2 não trabalha com ângulos e sim  */
  /* com duração de pulsos elétricos.                       */
  angBase = angulo(90);
  angDir = angulo(90);
  angEsq = angulo(90);
  angGuarra = angulo(90);
  /* Inicia todos os servos na posição inicial (90º).       */
  servo_base.write(angBase);
  servo_esquerda.write(angEsq);
  servo_direita.write(angDir);
  servo_garra.write(angGuarra);
}

void loop() {
  /* Chama a função auxiliar para realizar a leitura do     */
  /* Joystick e dos botões armazenando os dados nas         */
  /* respectivas variáveis.                                 */
  Ler_Joystick();
  /* Se o botão A foi pressionado.                          */
  if (Estado_bt_A == 0) {
    /* Defina a Escolha como A.                             */
    Escolha = 'A';
  }
  /* Se o botão B foi pressionado.                          */
  if (Estado_bt_B == 0) {
    /* Defina a Escolha como B.                             */
    Escolha = 'B';
  }
  /* Se o botão C foi pressionado.                          */
  if (Estado_bt_C == 0) {
    /* Defina a Escolha como C.                             */
    Escolha = 'C';
  }
  /* Se o botão D foi pressionado.                          */
  if (Estado_bt_D == 0) {
    /* Defina a Escolha como D.                             */
    Escolha = 'D';
  }
  /* Após um botão ser pressionado, entrará em um dos quatro*/
  /* modos de operação (A, B, C e D).                       */
  switch (Escolha) {
    /* Caso a Escolha for A.                                */
    case 'A':
      /* Se o Joystick for deslocado para a esquerda e o    */
      /* ângulo do servo da garra for menor que 100°, abrirá*/
      /* a garra.                                           */
      if (JoyX > 700 && angGuarra < angulo(100)) {
        /* Posiciona o servo no ângulo atual.               */
        servo_garra.write(angGuarra);
        /* Incrementa o valor do ângulo atual.              */
        angGuarra = angGuarra + 4;
        /* Aguarda 5 milissegundos para atualizar a posição.*/
        delay(5);
      }
      /* Se o Joystick for deslocado para a direita e o     */
      /* ângulo do servo da garra for maior que 60°, fechará*/
      /* a garra.                                           */
      if (JoyX < 300 && angGuarra > angulo(60)) {
        /* Posiciona o servo no ângulo atual.               */
        servo_garra.write(angGuarra);
        /* Decrementa o valor do ângulo atual.              */
        angGuarra = angGuarra - 4;
        /* Aguarda 5 milissegundos para atualizar a posição.*/
        delay(5);
      }
      /* Final desse caso.                                  */
      break;
    /* Caso a Escolha for B.                                */
    case 'B':
      /* Se o Joystick for deslocado para a frente e o      */
      /* ângulo do servo da direita for menor que 180°,     */
      /* abaixará o braço.                                  */
      if (JoyY > 700 && angDir < angulo(180)) {
        /* Posiciona o servo no ângulo atual.               */
        servo_esquerda.write(angDir);
        /* Incrementa o valor do ângulo atual.              */
        angDir = angDir + 4;
        /* Aguarda 5 milissegundos para atualizar a posição.*/
        delay(5);
      }
      /* Se o Joystick for deslocado para a trás e o ângulo */
      /* do servo da direita for maior que 50º, levantará o */
      /* braço.                                             */
      if (JoyY < 300 && angDir > angulo(50)) {
        /* Posiciona o servo no ângulo atual.               */
        servo_esquerda.write(angDir);
        /* Decrementa o valor do ângulo atual.              */
        angDir = angDir - 4;
        /* Aguarda 5 milissegundos para atualizar a posição.*/
        delay(5);
      }
      /* Final desse caso.                                  */
      break;
    /* Caso a Escolha for C.                                */
    case 'C':
      /* Se o Joystick for deslocado para a direita e o     */
      /* ângulo do servo da base for menor que 180°, o braço*/
      /* girará no sentido horário.                         */
      if (JoyX < 300 && angBase < angulo(180)) {
        /* Posiciona o servo no ângulo atual.               */
        servo_base.write(angBase);
        /* Incrementa o valor do ângulo atual.              */
        angBase = angBase + 4;
        /* Aguarda 5 milissegundos para atualizar a posição.*/
        delay(5);
      }
      /* Se o Joystick for deslocado para a esquerda e      */
      /* o ângulo do servo da base for maior que 0°, o braço*/
      /* girará no sentido anti-horário.                    */
      if (JoyX > 700 && angBase > angulo(0)) {
        /* Posiciona o servo no ângulo atual.               */
        servo_base.write(angBase);
        /* Decrementa o valor do ângulo atual.              */
        angBase = angBase - 4;
        /* Aguarda 5 milissegundos para atualizar a posição.*/
        delay(5);
      }
      /* Final desse caso.                                  */
      break;
    /* Caso a Escolha for D.                                */
    case 'D':
      /* Se o Joystick for deslocado para a frente e o      */
      /* ângulo do servo da esquerda for menor que 180°,    */
      /* levantará o antebraço.                             */
      if (JoyY > 700 && angEsq < angulo(180)) {
        /* Posiciona o servo no ângulo atual.               */
        servo_direita.write(angEsq);
        /* Incrementa o valor do ângulo atual.              */
        angEsq = angEsq + 4;
        /* Aguarda 5 milissegundos para atualizar a posição.*/
        delay(5);
      }
      /* Se o Joystick for deslocado para a trás e o ângulo */
      /* do servo da esquerda for maior que 90°, abaixará o */
      /* antebraço.                                         */
      if (JoyY < 300 && angEsq > angulo(90)) {
        /* Posiciona o servo no ângulo atual.               */
        servo_direita.write(angEsq);
        /* Decrementa o valor do ângulo atual.              */
        angEsq = angEsq - 4;
        /* Aguarda 5 milissegundos para atualizar a posição.*/
        delay(5);
      }
      /* Final desse caso.                                  */
      break;
  }
}
/* Função auxiliar para realizar a leitura do Joystick.     */
void Ler_Joystick() {
  /* Coleta os valores analógicos dos Potenciômetros.       */
  JoyX = analogRead(A0);
  JoyY = analogRead(A1);
  /* Coleta os valores digitais dos botões.                 */
  Estado_bt_A = digitalRead(Pino_bt_A);
  Estado_bt_B = digitalRead(Pino_bt_B);
  Estado_bt_C = digitalRead(Pino_bt_C);
  Estado_bt_D = digitalRead(Pino_bt_D);
}
/* Função auxiliar para converter valores de grau para      */
/* duração de pulsos elétricos.                             */
int angulo(int grau) {
  return  map(grau, 0, 180, 600, 2400);
}
