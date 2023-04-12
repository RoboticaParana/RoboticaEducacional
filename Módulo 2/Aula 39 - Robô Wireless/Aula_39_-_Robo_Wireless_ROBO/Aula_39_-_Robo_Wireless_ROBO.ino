/************************************************************/
/* Aula 39 - Robô Wireless                                  */
/* Programação da placa Arduino.                            */
/* Este programa faz seu robô se mover com comandos         */
/* recebidos de um dispositivo conectado à sua rede         */
/* wireless. Os comandos que o robô irá receber serão:      */
/* Mover para frente, mover para trás, girar no sentido     */
/* horário, girar no sentido anti-horário e parar.          */
/************************************************************/
/* Inclui a biblioteca que controla a Motor Shield.         */
#include <AFMotor.h>
/* Portas da Motor Shield que estão sendo utilizadas.               */
AF_DCMotor Motor_Direita(2);
AF_DCMotor Motor_Esquerda(3);
/* Variável que define a potência dos motores (0 a 255).     */
int potencia = 140;
/* Define o pino que receberá os pulsos do módulo wireless.*/
int pino_ESP = 9;
/* Variáveis utilizadas para determinar a duração dos       */
/* pulsosemitidos pelo módulo wireless.                         */
unsigned long Tempo_Pulso = 30;
unsigned long Tempo_Inicial_Pulso;
unsigned long Tempo_Final_Pulso;
void setup() {
  /* Configura o pino que receberá os pulsos como entrada. */
  pinMode(pino_ESP, INPUT);
  /* Inicia com os motores parados.                            */
  pare();
delay(2000);  
}
void loop() {
  /* Chama a função que checa a duração do pulso recebido. */
  checa_pulso();
  /* Se receber um pulso em torno de 10 milissegundos,     */
  /* siga em frente por 500 milissegundos e pare.              */
  if (Tempo_Pulso >= 5 && Tempo_Pulso <= 12) {
    frente();
    delay(500);
    pare();
  }
  /* Se receber um pulso em torno de 20 milissegundos,     */
  /* gire à Esquerda por 200 milissegundos e pare.             */
  if (Tempo_Pulso >= 15 && Tempo_Pulso <= 22) {
    esquerda();
    delay(200);
    pare();
  }
  /* Se receber um pulso em torno de 30 milissegundos,    */
  /* pare o movimento.          */
  if (Tempo_Pulso >= 25 && Tempo_Pulso <= 32) {
    pare();
  }
  /* Se receber um pulso em torno de 40 milissegundos,    */
  /* gire à direita por 200 milissegundos e pare.             */
  if (Tempo_Pulso >= 35 && Tempo_Pulso <= 42) {
    direita();
    delay(200);
    pare();
  }
  /* Se receber um pulso em torno de 50 milissegundos,   */
  /* mova de ré por 500 milissegundos e pare.                */
  if (Tempo_Pulso >= 45 && Tempo_Pulso <= 52) {
    re();
    delay(500);
    pare();
  }
  /* Enquanto o pulso estiver em torno de 60 milissegundos, */
  /* mantenha o movimento em frente.                        */
  if (Tempo_Pulso >= 55 && Tempo_Pulso <= 62) {
    frente();
    checa_pulso();
  }
  /* Enquanto o pulso estiver em torno de 70 milissegundos, */
  /* mantenha o movimento em marcha ré.                        */
  while (Tempo_Pulso >= 65 && Tempo_Pulso <= 72) {
    re();
    checa_pulso();
  }
}
/******************** Funções Criadas ***********************/
/* Função que para os motores.                                            */
void pare()
{
  Tempo_Pulso = 30;
  Motor_Esquerda.run(RELEASE);
  Motor_Direita.run(RELEASE);
}
/* Função que aciona os motores para frente.                      */
void frente()
{
  Motor_Esquerda.setSpeed(potencia+80);
  Motor_Direita.setSpeed(potencia);
  Motor_Esquerda.run(FORWARD);
  Motor_Direita.run(FORWARD);
}
/* Função que aciona os motores para trás.                       */
void re()
{
  Motor_Esquerda.setSpeed(potencia+80);
  Motor_Direita.setSpeed(potencia);
  Motor_Esquerda.run(BACKWARD);
  Motor_Direita.run(BACKWARD);
}
/* Função que gira o robô para a esquerda.                      */
void esquerda()
{
  Motor_Esquerda.setSpeed(potencia);
  Motor_Direita.setSpeed(potencia);
  Motor_Esquerda.run(BACKWARD);
  Motor_Direita.run(FORWARD);
}
/* Função que gira o robô para a direita.                      */
void direita()
{
  Motor_Esquerda.setSpeed(potencia);
  Motor_Direita.setSpeed(potencia);
  Motor_Esquerda.run(FORWARD);
  Motor_Direita.run(BACKWARD);
}
/* Função que calcula a duração do pulso recebido           */
void checa_pulso() { 
  /* Se o pulso iniciar, faz...                                     */
  if (digitalRead(pino_ESP) == HIGH) {
    /* Marca o tempo do início do pulso.                         */
    Tempo_Inicial_Pulso = millis();
    /* Aguarda enquanto o pulso estiver sendo enviado.  */
    while (digitalRead(pino_ESP) == HIGH) {}
    /* Marca o tempo que o pulso terminou.                      */
    Tempo_Final_Pulso = millis();
    /* Calcula a duração do pulso (T_final - T_inicial).*/
    Tempo_Pulso = Tempo_Final_Pulso - Tempo_Inicial_Pulso;
  }
  delay(1);
}
