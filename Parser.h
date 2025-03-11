#ifndef PARSER_H
#define PARSER_H
#include <memory>
#include <vector>

#include "Lexer.h"
#include "Node.h"


class Parser {
private:
    std::vector<Token> tokens;
    int idx = 0;

    std::unique_ptr<Node> parseLine();  //np let x = 5 + 3;
    std::unique_ptr<Node> parseOp();    //np 5 + 3
    std::unique_ptr<Node> parseNum(); //np 5
public:
    explicit Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {}

    std::unique_ptr<Node> parse();
};


#endif //PARSER_H
