#include <iostream>
#include <cstring>
#include <cstdio>
#include <Windows.h>

#include "Pet.h"
#include "Array.h"
#include "Point3D.h"
#include "Fraction.h"
#include "Point.h"
//#include "Templates.h"

int getSum(int count, int first, ...) {
    int sum = 0;
    int* p = &first;
    while (count--) {
        sum += *p;
        p++;
        p++;
    }
    return sum;
}

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int sum = getSum(5, 1, 2, 3, 4, 5);
    cout << sum << endl;

    return 0;
}

