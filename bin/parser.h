#ifndef PARSER_H
#define PARSER_H

#include <util.h>
#include <string>
#include <iostream>

using namespace std;

class Parser {

private:
    adjMatrix matriz_componentes;
    string caminho;

public:
        Parser();
        Parser(string _caminho);
        void tratamento(string _caminho);


};

#endif // PARSER_H
