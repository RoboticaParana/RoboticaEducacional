#include <Keypad.h>
#include<Servo.h>

// Definindo as Portas
byte PinosLinhas[] = {9, 8, 7, 6};
byte PinosColunas[] = {5, 4, 3, 2};

#define ledVermelho A4
#define ledVerde A5
#define Pin_Servo 10

// Teclado
#define caracteres 3
char password[] = "ABC";
int posicao;
char matrizTeclas[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
char tecla;

// Criando os objetos de controle
// keypad nomeObjeto(makekeymap(Matriz das Teclas), Matriz de Pinos das Colunas, Matriz de Pinos das Linhas, QtdLinhas, QtdColunas);
Keypad teclado( makeKeymap(matrizTeclas), PinosLinhas, PinosColunas, 4, 4);
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  servo.attach(Pin_Servo);
  Serial.println("Entre com a Senha...");
  trancada();
}

void loop() {
  // Captura a tecla quando pressionada
  tecla = teclado.getKey();

  // Se houver alteração na variável (tecla foi pressionada)
  if (tecla) {

    // Verifica o que foi pressionado
    switch (tecla) {
        case '*':
        posicao = 0; // reseta a checagem
        trancada();  // mantém a fechadura trancada
        break;

      case '#':
        posicao = 0; // reseta a checagem
        trancada();  // mantém a fechadura trancada
        break;

      default:
        Serial.print(tecla);
        if (tecla == password[posicao]) {
          posicao++; // incremente a posicao para checar o próximo caracter da senha
        }

        // Se foi checado o último caracter da senha (Acertou todos os dígitos)
        if (posicao == caracteres) {
          destrancada();
        }
        break;
    }
  }
}

void trancada() {
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledVerde, LOW);
  servo.write(90);
  Serial.println("");
  Serial.println("TRANCADO");
}

void destrancada() {
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, LOW);
  servo.write(180);
  Serial.println(" ABERTO");
}
