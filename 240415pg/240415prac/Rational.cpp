#include <iostream>
using namespace std;

#include "Rational.h"

void Rational::show() { // 출력
    cout << numerator << '/' << denominator << endl;
}

Rational Rational::operator+(Rational opAdd) { // 덧셈
    Rational add;
    add.denominator = this->denominator * opAdd.denominator;
    add.numerator = this->numerator * opAdd.denominator + opAdd.numerator * this->denominator;

    return add.gcd(add);
}

Rational Rational::operator-(Rational opSub) { // 뺄셈
    Rational sub;
    sub.denominator = this->denominator * opSub.denominator; // 통분
    sub.numerator = this->numerator * opSub.denominator - opSub.numerator * this->denominator;
    if (sub.numerator < 0) sub.numerator /= -1;

    return sub.gcd(sub);
}

Rational Rational::operator*(Rational opMul) {
    Rational mul;
    mul.denominator = this->denominator * opMul.denominator;
    mul.numerator = this->numerator * opMul.numerator;

    mul = mul.gcd(mul);

    return mul;
}

Rational Rational::operator/(Rational opDiv) {
    Rational div;

    div.denominator = this->denominator * opDiv.numerator;
    div.numerator = this->numerator * opDiv.denominator;

    div = div.gcd(div);

    return div;
}

Rational Rational::operator++() {
    numerator += denominator;
    return *this;
}

Rational Rational::operator++(int x) {
    Rational tmp = *this;
    numerator += denominator;
    return tmp;
}

Rational Rational::operator--() {
    numerator -= denominator;
    return *this;
}

Rational Rational::operator--(int x) {
    Rational tmp = *this;
    numerator -= denominator;
    return tmp;
}

Rational operator+ (int op1, Rational op2) {
    Rational tmp;
    tmp.denominator = op2.denominator;
    tmp.numerator = op2.numerator + op1 * op2.denominator;

    return tmp; 
}

Rational Rational::gcd(Rational op) { // 약분
    int tmp = 0, a = op.numerator, b = op.denominator;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    op.numerator /= a;
    op.denominator /= a;
    return op;
}