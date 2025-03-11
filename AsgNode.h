#ifndef ASGNODE_H
#define ASGNODE_H

#include <memory>
#include <string>


#include "Node.h"

class AsgNode:Node {
public:

    std::string name;
    std::unique_ptr<Node> value;
    explicit AsgNode(std::string name, std::unique_ptr<Node> value) : name(std::move(name)), value(std::move(value)) {};

    static NodeType getType() override {return NodeType::ASG;};
};

#endif //ASGNODE_H
