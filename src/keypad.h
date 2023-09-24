#pragma once

#include <optional>
#include <iostream>

#include "button.h"

const int BUTTON_WIDTH = 30;
const int MARGIN = 2;

class KeyPad {
public:
    KeyPad(int x, int y) : x(x), y(y) {}

    void draw();
    void tick();
    void addDigit(int digit);
    void resetNumber();
    int getNumber();

private:
    int x;
    int y;

    int number = 0;

    Button zero{
        "0",
        [this]() { addDigit(0); },
        x + BUTTON_WIDTH + MARGIN,
        y,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button clear{
        "C",
        [this]() { resetNumber(); },
        x + (BUTTON_WIDTH + MARGIN) * 2,
        y,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button one{
        "1",
        [this]() { addDigit(1); },
        x,
        y + BUTTON_WIDTH + MARGIN,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button two{
        "2",
        [this]() { addDigit(2); },
        x + BUTTON_WIDTH + MARGIN,
        y + BUTTON_WIDTH + MARGIN,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button three{
        "3",
        [this]() { addDigit(3); },
        x + (BUTTON_WIDTH + MARGIN) * 2,
        y + BUTTON_WIDTH + MARGIN,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button four{
        "4",
        [this]() { addDigit(4); },
        x,
        y + (BUTTON_WIDTH + MARGIN) * 2,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button five{
        "5",
        [this]() { addDigit(5); },
        x + BUTTON_WIDTH + MARGIN,
        y + (BUTTON_WIDTH + MARGIN) * 2,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button six{
        "6",
        [this]() { addDigit(6); },
        x + (BUTTON_WIDTH + MARGIN) * 2,
        y + (BUTTON_WIDTH + MARGIN) * 2,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button seven{
        "7",
        [this]() { addDigit(7); },
        x,
        y + (BUTTON_WIDTH + MARGIN) * 3,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button eight{
        "8",
        [this]() { addDigit(8); },
        x + BUTTON_WIDTH + MARGIN,
        y + (BUTTON_WIDTH + MARGIN) * 3,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button nine{
        "9",
        [this]() { addDigit(9); },
        x + (BUTTON_WIDTH + MARGIN) * 2,
        y + (BUTTON_WIDTH + MARGIN) * 3,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
};
