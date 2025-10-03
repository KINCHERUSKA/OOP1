#include <iostream>
#include <cstring>
#include <cstdio>
#include <Windows.h>

#include "Pet.h"
#include "Array.h"
#include "Point3D.h"
#include "Fraction.h"
#include "Point.h"
#include "Templates.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int intArray[]{ 1,3,7,-4,-2,4 };
    int size = sizeof(intArray) / sizeof(int);
    cout << "Оригинальный массив" << endl;
    display(intArray, size);
    sort(intArray, size);
    cout << "Сортированый массив" << endl;
    display(intArray, size);

    char charArray[]{ 'd','s','w','g','h'};
    size = sizeof(charArray) / sizeof(char);
    cout << "Оригинальный массив" << endl;
    display<char>(charArray, size);
    sort<char>(charArray, size);
    cout << "Сортированый массив" << endl;
    display<char>(charArray, size);

    return 0;
}

