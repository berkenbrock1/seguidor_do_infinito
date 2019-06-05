void ler_sensores (void) {
  leitura[0] = digitalRead(s0);
  leitura[1] = digitalRead(s1);
  leitura[2] = digitalRead(s2);
  leitura[3] = digitalRead(s3);
  leitura[4] = digitalRead(s4);
}

void definir_acao (void){
  if (leitura[4] == 1 && andar == 0){
    andar = 1;
    modo = andando;
  }
  else if (leitura [4] == 1 && andar == 1){
    andar = 0;
    modo = parado;
  }
  //Verifica sensor de curva
  if(leitura[0] == 1){
    //Verifica se o sensor já esteve na marca.
    if(naMarca == false){
      //Ativa flag para avisar que o sensor está sobre um marca.
      naMarca = true;
      //Verifica se é inicio(ou meio) de curva.
      if(vetorQnt[contador] == true){
        //Ativa modo de curva.
        modo = curva;
      }
      //Caso não seja inicio/meio de curva, ativa modo para andar em linha reta.
      else if(vetorQnt[contador] == false){
        //Ativa modo de linha reta.
        modo = andando;
      }
      //Apenas para verificar se o carro não passou do número de marcações.
      if(contador <= N-1)
        contador++;
      else
        contador=0;
    }
  }
  //Define que o Thanos já passou pela marca.
  else if(naMarca == true){
    naMarca = false;
  }
}

/**
 * Funcao para verificar qual lado o carro terá que fazer a curva.
 * Depois de definido, ele chama a função para fazer a curva do jeito adequado. 
 */
void verificaCurva(){
  //Caso esteja em algum ponto da curva que possa 'ir reto' sem precisar virar
  if(leitura[1] == 1 && leitura[2] == 1 && leitura[3] == 1){
     avancar();
  }
  //Curva para esquerda (eu acho kkkk)
  else if(leitura[1] == 1 && leitura[2] == 1 && leitura[3] == 0){
    //Freia bastante a roda direita e pouco a esquerda;
    virar(125, 25);
  }
  //Curva para direita (eu acho tbm kkkkkkkkkkkkk)
  else if(leitura[1] == 0 && leitura[2] == 1 && leitura[3] == 1){
    //Freia bastante a roda esquerda e um pouco a direita.
    virar(25, 125);
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
