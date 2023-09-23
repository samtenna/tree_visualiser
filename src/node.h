#include <optional>
#include <memory>
#include <iostream>

class Node {
public:
    Node(int value)
        : value(value) {}

    void setLeft(int value);

    void setRight(int value);

    void setParent(std::shared_ptr<Node> parent) {
        this->parent = parent;
    }

    std::shared_ptr<Node> getLeft() {
        return left.value();
    }

    std::shared_ptr<Node> getRight() {
        return right.value();
    }

    std::shared_ptr<Node> getParent() {
        return parent.value();
    }

public:
    int value;

private:
    std::optional<std::shared_ptr<Node>> left;
    std::optional<std::shared_ptr<Node>> right;
    std::optional<std::shared_ptr<Node>> parent;
};
