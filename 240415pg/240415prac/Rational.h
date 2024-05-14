#include <iostream>
using namespace std;

class Rational {
    int numerator;
    int denominator;
public:
    Rational(int numerator = 0, int denominator = 0) {
        this->numerator = numerator;
        this->denominator = denominator;
        
        if (numerator%denominator > 0) {
            int tmp = 0, a = this->numerator, b = this->denominator;
            while (b != 0) {
                tmp = a % b;
                a = b;
                b = tmp;
            }
            this->numerator /= a;
            this->denominator /= a;
        }
    }
    void show();
    Rational gcd(Rational);
    Rational operator+(Rational opAdd);
    Rational operator-(Rational opSub);
    Rational operator*(Rational opMul);
    Rational operator/(Rational opDiv);
    Rational operator++();
    Rational operator++(int x);
    Rational operator--();
    Rational operator--(int x);
    friend Rational operator+ (int op1, Rational op2);
};