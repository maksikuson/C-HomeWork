#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerators = 0, int denominators = 1) 
    {
        numerator = numerators;
        denominator = denominators;
    }

    void simplify()
    {
        int gcd = gcdCalc(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int gcdCalc(int a, int b) 
    {
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Fraction add(Fraction& other) 
    {
        int resultNumerator = numerator * other.denominator + other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        Fraction result(resultNumerator, resultDenominator);
        result.simplify();
        return result;
    }

    Fraction subtract(Fraction& other) 
    {
        int resultNumerator = numerator * other.denominator - other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        Fraction result(resultNumerator, resultDenominator);
        result.simplify();
        return result;
    }

    Fraction multiply(Fraction& other)
    {
        int resultNumerator = numerator * other.numerator;
        int resultDenominator = denominator * other.denominator;
        Fraction result(resultNumerator, resultDenominator);
        result.simplify();
        return result;
    }

    Fraction divide(Fraction& other)
    {
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
        Fraction result(resultNumerator, resultDenominator);
        result.simplify();
        return result;
    }

    void display()
{
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    int num1, den1, num2, den2;

    cout << "Enter the numerator and denominator for the first fraction:" << endl;
    cin >> num1 >> den1;
    Fraction fraction1(num1, den1);

    cout << "Enter the numerator and denominator for the second fraction:" << endl;
    cin >> num2 >> den2;
    Fraction fraction2(num2, den2);

    cout << "Addition:" << endl;
    Fraction result_add = fraction1.add(fraction2);
    result_add.display();

    cout << "Subtraction:" << endl;
    Fraction result_subtract = fraction1.subtract(fraction2);
    result_subtract.display();

    cout << "Multiplication:" << endl;
    Fraction result_multiply = fraction1.multiply(fraction2);
    result_multiply.display();

    cout << "Division:" << endl;
    Fraction result_divide = fraction1.divide(fraction2);
    result_divide.display();
}
