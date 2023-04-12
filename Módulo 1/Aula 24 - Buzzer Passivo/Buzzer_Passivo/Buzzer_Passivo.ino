/*******************************************************/
/* Aula 24 - Buzzer Passivo                            */
/* Programação: Produzindo sons através de um buzzer   */
/* passivo. Os sons emitidos formam a canção DóRéMi,   */
/* as notas são executadas pela frequência em Hertz    */
/* e o andamento controlado pela função delay.         */
/*******************************************************/

/* Define a porta digital 8 para acionar o buzzer.     */
int Pino_buzzer = 8;
void setup()
{
  /* Configura o pino digital 8 como saída.            */
  pinMode(8, OUTPUT);
}

void loop()
{
  /* Utiliza-se a função tone() para emitir sons através */
  /* do buzzer passivo. A sintaxe é:                     */
  /* tone(pino, frequencia, duração_milissegundos)       */

  /* Emite através do pino Pino_buzzer a nota DÓ (264 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 264, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota RÉ (297 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 297, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota MI (330 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 330, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota FÁ (352 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 352, 100);
  /* Pausa entre notas de 500 milissegundos.             */
  delay(500);
  /* Emite através do pino Pino_buzzer a nota FÁ (352 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 352, 100);
  /* Pausa entre notas de 200 milissegundos.             */
  delay(200);
  /* Emite através do pino Pino_buzzer a nota FÁ (352 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 352, 100);
  /* Pausa entre notas de 500 milissegundos.             */
  delay(500);
  /* Emite através do pino Pino_buzzer a nota DÓ (264 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 264, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota RÉ (297 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 297, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota DÓ (264 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 264, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota RÉ (297 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 297, 100);
  /* Pausa entre notas de 500 milissegundos.             */
  delay(500);
  /* Emite através do pino Pino_buzzer a nota RÉ (297 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 297, 100);
  /* Pausa entre notas de 200 milissegundos.             */
  delay(200);
  /* Emite através do pino Pino_buzzer a nota RÉ (297 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 297, 100);
  /* Pausa entre notas de 500 milissegundos.             */
  delay(500);
  /* Emite através do pino Pino_buzzer a nota DÓ (264 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 264, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota SOL (396 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 396, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota FÁ (352 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 352, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota MI (330 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 330, 100);
  /* Pausa entre notas de 500 milissegundos.             */
  delay(500);
  /* Emite através do pino Pino_buzzer a nota MI (330 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 330, 100);
  /* Pausa entre notas de 200 milissegundos.             */
  delay(200);
  /* Emite através do pino Pino_buzzer a nota MI (330 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 330, 100);
  /* Pausa entre notas de 500 milissegundos.             */
  delay(500);
  /* Emite através do pino Pino_buzzer a nota DÓ (264 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 264, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota RÉ (297 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 297, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota MI (330 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 330, 100);
  /* Pausa entre notas de 250 milissegundos.             */
  delay(250);
  /* Emite através do pino Pino_buzzer a nota FÁ (352 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 352, 100);
  /* Pausa entre notas de 500 milissegundos.             */
  delay(500);
  /* Emite através do pino Pino_buzzer a nota FÁ (352 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 352, 100);
  /* Pausa entre notas de 200 milissegundos.             */
  delay(200);
  /* Emite através do pino Pino_buzzer a nota FÁ (352 Hz)*/
  /* por 100 milissegundos.                              */
  tone(Pino_buzzer, 352, 100);
  /* Pausa entre notas de 500 milissegundos.             */
  delay(500);

}
