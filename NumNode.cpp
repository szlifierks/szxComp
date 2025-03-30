#include "NumNode.h"

NumNode::NumNode(int num) : num(num) {}

NodeType NumNode::getType() const {
  return NodeType::NUM;
}

int NumNode::getNum() const {
  return num;
}