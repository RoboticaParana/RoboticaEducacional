/****************************************************************/
/* Aula 13 - Push Button                                        */
/* Programação: Liga ou desliga um LED cada vez que um push     */
/* button for pressionado.                                      */
/****************************************************************/

/* Define o pino do botão com o pino digital 10 do Arduino.     */
#define Pino_Botao 10 
/* Define o pino do LED com o pino digital 9 do Arduino.        */
#define Pino_LED 8 
/* Variável do tipo boleana para o estado do LED (Ligado/HIGH   */
/* ou Desligado/LOW).                                           */
bool Estado = LOW; 
/* Variável do tipo inteiro para o estado do botão              */
/* (Pressionado/0 ou Solto/1).                                  */
int Estado_Botao = 0; 

/* Função para configuração da placa Arduino.                   */
void setup() {
  /* Define o pino do LED como saída de dados.                  */
  pinMode(Pino_LED, OUTPUT);
  /* Define o pino do botão como entrada de dados.              */
  pinMode(Pino_Botao, INPUT);
}

/* Função looping infinito.                                     */
void loop() {
  /* Lê o estado do botão (HIGH ou LOW) e armazena na variável. */
  Estado_Botao = digitalRead(Pino_Botao);
  /* Se o botão foi pressionado, faça...                        */
  if (Estado_Botao == HIGH) {
    /* Troque o estado do LED (ligado para desligado ou         */
    /* vice-versa).                                             */
    Estado = !Estado;
    /* Ativa o LED para seu novo Estado (ligado ou desligado).  */
    digitalWrite(Pino_LED, Estado);
  }
  /* Enquanto o botão estiver pressionado, não faça mais nada.  */
  while (digitalRead(Pino_Botao) == HIGH);{
  }
  /* Pequena pausa antes de realizar outra verificação no botão.*/
  delay(100);
}
