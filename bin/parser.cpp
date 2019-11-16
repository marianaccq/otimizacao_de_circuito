#include "parser.h"
#include <iostream>
#include <fstream>  //para o ifstream
#include <sstream>  //para o stringstream


Parser::Parser() { }

Parser::Parser(string _caminho) {
    caminho = _caminho;
}

void Parser::tratamento(string _caminho) {
    caminho = _caminho;

    ifstream fin;       //objeto conectado ao fluxo de saída;
    string linha;       //linha de comando encontrada no arquivo .txt
    string cmd;         //comando encontrado no arquivo .txt
    stringstream ss;    //objeto responsável pela leitura de cada palavra do arquivo de texto

    //abrindo o fluxo para o arquivo de .txt
    fin.open(caminho);
    if(!fin.is_open()) {
        cout << "Falha na abertura do arquivo. Caminho especificado correto? \n";
    }

    //aqui comeca a leitura das linhas
    while (fin.good()) {
        getline(fin, linha);    //lê a linha;

        if(!fin.good()) {       //caso em que tentei ler a linha, mas não tinha nada;
            break;
        }

    }
}

