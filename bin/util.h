#ifndef UTIL_H
#define UTIL_H
// Header para a definição de algumas funções e structs úteis no tratamento das nossas estruturas
#define MAX 4

struct componente{
    char type;
    float value;
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
void addComponente(adjMatrix *matriz, char type, float value, int n1, int n2);
void printMatrix(adjMatrix *matriz, int nodes);
void criar_lista(Lista *lista_adjacencia, int tamanho);
void inserir_ligacao(Lista *lista_adjacencia, char type, int valor, int n1, int n2);
void print_lista(Lista *lista_adjacencia);
void findSpanningTree(adjMatrix *matriz, adjMatrix *result, int nodes);
int findFundamentalcycles(adjMatrix *A, adjMatrix *B, adjMatrix *C, adjMatrix D[], int nodes);

#endif // UTIL_H
