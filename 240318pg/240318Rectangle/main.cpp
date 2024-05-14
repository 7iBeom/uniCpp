#include <iostream>
using namespace std;

#include "Rectangle.h"

int main() {
    Rectangle rect1;
    Rectangle rect2(11);
    Rectangle rect3(12, 8);

    cout << "rect1: " << rect1.getArea() << endl;
    cout << "rect2: " << rect2.getArea() << endl;
    cout << "rect2: " << rect3.getArea() << endl;

    return 0;
}