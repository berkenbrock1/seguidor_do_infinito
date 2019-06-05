void motor_direito (int sinal) {
  digitalWrite (MD1, HIGH);
  digitalWrite (MD2, LOW);
}

void motor_esquerdo (int sinal) {
  digitalWrite(ME1, HIGH);
  digitalWrite(ME2, LOW);
}

void frear (void) {
  motor_direito(0);
  motor_esquerdo(0);
}

void avancar (void) {
  motor_direito(255);
  motor_esquerdo(255);
  // acho que ainda preciso mexer nisso depois
}

void virar (int sinal_direito, int sinal_esquerdo) {
  motor_direito (255 - sinal_direito);
  motor_esquerdo (255 - sinal_esquerdo);
}
