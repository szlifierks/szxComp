#ifndef NUMNODE_H
#define NUMNODE_H
#include "Node.h"

class NumNode:Node {
    public:

    int num;
    explicit NumNode(int num) : num(num) {};

    static NodeType getType() override {return NodeType::NUM;};
};

#endif //NUMNODE_H
