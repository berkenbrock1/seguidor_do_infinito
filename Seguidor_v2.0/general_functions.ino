void ler_sensores (void) {
  leitura[0] = digitalRead(s0);
  leitura[1] = digitalRead(s1);
  leitura[2] = digitalRead(s2);
  leitura[3] = digitalRead(s3);
  leitura[4] = digitalRead(s4);
}


void definir_acao ( void ){
  //Sensor de início/fim ativo.
  if(leitura[4] == 1){
    //Inicio de corrid(sensor de inicio/fim ativo e carro parado).
      if (andar == 0){
        andar = 1; 
        modo = andando;
      }
      //Fim de corrida (sensor de inicio/fim ativo e carro em movimento).
      else if (leitura [4] == 1 && andar == 1){
        andar = 0;
        modo = parado;
      }
  }

  //Sensor de inicio/fim de curva ativo  
  if (leitura[0] == 1){
    //Modifiquei o comparativo, acredito que nunca entraria nesse if, pois exigia que os sensores s1 e s3 fossem 0 ao msm tempo
    if ((leitura[1] == 0|| leitura [3] == 0) && leitura[2] == 1){
      modo = curva;
      error = 0;
    }
    //Retirei o leitura[4] do if, acho que não é necessário.
    else if (leitura[1] == leitura[2] == leitura[3] == 1){
      modo = andando;
      error = 0;
    }
  }
  //Sensor de inicio/fim de curva
  else if (leitura[0] == 0){
    //Acho que não entra nesse if, pois seria impossível sensor s1 e s3 serem 0 ao mesmo tempo.
    if (leitura[1] == 0 && leitura[2] == 1 && leitura[3] == 0 && leitura[4] == 1) {
      modo = andando;
      error = 0;
    }
    //Acredito que o parâmetro estava invertido.
    else if (leitura[1] == 0){
      modo = curva;
      error = -leitura[1];
    }
    //Mesma coisa do caso anterior, acredito que o parâmetro estava invertido.
    else if (leitura[3] == 0){
      modo = curva;
      error = leitura[3];
    }
    //Alterei o if para uma forma que entre no if
    else if (leitura[2] == 1 && leitura[1] == 1 && leitura[3] == 1){
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
