#include <iostream>
using namespace std;

#include "Circle.h"

int main() {
    Circle donut;
    double area = donut.getArea();
    cout << "donut 면적 " << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적 " << area << endl;
}