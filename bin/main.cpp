#include <iostream>
#include "util.h"
#include "parser.h"
#include "time.h"

using namespace std;

int main()
{
//    int n = 8;


    adjMatrix *matriz = new adjMatrix();

    // Código para gerar um circuito com m1*m2 nós
    int m1 = 8;
    int m2 = 10;
    int n = m1*m2;
    gerarMatrizAdj(matriz, m1, m2);

    // Código para ler um circuito de um .txt definido pelo usuário
//    Parser leitor_dados(matriz);
//    leitor_dados.tratamento("teste_8-2_circuito");
//    int n = leitor_dados.getNodes();

    //---------------------------------------
    clock_t time, timef;
    time = clock();
    //---------------------------------------

    // TRECHO USADO APENAS PARA TESTES RAPIDOS
//    bool *poltrue = new bool();
//    bool *polfalse = new bool();
//    *poltrue = true;
//    *polfalse = false;
//    createAdjMatrix(matriz, n);
//    addComponente(matriz, 'V',  12.0, 0, 1, poltrue);
//    addComponente(matriz, 'R',  3.0, 1, 2);
//    addComponente(matriz, 'R',  4.0, 2, 3);
//    addComponente(matriz, 'R',  1.0, 3, 0);
//    addComponente(matriz, 'W',  0.0, 2, 4);
//    addComponente(matriz, 'V',  6.0, 5, 3, polfalse);
//    addComponente(matriz, 'R',  8.0, 4, 5);
//    addComponente(matriz, 'R',  8.0, 4, 6);
//    addComponente(matriz, 'W',  0.0, 6, 7);
//    addComponente(matriz, 'W',  0.0, 7, 5);
    // TRECHO USADO APENAS PARA TESTES RAPIDOS

    printMatrix(matriz, n);
    cout<<endl;

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

    float x[MAX] = {0};
    float matrizTensoes[MAX][MAX] = {0};

    resolverSistema(matrizResistencia, arrayVoltagem, k, x);

    float matrizCorrentes[MAX][MAX] = {0};
    montarMatrizCorrentes(matriz, n, D, k, matrizCorrentes, x);
    montarMatrizTensoes(matriz, n, matrizCorrentes, matrizTensoes);
    timef = clock();

//    for(int i=0; i<k; i++){
//        for(int j=0; j<k; j++){
//            cout<<matrizResistencia[i][j]<<", ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    for(int j=0; j<k; j++){
//        cout<<arrayVoltagem[j]<<", ";
//    }
//    cout<<endl;

    cout<<endl<<"Correntes de Malha:"<<endl;
    for(int i=0; i<k; i++){
        cout<<"| I"<<i<<" = "<<x[i]<<"A ";
    }
    cout<<"|";
    cout<<endl;

    cout<<endl<<"Correntes de Ramo:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrizCorrentes[i][j] != 0){
                cout<<"I("<<i<<"-"<<j<<")= "<<matrizCorrentes[i][j]<<"A | ";
            }
        }
    }
    cout<<endl;

    cout<<endl<<"Tensoes de Ramo:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrizCorrentes[i][j] != 0){
                cout<<"V("<<i<<"-"<<j<<")= "<<matrizTensoes[i][j]<<"V | ";
            }
        }
    }

//    cout<<"MATRIZ A: "<<endl;
//    printMatrix(matriz, n);
//    cout<<"MATRIZ B: "<<endl;
//    printMatrix(B, n);
//    cout<<"MATRIZ C: "<<endl;
//    printMatrix(C, n);

//    for(int i=0; i<k; i++){
//        cout<<"MATRIZ D["<<i<<"]: "<<endl;
//        printMatrix(&D[i], n);
//    }

    cout<<endl;

    cout<<"TEMPO DE EXECUÇÃO: "<<(float(timef - time))/CLOCKS_PER_SEC<<endl;
    return 0;
}

