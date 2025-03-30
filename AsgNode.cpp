#include "AsgNode.h"

AsgNode::AsgNode(std::string name, std::unique_ptr<Node> value)
    : name(std::move(name)), value(std::move(value)) {}

NodeType AsgNode::getType() const {
  return NodeType::ASG;
}

const std::string &AsgNode::getName() const {
  return name;
}

const Node *AsgNode::getValue() const {
  return value.get();
}