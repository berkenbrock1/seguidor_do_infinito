#define parado 0
#define andando 1
#define curvaDireita 2
#define curvaEsquerda 3

#define ME1 7   // Motor esquerdo
#define ME2 8
#define MEsinal 9
#define MD1 5   // Motor direito
#define MD2 6
#define MDsinal 3

#define s0 A0   // Sensor Curvas
#define s1 A1   // Sensor esquerdo de linha
#define s2 A2   // Sensor central de linha
#define s3 A3   // Sensor direito de linha
#define s4 A4   // Sensor chegada

int leitura[5];
int sinal_direito;
int sinal_esquerdo;
int sinal;
int error = 0;
int modo = 0;
int andar = 0;

int p, i, d, last_error;
int PID_value;
