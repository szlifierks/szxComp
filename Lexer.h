#ifndef LEXER_H
#define LEXER_H

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

enum class TokenType { NAZWA, NUMER, OPERATOR, SLOWOK, NAWIAS, END };

struct Token {
  TokenType type;
  std::string value;
};

class Lexer {
protected:
  std::vector<Token> tokenizator(const std::string &code);
};

#endif // LEXER_H
