#include <memory>
#include <optional>

#include "node.h"

class Tree {
public:
    Tree() {}

    virtual void insertValue(int value) = 0;
    virtual void deleteValue(int value) = 0;

private:
    std::optional<std::shared_ptr<Node>> root;
};
