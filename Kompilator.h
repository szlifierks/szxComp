#ifndef KOMPILATOR_H
#define KOMPILATOR_H
#include <string>

#include "Lexer.h"


class Kompilator : Lexer {
public:
    std::string kompiluj(std::string kod);

    std::string kompiluj(std::string kod, std::string flagi);
};


#endif //KOMPILATOR_H
