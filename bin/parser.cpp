#include "parser.h"
#include "util.h"
#include <iostream>
#include <fstream>  //para o ifstream
#include <sstream>  //para o stringstream


Parser::Parser() { }

Parser::Parser(adjMatrix *matriz) {
    matriz_componentes = matriz;
}

void Parser::tratamento(string filename) {

    fstream fin;       //objeto conectado ao fluxo de saída;
    string linha;
    stringstream ss;

    //filename = "instrucoes";

    //abrindo o fluxo para o arquivo de .txt
    fin.open("./../" + filename + ".txt");
    if(!fin.is_open()) {
        cout << "Falha na abertura do arquivo. Caminho especificado incorreto. \n";
        exit(0);
    }

    //aqui comeca a leitura das linhas
    while (fin.good()) {
        getline(fin, linha);    //lê a linha;
        ss.clear();
        ss.str(linha);
        ss >> linha;

        if (linha.compare("dim") == 0){
            int nodes;
            ss >> nodes;

            n = nodes;

            createAdjMatrix(matriz_componentes, nodes);

        } else if (linha.compare("r") == 0 || linha.compare("R") == 0){
            float valor;
            int no1, no2;

            ss >> valor >> no1 >> no2;

            addComponente(matriz_componentes, 'R', valor, no1, no2);

        } else if (linha.compare("v") == 0 || linha.compare("V") == 0) {
            float valor;
            int no1, no2;

            ss >> valor >> no1 >> no2;

            addComponente(matriz_componentes, 'V', valor, no1, no2);

        } else if (linha.compare("w") == 0 || linha.compare("W") == 0) {
           float valor;
           int no1, no2;

           ss >> valor >> no1 >> no2;

           addComponente(matriz_componentes, 'W', valor, no1, no2);

        } else {
            cout << "Erro na leitura do arquivo!";
            exit(0);
        }
    }


}

int Parser::getNodes() {
    return n;
}
