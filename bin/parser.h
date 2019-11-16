#ifndef PARSER_H
#define PARSER_H

#include <util.h>
#include <string>
#include <iostream>

using namespace std;

class Parser {

private:
    adjMatrix *matriz_componentes;
    int n;  //tamanho da matriz;

public:
        Parser();
        void tratamento();
        int getTamanho_matriz();
        Parser(adjMatrix *matriz);


};

#endif // PARSER_H
