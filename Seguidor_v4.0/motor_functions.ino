void motor_direito (int sinal) {
  digitalWrite (MD1, LOW);
  digitalWrite (MD2, HIGH);
  analogWrite(MDsinal, sinal);
}

void motor_esquerdo (int sinal) {
  digitalWrite (ME1, HIGH);
  digitalWrite (ME2, LOW);
  analogWrite(MEsinal, sinal);
}

void frear (void) {
  motor_direito(0);
  motor_esquerdo(0);
}

void avancar (void) {
  motor_direito(100);
  motor_esquerdo(100);
}

void virar (int sinal_direito, int sinal_esquerdo, int sentido) {
  frear();
  //Curva para esquerda
  if (sentido == -1){
    motor_direito (100 + sinal_esquerdo);
    motor_esquerdo (0);
    /*if (leitura[3] == 0){
      delay(50);
      modo = andando;
    }*/
  }
  //Curva para direita
  else if (sentido == 1) {
    motor_direito (0);
    motor_esquerdo (200 + sinal_direito);
    /*if(leitura[1] == 0){
      delay(50);
      modo = andando;
    }*/
  }
}

