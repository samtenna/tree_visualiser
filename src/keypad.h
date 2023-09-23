#pragma once

#include "button.h"

const int BUTTON_WIDTH = 30;
const int MARGIN = 2;

class KeyPad {
public:
    KeyPad(int x, int y) : x(x), y(y) {}

    void draw();

private:
    int x;
    int y;

    Button zero{
        "0",
        []() {},
        x + BUTTON_WIDTH + MARGIN,
        y,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button one{
        "1",
        []() {},
        x,
        y + BUTTON_WIDTH + MARGIN,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button two{
        "2",
        []() {},
        x + BUTTON_WIDTH + MARGIN,
        y + BUTTON_WIDTH + MARGIN,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button three{
        "3",
        []() {},
        x + (BUTTON_WIDTH + MARGIN) * 2,
        y + BUTTON_WIDTH + MARGIN,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button four{
        "4",
        []() {},
        x,
        y + (BUTTON_WIDTH + MARGIN) * 2,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button five{
        "5",
        []() {},
        x + BUTTON_WIDTH + MARGIN,
        y + (BUTTON_WIDTH + MARGIN) * 2,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button six{
        "6",
        []() {},
        x + (BUTTON_WIDTH + MARGIN) * 2,
        y + (BUTTON_WIDTH + MARGIN) * 2,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button seven{
        "7",
        []() {},
        x,
        y + (BUTTON_WIDTH + MARGIN) * 3,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button eight{
        "8",
        []() {},
        x + BUTTON_WIDTH + MARGIN,
        y + (BUTTON_WIDTH + MARGIN) * 3,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
    Button nine{
        "9",
        []() {},
        x + (BUTTON_WIDTH + MARGIN) * 2,
        y + (BUTTON_WIDTH + MARGIN) * 3,
        BUTTON_WIDTH,
        BUTTON_WIDTH,
    };
};
