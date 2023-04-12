/************************************************************/
/* Aula 31 - Relé                                           */
/* Programação do módulo Relé.                              */
/* Ao transferir o código abaixo para seu Arduino, você     */
/* controlará uma carga (aparelho conectado à extensão),    */
/* através do som (palmas) e do Módulo Relé.                */
/************************************************************/
/* Define os pinos que serão utilizados para os Módulos     */
/* Sensor de Som e Relé.                                    */
int pino_som = 3;
int pino_rele = 2;
/* Variável booleana para armazenar o estado do Relé.       */
/* 0: Desligado e 1: Ligado */
boolean estado = 0; 

void setup() {
  /* Define o pino do Módulo Sensor de Som como entrada e o */
  /* pino do Módulo Relé como saída.                        */
  pinMode(pino_som, INPUT);
  pinMode(pino_rele, OUTPUT);
}
void loop() {
  /* Armazena na variável o estado do sensor de Som: 0 não  */
  /* detectou som e 1 se detectar som.                      */
  int som = digitalRead(pino_som);
  /* Se for detectado um som, faça...                       */
  if (som == 1) {
    /* Altera o estado da variável booleana: Se estiver     */
    /* LOW, passa pra HIGH, se estiver HIGH passa para LOW  */
    estado = !estado;                
    /* Ativa o Relé de acordo com a variável estado.        */
    digitalWrite(pino_rele, estado);  
    /* Pequena pausa para reiniciar a leitura do sensor.    */
    delay(300);                                 
  }
}
