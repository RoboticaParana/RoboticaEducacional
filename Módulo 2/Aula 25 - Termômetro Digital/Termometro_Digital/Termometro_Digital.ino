/************************************************************/
/* Aula 25 - Termômetro Digital                             */
/* Programação do Termômetro Digital.                       */
/* Ao transferir o código abaixo para seu Arduino, o sensor */
/* de Umidade e Temperatura DHT11 irá monitorar as condições*/
/* do ambiente e enviará dados analógicos ao Arduino, e com */
/* o auxílio da bibliteca DHT, obterá as informações de     */
/* umidade e temperatura que serão exibidas no Display LCD. */
/* Links para obtenção da biblioteca by Adafruit            */
/* http://librarymanager/All#DHT11#DHT22                    */
/* https://github.com/adafruit/DHT-sensor-library           */
/* https://github.com/adafruit/Adafruit_Sensor              */
/************************************************************/

#include <DHT.h>
/* Inclui a biblioteca de controle do Display LCD.          */
#include <LiquidCrystal.h>
/* Cria o objeto dht para controle do Sensor DHT11 através  */
/* da porta analógica A0.                                   */
DHT dht(A0, DHT11);
/* Cria o objeto lcd para controle do Display e define os   */
/* pinos digitais utilizados.                               */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/* Matriz binária para o símbolo grau (°).                  */
byte grau[8] = { B00001100,
                 B00010010,
                 B00010010,
                 B00001100,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
               };
void setup()
{
  /* Inicializa o Display LCD com 16 colunas e 2 linhas.   */
  lcd.begin(16, 2);
  /* Limpa o LCD.                                          */
  lcd.clear();
  /* Cria o caractere customizado com o símbolo do grau.   */
  lcd.createChar(0, grau);
  /* Inicia o objeto de controle do Sensor DHT11.          */
  dht.begin();
  /* Posiciona o cursor na coluna 3 e linha 0.             */
  lcd.setCursor(3, 0);
  /* Escreve a palavra no Display.                         */
  lcd.print("Termometro");
  /* Posiciona o cursor na coluna 5 e linha 1.             */
  lcd.setCursor(5, 1);
  /* Escreve a palavra no Display.                         */
  lcd.print("Digital");
  /* Aguarda 2 segundos exibindo as palavras acima.        */
  delay(2000);
  /* Limpa o LCD.                                          */
  lcd.clear();
}
void loop()
{
  /* Realiza a leitura do Sensor e armazena os dados nas   */
  /* variáveis h e t.                                      */
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  /* Posiciona o cursor na coluna 2 e linha 0.             */
  lcd.setCursor(2, 0);
  /* Escreve a palavra no Display.                         */
  lcd.print("Temperatura");
  /* Posiciona o cursor na coluna 4 e linha 1.             */
  lcd.setCursor(4, 1);
  /* Escreve o valor da temperatura no Display.            */
  lcd.print(t, 1);
  /* Posiciona o cursor na coluna 9 e linha 1.             */
  lcd.setCursor(9, 1);
  /* Mostra o símbolo do grau. */
  lcd.write((byte)0);
  /* Posiciona o cursor na coluna 10 e linha 1.            */
  lcd.setCursor(10, 1);
  /* Escreve a letra no Display.                           */
  lcd.print("C");
  /* Intervalo entre medidas.                              */
  delay(2500);
  /* Limpa o LCD.                                          */
  lcd.clear();
  /* Posiciona o cursor na coluna 1 e linha 0.             */
  lcd.setCursor(1, 0);
  /* Escreve as palavras no Display.                       */
  lcd.print("Umidade do Ar");
  /* Posiciona o cursor na coluna 6 e linha 1.             */
  lcd.setCursor(6, 1);
  /* Escreve o valor da umidade no Display.                */
  lcd.print(h, 0);
  /* Posiciona o cursor na coluna 9 e linha 1.             */
  lcd.setCursor(9, 1);
  /* Escreve o símbolo no Display.                         */
  lcd.print("%");
  /* Intervalo entre medidas */
  delay(2500);
  /* Limpa o LCD.                                          */
  lcd.clear();
}
