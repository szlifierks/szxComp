#ifndef PRINTNODE_H
#define PRINTNODE_H

#include "Node.h"
#include <memory>

class PrintNode : public Node {
private:
  std::unique_ptr<Node> expression;

public:
  explicit PrintNode(std::unique_ptr<Node> expression);
  ~PrintNode() override;

  [[nodiscard]] NodeType getType() const override;
  [[nodiscard]] const Node* getExpression() const;
};

#endif // PRINTNODE_H