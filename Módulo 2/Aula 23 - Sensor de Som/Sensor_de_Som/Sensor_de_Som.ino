/************************************************************/
/* Aula 23 - Sensor de Som                                  */
/* Programação do Sensor de Som.                            */
/* Ao transferir o código abaixo para seu Arduino, o sensor */
/* iniciará o monitoramento. Caso detecte um som na         */
/* intensidade ajustada através do Potenciômetro integrado  */
/* ao Sensor, será enviado um sinal elétrico ao Arduino, o  */
/* qual irá ativar ou desativar o LED presente no protótipo.*/
/************************************************************/
/* Definição dos pinos do Sensor e do LED.                  */
#define pino_sensor 8
#define pino_LED 13
/* Variável booleana para controle do LED.                  */
boolean estado = LOW;

void setup() {
  /* Configuração do modo de operação dos pinos digitais.   */
  pinMode(pino_sensor, INPUT);
  pinMode(pino_LED, OUTPUT);
}

void loop() {
  /* Armazena na variável som os dados do Sensor.           */
  int som = digitalRead(pino_sensor);
  /* Se a variável som recebeu o pulso elétrico (som = 1),  */
  /* faça...                                                */
  if (som == 1) {
    /* Altera o valor booleano da variável estado (Se for   */
    /* LOW, muda para HIGH e se for HIGH, muda para LOW).   */
    estado = !estado;
    /* Envia para o pino do LED o valor booleano atual da   */
    /* variável estado (LOW ou HIGH).                       */
    digitalWrite(pino_LED, estado);
    /* Pequena pausa para a nova leitura do Sensor.         */
    delay(300);
  }
}
