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
    std::shared_ptr<Node> current = root.value();
    // NOTE: this currently crashes when deleting the root node, maybe do something about that idk

    while (true) {
        if (value < current->value) {
            if (current->getLeft().has_value()) {
                current = current->getLeft().value();
            } else {
                return;
            }
        } else if (value > current->value) {
            if (current->getRight().has_value()) {
                current = current->getRight().value();
            } else {
                return;
            }
        } else {
            // case 1: no children
            if (!current->getLeft().has_value() && !current->getRight().has_value()) {
                Node* parent = current->getParent();

                if (parent->getLeft() == current) {
                    parent->clearLeft();
                } else {
                    parent->clearRight();
                }

                return;
            }

            // case 2: one child
            if (current->getLeft().has_value() && !current->getRight().has_value()) {
                Node* parent = current->getParent();

                if (parent->getLeft() == current) {
                    parent->setLeft(current->getLeft().value()->value);
                } else {
                    parent->setRight(current->getLeft().value()->value);
                }

                return;
            }

            if (!current->getLeft().has_value() && current->getRight().has_value()) {
                Node* parent = current->getParent();

                if (parent->getLeft() == current) {
                    parent->setLeft(current->getRight().value()->value);
                } else {
                    parent->setRight(current->getRight().value()->value);
                }

                return;
            }

            // case 3: two children
            if (current->getLeft().has_value() && current->getRight().has_value()) {
                // find the smallest value in the right subtree
                std::shared_ptr<Node> successor = current->getRight().value();

                while (successor->getLeft().has_value()) {
                    successor = successor->getLeft().value();
                }

                // replace the current node with the successor
                current->value = successor->value;

                // delete the successor
                Node* parent = successor->getParent();
                if (successor->getRight() != std::nullopt) {
                    successor->getRight().value()->setParent(parent);

                    if (parent->value == current->value) {
                        parent->right = successor->getRight();
                    } else {
                        parent->left = successor->getRight();
                    }
                } else {
                    if (parent->value == current->value) {
                        parent->clearRight();
                    } else {
                        parent->clearLeft();
                    }
                }
            }
        }
    }
}
