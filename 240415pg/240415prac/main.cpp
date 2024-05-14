// 연산자 중복을 이용한 유리수(분수)의 사칙연산
// 22213487 권기범

#include <iostream>
using namespace std;

#include "Rational.h"

int main() {
    Rational r1(1,6), r2(5,8), rAdd/*덧셈*/, rSub/*뺄셈*/, rMul/*곱셈*/, rDiv/*나눗셈*/, r9/*2+a*/;

    cout << "덧셈" << endl;
    cout << "r1 = "; r1.show();
    cout << "r2 = "; r2.show();
    cout << "r1 + r2 = ";rAdd = r1+r2;
    rAdd.show();

    cout << "뺄셈" << endl;
    cout << "r1 = "; r1.show();
    cout << "r2 = "; r2.show();
    cout << "r1 - r2 = "; rSub = r1-r2;
    rSub.show();

    cout << "곱셈" << endl;
    cout << "r1 = "; r1.show();
    cout << "r2 = "; r2.show();
    cout << "r1 * r2 = "; rMul = r1*r2;
    rMul.show();

    cout << "나눗셈" << endl;
    cout << "r1 = "; r1.show();
    cout << "r2 = "; r2.show();
    cout << "r1 / r2 = ";rDiv = r1/r2;
    rDiv.show();

    cout << "전위연산자 ++" << endl;
    cout << "r1 = "; r1.show();
    ++r1;
    cout << "r1 = "; r1.show();

    cout << "후위연산자 ++" << endl;
    cout << "r1 = "; r1.show();
    cout << "r2 = "; r2.show();
    r2 = r1++;
    cout << "r2 = "; r2.show();
    cout << "r1 = "; r1.show();

    cout << "전위연산자 --" << endl;
    cout << "r1 = "; r1.show();
    --r1;
    cout << "r1 = "; r1.show();

    cout << "후위연산자 --" << endl;
    cout << "r1 = "; r1.show();
    cout << "r2 = "; r2.show();
    r2 = r1--;
    cout << "r2 = "; r2.show();
    cout << "r1 = "; r1.show();

    cout << "2 + r1 = 2 + "; r1.show();
    r1 = 2 + r1;
    r1.show();

    return 0;
}
