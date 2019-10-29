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

void createAdjMatrix(adjMatrix *matriz, int nodes);
void addComponente(adjMatrix *matriz, char type, float value, int n1, int n2);
void printMatrix(adjMatrix *matriz, int nodes);

int main()
{
    int n = 4;
    adjMatrix* matriz = new adjMatrix();
    createAdjMatrix(matriz, n);
    addComponente(matriz, 'R', 2.0, 0, 1);
    addComponente(matriz, 'I', 1.0, 1, 3);
    addComponente(matriz, 'W', 0.0, 0, 2);
    addComponente(matriz, 'W', 0.0, 2, 3);
    printMatrix(matriz, n);
    cout << "Hello World!" << endl;
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
}
