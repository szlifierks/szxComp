#ifndef NUMNODE_H
#define NUMNODE_H
#include "Node.h"

class NumNode : public Node {
private:
  int num;

public:
  explicit NumNode(int num);
  ~NumNode() override = default;

  [[nodiscard]] NodeType getType() const override;
  [[nodiscard]] int getNum() const;
};

#endif // NUMNODE_H