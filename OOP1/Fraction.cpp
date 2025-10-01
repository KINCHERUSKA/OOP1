#include "Fraction.h"
#include <iostream>

void Fraction::setNumerator(int num) {
    numerator = num; reduce();
};

int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setDenominator(int denom) {
    denominator = denom ? denom : 1; reduce();
};

int Fraction::getDenominator() const { return denominator; }


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
    std::cout << '(' << numerator << " / " << denominator << ")";
    std::cout << '(' << one.numerator << " / " << one.denominator << ")";
}

Fraction operator+(const Fraction& left, const Fraction& right) {
    return Fraction(left.numerator * right.denominator + right.numerator * left.denominator,
        left.denominator * right.denominator);
}

Fraction operator+(const Fraction& left, int right) {
    return Fraction(left.numerator + right * left.denominator, left.denominator);
}

Fraction operator+(int left, const Fraction& right) {
    return right + left;
}
