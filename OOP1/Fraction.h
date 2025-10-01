#pragma once

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

    void setNumerator(int num);
    int getNumerator() const;

    void setDenominator(int denom);
    int getDenominator() const;

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



