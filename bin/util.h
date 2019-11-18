#ifndef UTIL_H
#define UTIL_H
// Header para a definição de algumas funções e structs úteis no tratamento das nossas estruturas
#define MAX 100

struct componente{
    char type;
    float value;
    bool polN1N2;
};

struct adjMatrix{
    componente v[MAX][MAX];
    int nodes;
};

struct No {
    No* proximo_no;
    int indice;
    char type;
    float valor;
};

struct Lista {
    No lista[MAX];
    int tamanho;
};

void createAdjMatrix(adjMatrix *matriz, int nodes);
void addComponente(adjMatrix *matriz, char type, float value, int n1, int n2, bool *polN1N2 = nullptr);
void printMatrix(adjMatrix *matriz, int nodes);
void criarLista(Lista *lista_adjacencia, int tamanho);
void inserirLigacao(Lista *lista_adjacencia, char type, int valor, int n1, int n2);
void printLista(Lista *lista_adjacencia);
void findSpanningTree(adjMatrix *matriz, adjMatrix *result, int nodes);
int findFundamentalcycles(adjMatrix *A, adjMatrix *B, adjMatrix *C, adjMatrix D[], int nodes);
void acharPontesRec(adjMatrix *matriz, int u, bool visitado[], int ordemDesc[], int low[], int pais[], int &contador);
void acharPontesUtil(adjMatrix *matriz);
void direcionarGrafo(adjMatrix *matriz);
void montarMatrizCircuito(adjMatrix D[], int k, int nodes, float matrizR[][MAX], float arrayV[]);
float somarResistenciaCiclo(adjMatrix D[], int k, int nodes);
float interseccionarResistencias(adjMatrix D[], int k1, int k2, int nodes);
float somarTensaoCiclo(adjMatrix D[], int k, int nodes);
void resolverSistema(float a[][MAX], float b[], int n, float x[]);
void montarMatrizCorrentes(adjMatrix *matriz, int nodes, adjMatrix D[], int k, float correntes[][MAX], float correntesMalha[]);

#endif // UTIL_H
