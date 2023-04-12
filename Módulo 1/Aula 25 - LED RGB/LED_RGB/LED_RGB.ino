/*********************************************************/
/* Aula 25 - LED RGB                                     */
/* Programação: Alternando as cores do LED RGB através   */
/* do sensor potenciômetro.                              */
/*                                                       */
/*                    ATENÇÃO!                           */
/* Nas linhas 13 ou 14 deste código, você deverá informar*/
/* se o LED RGB utilizado é de ânodo comum ou cátodo     */
/* comum para o correto funcionamento deste protótipo    */
/* descomentando a linha correspondente ao seu LED RGB.  */
/*********************************************************/

// char modelo[] = "Ânodo Comum";
// char modelo[] = "Cátodo Comum";

/* Define o pino analógico A0 para o potenciômetro.      */
int Pin_pot = A0;
/* Variável que armazenará os dados do potenciômetro.    */
int Pot = 0;
/* Define o pino digital 2 para o LED Vermelho.          */
int Led_R = 2;
/* Define o pino digital 3 para o LED Verde.             */
int Led_G = 3;
/* Define o pino digital 4 para o LED Azul.              */
int Led_B = 4;
/* Variáveis para controle dos LEDs.                     */
int ligar;
int desligar;

void setup() {
  /* Define o pino Led_R como SAÍDA.                     */
  pinMode(Led_R, OUTPUT);
  /* Define o pino Led_G como SAÍDA.                     */
  pinMode(Led_G, OUTPUT);
  /* Define o pino Led_B como SAÍDA.                     */
  pinMode(Led_B, OUTPUT);

  /* Rotina que verifica o tipo de LED RGB utilizado e   */
  /* adequa os parâmetros para ligar e desligar o LED.   */
  if (modelo[0] != 'C') {
    ligar = 0;
    desligar = 1;
  } else {
    ligar = 1;
    desligar = 0;
  }
  /* Inicia com os LEDs desligados.                      */
  digitalWrite(Led_R, desligar);
  digitalWrite(Led_G, desligar);
  digitalWrite(Led_B, desligar);
}
void loop() {
  /* Armazena os dados do potenciômetro na variável Pot. */
  Pot = analogRead(Pin_pot);
  /* Se Pot estiver entre 0 e 341, faça...               */
  if (Pot >= 0 && Pot <= 341) {
    /* Ligue o LED Vermelho.                             */
    digitalWrite(Led_R, ligar);
    /* Senão...                                          */
  } else {
    /* Desligue o LED Vermelho.                          */
    digitalWrite(Led_R, desligar);
  }
  /* Se Pot estiver entre 342 e 682, faça...             */
  if (Pot >= 342 && Pot <= 682) {
    /* Ligue o LED Verde.                                */
    digitalWrite(Led_G, ligar);
    /* Senão...                                          */
  } else {
    /* Desligue o LED Verde.                             */
    digitalWrite(Led_G, desligar);
  }
  /* Se Pot estiver entre 686 e 1023, faça...            */
  if (Pot >= 683 && Pot <= 1023) {
    /* Ligue o LED Azul.                                 */
    digitalWrite(Led_B, ligar);
    /* Senão...                                          */
  } else {
    /* Desligue o LED Azul.                              */
    digitalWrite(Led_B, desligar);
  }
}
