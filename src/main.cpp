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
    KeyPad keypad{SCREEN_WIDTH - BUTTON_WIDTH * 3 - MARGIN * 2 - 10, 10};
    tree.insertValue(50);
    tree.insertValue(25);
    tree.insertValue(100);
    tree.insertValue(75);
    tree.insertValue(76);
    tree.insertValue(101);

    Button insertButton{"Insert", [&tree, &keypad]() mutable {
                            tree.insertValue(keypad.getNumber());
                            keypad.resetNumber();
                        },
                        10, 10, 100, 50};
    Button deleteButton{"Delete", [&tree, &keypad]() mutable {
                            tree.deleteValue(keypad.getNumber());
                            keypad.resetNumber();
                        },
                        10, 70, 100, 50};

    while (!WindowShouldClose()) {
        insertButton.tick();
        deleteButton.tick();
        keypad.tick();

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
