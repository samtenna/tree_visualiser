#include <optional>
#include <iostream>
#include <raylib.h>
#include <string>

#include "node.h"

void Node::setLeft(int value) {
    left = std::make_shared<Node>(value);
    left.value()->setParent(this);
}

void Node::setRight(int value) {
    right = std::make_shared<Node>(value);
    right.value()->setParent(this);
}

void Node::draw(int x, int y, int level) {
    int nodesOnLevel = 1 << level;
    int levelOffset = GetScreenWidth() / nodesOnLevel / 6;

    // Lines need to be drawn before circles so that the circles are on top
    if (left.has_value()) {
        DrawLine(x, y, x - levelOffset, y + 100, BLACK);
    }

    if (right.has_value()) {
        DrawLine(x, y, x + levelOffset, y + 100, BLACK);
    }

    DrawCircle(x, y, 30.0f, BLACK);
    DrawCircle(x, y, 28.0f, RAYWHITE);
    DrawText(std::to_string(value).c_str(), x - 12, y - 12, 24, BLACK);

    // Recursively draw children
    if (right.has_value()) {
        right.value()->draw(x + levelOffset, y + 100, level + 1);
    }

    if (left.has_value()) {
        left.value()->draw(x - levelOffset, y + 100, level + 1);
    }
}
