#include <iostream>
#include <raylib.h>

#include "binary_search_tree.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tree Visualiser");

    SetTargetFPS(60);

    BinarySearchTree tree{};
    tree.insertValue(50);
    tree.insertValue(25);
    tree.insertValue(100);
    tree.insertValue(75);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        tree.draw();

        EndDrawing();
    }

    CloseWindow();
}
