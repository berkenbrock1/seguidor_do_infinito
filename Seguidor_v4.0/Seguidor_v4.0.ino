#include "Seguidor_defines.h"

// Mudar para analógica a leitura dos sensores
// Mexer no delay
// 

void setup (void) {

  pinMode (s0, INPUT);
  pinMode (s1, INPUT);
  pinMode (s2, INPUT);
  pinMode (s3, INPUT);
  pinMode (s4, INPUT);

  pinMode (ME1, OUTPUT);
  pinMode (ME2, OUTPUT);
  pinMode (MEsinal, OUTPUT);
  pinMode (MD1, OUTPUT);
  pinMode (MD2, OUTPUT);
  pinMode (MDsinal, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  ler_sensores();
  definir_acao(leitura);
  sinal = 0;
  sinal = pid_calculate (1, 1, 10, error);
  Serial.println(error);
  Serial.println(sinal);
  Serial.println(leitura[1]);
  Serial.println(leitura[2]);
  Serial.println(leitura[3]);
  Serial.println("-----");
  delay(350);
  
  switch (modo) {
    case parado:
      frear();
      break;

    case andando:
      avancar();
      break;

    case curvaDireita:
      virar (sinal, sinal, -1);
      break;
      
    case curvaEsquerda:
      virar(sinal, sinal, 1);
      break;
  }
}
