#include "Kompilator.h"

std::string Kompilator::kompiluj(std::string kod) {
    tokenizator(kod); //bede tutaj robil wszystko po kolei

    return "";
}

std::string Kompilator::kompiluj(std::string kod, std::string flagi) {//pojedyncze rzeczy przez flagi
    if (flagi == "-t") {//sam lexer
        std::vector<Token> tokens = tokenizator(kod);
        std::string result;
        for (const auto& token : tokens) {
            result += token.value + " ";
        }
        return result;
    }

    return "";
}