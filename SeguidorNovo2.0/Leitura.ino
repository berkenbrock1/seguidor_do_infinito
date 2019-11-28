  void confere_chegada (){
    chegada = digitalRead(sensor);
    if (chegada == 0) {
      if (noSensor == false) {
        noSensor = true;
        iterador++;
      }
    }
    else if (chegada == 1) {
      if (noSensor == true) {
        noSensor = false;
      }
    }
    tempo = millis();
  
    if (iterador == 12) {
      iterador++;
      tempo1 = millis();
    }
  
    if (iterador >= 13 &&  tempo - tempo1 >= 300) {
      delay(250);
      setSpeedDireita(0);
      setSpeedEsquerda(0);
      delay(100000);
    }
  }

