#include <iostream>
#include "util.h"

using namespace std;

/* Funcão que tem como propósito percorrer uma matriz de adjacência de ordem n
 * e setar todos os seus elementos com o valor zero.
 */
void createAdjMatrix(adjMatrix *matriz, int nodes){
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            matriz->v[i][j].type = '0';
            matriz->v[i][j].value = 0;
        }
    }
    matriz->nodes = nodes;
}
/*
 * Esta função adiciona um componente, ou seja, um elemento de circuito como já foi definido na modelagem do
 * problema, à matriz de adjacência.
 */
void addComponente(adjMatrix *matriz, char type, float value, int n1, int n2){
    bool polN1N2 = true;
    if(type == 'v' or type == 'V'){
        if(n1 < n2){
            polN1N2 = true;
        } else {
            polN1N2 = false;
        }
    }

    matriz->v[n1][n2].type = type;
    matriz->v[n1][n2].value = value;
    matriz->v[n2][n1].polN1N2 = polN1N2;
    //não faz sentido colacar um if para o caso de n1 == n2, pois não faz sentido ligar
    //um nó nele mesmo!
    matriz->v[n2][n1].type = type;
    matriz->v[n2][n1].value = value;
    matriz->v[n2][n1].polN1N2 = polN1N2;
}
/*
 * Esta função percorre a matriz de adjacência e exibe todos os seus elementos.
 * Para o caso do grafo modelar um circuito, ela exibe o tipo do elemento e seu valor.
 */
void printMatrix(adjMatrix *matriz, int nodes){
    cout<<"--------------------------"<<endl;
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(matriz->v[i][j].type == '0'){
                cout<<"  0  ";
                cout<<" ";
            }
            else{
                cout<<"["<<matriz->v[i][j].type<<","<<matriz->v[i][j].value<<"] ";
            }
        }
        cout<<endl;
    }
    cout<<"--------------------------"<<endl;
}

void criarLista(Lista *lista_adjacencia, int tamanho) {
    lista_adjacencia->tamanho = tamanho;

    for (int i=0; i<tamanho; i++) {
        lista_adjacencia->lista[i].type = '0';
        lista_adjacencia->lista[i].valor = 0.0;
        lista_adjacencia->lista[i].proximo_no = nullptr;
    }
}

void inserirLigacao(Lista *lista_adjacencia, char type, int valor, int n1, int n2) {
    No* novo_no = new No();
    novo_no->indice = n2;
    novo_no->type = type;
    novo_no->valor = valor;
    novo_no->proximo_no = nullptr;

    novo_no->proximo_no = lista_adjacencia->lista[n1].proximo_no;
    lista_adjacencia->lista[n1].proximo_no = novo_no;
}

void printLista(Lista *lista_adjacencia){
    cout<<"Print Lista de Adjacencia"<<endl;
    cout<<"-------------------------"<<endl;
    for(int i=0; i<lista_adjacencia->tamanho; i++){
        cout<<"["<<lista_adjacencia->lista[i].type<<","<<lista_adjacencia->lista[i].valor<<"]";
        No *aux = new No();
        aux = &lista_adjacencia->lista[i];
        while(aux->proximo_no != nullptr){
            cout<<" -> ["<<aux->proximo_no->type<<","<<aux->proximo_no->valor<<"]";
            aux = aux->proximo_no;
        }
        cout<<endl;
    }
    cout<<"-------------------------"<<endl;
}
/*
 * Esta função acha uma arvore geradora qualquer do grafo que representa um circuito
 */
void findSpanningTree(adjMatrix *matriz, adjMatrix *result, int nodes){
    int C[MAX] = {0};
    C[0] = 1;
    for (int i=0;i<nodes;i++) {
        for (int j=0;j<nodes;j++) {
            result->v[i][j].type = '0';
            result->v[i][j].value = 0.0;

        }
    }
    for (int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++){
            if(matriz->v[i][j].type != '0' && C[i] == 1 && C[j] == 0){
                addComponente(result, matriz->v[i][j].type, matriz->v[i][j].value, i, j);
                C[j] = 1;
            }
            if(matriz->v[i][j].type != '0' && C[i] == 0 && C[j] == 1){
                addComponente(result, matriz->v[i][j].type, matriz->v[i][j].value, i, j);
                C[i] = 1;
            }
        }
    }
}
/*
 * Esta função deve retornar o número de circuitos fundamentais formados.
 * Usando 4 matrizes, A, B, C e D, onde A é a matriz de adjacência original, B é a matriz de adjacência da árvore geradora
 * C é a matriz obtida da subtração A-B, e D é um array de k matrizes, onde k é a quantidade de ramos em C (quantidade de ciclos do circuito).
 */
int findFundamentalcycles(adjMatrix *A, adjMatrix *B, adjMatrix *C, adjMatrix D[], int nodes){

    findSpanningTree(A, B, nodes);
    *C = *A;
    adjMatrix *aux = new adjMatrix();
    aux->nodes = A->nodes;
    for(int i = 0;i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            if(B->v[i][j].type != '0'){
                C->v[i][j].value = 0.0;
                C->v[i][j].type = '0';
            }
            aux->v[i][j].value = B->v[i][j].value;
            aux->v[i][j].type = B->v[i][j].type;
        }
    }
    // Iterando sobre a matriz C, achando uma aresta não nula, somando essa aresta a uma
    // copia de B e atribuindo à D[k] essa nova matriz. Repete-se o processo até que se
    // esgotem as arestas não nulas em C. Sendo assim, obteremos k matrizes D, onde cada
    // uma dessas matrizes representa um ciclo fundamental do circuito. Em tese, k será
    // sempre menor que n.
    int k = 0;
    for(int i = 0; i < nodes-1; i++){
        for(int j = i+1; j < nodes; j++){
            D[k] = *aux;
            if(C->v[i][j].type != '0'){
                addComponente(&D[k], C->v[i][j].type, C->v[i][j].value, i, j);

                // Procedimento de "prunning" na matriz D[k]
                // Onde k = numero de ramos que podem formar ciclos fundamentais
                acharPontesUtil(&D[k]);
                // Transformar o grafo em direcionado
                // Isso serve para dar sentido as correntes
                direcionarGrafo(&D[k]);
                k++;

            }
        }
    }
    return k;
}

