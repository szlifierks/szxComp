#include "Lexer.h"

std::vector<Token> Lexer::tokenizator(const std::string &code) {
    std::vector<Token> tokens;
    int pos = 0;

    while (pos < code.length()) {
        if (std::isspace(code[pos])) {
            pos++;
        } else if (code[pos] == '(' || code[pos] == ')') {
            tokens.push_back(Token{TokenType::NAWIAS, code.substr(pos, 1)});
            pos++;
        } else if (code[pos] == '+' || code[pos] == '-' || code[pos] == '*' || code[pos] == '/' || code[pos] == '=') {
            tokens.push_back(Token{TokenType::OPERATOR, code.substr(pos, 1)});
            pos++;
        } else if (std::isdigit(code[pos])) {
            std::string num = "";
            while (pos < code.length() && std::isdigit(code[pos])) {
                num += code[pos];
                pos++;
            }
            tokens.push_back(Token{TokenType::NUMER, num});
        } else if (code.substr(pos, 3) == "let") {
            tokens.push_back(Token{TokenType::SLOWOK, "let"});
            pos += 3;
        } else if (code.substr(pos, 5) == "print") {
            tokens.push_back(Token{TokenType::SLOWOK, "print"});
            pos += 5;
        } else if (std::isalpha(code[pos]) || code[pos] == '_' && tokens.back().value == "let") {
            std::string name = "";
            while (pos < code.length() && (std::isalpha(code[pos]) || std::isdigit(code[pos]))) {
                name += code[pos];
                pos++;
            }
            tokens.push_back(Token{TokenType::NAZWA, name});
        } else if (code[pos] == ';') {
            tokens.push_back(Token{TokenType::END, ";"});
            pos++;
        } else {
            pos++;
        }
    }

    return tokens;
}
