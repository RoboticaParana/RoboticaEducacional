/************************************************************/
/* Aula 27 - Sensor LDR                                     */
/* Programação: Aciona um LED a partir da leitura do Sensor */
/* de luminosidade LDR.                                     */
/************************************************************/

/* Variável que armazenará os dados do sensor LDR.          */
int Sensor_LDR = 0;
/* Define A0 como porta de entrada do sensor LDR.           */
int Pin_LDR = A0;
/* Define a porta digital 5 para controle do LED.           */
int Pin_LED = 5;

void setup() {
  /* Define a porta de controle do LED como SAÍDA.          */
  pinMode(Pin_LED, OUTPUT);
  /* Inicia a comunicação serial na velocidade de 9600.     */
  Serial.begin(9600);
}

void loop() {
  /* A variável Sensor_LDR recebe os dados do sensor LDR.   */
  Sensor_LDR = analogRead(Pin_LDR);
  /* Imprime o valor lido do sensor LDR (0 a 1023).         */
  Serial.print("Valor lido: ");
  Serial.println(Sensor_LDR);
  /* Pequena pausa para realizar a próxima leitura.         */
  delay(100);
  /* Se o valor lido for menor que 800, faça...             */
  if (Sensor_LDR < 800) {
    /* Ligue o LED.                                         */
    digitalWrite(Pin_LED, HIGH);
    /* Senão...                                             */
  } else { 
    /* Desligue o LED.                                      */
    digitalWrite(Pin_LED, LOW);
  }
}
