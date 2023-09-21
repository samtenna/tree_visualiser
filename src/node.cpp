#include "node.h"

void Node::insertLeft(int value) {
    if (left.has_value()) {
        std::cout << stderr << "Left node already exists" << std::endl;
        return;
    }

    left = std::make_shared<Node>(this, value);
}

void Node::insertRight(int value) {
    if (right.has_value()) {
        std::cout << stderr << "Right node already exists" << std::endl;
        return;
    }

    right = std::make_shared<Node>(this, value);
}