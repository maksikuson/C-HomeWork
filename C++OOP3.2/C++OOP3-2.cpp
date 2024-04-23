#include <iostream>
using namespace std;

class Drib {
private:
    int numerator;
    int denominator;

public:
    Drib(int num, int denom) : numerator(num), denominator(denom) {}

    Drib operator+(const Drib& other) const 
    {
        int resultNum = numerator * other.denominator + other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Drib(resultNum, resultDenom);
    }

    Drib operator-(const Drib& other) const 
    {
        int resultNum = numerator * other.denominator - other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Drib(resultNum, resultDenom);
    }

    Drib operator*(const Drib& other) const 
    {
        int resultNum = numerator * other.numerator;
        int resultDenom = denominator * other.denominator;
        return Drib(resultNum, resultDenom);
    }

    Drib operator/(const Drib& other) const 
    {
        int resultNum = numerator * other.denominator;
        int resultDenom = denominator * other.numerator;
        return Drib(resultNum, resultDenom);
    }

    void setShow() const {
        cout << numerator << "/" << denominator;
    }
};

int main()
{
    Drib f1(1, 2);
    Drib f2(1, 3);

    Drib sum = f1 + f2;
    Drib difference = f1 - f2;
    Drib product = f1 * f2;
    Drib quotient = f1 / f2;

    cout << "Sum: ";
    sum.setShow();
    cout << endl;

    cout << "difference: ";
    difference.setShow();
    cout << endl;

    cout << "Product: ";
    product.setShow();
    cout << endl;

    cout << "Quotient: ";
    quotient.setShow();
    cout << endl;
}