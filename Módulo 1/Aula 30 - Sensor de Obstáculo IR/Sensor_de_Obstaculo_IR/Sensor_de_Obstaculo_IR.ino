/****************************************************************/
/* Aula 30 - Sensor de Obstáculo IR                             */
/* Programação: Detecta um obstáculo próximo ao sensor e indica */
/* através do acionamento de um LED. També é pssível acompanhar */
/* através do monitor serial a leitura do sensor representado   */
/* pelos números 0 e 1(0 indica que o sensor detectou um        */
/* obstáculo e 1 indica que não detetectou obstáculo).          */
/****************************************************************/

/* Pino digital 2 utilizado para receber dados do sensor IR.    */
int pinoSensor = 2;
/* Pino digital 4 utilizado para acionar o LED.                 */
int Pin_LED = 4;
/* Variável que armazenará os dados do sensor IR.               */
int Sensor_IR = 0;
/* Função de configuração da placa Arduino.                     */
void setup() {
  /* Configura o pino digital ligado ao sensor como ENTRADA.    */
  pinMode(pinoSensor, INPUT);
  /* Configura o pino digital ligado ao LED como SAÍDA.         */
  pinMode(Pin_LED, OUTPUT);
  /* Inicializa a comunicação serial com velocidade de 9600     */
  Serial.begin(9600);
}
/* Função que entrará em looping infinito. dentro dela ficará   */
/* toda a lógica do nosso programa.                             */
void loop() {
  /* Realiza a leitura do sensor e armazena o valor na variável */
  Sensor_IR = digitalRead(pinoSensor);
  /* Imprime no monitor serial valor registrado na variável.    */
  Serial.println(Sensor_IR);
  /* Se a variável conter o valor 0, faça...                    */
  if (Sensor_IR == 0) {
    /* Ative o pino conectado ao LED (Ligará o LED).            */
    digitalWrite(Pin_LED, HIGH);
  }
  /* Se a variável conter o valor 1, faça...                    */
  if (Sensor_IR == 1) {
    /* Desative o pino conectado ao LED (Desligará o LED).     */   
    digitalWrite(Pin_LED, LOW);
  }
}
