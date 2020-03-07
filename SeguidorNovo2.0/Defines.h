#define ME1 PA1
#define ME2 PA2
#define MEsinal PA0
#define MD1 PA4
#define MD2 PA3
#define MDsinal PA6

const int sensor = PA7;

int ultimoTempo = 0;
int tempo;
int tempo1;
int modo = 0;
int iterador = 0;
int chegada;
unsigned int sinal;
unsigned int PID_value;
int p, i, d, last_error;
unsigned int erro;
bool noSensor = false;



