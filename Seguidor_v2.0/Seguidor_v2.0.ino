#include "Seguidor_defines.h"

// NOTAS MENTAIS
// Preciso mexer nas funções de curva, provavelmente incompletas;
// Testar as funções para garantir que a potência do motor e o tempo de curva estejam adequados à pista
// Talvez fazer uma nova função para curva baseada em sensores, não em padrões
// Arrumar partida do robô

// Simplificar funções

void setup (void) {

  /*pinMode (s0, INPUT);
  pinMode (s1, INPUT);
  pinMode (s2, INPUT);
  pinMode (s3, INPUT);
  pinMode (s4, INPUT);

  pinMode (ME1, OUTPUT);
  pinMode (ME2, OUTPUT);
  pinMode (MEsinal, OUTPUT);
  pinMode (MD1, OUTPUT);
  pinMode (MD2, OUTPUT);
  pinMode (MDsinal, OUTPUT);*/

}

void loop() {
  ler_sensores();
  sinal = pid_calculate (0, 0.01, 50, error, 1);
  definir_acao();
  switch (modo) {
    case parado:
      frear();
      break;

    case andando:
      avancar();
      break;

    case curva:
      verificaCurva();
  }
}
