#include <iostream>
#include "util.h"
#include "numericalrecipes.h"

using namespace std;

int main()
{
    int n = 6;
    adjMatrix *matriz = new adjMatrix();
    createAdjMatrix(matriz, n);
    addComponente(matriz, 'V', 12.0, 0, 1);
    addComponente(matriz, 'R', 2.0, 1, 2);
    addComponente(matriz, 'R', 2.0, 2, 3);
    addComponente(matriz, 'W', 0.0, 3, 0);
    addComponente(matriz, 'W', 0.0, 2, 4);
    addComponente(matriz, 'W', 0.0, 3, 5);
    addComponente(matriz, 'R', 2.0, 4, 5);

    adjMatrix *B = new adjMatrix();
    adjMatrix *C = new adjMatrix();
    adjMatrix D[n];
    createAdjMatrix(B, n);
    createAdjMatrix(C, n);
    int k=0;

    k=findFundamentalcycles(matriz, B, C, D, n);

    float matrizResistencia[MAX][MAX];
    float arrayVoltagem[MAX];
    montarMatrizCircuito(D, k, n, matrizResistencia, arrayVoltagem);

    int *indx;
    float *d;
    float b[MAX] = {12, 12};
    //ludcmp(resultado, k, indx, d);
    //lubksb(resultado, k, indx, b);

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            cout<<matrizResistencia[i][j]<<", ";
        }
        cout<<endl;
    }

    for(int i=0; i<k; i++){
        cout<<arrayVoltagem[i]<<", ";
    }
    cout<<endl;


    printMatrix(matriz, n);
    printMatrix(B, n);
    printMatrix(C, n);
    cout<<"MATRIZES D: "<<endl;
    for(int i=0; i<k; i++){
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

