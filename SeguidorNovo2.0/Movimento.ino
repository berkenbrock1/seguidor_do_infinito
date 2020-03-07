/*void motor_direito (int sinal, int aux1, int aux2) {
  digitalWrite (MD1, aux1);
  digitalWrite (MD2, aux2);
  analogWrite(MDsinal, sinal);
}

void motor_esquerdo (int sinal, int aux1, int aux2) {
  digitalWrite (ME1, aux1);
  digitalWrite (ME2, aux2);
  analogWrite(MEsinal, sinal);
}*/

void setSpeedEsquerda(int speed)
{
  if(speed > 255) speed = 255;
  if(speed < -255) speed = -255;
  if(speed < 0)
  {
    digitalWrite(ME1, LOW);
    digitalWrite(ME2, HIGH);
    analogWrite(MEsinal, -speed);
  }
  else
  {
    digitalWrite(ME1, HIGH);
    digitalWrite(ME2, LOW);
    analogWrite(MEsinal, 255-speed);
  }
}

void setSpeedDireita(int speed)
{
  if(speed > 255) speed = 255;
  if(speed < -255) speed = -255;
  if(speed < 0)
  {
    digitalWrite(MD1, LOW);
    digitalWrite(MD2, HIGH);
    analogWrite(MDsinal, -speed);
  }
  else
  {
    digitalWrite(MD1, HIGH);
    digitalWrite(MD2, LOW);
    analogWrite(MDsinal, 255-speed);
  }
}

void setSpeed(int linear, int diferencial)
{
  diferencial = map(diferencial, 0, 65535, 0, 255);
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
