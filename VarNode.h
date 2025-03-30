#ifndef VARNODE_H
#define VARNODE_H

#include "Node.h"
#include <string>

class VarNode : public Node {
private:
  std::string name;

public:
  explicit VarNode(std::string name);
  ~VarNode() override = default;

  [[nodiscard]] NodeType getType() const override;
  [[nodiscard]] const std::string &getName() const;
};

#endif // VARNODE_H