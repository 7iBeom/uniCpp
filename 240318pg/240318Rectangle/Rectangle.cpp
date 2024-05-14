#include <iostream>
using namespace std;

#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(1, 1) {}

Rectangle::Rectangle(int len) : Rectangle(len, len) {}

Rectangle::Rectangle(int w, int h) {
    width = w;
    height = h;
}

double Rectangle::getArea() {
    return width * height;
}