#include <iostream>
#define MAX 50

using namespace std;

struct No {
    No* proximo_no;
    int valor;
    char type;
};

struct Lista {
    No lista[MAX];
    int tamanho;
};


void cria_lista(Lista lista_adjacencia, int tamanho) {
    lista_adjacencia.tamanho = tamanho;

    for (int i=0; i<tamanho; i++) {
        lista_adjacencia.lista[i].valor = 0;
        lista_adjacencia.lista[i] = nullptr;
        lista_adjacencia.lista[i].type = '0';
    }
}

void insirir_ligacao(Lista lista_adjacencia, int indice, char type_component, int valor) {
    No* novo_no = new No();
    novo_no->valor = valor;
    novo_no->type = type_component;
    novo_no->proximo_no = nullptr;

    lista_adjacencia.lista[indice] = novo_no;
}


int main() {


    return 0;
}
