#include <raylib.h>

#include "tree.h"

void Tree::draw() {
    if (root.has_value()) {
        root.value()->draw(GetScreenWidth() / 2, 100, 0);
    }
}