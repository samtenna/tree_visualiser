#include <optional>
#include <memory>
#include <iostream>

class Node {
public:
    Node(std::shared_ptr<Node> parent, int value)
        : parent(parent), value(value) {}

    void insertLeft(int value);
    void insertRight(int value);

public:
    std::optional<std::shared_ptr<Node>>
        left;
    std::optional<std::shared_ptr<Node>> right;
    std::optional<std::shared_ptr<Node>> parent;
    int value;
};
