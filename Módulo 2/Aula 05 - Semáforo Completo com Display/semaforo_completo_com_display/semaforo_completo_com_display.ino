/****************************************************/
/* Aula 05 - Semáforo Completo com Display.         */
/* Programação do semáforo completo com display de 7*/
/* segmentos. Seu funcionamento consiste em   */
/* alterar seu modo de operação assim que o botão   */
/* for pressionado e durante o período de travessia */
/* o display irá iniciar uma contagem regressiva    */
/* informando o tempo restante. Neste código,       */
/* utilizou a função de interrupção (attachInterrupt),*/
/* para saber mais sobre a função acesse:             */
/* https://www.arduino.cc/reference/pt/language/functions/external-interrupts/attachinterrupt/ */
/****************************************************/
/* ATENÇÃO! De acordo com o modelo de seu Display 7 Segmentos */
/* descomente uma das duas linhas abaixo.                     */
//int modelo = 1; /* Display de Ânodo Comum. */
//int modelo = 2; /* Display de Cátodo Comum. */

/* Define o nome "botao" para o pino 2. */
#define botao 2

/*
  Variável que seleciona o modo de operação do semáforo
  0 - Modo aberto para carros;
  1 - Modo aberto para pedestres;
*/
int modo = 0;

/* Variável matricial que armazena os estados de    */
/* cada segmento do display para cada dígito.       */
byte displaySeteSeg[10][7] = {
  { 1, 0, 1, 1, 1, 1, 1 },  //DIGITO 9
  { 1, 1, 1, 1, 1, 1, 1 },  //DIGITO 8
  { 1, 0, 0, 0, 0, 1, 1 },  //DIGITO 7
  { 1, 1, 1, 1, 1, 0, 1 },  //DIGITO 6
  { 1, 0, 1, 1, 1, 0, 1 },  //DIGITO 5
  { 1, 0, 0, 1, 1, 1, 0 },  //DIGITO 4
  { 1, 0, 1, 0, 1, 1, 1 },  //DIGITO 3
  { 0, 1, 1, 0, 1, 1, 1 },  //DIGITO 2
  { 1, 0, 0, 0, 0, 1, 0 },  //DIGITO 1
  { 1, 1, 1, 1, 0, 1, 1 }   //DIGITO 0
};

void setup() {
  /* Loop para configurar os pinos como saída.  */
  for (int i = 0; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  /* Configuramos o pino do botão como entrada. */
  pinMode(botao, INPUT);

  /* Ativa a função de interrupção no pino que o botão está conectado. v */
  attachInterrupt(digitalPinToInterrupt(botao), botaoAcionado, FALLING);

  /* Comando para o Display de Ânodo Comum iniciar desligado.            */
  if (modelo == 1) {
    for (int i = 3; i <= 9; i++) {
      digitalWrite(i, HIGH);
    }
  }
}

void loop() {
  switch (modo) {
    case 0:
      /* Caso o botão não for pressionado mantém o semáforo
        aberto para os carros chamando a função "espera()"  */
      espera();
      break;
    case 1:
      /* Caso o botão seja pressionado, após 1 segundo o semáforo entrará
        no modo de travessia por 10 segundos chamando a função "travessia()" */
      delay(1000);
      travessia();
      modo = 0;
      break;
  }
}

/* Após pressionar o botão, será executada essa função, ela
  seleciona o modo de operação do semáforo. */
void botaoAcionado() {
  modo = 1;
}

/* Função que mantém o semáforo aberto para os carros */
void espera() {
  digitalWrite(0, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  if (modelo == 1) {
    for (int i = 7; i <= 13; i++) {
      digitalWrite(i, HIGH);
    }
  } else {
    for (int i = 7; i <= 13; i++) {
      digitalWrite(i, LOW);
    }
  }
}

/* Função que controla o semáforo para a travessia de pedestre */
void travessia()
{
  /* Aciona o amarelo do semáforo dos carros; */
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  delay(3000);
  /* Aciona vermelho para os carros e verde para pedestre; */
  digitalWrite(1, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  /* Inicia a contagem de 9 a 0 para a travessia */
  boolean led = HIGH;
  for (byte contador = 0; contador < 10; contador++) {
    if (contador >= 6)
    {
      digitalWrite(4, LOW);
      digitalWrite(5, led);
      led = !led;
    }
    /* Chama a função para acionar o display */
    ligaSegmentosDisplay(contador);
  }

}

/* Função para acionar o display com o digito correspondente*/
void ligaSegmentosDisplay(byte digito) {
  byte pino = 7;
  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos) {
    if(modelo == 1){
      digitalWrite(pino, displaySeteSeg[digito][contadorSegmentos]);
    }else{
      digitalWrite(pino, !displaySeteSeg[digito][contadorSegmentos]);
    }    
    ++pino; /*incrementa o valor do pino (vai de 7 a 13) */
  }
  delay(1000); /* Aguarda 1 segundo para reiniciar a contagem */
}
