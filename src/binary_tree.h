#include "tree.h"

class BinaryTree : public Tree {
public:
    BinaryTree() : Tree() {}

    void insertValue(int value) override;
    void deleteValue(int value) override;
};
