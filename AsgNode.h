#ifndef ASGNODE_H
#define ASGNODE_H

#include "Node.h"
#include <memory>
#include <string>

class AsgNode : public Node {
private:
  std::string name;
  std::unique_ptr<Node> value;

public:
  explicit AsgNode(std::string name, std::unique_ptr<Node> value);
  ~AsgNode() override = default;

  [[nodiscard]] NodeType getType() const override;
  [[nodiscard]] const std::string &getName() const;
  [[nodiscard]] const Node *getValue() const;
};

#endif // ASGNODE_H