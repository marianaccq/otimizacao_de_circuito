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
}
/*
 * Esta função adiciona um componente, ou seja, um elemento de circuito como já foi definido na modelagem do
 * problema, à matriz de adjacência.
 */
void addComponente(adjMatrix *matriz, char type, float value, int n1, int n2){
    matriz->v[n1][n2].type = type;
    matriz->v[n1][n2].value = value;
    //não faz sentido colacar um if para o caso de n1 == n2, pois não faz sentido ligar
    //um nó nele mesmo!
    matriz->v[n2][n1].type = type;
    matriz->v[n2][n1].value = value;
}
/*
 * Esta função percorre a matriz de adjacência e exibe todos os seus elementos.
 * Para o caso do grafo modelar um circuito, ela exibe o tipo do elemento e seu valor.
 */
void printMatrix(adjMatrix *matriz, int nodes){
    cout<<"Print Matriz de Adjacencia"<<endl;
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

void criar_lista(Lista *lista_adjacencia, int tamanho) {
    lista_adjacencia->tamanho = tamanho;

    for (int i=0; i<tamanho; i++) {
        lista_adjacencia->lista[i].type = '0';
        lista_adjacencia->lista[i].valor = 0.0;
        lista_adjacencia->lista[i].proximo_no = nullptr;
    }
}

void inserir_ligacao(Lista *lista_adjacencia, char type, int valor, int n1, int n2) {
    No* novo_no = new No();
    novo_no->indice = n2;
    novo_no->type = type;
    novo_no->valor = valor;
    novo_no->proximo_no = nullptr;

    novo_no->proximo_no = lista_adjacencia->lista[n1].proximo_no;
    lista_adjacencia->lista[n1].proximo_no = novo_no;
}

void print_lista(Lista *lista_adjacencia){
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
            if((matriz->v[i][j].type == 'W' ||
            matriz->v[i][j].type == 'R' ||
            matriz->v[i][j].type == 'C' ||
            matriz->v[i][j].type == 'I') &&
            C[i] == 1 && C[j] == 0){
                result->v[i][j].type = matriz->v[i][j].type;
                result->v[i][j].value = matriz->v[i][j].value;

                result->v[j][i].type = matriz->v[j][i].type;
                result->v[j][i].value = matriz->v[j][i].value;
                C[j] = 1;
            }
            if((matriz->v[i][j].type == 'W' ||
            matriz->v[i][j].type == 'R' ||
            matriz->v[i][j].type == 'C' ||
            matriz->v[i][j].type == 'I') &&
            C[i] == 0 && C[j] == 1){
                result->v[i][j].type = matriz->v[i][j].type;
                result->v[i][j].value = matriz->v[i][j].value;

                result->v[j][i].type = matriz->v[j][i].type;
                result->v[j][i].value = matriz->v[j][i].value;
                C[i] = 1;
            }
        }
    }
}
/*
 * Esta função deve retornar o número de circuitos fundamentais formados.
 * Usando 4 matrizes, A, B, C e D, onde A é a matriz de adjacência original, B é a matriz de adjacência da árvore geradora
 *
 */
int findFundamentalcycles(adjMatrix *A, adjMatrix *B, adjMatrix *C, adjMatrix D[], int nodes){

    findSpanningTree(A, B, nodes);
    *C = *A;
    adjMatrix *aux = new adjMatrix();
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
    int k = 0;
    // Ver se os ranges desse i e j tao contidos dentro de n (pra n dar segmentation fault)
    for(int i = 0; i < nodes-1; i++){
        for(int j = i+1; j < nodes; j++){
            if(C->v[i][j].type != '0'){
                D[k] = *aux;
                D[k].v[i][j].type = C->v[i][j].type;
                D[k].v[i][j].value = C->v[i][j].value;
                k = k + 1;
                //procedimento de remover os ramos sobrando q n fazem parte do ciclo
            }
        }
    }
    return k;
}
