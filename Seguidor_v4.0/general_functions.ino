void ler_sensores (void) {
  leitura[0] = digitalRead(s0);
  leitura[1] = digitalRead(s1);
  leitura[2] = digitalRead(s2);
  leitura[3] = digitalRead(s3);
  leitura[4] = digitalRead(s4);
}

void definir_acao (int leitura[]) {
  if(leitura[2] == 1){
    if (leitura[1] == 0 && leitura[3] == 0){
      modo = andando;
      error = 0;
      sinal = 0;
    }
    else if (leitura[1] == 1 && leitura[3] == 0){
      modo = curvaEsquerda;
      error = 1;
    }
    else if (leitura[1] == 0 && leitura[3] == 1){
      modo = curvaDireita;
      error = 1;
    }
    else if (leitura[1] == 1 && leitura[3] == 1){
      modo = andando;
      error = 0;
      sinal = 0;
    }
  }
  else if (leitura[2] == 0){
    if (leitura[1] == 0 && leitura[3] == 1){
      modo = curvaDireita;
      error = 2;
    }
    else if (leitura[3] == 0 && leitura[1] == 1){
      modo = curvaEsquerda;
      error = 2;
    }
  }
}

int pid_calculate (int ki, int kd, int kp, int error) {
  p = error;
  i = i + error;
  d = error - last_error;
  PID_value = (kp * p) + (ki * i) + (kd * d);
  last_error = error;

  return PID_value;
}

