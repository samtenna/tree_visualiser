#include <raylib.h>

#include "button.h"

const int BUTTON_FONT_SIZE = 20;
const int BUTTON_FONT_SPACING = 1;

void Button::draw() {
    Font font = GetFontDefault();
    Vector2 textSize = MeasureTextEx(font, text.c_str(), BUTTON_FONT_SIZE, BUTTON_FONT_SPACING);
    int textX = x + static_cast<int>(width / 2) - static_cast<int>(textSize.x / 2);
    int textY = y + static_cast<int>(height / 2) - static_cast<int>(textSize.y / 2);

    if (isHovered()) {
        DrawRectangle(x, y, width, height, backgroundColorHover);
        DrawText(text.c_str(), textX, textY, BUTTON_FONT_SIZE, textColorHover);
    } else {
        DrawRectangle(x, y, width, height, backgroundColor);
        DrawText(text.c_str(), textX, textY, BUTTON_FONT_SIZE, textColor);
    }
}

void Button::tick() {
    if (isHovered()) {
        if (!mouseWasHovered) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            action();
        }
    }

    if (!isHovered() && mouseWasHovered) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    mouseWasHovered = isHovered();
}

bool Button::isHovered() {
    return CheckCollisionPointRec(GetMousePosition(),
                                  Rectangle{static_cast<float>(x),
                                            static_cast<float>(y),
                                            static_cast<float>(width),
                                            static_cast<float>(height)});
}
