void ler_sensores (void) {
  leitura[0] = digitalRead(s0);
  leitura[1] = digitalRead(s1);
  leitura[2] = digitalRead(s2);
  leitura[3] = digitalRead(s3);
  leitura[4] = digitalRead(s4);
}

void definir_acao (int leitura[]){
  if (leitura[4] == 1 && andar == 0){
    andar = 1;
    modo = andando;
  }
  else if (leitura [4] == 1 && andar == 1){
    andar = 0;
    modo = parado;
  }
  
  if (leitura[0] == 1){
    if (leitura[1] == leitura [3] == leitura[4] == 0 && leitura[2] == 1){
      modo = curva;
      error = 0;
    }
    else if (leitura[1] == leitura[2] == leitura[3] == leitura[4] == 1){
      modo = andando;
      error = 0;
    }
  }
  else if (leitura[0] == 0){
    if (leitura[1] == 0 && leitura[2] == 1 && leitura[3] == 0 && leitura[4] == 1) {
      modo = andando;
      error = 0;
    }
    else if (leitura[1] == 1){
      modo = curva;
      error = -leitura[1];
    }
    else if (leitura[3] == 1){
      modo = curva;
      error = leitura[3];
    }
    else if (leitura[2] == 1 && leitura[1] == leitura[3] == leitura[4] == 0){
      modo = andando;
      error = 0;
    }
  }
}


int pid_calculate (int ki, int kd, int kp, int error, int kr){
  error = error / kr;
  p = error;
  i = i + error;
  d = error - last_error;
  PID_value = (kp * p) + (ki * i) + (kd * d);
  last_error = error;

  return PID_value;
}

