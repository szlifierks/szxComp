#ifndef OPNODE_H
#define OPNODE_H

#include "Node.h"

class OpNode:Node {
public:

    char op;
    explicit OpNode(char op) : op(op) {};

    static NodeType getType() override { return NodeType::OP;};
};

#endif //OPNODE_H
