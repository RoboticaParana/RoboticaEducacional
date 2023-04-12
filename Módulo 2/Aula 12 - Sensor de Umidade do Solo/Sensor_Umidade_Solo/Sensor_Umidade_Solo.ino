/************************************************************/
/* Aula 12 - Sensor de umidade do solo                                */
/* Programação do projeto sensor de umidade do solo.        */
/* Ao transferir o código abaixo para seu Arduino, o sensor */
/* de umidade do solo irá monitorar a intensidade de umidade*/
/* da superfície em que sua sonda está espetada (o solo).   */
/* De acordo com os dados obtidos pelo sensor, será possível*/
/* identificar através de LEDs, baixa umidade (LED Vermelho)*/
/* ou umidade adequada (LED Verde) e também através do      */
/* monitor serial, por meio de mensagem informando a        */
/* condição de umidade em tempo real.                       */
/************************************************************/
/* Definições de pinos para o sensor de umidade e LEDs.     */
#define pino_Sensor A0
#define pino_LED_Verde 3
#define pino_LED_Vermelho 4

/* Porcentagem de umidade em que o sistema delimitará a     */
/* condição da umidade (baixa ou adequada).                 */
int Valor_Critico = 45;
/* Variável para armazenar o valor analógico do sensor.     */
int ValAnalogIn;
void setup() {
  /* Inicia a comunicação Serial com velocidade de 9600     */
  /* bauds.                                                 */
  Serial.begin(9600);
  /* Configura os pinos dos LEDs como saída.                */
  pinMode(pino_LED_Verde, OUTPUT);
  pinMode(pino_LED_Vermelho, OUTPUT);
}
void loop() {
  /* Realiza a leitura do sensor e armazena o valor na      */
  /* variável ValAnalogIn.                                  */
  ValAnalogIn = analogRead(pino_Sensor);
  /* Converte o valor analógico para porcentagem.           */
  int Porcento = map(ValAnalogIn, 1023, 0, 0, 100);
  /* Imprime o valor em porcentagem no Monitor Serial.      */
  Serial.print(Porcento);
  /* Imprime o símbolo junto ao valor da porcentagem.       */
  Serial.println("%");
  /* Se a porcentagem for menor ou igual ao valor definido. */
  if (Porcento <= Valor_Critico) {
    /* Imprime a frase no Monitor Merial.                   */
    Serial.println("Umidade baixa!");
    /* Acende o LED Vermelho.                               */
    digitalWrite(pino_LED_Vermelho, HIGH);
    /* Apaga o LED Verde.                                   */
    digitalWrite(pino_LED_Verde, LOW);
  }
  else {
    /* Imprime a frase no Monitor Serial.                   */
    Serial.println("Umidade Adequada...");
    /* Acende o LED Verde.                                  */
    digitalWrite(pino_LED_Verde, HIGH);
    /* Apaga o LED Vermelho.                                */
    digitalWrite(pino_LED_Vermelho, LOW);
  }
  /* Aguarda 1 segundo para reiniciar a nova leitura.       */
  delay (1000);
}
