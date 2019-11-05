#include <iostream>
#include "util.h"

using namespace std;

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
