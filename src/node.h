#pragma once

#include <optional>
#include <memory>
#include <iostream>

class Node {
public:
    Node(int value)
        : value(value) {}

    void setLeft(int value);

    void setRight(int value);

    void clearLeft() {
        left = std::nullopt;
    }

    void clearRight() {
        right = std::nullopt;
    }

    void setParent(Node* parent) {
        this->parent = parent;
    }

    std::optional<std::shared_ptr<Node>> getLeft() {
        return left;
    }

    std::optional<std::shared_ptr<Node>> getRight() {
        return right;
    }

    Node* getParent() {
        return parent;
    }

    void draw(int x, int y, int level);

public:
    int value;
    std::optional<std::shared_ptr<Node>> left;
    std::optional<std::shared_ptr<Node>> right;
    Node* parent;
};
