/**********************************************************/
/* Aula 16 - Display 7 Segmentos com Ânodo ou Ânodo Comum */
/* Programação de um contador com o display 7 segmentos.  */
/**********************************************************/

/* ATENÇÃO! Descomente as linhas corresponente ao modelo  */
/* de seu display.                                        */

/* Descomente essas linhas para Display de Ânodo Comum.  */
//bool liga = LOW;
//bool desliga = HIGH;

/* Descomente essas linhas para Display de Cátodo Comum.  */
//bool liga = HIGH;
//bool desliga = LOW;


/* Define os pinos do para cada segmento do display.      */
#define a 8 
#define b 9 
#define c 3
#define d 4
#define e 5 
#define f 7
#define g 6
#define ponto 2 

void setup() {
  /* Define os pinos como saída.                          */
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(ponto, OUTPUT);
  /* Inicia com todos os segmentos desligados.            */
  digitalWrite(a, desliga);
  digitalWrite(b, desliga);
  digitalWrite(c, desliga);
  digitalWrite(d, desliga);
  digitalWrite(e, desliga);
  digitalWrite(f, desliga);
  digitalWrite(g, desliga);
  digitalWrite(ponto, desliga);
}
void loop() {
  /* Loop para a passagem dos 10 dígitos (0-9).           */
  for (int digito = 0; digito < 10; digito++)
  {
    /* Condição para ligar o segmento a.                  */
    /* Se o digito não for 1 e 4, faça...                 */
    if (digito != 1 && digito != 4)
      digitalWrite(a, liga);
    /* Condição para ligar o segmento b.                  */
    /* Se o digito não for 5 e 6, faça...                 */
    if (digito != 5 && digito != 6)
      digitalWrite(b, liga);
    /* Condição para ligar o segmento c.                  */
    /* Se o digito não for 2, faça...                     */
    if (digito != 2)
      digitalWrite(c, liga);
    /* Condição para ligar o segmento d.                  */
    /* Se o digito não for 1, 4 e 7 faça...               */
    if (digito != 1 && digito != 4 && digito != 7)
      digitalWrite(d, liga);
    /* Condição para ligar o segmento e                           */
    /* Se o digito for 2 ou 6 ou 8 ou 0, faça...                  */
    if (digito == 2 || digito == 6 || digito == 8 || digito == 0)
      digitalWrite(e, liga);
    /* Condição para ligar o segmento f                           */
    /* Se o digito não for 1, 2, 3 e 7 faça...                    */
    if (digito != 1 && digito != 2 && digito != 3 && digito != 7)
      digitalWrite(f, liga);
    /* Condição para ligar o segmento d.                          */
    /* Se o digito não for 0, 1 e 7 faça...                       */      
    if (digito != 0 && digito != 1 && digito != 7)
      digitalWrite(g, liga);
    /* Liga e desliga de forma alternada o ponto.                 */
    digitalWrite(ponto, !digitalRead(ponto));
    /* Aguarda 1 segundo para trocar de dígito.                   */
    delay(1000); 
    /* Apaga todos os segmentos para apresentar o próximo dígito */
    digitalWrite(a, desliga);
    digitalWrite(b, desliga);
    digitalWrite(c, desliga);
    digitalWrite(d, desliga);
    digitalWrite(e, desliga);
    digitalWrite(f, desliga);
    digitalWrite(g, desliga);
  }
}
