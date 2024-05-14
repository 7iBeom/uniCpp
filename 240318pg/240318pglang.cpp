// rectangle 위임생성자

#include <iostream>
using namespace std;

class Rectangle {
	int width;
	int height;
public:
	Rectangle() : Rectangle(1, 1) {} // 위임생성자
	Rectangle(int len) : Rectangle(len, len) {}
	Rectangle(int w, int h) {
		width = w;
		height = h;
	}
	int getArea();
};

int Rectangle::getArea() {

return width * height;

}

  

  

int main() {

Rectangle rect(3, 5);

Rectangle rect2;

Rectangle rect3(5);

cout << " 사각형의 면적은 " << rect.getArea() << endl;

cout << " 사각형의 면적은 " << rect2.getArea() << endl;

cout << " 사각형의 면적은 " << rect3.getArea() << endl;

return 0;

  

}