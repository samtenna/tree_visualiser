#include <iostream>
#include <raylib.h>

#include "binary_search_tree.h"
#include "button.h"
#include "keypad.h"

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
    tree.insertValue(76);

    Button insertButton{"Insert", []() {}, 10, 10, 100, 50};
    Button deleteButton{"Delete", []() {}, 10, 70, 100, 50};

    KeyPad keypad{SCREEN_WIDTH - BUTTON_WIDTH * 3 - MARGIN * 2 - 10, 10};

    while (!WindowShouldClose()) {
        insertButton.tick();
        deleteButton.tick();

        BeginDrawing();

        ClearBackground(RAYWHITE);

        tree.draw();
        insertButton.draw();
        deleteButton.draw();
        keypad.draw();

        EndDrawing();
    }

    CloseWindow();
}
