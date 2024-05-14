#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0; // 순수 가상 함수(또는 추상함수), 개념만 있음, 구현되지 않은 부분이 있기 때문에 객체 생성 불가, 추상함수가 하나라도 있는 클래스는 추상클래스(상속용)으로 오버라이딩을 해야만 사용가능
};

class Circle : public Shape {
    int r;
public:
    Circle(int r) { this->r = r;}
    virtual void area() {
        double a = r * r * 3.14;
        cout << "넓이: " << a << endl;
    }
};

class Rect : public Shape {
    int w, h;
public:
    Rect(int w, int h) { this->w = w; this->h = h;}
    virtual void area() {
        double a = w * h;
        cout << "넓이: " << a << endl;
    }
};

class Triangle : public Shape {
    int w, h;
public:
    Triangle(int w, int h) { this->w = w; this->h = h;}
    virtual void area() {
        double a = (w * h) / 2;
        cout << "넓이: " << a << endl;
    }
};

int main() {
    Shape *s[3];
    s[0] = new Circle(5);
    s[1] = new Rect(3, 5);
    s[2] = new Triangle(2, 8);

    for (int i = 0; i < 3; i++) {
        s[i]->area();
    }

    return 0;

}