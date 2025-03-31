#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Node.h"
#include <map>
#include <string>
#include <vector>
#include "NumNode.h"
#include "VarNode.h"
#include "OpNode.h"
#include "AsgNode.h"
#include <stdexcept>
#include "PrintNode.h"
#include <iostream>

class Interpreter {
public:
  Interpreter() = default;

  int interpretuj(const Node* node);
  std::string drzewoAst(const Node* node, int indent = 0, bool ostatni = true);

  void czyscWyniki();
  const std::vector<std::string>& pobierzWyniki() const;

private:
  std::map<std::string, int> zmienne;
  std::vector<std::string> wynikiPrint; // przechowuje wyniki print
};

#endif // INTERPRETER_H