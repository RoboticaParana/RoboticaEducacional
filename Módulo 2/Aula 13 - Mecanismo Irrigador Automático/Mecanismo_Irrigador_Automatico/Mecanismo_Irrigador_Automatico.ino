/************************************************************/
/* Aula 13 - Mecanismo Irrigador Automático                 */
/* Programação do mecanismo do irrigador automático.        */
/* Ao transferir o código abaixo para seu Arduino, o sensor */
/* de umidade monitorará o nível de umidade do solo. Quando */
/* a porcentagem estiver abaixo do valor definido, será     */
/* acionado o módulo Relé, consequentemente, o motor que    */
/* está conectado ao módulo também será ligado (podendo ser */
/* uma bomba dágua que irrigará o solo). Estando a umidade  */
/* acima do valor critico definido, o módulo Relé será      */
/* desativado, desligando assim o motor (bomba dágua).      */
/* També é possível acompanhar o estado do mecanismo através*/
/* do Monitor Serial do Arduino IDE.                        */
/************************************************************/
/* Define os pinos para o Sensor e para o Relé.             */
#define pinoAnalog A0
#define pinoRele 8

/* Variável que armazena a leitura analógica do Sensor.     */
int ValAnalogIn;
void setup() {
  /* Inicia a comunicação Serial em 9600 bauds.             */
  Serial.begin(9600);
  /* Condfigura o pinoRele como Saída.                      */
  pinMode(pinoRele, OUTPUT);
}
void loop() {
  /* Armazena o valor analógico recebido do Sensor.         */
  ValAnalogIn = analogRead(pinoAnalog);
  /* Converte o valor analógico em uma escala de 0% à 100%  */
  int Porcento = map(ValAnalogIn, 1023, 0, 0, 100);
  /* Imprime a porcentagem de umidade no Monitor Serial.    */
  Serial.print(Porcento);
  /* Imprime o símbolo % junto ao valor da porcentagem.     */
  Serial.print("%. ");
  /* Se a porcentagem for menor ou igual à 45, faz...       */
  if (Porcento <= 45) {
    /* Imprime a frase no Monitor Serial.                   */
    Serial.println("Irrigação ATIVADA...");
    /* Altera o estado do pinoRele para nível lógico Alto.  */
    digitalWrite(pinoRele, HIGH);
  }
  /* Senão...                                               */
  else { 
    /* Imprime a frase no Monitor Serial.                   */
    Serial.println("Irrigação DESATIVADA...");
    /* Altera o estado do pinoRele para nível lógico Baixo. */
    digitalWrite(pinoRele, LOW);
  }
  /* Aguarda 1 segundo para a próxima leitura.              */
  delay (1000);
}
