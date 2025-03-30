#include "OpNode.h"

OpNode::OpNode(std::string op, std::unique_ptr<Node> left,
               std::unique_ptr<Node> right)
    : op(std::move(op)), left(std::move(left)), right(std::move(right)) {}

NodeType OpNode::getType() const {
  return NodeType::OP;
}

const std::string &OpNode::getOp() const {
  return op;
}

const Node *OpNode::getLeft() const {
  return left.get();
}

const Node *OpNode::getRight() const {
  return right.get();
}