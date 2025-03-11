#ifndef VARNODE_H
#define VARNODE_H

#include <string>
#include <utility>


#include "Node.h"

class VarNode:Node {
public:

    std::string name;
    explicit VarNode(std::string name) : name(std::move(name)) {};

    static NodeType getType() override {return NodeType::VAR;};
};

#endif //VARNODE_H
