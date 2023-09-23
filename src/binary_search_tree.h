#pragma once

#include "tree.h"

class BinarySearchTree : public Tree {
public:
    BinarySearchTree() : Tree() {}

    void insertValue(int value) override;
    void deleteValue(int value) override;
};
