#include <memory>

#include "node.h"

enum TreeType {
    AVLTree,
    BinarySearchTree,
    RedBlackTree,
};

class Tree {
public:
    Tree() {
        root = std::make_shared<Node>();
    }

public:
    TreeType type;

private:
    std::shared_ptr<Node> root;
};
