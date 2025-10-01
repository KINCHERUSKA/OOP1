#include <iostream>
#include <cstring>
#include <cstdio>
#include <Windows.h>

#include "Pet.h"

using namespace std;

class Point3D
{
protected:
    double x;
    double y;
    double z;
public:
    void fillPoint()
    {
        cout << "x = ";
        cin >> x;

        cout << "y = ";
        cin >> y;

        cout << "z = ";
        cin >> z;
    }

    void printPoint()
    {
        cout << "(x:" << x << ", y:" << y << ", z:" << z << ")\n";
    }

    //сеттеры
    void setX(const double newX) { x = newX; }
    void setY(const double newY) { y = newY; }
    void setZ(const double newZ) { z = newZ; }

    //геттеры
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    void saveToFile(const char* path)
    {
        FILE* file;
        fopen_s(&file, path, "w");
        if (file != nullptr)
        {
            int written = fprintf_s(file, "%f %f %f", x, y, z);
            if (written < 0)
                cout << "Ошибка при записи\n";
            else
                cout << "Запись успешна";

            fclose(file);
        }
    }
    void loadFromFile(const char* path)
    {
        FILE* file;
        fopen_s(&file, path, "r");
        if (file != nullptr)
        {
            fscanf_s(file, "%lf %lf %lf", &x, &y, &z);
            fclose(file);
        }
    }
};


class Point {
    int x;
    int y;
public:
    Point(int pX, int pY) : x{pX}, y{pY} {}
    Point() = default;
    

    Point& setX(int pX) { x = pX; return *this; }
    Point& setY(int pY) { y = pY; return *this; }

    void showPoint() const {
        cout << x << ' ' << y << endl;
    }

    explicit operator bool() const { return x and y; }
};


class Date {
    int day;
    int month;
    int year;

public:
    Date(int dayP, int monthP, int yearP) : day{ dayP }, month{ monthP }, year{ yearP } {}
    Date(int year) : Date(1, 1, year) {
        // Невозвращающая функция
    }
    friend void displayDate(Date date);
//
//    void print() {
//        cout << day << '.' << month << '.' << year << endl;
//    }
//
//    void print(string s) {
//        cout << this << endl;
//    }
//
//    Date& setDay(int dayP) {
//        day = dayP;
//        return *this;
//    }
//    Date& setMonth(int monthP) {
//        month = monthP;
//        return *this;
//    }
//    Date& setYear(int yearP) {
//        year = yearP;
//        return *this;
//    }
};

void displayDate(Date date) {
    cout << date.day << '.' << date.month << '.' << date.year << endl;
}

Date baseDate() {
    return 2000;
}

class Array {
    int size;
    int* array;
public:
    explicit Array(int size = 10);
    ~Array();

    int getSize() const;
    int getValue(int index) const;
    void setValue(int index, int value);
    void display(int index) const;
};

Array::Array(int size) {
    Array::size = size;
    array = new int[size];
}

Array::~Array() {
    delete[] array;
}

int Array::getSize() const {
    return size;
}

int Array::getValue(int index) const {
    return array[index];
}

void Array::setValue(int index, int value) {
    array[index] = value;
}

void Array::display(int index) const {
    cout << array[index] << " ";
}

void display(const Array& array) {
    for (int i = 0; i < array.getSize(); i++) {
        array.display(i);
    }
    cout << endl;
}

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