void acharPontesRec(adjMatrix *matriz, int u, bool visitado[], int ordemDesc[], int low[], int pais[], int &contador)
{
    visitado[u] = true;
    ordemDesc[u] = low[u] = ++contador;

    for(int i=0; i<matriz->nodes; i++){
        if(matriz->v[u][i].type != '0'){
            int v = i;

            if(!visitado[v]){
                pais[v] = u;
                acharPontesRec(matriz, v, visitado, ordemDesc, low, pais, contador);

                low[u] = min(low[u], low[v]);
                if(low[v]>ordemDesc[u])
                    addComponente(matriz, '0', 0.0, u, v);
            }
            else if(v != pais[u]){
                low[u] = min(low[u], ordemDesc[v]);
            }
        }
    }
}

void acharPontesUtil(adjMatrix *matriz)
{
    // Declarando variáveis para utilizar na função recursiva de achar pontes no grafo
    bool *visitado = new bool[matriz->nodes];
    int *ordemDesc = new int[matriz->nodes];
    int *low = new int[matriz->nodes];
    int *pai = new int[matriz->nodes];
    int contador = 0;

    // "Zerando" os arrays de nós pai e nós visitados
    for(int i=0; i<matriz->nodes; i++){
        pai[i] = NULL;
        visitado[i] = false;
    }

    acharPontesRec(matriz, 0, visitado, ordemDesc, low, pai, contador);
}

// Percorrendo os vertices do grafico em ordem apagando o simétrico de cada aresta,
// ou seja, criando uma "corrente" através do direcionamento
void direcionarGrafo(adjMatrix *matriz)
{
    int visitado[MAX][MAX] = {0};
    int aux;
    for(int i = 0; i < matriz->nodes; i++){
        for(int j = 0; j < matriz->nodes; j++){
            if(matriz->v[i][j].type != '0' and visitado[i][j] == 0){
                matriz->v[j][i].type = '0';
                matriz->v[j][i].value = 0.0;
                visitado[i][j] = 1;
                visitado[j][i] = 1;

                i = j;
                j = -1;
            }
        }
    }
}

// Montando a matriz de resistencias e o vetor de tensões baseando-se nas leis físicas da eletrônica.
void montarMatrizCircuito(adjMatrix D[], int k, int nodes, float matrizR[][MAX], float arrayT[])
{
    for(int i=0; i<k; i++){
        for(int j=i; j<k; j++){
            if(i==j){
                matrizR[i][j] = somarResistenciaCiclo(D, i, nodes);
            }
            else{
                matrizR[i][j] = interseccionarResistencias(D, i, j, nodes);
                matrizR[j][i] = matrizR[i][j];
            }
        }

        arrayT[i] = somarTensaoCiclo(D, i, nodes);
    }
}

float somarResistenciaCiclo(adjMatrix D[], int k, int nodes){
    float somaResistores = 0;

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(D[k].v[i][j].type == 'R'){
                somaResistores += D[k].v[i][j].value;
            }
        }
    }
    return somaResistores;
}

float interseccionarResistencias(adjMatrix D[], int k1, int k2, int nodes){
    int somaResistores = 0;
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(D[k1].v[i][j].type == 'R' and D[k2].v[i][j].type == 'R'){
                somaResistores += D[k1].v[i][j].value;
            }
        }
    }
    return somaResistores;
}

float somarTensaoCiclo(adjMatrix D[], int k, int nodes){
    float somaTensao = 0;

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            if(D[k].v[i][j].type == 'V'){
                if((i<j && D[k].v[i][j].polN1N2) or (i>j && !D[k].v[i][j].polN1N2)){
                    somaTensao -= D[k].v[i][j].value;
                } else{
                    somaTensao += D[k].v[i][j].value;
                }
            }
        }
    }
    return somaTensao;
}

/*
 * A função resolverSistema é baseada no código de Matey Glishev, disponível
 * em https://stackoverflow.com/a/37702796/10209945
 */
void resolverSistema(float a[][MAX], float b[], int n, float x[])
{
    // Criando uma matrix auxiliar de tamanho n * n+1
    // Essa matriz será usada para guardar a  matriz "a" n * n
    // Juntamente com o vetor b de tamanho n, caracterizando um
    // Sistema linear do tipo a*x = b onde x = correntes de malha do circuito
    float aux[MAX][MAX] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            aux[i][j] = a[i][j];
        }
    }
    // Atribuindo à ultima coluna da matrix auxiliar o vetor b
    for(int i=0; i<n; i++){
        aux[i][n] = b[i];
        x[i] = 0;
    }

    // Triangularização
    for (int i = 0; i < n - 1; i++){
        for (int h = i + 1; h < n+1; h++){
            double t = aux[h][i] / aux[i][i];
            for (int j = 0; j <= n; j++){
                aux[h][j] = aux[h][j] - t * aux[i][j];
            }
        }
    }

    // Resolução
    for (int i = n - 1; i >= 0; i--){
        x[i] = aux[i][n];
        for (int j = n - 1; j > i; j--){
            x[i] = x[i] - aux[i][j] * x[j];
        }
        x[i] = x[i] / aux[i][i];
    }
}
