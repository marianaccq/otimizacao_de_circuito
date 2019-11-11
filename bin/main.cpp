#include <iostream>
#include "util.h"

using namespace std;

int main()
{
    int n = 4;
    adjMatrix *matriz = new adjMatrix();
    createAdjMatrix(matriz, n);
    addComponente(matriz, 'R', 2.0, 0, 1);
    addComponente(matriz, 'I', 1.0, 1, 2);
    addComponente(matriz, 'W', 0.0, 2, 3);
    addComponente(matriz, 'W', 0.0, 3, 4);

    adjMatrix *B = new adjMatrix();
    adjMatrix *C = new adjMatrix();
    //fazer adjMatrix *D[n]; pra testar
    adjMatrix D[n];
    createAdjMatrix(B, n);
    createAdjMatrix(C, n);
    int x=0;

    x=findFundamentalcycles(matriz, B, C, D, n);
    printMatrix(matriz, n);
    //printMatrix(B, n);
    //printMatrix(C, n);
    for(int i=0; i<n; i++){
        printMatrix(&D[i], n);
    }

    cout<<endl;
    cout<<endl;

//    adjMatrix *spanningTree = new adjMatrix();
//    findSpanningTree(matriz, spanningTree, n);
//    printMatrix(spanningTree, n);
//    cout<<endl;
//    n = 4;
//    Lista *listaajd = new Lista();
//    criar_lista(listaajd, n);
//    inserir_ligacao(listaajd, 'R', 2.0, 0, 1);
//    inserir_ligacao(listaajd, 'I', 1.0, 1, 3);
//    inserir_ligacao(listaajd, 'R', 1.0, 1, 2);
//    inserir_ligacao(listaajd, 'W', 0.0, 0, 2);
//    inserir_ligacao(listaajd, 'W', 0.0, 2, 3);
//    print_lista(listaajd);

    return 0;
}

