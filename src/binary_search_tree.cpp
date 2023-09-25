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
    if (root == std::nullopt) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    std::shared_ptr<Node> current = root.value();

    while (true) {
        if (current->value < value) {
            if (current->getRight().has_value()) {
                current = current->getRight().value();
            } else {
                break;
            }
        } else if (current->value > value) {
            if (current->getLeft().has_value()) {
                current = current->getLeft().value();
            } else {
                break;
            }
        } else if (current->value == value) {
            // case 1: no children
            if (!current->getLeft().has_value() && !current->getRight().has_value()) {
                if (current == root) {
                    root = std::nullopt;
                    return;
                }

                if (current->getParent()->left.has_value() && current->getParent()->left.value()->value == value) {
                    current->getParent()->clearLeft();
                } else {
                    current->getParent()->clearRight();
                }
            }

            // case 2: one child
            if (current->getLeft().has_value() && !current->getRight().has_value()) {
                if (current == root) {
                    root = current->getLeft();
                    root.value()->setParent(nullptr);
                    return;
                }

                Node* parent = current->getParent();

                if (parent->left.has_value() && parent->left.value()->value == value) {
                    // current is a left child
                    parent->left = current->getLeft();
                    parent->left.value()->setParent(parent);
                } else {
                    // current is a right child
                    parent->right = current->getLeft();
                    parent->right.value()->setParent(parent);
                }
            }

            if (!current->getLeft().has_value() && current->getRight().has_value()) {
                if (current == root) {
                    root = current->getRight();
                    root.value()->setParent(nullptr);
                    return;
                }

                Node* parent = current->getParent();

                if (parent->left.has_value() && parent->left.value()->value == value) {
                    // current is a left child
                    parent->left = current->getRight();
                    parent->left.value()->setParent(parent);
                } else {
                    // current is a right child
                    parent->right = current->getRight();
                    parent->right.value()->setParent(parent);
                }
            }

            // case 3: two children
            if (current->getLeft().has_value() && current->getRight().has_value()) {
                std::shared_ptr<Node> successor = current->getRight().value();

                while (successor->getLeft().has_value()) {
                    successor = successor->getLeft().value();
                }

                current->value = successor->value;

                if (successor->getParent()->left.has_value() && successor->getParent()->left.value()->value == successor->value) {
                    if (successor->right.has_value()) {
                        successor->getParent()->left = successor->right;
                        successor->right.value()->setParent(successor->getParent());
                    } else {
                        successor->getParent()->clearLeft();
                    }
                } else {
                    if (successor->right.has_value()) {
                        successor->getParent()->right = successor->right;
                        successor->right.value()->setParent(successor->getParent());
                    } else {
                        successor->getParent()->clearRight();
                    }
                }
            }

            break;
        }
    }
}
