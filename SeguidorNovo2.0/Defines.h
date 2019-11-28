#define ME 8
#define MEsinal 9
#define MD 10
#define MDsinal 11

int sensor = 3;

int ultimoTempo = 0;
int tempo;
int tempo1;
int modo = 0;
int iterador = 0;
int chegada;
float sinal;
float PID_value;
int p, i, d, last_error;
float erro;
bool noSensor = false;


