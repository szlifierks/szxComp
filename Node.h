#ifndef NODE_H
#define NODE_H

enum class NodeType {
  NUM,   // liczba
  OP,    // operator
  VAR,   // zmienne
  ASG,   // definicje
  PRINT,  // instrukcja print
  SEQ //obsluga wielu instrukcji po ;
};

class Node {
public:
  virtual ~Node() = default;
  [[nodiscard]] virtual NodeType getType() const = 0;
};

#endif // NODE_H