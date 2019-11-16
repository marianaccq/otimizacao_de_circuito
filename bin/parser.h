#ifndef PARSER_H
#define PARSER_H

#include <util.h>
#include <string>
#include <iostream>

using namespace std;

class Parser {

private:
    int n;


public:
    Parser();
    Parser(adjMatrix *matriz);
    void tratamento();
    adjMatrix *matriz_componentes;
    int getNodes();

};

#endif // PARSER_H
