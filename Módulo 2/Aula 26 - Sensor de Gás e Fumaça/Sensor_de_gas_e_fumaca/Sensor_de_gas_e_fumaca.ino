/************************************************************/
/* Aula 26 - Sensor de Gás e Fumaça                         */
/* Programação do Sensor de Gás e Fumaça.                   */
/* Ao transferir o código abaixo para seu Arduino, o sensor */
/* de Gás e Fumaça irá monitorar as condições do ambiente e */
/* enviará dados digitais e analógicos ao Arduino.          */
/* Ao detectar a presença de gás ou fumaça, o Sensor enviará*/
/* os dados ao Arduino, que por sua vez, irá indicar através*/
/* do acionamento de um LED Vermelho e de bips no Buzzer.   */
/* Enquanto o sistema não detectar a presença de gás ou     */
/* fumaça, um LED Verde permanecerá ligado e o Buzzer       */
/* desligado. A calibração da sensibilidade do Sensor é     */
/* feita com auxílio de uma pequena chave Philips ou fenda  */
/* através do Potenciômetro presente em sua traseira.       */
/* Os dados recebidos do sensor podem serem vistos através  */
/* do monitor serial do Arduino IDE.                        */
/************************************************************/
/* Definição dos pinos digitais e analógico.                */
#define MQ_analogico A0
#define MQ_digital 4
#define Buzzer 5
#define Led_Verde 6
#define Led_Vermelho 7
/* Variáveis para armazenar os dados do Sensor.             */
int valor_analogico;
int valor_digital;
void setup() {
  /* Inicia a comunicação Serial na velocidade de 9600 bauds*/
  Serial.begin(9600);
  /* Configura os pinos digitais como saída e entrada.      */
  pinMode(MQ_digital, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Led_Verde, OUTPUT);
  pinMode(Led_Vermelho, OUTPUT);
}
void loop() {
  /* Coleta os dados do Sensor nas variáveis definidas.     */
  valor_analogico = analogRead(MQ_analogico);
  valor_digital = digitalRead(MQ_digital);
  /* Imprime no Monitor Serial o valor Analógico atual.     */
  Serial.print(valor_analogico);
  /* Imprime no Monitor Serial um separador.                */
  Serial.print(" || ");
  /* Se o Sensor detectar gás ou fumaça através do pino     */
  /* digital, faça...                                       */
  if (valor_digital == 0)
  {
    /* Após o separador, escreva GÁS DETECTADO!!!           */
    Serial.println("GAS DETECTADO!!!");
    /* Desligue o LED Verde.                                */
    digitalWrite(Led_Verde, LOW);
    /* Ligue o LED Vermelho.                                */
    digitalWrite(Led_Vermelho, HIGH);
    /* Emita bips, através do Buzzer, na frequência 262Hz   */
    /* em intervalo de 250 milissegundos.                   */
    tone(Buzzer, 262, 250);
  }
  /* Senão, faça...                                         */
  else
  {
    /* Após o separador, escreva GÁS AUSENTE!!!             */
    Serial.println("GAS AUSENTE!!!");
    /* Ligue o LED Verde.                                   */
    digitalWrite(Led_Verde, HIGH);
    /* Desligue o LED Vermelho.                             */
    digitalWrite(Led_Vermelho, LOW);
    /* Desligue o Buzzer.                                   */
    noTone(Buzzer);
  }
  /* Pausa de 500 milissegundos para a nova leitura.        */
  delay(500);
}
