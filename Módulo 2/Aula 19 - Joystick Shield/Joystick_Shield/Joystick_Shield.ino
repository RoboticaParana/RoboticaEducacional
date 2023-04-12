/************************************************************/
/* Aula 19 - Joystick Shield                                */
/* Programação do controle Joystick Shield.                 */
/* Ao transferir o código abaixo para seu Arduino, você     */
/* poderá controlar dois Servos Motores, através dos eixos  */
/* do Joystick, 6 LEDs e 1 Buzzer, através dos botões       */
/* presentes na placa Joystick Shield.                      */
/************************************************************/
/* Inclui a bliblioteca de controle do Servo Motor.         */
#include <Servo.h>
/* Cria os objetos de controle dos Servos Motores.          */
Servo servo1;
Servo servo2;
/* Definição de pinagem.                                    */
#define Servo1 A2
#define Servo2 A3
#define Botao_A 2
#define Botao_B 3
#define Botao_C 4
#define Botao_D 5
#define Botao_E 6
#define Botao_F 7
#define Botao_K 8
#define LED_C 9
#define LED_D 10
#define LED_E 11
#define LED_F 12
#define Buzzer 13
#define Pot_X A0
#define Pot_Y A1
#define LED_A A4
#define LED_B A5

void setup() {
  /* Endereça os objetos de controle aos pinos definidos    */
  /* para controle dos Servos Motores.                      */
  servo1.attach(Servo1);
  servo2.attach(Servo2);
  /* Loop para definir os pinos 2 ao 8 como entradas        */
  /* ativando os resistores internos do Arduino.            */
  for (int i = 2; i <= 8; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  /* Loop para definir os pinos 9 ao 13 como saídas.        */
  for (int i = 9; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  /* Define os pinos analógicos do LED_A e LED_B como saídas*/
  /* digitais.                                              */
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  /* Posiciona os servos de acordo com as leituras dos dados*/
  /* dos Potenciômetros(Joystick).                          */
  servo1.write(map(analogRead(Pot_X), 0, 1023, 0, 180));
  servo2.write(map(analogRead(Pot_Y), 0, 1023, 0, 180));

  /* Enquanto o Botão_A estiver pressionado, mantenha o     */
  /* LED_A ligado.                                          */
  while (!digitalRead(Botao_A)) {
    digitalWrite(LED_A, HIGH);
  }
  /* Enquanto o Botão_B estiver pressionado, mantenha o     */
  /* LED_B ligado.                                          */
  while (!digitalRead(Botao_B)) {
    digitalWrite(LED_B, HIGH);
  }
  /* Enquanto o Botão_C estiver pressionado, mantenha o     */
  /* LED_C ligado.                                          */
  while (!digitalRead(Botao_C)) {
    digitalWrite(LED_C, HIGH);
  }
  /* Enquanto o Botão_D estiver pressionado, mantenha o     */
  /* LED_D ligado.                                          */
  while (!digitalRead(Botao_D)) {
    digitalWrite(LED_D, HIGH);
  }
  /* Enquanto o Botão_E estiver pressionado, mantenha o     */
  /* LED_E ligado.                                          */
  while (!digitalRead(Botao_E)) {
    digitalWrite(LED_E, HIGH);
  }
  /* Enquanto o Botão_F estiver pressionado, mantenha o     */
  /* LED_F ligado.                                          */
  while (!digitalRead(Botao_F)) {
    digitalWrite(LED_F, HIGH);
  }
  /* Enquanto o Botão_K estiver pressionado, emita som      */
  /* através do Buzzer.                                     */
  while (!digitalRead(Botao_K)) {
    tone(Buzzer, 800);
  }
  /* Se nenhum botão estiver sendo pressionado, chame a     */
  /* função que desliga todos os LEDs e o Buzzer.           */
  Off_LEDs();
  noTone(Buzzer);
}
/* Função que desliga todos os LEDs.                        */
void Off_LEDs() {
  for (int i = 9; i <= 12; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
}
