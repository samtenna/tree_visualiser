#include <memory>
#include <optional>

#include "node.h"

class Tree {
public:
    Tree() {}

    void draw();

    virtual void insertValue(int value) = 0;
    virtual void deleteValue(int value) = 0;

protected:
    std::optional<std::shared_ptr<Node>> root;
};
