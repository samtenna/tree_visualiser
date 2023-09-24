#include <iostream>
#include <optional>
#include <memory>

#include "binary_search_tree.h"

void BinarySearchTree::insertValue(int value) {
    if (!root.has_value()) {
        root = std::make_shared<Node>(value);
        return;
    }

    std::shared_ptr<Node> current = root.value();

    while (true) {
        if (value < current->value) {
            if (current->getLeft().has_value()) {
                current = current->getLeft().value();
            } else {
                current->setLeft(value);
                return;
            }
        } else if (value > current->value) {
            if (current->getRight().has_value()) {
                current = current->getRight().value();
            } else {
                current->setRight(value);
                return;
            }
        } else {
            std::cout << "Value already in tree" << std::endl;
            break;
        }
    }
}

void BinarySearchTree::deleteValue(int value) {
}
