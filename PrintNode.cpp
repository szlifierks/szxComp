#include "PrintNode.h"

PrintNode::PrintNode(std::unique_ptr<Node> expression)
    : expression(std::move(expression)) {}

PrintNode::~PrintNode() = default;

NodeType PrintNode::getType() const {
  return NodeType::PRINT;
}

const Node* PrintNode::getExpression() const {
  return expression.get();
}