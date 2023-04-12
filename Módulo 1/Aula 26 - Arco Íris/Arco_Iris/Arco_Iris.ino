/***************************************************************/
/* Aula 26 - Arco Íris                                         */
/* Programação: Gerando no LED RGB, por meio das portas        */
/* digitais PWM, o espectro do arco-íris, controlado           */
/* pelo sensor potenciômetro.                                  */
/*                                                             */
/*                    ATENÇÃO!                                 */
/* Nas linhas 14 ou 15 deste código, você deverá informar se o */
/* LED RGB utilizado é de ânodo comum ou cátodo comum para o   */
/* correto funcionamento deste protótipo descomentando a linha */
/* correspondente ao seu LED RGB.                              */
/***************************************************************/

// char modelo[] = "Ânodo Comum";
// char modelo[] = "Cátodo Comum";

/* Variável que armazena os dados do potenciômetro.            */
int Pot = 0;
/* Define a porta analógica A0 como pino do potenciômetro.     */
int Pin_pot = A0;
/* Define a porta digital 3 (PWM) no controle do LED Vermelho. */
int Led_R = 3;
/* Define a porta digital 5 (PWM) no controle do LED Verde.  */
int Led_G = 5;
/* Define a porta digital 6 (PWM) no controle do LED Azul.   */
int Led_B = 6;

void setup() {
  /* Define o pino do LED Vermelho (Red) como SAÍDA.         */
  pinMode(Led_R, OUTPUT);
  /* Define o pino do LED Verde (Green) como SAÍDA.          */
  pinMode(Led_G, OUTPUT);
  /* Define o pino do LED Azul (Blue) como SAÍDA.            */
  pinMode(Led_B, OUTPUT);
}

