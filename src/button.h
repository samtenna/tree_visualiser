#pragma once

#include <string>
#include <functional>
#include <raylib.h>

class Button {
public:
    Button(std::string text,
           std::function<void()> action,
           int x,
           int y,
           int width,
           int height,
           Color backgroundColor,
           Color textColor,
           Color backgroundColorHover,
           Color textColorHover)
        : text(text),
          action(action),
          x(x),
          y(y),
          width(width),
          height(height),
          backgroundColor(backgroundColor),
          textColor(textColor),
          backgroundColorHover(backgroundColorHover),
          textColorHover(textColorHover) {}

    Button(std::string text,
           std::function<void()> action,
           int x,
           int y,
           int width,
           int height)
        : text(text),
          action(action),
          x(x),
          y(y),
          width(width),
          height(height),
          backgroundColor(BLACK),
          textColor(WHITE),
          backgroundColorHover(DARKGRAY),
          textColorHover(WHITE) {}

    void draw();
    void tick();

private:
    bool isHovered();

private:
    std::string text;
    std::function<void()> action;
    int x;
    int y;
    int width;
    int height;
    Color backgroundColor;
    Color textColor;
    Color backgroundColorHover;
    Color textColorHover;

    bool mouseWasHovered = false;
};
