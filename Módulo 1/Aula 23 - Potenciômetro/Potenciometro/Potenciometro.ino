/*******************************************************/
/* Aula 23 - Potenciômetro                             */
/* Programação de leitura do sensor potenciômetro      */
/* através do Monitor Serial.                          */
/*******************************************************/

/* Variável que armazenará os dados do potenciômetro.  */
int potenciometro = 0;
void setup() {
  /* Inicia a comunicação serial com velocidade de 9600 */
  Serial.begin(9600);
}
void loop() {
  /* A variável recebe os dados lidos no pino A0.       */
  potenciometro = analogRead(A0);
  /* Imprime no Monitor Serial o valor lido do potenciômetro. */
  Serial.println(potenciometro);
  /* Aguarda 100 milissegundos para realizar uma nova leitura.*/
  delay(100);
}