void loop() {
  /* Mapeia o valor lido no potenciômetro (0 à 1023) para    */
  /* sete valores (1 à 7).                                   */
  Pot = map(analogRead(Pin_pot), 0, 1023, 1, 7);
/* Se o modelo do LED é cátodo comum, faça...                */
  if (modelo[0] == 'C') {
    /* Se o valor de Pot for igual a 1, acenda VERMELHO      */
    if (Pot == 1) {
      /* Enviando o sinal PWM 255 no LED Vermelho.           */
      analogWrite(Led_R, 255);
      /* Enviando o sinal PWM 0 no LED Verde.                */
      analogWrite(Led_G, 0);
      /* Enviando o sinal PWM 0 no LED Azul.                 */
      analogWrite(Led_B, 0);
    }
    /* Se o valor de Pot for igual a 2, acenda LARANJA       */
    if (Pot == 2) {
      /* Enviando o sinal PWM 255 no LED Vermelho.           */
      analogWrite(Led_R, 255);
      /* Enviando o sinal PWM 100 no LED Verde.              */
      analogWrite(Led_G, 100);
      /* Enviando o sinal PWM 0 no LED Azul.                 */
      analogWrite(Led_B, 0);
    }
    /* Se o valor de Pot for igual a 3, acenda AMARELO       */
    if (Pot == 3) {
      /* Enviando o sinal PWM 255 no LED Vermelho.           */
      analogWrite(Led_R, 255);
      /* Enviando o sinal PWM 255 no LED Verde.              */
      analogWrite(Led_G, 255);
      /* Enviando o sinal PWM 0 no LED Azul.                 */
      analogWrite(Led_B, 0);
    }
    /* Se o valor de Pot for igual a 4, acenda VERDE         */
    if (Pot == 4) {
      /* Enviando o sinal PWM 0 no LED Vermelho.             */
      analogWrite(Led_R, 0);
      /* Enviando o sinal PWM 255 no LED Verde.              */
      analogWrite(Led_G, 255);
      /* Enviando o sinal PWM 0 no LED Azul.                 */
      analogWrite(Led_B, 0);
    }
    /* Se o valor de Pot for igual a 5, acenda AZUL          */
    if (Pot == 5) {
      /* Enviando o sinal PWM 0 no LED Vermelho.             */
      analogWrite(Led_R, 0);
      /* Enviando o sinal PWM 0 no LED Verde.                */
      analogWrite(Led_G, 0);
      /* Enviando o sinal PWM 255 no LED Azul.               */
      analogWrite(Led_B, 255);
    }
    /* Se o valor de Pot for igual a 6, acenda ANIL          */
    if (Pot == 6) {
      /* Enviando o sinal PWM 75 no LED Vermelho.            */
      analogWrite(Led_R, 75);
      /* Enviando o sinal PWM 0 no LED Verde.                */
      analogWrite(Led_G, 0);
      /* Enviando o sinal PWM 130 no LED Azul.               */
      analogWrite(Led_B, 130);
    }
    /* Se o valor de Pot for igual a 7, acenda VIOLETA       */
    if (Pot == 7) {
      /* Enviando o sinal PWM 255 no LED Vermelho.           */
      analogWrite(Led_R, 255);
      /* Enviando o sinal PWM 0 no LED Verde.                */
      analogWrite(Led_G, 0);
      /* Enviando o sinal PWM 255 no LED Azul.               */
      analogWrite(Led_B, 255);
    }
  } else { /* Senão ... (LED com ânodo comum, faça...)       */
    /* Se o valor de Pot for igual a 1, acenda VERMELHO      */
    if (Pot == 1) {
      /* Enviando o sinal PWM 0 no LED Vermelho.             */
      analogWrite(Led_R, 0);
      /* Enviando o sinal PWM 255 no LED Verde.              */
      analogWrite(Led_G, 255);
      /* Enviando o sinal PWM 255 no LED Azul.               */
      analogWrite(Led_B, 255);
    }
    /* Se o valor de Pot for igual a 2, acenda LARANJA       */
    if (Pot == 2) {
      /* Enviando o sinal PWM 0 no LED Vermelho.             */
      analogWrite(Led_R, 0);
      /* Enviando o sinal PWM 155 no LED Verde.              */
      analogWrite(Led_G, 155);
      /* Enviando o sinal PWM 255 no LED Azul.               */
      analogWrite(Led_B, 255);
    }
    /* Se o valor de Pot for igual a 3, acenda AMARELO       */
    if (Pot == 3) {
      /* Enviando o sinal PWM 0 no LED Vermelho.             */
      analogWrite(Led_R, 0);
      /* Enviando o sinal PWM 0 no LED Verde.                */
      analogWrite(Led_G, 0);
      /* Enviando o sinal PWM 255 no LED Azul.               */
      analogWrite(Led_B, 255);
    }
    /* Se o valor de Pot for igual a 4, acenda VERDE         */
    if (Pot == 4) {
      /* Enviando o sinal PWM 255 no LED Vermelho.           */
      analogWrite(Led_R, 255);
      /* Enviando o sinal PWM 0 no LED Verde.                */
      analogWrite(Led_G, 0);
      /* Enviando o sinal PWM 255 no LED Azul.               */
      analogWrite(Led_B, 255);
    }
    /* Se o valor de Pot for igual a 5, acenda AZUL          */
    if (Pot == 5) {
      /* Enviando o sinal PWM 255 no LED Vermelho.           */
      analogWrite(Led_R, 255);
      /* Enviando o sinal PWM 255 no LED Verde.              */
      analogWrite(Led_G, 255);
      /* Enviando o sinal PWM 0 no LED Azul.                 */
      analogWrite(Led_B, 0);
    }
    /* Se o valor de Pot for igual a 6, acenda ANIL          */
    if (Pot == 6) {
      /* Enviando o sinal PWM 180 no LED Vermelho.           */
      analogWrite(Led_R, 180);
      /* Enviando o sinal PWM 255 no LED Verde.              */
      analogWrite(Led_G, 255);
      /* Enviando o sinal PWM 125 no LED Azul.               */
      analogWrite(Led_B, 125);
    }
    /* Se o valor de Pot for igual a 7, acenda VIOLETA       */
    if (Pot == 7) {
      /* Enviando o sinal PWM 0 no LED Vermelho.             */
      analogWrite(Led_R, 0);
      /* Enviando o sinal PWM 255 no LED Verde.              */
      analogWrite(Led_G, 255);
      /* Enviando o sinal PWM 0 no LED Azul.                 */
      analogWrite(Led_B, 0);
    }
  }
}
