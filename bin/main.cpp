#include <iostream>
#define MAX 50

using namespace std;

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

int main()
{
    int n = 4;
    adjMatrix *matriz = new adjMatrix();
    createAdjMatrix(matriz, n);
    addComponente(matriz, 'R', 2.0, 0, 1);
    addComponente(matriz, 'I', 1.0, 1, 3);
    addComponente(matriz, 'W', 0.0, 0, 2);
    addComponente(matriz, 'W', 0.0, 2, 3);
    printMatrix(matriz, n);
    cout<<endl;

    Lista *listaajd = new Lista();
    criar_lista(listaajd, n);
    inserir_ligacao(listaajd, 'R', 2.0, 0, 1);
    inserir_ligacao(listaajd, 'I', 1.0, 1, 3);
    inserir_ligacao(listaajd, 'R', 1.0, 1, 2);
    inserir_ligacao(listaajd, 'W', 0.0, 0, 2);
    inserir_ligacao(listaajd, 'W', 0.0, 2, 3);
    print_lista(listaajd);

    return 0;
}

void createAdjMatrix(adjMatrix *matriz, int nodes){
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            matriz->v[i][j].type = '0';
            matriz->v[i][j].value = 0;
        }
    }
}

void addComponente(adjMatrix *matriz, char type, float value, int n1, int n2){
    matriz->v[n1][n2].type = type;
    matriz->v[n1][n2].value = value;

    //não faz sentido colacar um if para o caso de n1 == n2, pois não faz sentido ligar
    //um nó nele mesmo!
    matriz->v[n2][n1].type = type;
    matriz->v[n2][n1].value = value;
}

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
