// C++ code
//
// Definindo a configuração dos segmentos para cada dígito
byte seven_seg_digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // = 0
  { 0, 1, 1, 0, 0, 0, 0 }, // = 1
  { 1, 1, 0, 1, 1, 0, 1 }, // = 2
  { 1, 1, 1, 1, 0, 0, 1 }, // = 3
  { 0, 1, 1, 0, 0, 1, 1 }, // = 4
  { 1, 0, 1, 1, 0, 1, 1 }, // = 5
  { 1, 0, 1, 1, 1, 1, 1 }, // = 6
  { 1, 1, 1, 0, 0, 0, 0 }, // = 7
  { 1, 1, 1, 1, 1, 1, 1 }, // = 8
  { 1, 1, 1, 1, 0, 1, 1 }  // = 9
};

// Setup: Instruções para serem executadas apenas 1 vez na inicialização do Arduino.
void setup() {
  	// Definindo os pinos como saída para os LEDS
	pinMode(0, OUTPUT); // vermelho
  	pinMode(1, OUTPUT); // amarelo
  	pinMode(2, OUTPUT); // verde
  	pinMode(3, OUTPUT); // verde
  	pinMode(4, OUTPUT); // amarelo
  	pinMode(5, OUTPUT); // vermelho
    // Definindo os pinos como saída para o Display 1
    pinMode(6, OUTPUT); // A
    pinMode(7, OUTPUT); // B
    pinMode(8, OUTPUT); // C
    pinMode(9, OUTPUT); // D
    pinMode(10, OUTPUT); // E
    pinMode(11, OUTPUT); // F
    pinMode(12, OUTPUT); // G
    // Definindo os pinos como saída para o Display 2
    pinMode(13, OUTPUT); // A
    pinMode(14, OUTPUT); // B
    pinMode(15, OUTPUT); // C
    pinMode(16, OUTPUT); // D
    pinMode(17, OUTPUT); // E
    pinMode(18, OUTPUT); // F
    pinMode(19, OUTPUT); // G
}
// Fim do Setup

// Loop: Instruções para serem executadas em loop pelo Arduino.
void loop() {
  digitalWrite(5, HIGH); // Vermelho
  digitalWrite(4, LOW); // Amarelo
  
  digitalWrite(2, HIGH); // Verde
  displayTimer(5, 0); // 5 a 0
  digitalWrite(1, HIGH); // Amarelo
  digitalWrite(2, LOW); // Verde
  displayTimer(2, 0); // 2 a 0
  digitalWrite(5, LOW); // Vermelho
  digitalWrite(0, HIGH); // Vermelho
  digitalWrite(1, LOW); // Amarelo
  
  digitalWrite(3, HIGH); // Verde
  displayTimer(7, 2); // 7 a 2
  digitalWrite(4, HIGH); // Amarelo
  digitalWrite(3, LOW); // Verde
  displayTimer(1, 0); // 1 a 0
  digitalWrite(0, LOW); // Vermelho
}
// Fim do loop

// Função displayNumber serve para acender os dois displays com os números recebidos digit1 e digit2.
void displayNumber(byte digit1, byte digit2) {
  // Pinos para o Display 1 (dezena)
  byte pinsDisplay1[] = {6, 7, 8, 9, 10, 11, 12};
  // Pinos para o Display 2 (unidade)
  byte pinsDisplay2[] = {13, 14, 15, 16, 17, 18, 19};
  // Atualiza o Display 1 com o dígito das dezenas
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pinsDisplay1[segCount], seven_seg_digits[digit1][segCount]);
  }
  // Atualiza o Display 2 com o dígito das unidades
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pinsDisplay2[segCount], seven_seg_digits[digit2][segCount]);
  }
}

// Função displayTimer serve para acender os dois displays com os números recebidos	e ir aumentando ou diminuindo de um em um com intervalo de um segundo até exibir todos os números.
void displayTimer(byte first, byte finish) { // Colocar o valor inicial e o valor final
  // Se o primeiro número é igual ao ultimo só exibe
  if (first == finish) {
    int digit1 = first / 10; // Dígito das dezenas
    int digit2 = first % 10; // Dígito das unidades
    displayNumber(digit1, digit2); // Exibe o valor digitado no display
  // Se o primeiro número é menor que o ultimo, contagem regressiva
  } else if (first < finish) { 
    for (int i = first; i <= finish; i++) {
      int digit1 = i / 10; // Dígito das dezenas
      int digit2 = i % 10; // Dígito das unidades
      displayNumber(digit1, digit2); // Atualiza os displays
      delay(1000); // Aguarda 1 segundo
    }
  // Se o primeiro número é maior que o ultimo, contagem progressiva
  } else {
    for (int i = first; i >= finish; i--) {
      int digit1 = i / 10; // Dígito das dezenas
      int digit2 = i % 10; // Dígito das unidades
      displayNumber(digit1, digit2); // Atualiza os displays
      delay(1000); // Aguarda 1 segundo
    }
  }
}
