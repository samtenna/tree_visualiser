#include <iostream>
#include <raylib.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tree Visualiser");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
}
