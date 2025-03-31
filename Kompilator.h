#ifndef KOMPILATOR_H
#define KOMPILATOR_H
#include <string>

#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>

class Kompilator : public Lexer {
public:
  std::string kompiluj(std::string kod);
  std::string kompiluj(std::string kod, std::string flagi);

private:
  Interpreter interpreter;
};

#endif // KOMPILATOR_H