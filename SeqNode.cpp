#include "SeqNode.h"

NodeType SeqNode::getType () const{
  return NodeType::SEQ;
}

void SeqNode::dodajInstr(std::unique_ptr<Node> instrukcja) {
  instrukcje.push_back(std::move(instrukcja));
}

const std::vector<std::unique_ptr<Node>>& SeqNode::getInstr() const {
  return instrukcje;
}

