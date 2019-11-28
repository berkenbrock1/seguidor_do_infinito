  void motor_direito (int sinal, int sinal_aux) {
  digitalWrite (MD, sinal_aux);
  analogWrite(MDsinal, sinal);
}

void motor_esquerdo (int sinal, int sinal_aux) {
  digitalWrite (ME, sinal_aux);
  analogWrite(MEsinal, sinal);
}

void setSpeedEsquerda(int speed)
{
  if(speed > 255) speed = 255;
  if(speed < -255) speed = -255;
  if(speed < 0)
  {
    digitalWrite(ME, LOW);
    analogWrite(MEsinal, -speed);
  }
  else
  {
    digitalWrite(ME, HIGH);
    analogWrite(MEsinal, 255-speed);
  }
}

void setSpeedDireita(int speed)
{
  if(speed > 255) speed = 255;
  if(speed < -255) speed = -255;
  if(speed < 0)
  {
    digitalWrite(MD, LOW);
    analogWrite(MDsinal, -speed);
  }
  else
  {
    digitalWrite(MD, HIGH);
    analogWrite(MDsinal, 255-speed);
  }
}

void setSpeed(int linear, int diferencial)
{
  
  if(linear + abs(diferencial)/2 > 255)
    linear = 255 - abs(diferencial)/2; 
  setSpeedDireita(linear - diferencial/2);
  setSpeedEsquerda(linear + diferencial/2);
}


float pid (float kp, float ki, float kd, int error) {
  p = error;
  i = i + error;
  d = error - last_error;
  PID_value = (kp * p) + (ki * i) + (kd * d);
  last_error = error;
  return PID_value;
}
