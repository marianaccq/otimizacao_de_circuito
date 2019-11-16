#ifndef PARSER_H
#define PARSER_H

#include <util.h>
#include <string>
#include <iostream>

using namespace std;

class Parser {

private:
    adjMatrix *matriz_componentes;

public:
    Parser();
    Parser(adjMatrix *matriz);
    void tratamento();

};

#endif // PARSER_H
