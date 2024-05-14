#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y;
public:
    void set(int x, int y) {this->x = x; this->y = y;}
    void showPoint() {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class ColorPoint: public Point {
    string color;
public:
    void setColor(string color) {this->color = color; }
    void showColorPoint();
};

void ColorPoint::showColorPoint() {
    cout << color << ":";
    showPoint();
}

int main() {
    Point p;
    ColorPoint cp;
    cp.set(3,4);
    cp.setColor("Red");
    cp.showColorPoint();

    // 업 캐스팅
    ColorPoint cp1;
    ColorPoint *pDer = &cp1;
    Point *pBase = pDer;

    pDer->set(3,4);
    pBase->showPoint();
    pDer->setColor("Red");
    pDer->showColorPoint();

    // 다운 캐스팅
    pDer = (ColorPoint*)pBase;
    pDer->setColor("Red");
    pDer->showColorPoint();
}
