#include <iostream>
#include <cstring>
#include <cstdio>
#include <Windows.h>

#include "Pet.h"

using namespace std;

class Fraction {
    int numerator;
    int denominator;
    int gcd(int a, int b);
    void reduce();

public:
    Fraction(int num, int denom) : numerator{ num }, denominator{ denom ? denom : 1 }
    {
        reduce();
    };

    Fraction() : Fraction(1, 1) {};

    void setNumerator(int num) {
        numerator= num; reduce();
    };

    int getNumerator() const {
        return numerator;
    }

    void setDenominator(int denom) {
        denominator = denom ? denom : 1; reduce();
    };

    int getDenominator() const { return denominator; }

    void print(const Fraction& one) const;

    // Перегрузка оператора +
    friend Fraction operator+(const Fraction& left, const Fraction& right);
    friend Fraction operator+(const Fraction& left, int right);
    friend Fraction operator+(int left, const Fraction& right);

    // Перегрузка оператора -
    friend Fraction operator-(const Fraction& left, const Fraction& right);
    friend Fraction operator-(const Fraction& left, int right);
    friend Fraction operator-(int left, const Fraction& right);

    // Перегрузка оператора *
    friend Fraction operator*(const Fraction& left, const Fraction& right);
    friend Fraction operator*(const Fraction& left, int right);
    friend Fraction operator*(int left, const Fraction& right);

    // Перегрузка оператор /
    friend Fraction operator/(const Fraction& left, const Fraction& right);
    friend Fraction operator/(const Fraction& left, int right);
    friend Fraction operator/(int left, const Fraction& right);
};

int Fraction::gcd(int a, int b) {
    int copy;
    while (b) {
        a %= b;
        copy = a;
        a = b;
        b = copy;
    }

    return a;
}

void Fraction::reduce() {
    int gcdVal{
        gcd(numerator, denominator)
    };
    numerator /= gcdVal;
    denominator /= gcdVal;

    if (denominator < 0 and numerator < 0) {
        denominator *= -1;
        numerator *= -1;
    }
}

void Fraction::print(const Fraction& one) const {
    cout << '(' << numerator << " / " << denominator << ")";
    cout << '(' << one.numerator << " / " << one.denominator << ")";
}

Fraction operator+(const Fraction& left, const Fraction& right) {
    return Fraction(left.numerator * right.denominator + right.numerator * left.denominator,
        left.denominator * right.denominator);
}

Fraction operator+(const Fraction& left, int right) {
    return Fraction(left.numerator + right * left.denominator,left.denominator);
}

Fraction operator+(int left, const Fraction& right) {
    return right + left;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    return 0;
}

