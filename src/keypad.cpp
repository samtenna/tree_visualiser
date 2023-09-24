#include <string>
#include <raylib.h>

#include "keypad.h"

void KeyPad::draw() {
    DrawText(std::to_string(number).c_str(),
             x,
             BUTTON_WIDTH * 4 + MARGIN * 4 + 10,
             30,
             BLACK);

    zero.draw();
    clear.draw();
    one.draw();
    two.draw();
    three.draw();
    four.draw();
    five.draw();
    six.draw();
    seven.draw();
    eight.draw();
    nine.draw();
}

void KeyPad::tick() {
    zero.tick();
    clear.tick();
    one.tick();
    two.tick();
    three.tick();
    four.tick();
    five.tick();
    six.tick();
    seven.tick();
    eight.tick();
    nine.tick();
}

void KeyPad::addDigit(int digit) {
    if (number != 0) {
        number = number * 10 + digit;
    } else {
        number = digit;
    }
}

void KeyPad::resetNumber() {
    number = 0;
}

int KeyPad::getNumber() {
    return number;
}
