#include "VarNode.h"

VarNode::VarNode(std::string name) : name(std::move(name)) {}

NodeType VarNode::getType() const {
  return NodeType::VAR;
}

const std::string &VarNode::getName() const {
  return name;
}