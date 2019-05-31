#define parado 0
#define andando 1
#define curva 2

const int ME1 = 18;   // Motor esquerdo
const int ME2 = 19;
const int MEsinal = 5;
const int MD1 = 16;   // Motor direito
const int MD2 = 17;
const int MDsinal = 4;

const int s0 = 14;   // Sensor Curvas
const int s1 = 27;   // Sensor esquerdo de linha
const int s2 = 26;   // Sensor central de linha
const int s3 = 25;   // Sensor direito de linha
const int s4 = 33;   // Sensor chegada

int leitura[5];
int sinal_direito;
int sinal_esquerdo;
int sinal;
int error;
int modo = 0;
int andar = 0;

int p, i, d, last_error;
int PID_value;
