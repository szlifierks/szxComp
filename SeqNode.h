#ifndef SEQNODE_H
#define SEQNODE_H

#include "Node.h"
#include <memory>
#include <vector>

class SeqNode : public Node {
private:
  std::vector<std::unique_ptr<Node>> instrukcje;

public:
  explicit SeqNode() = default;
  ~SeqNode() override = default;

  [[nodiscard]] NodeType getType() const override;
  void dodajInstr(std::unique_ptr<Node> instrukcja);
  [[nodiscard]] const std::vector<std::unique_ptr<Node>>& getInstr() const;
};



#endif //SEQNODE_H
