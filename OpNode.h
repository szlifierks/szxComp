#ifndef OPNODE_H
#define OPNODE_H

#include "Node.h"
#include <memory>
#include <string>

class OpNode : public Node {
private:
  std::string op;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;

public:
  OpNode(std::string op, std::unique_ptr<Node> left,
         std::unique_ptr<Node> right);
  ~OpNode() override = default;

  [[nodiscard]] NodeType getType() const override;
  [[nodiscard]] const std::string &getOp() const;
  [[nodiscard]] const Node *getLeft() const;
  [[nodiscard]] const Node *getRight() const;
};

#endif // OPNODE_H