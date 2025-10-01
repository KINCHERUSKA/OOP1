#include <iostream>
#include <cstring>
#include <cstdio>
#include <Windows.h>

#include "Pet.h"
#include "Array.h"
#include "Point3D.h"
#include "Fraction.h"
#include "Point.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Point p1{ 5,5 };
    Point p2{ 10,10 };

    cout << "Дистанция между p1: " << p1 << " и p2: " << p2 << " составляет " << distance(p1, p2) << endl;

    const int testCases{ 9 };
    Point points[testCases]{
        {0,0},
        {1,1},
        {-1,1},
        {-1,-1},
        {1,-1},
        {1,0},
        {-1,0},
        {0,1},
        {0,-1},
    };

    for (int i{ 0 }; i < testCases; i++) {
        cout << points[i] << ' ';
        quadrantDecode(quadrant(points[i]));
        cout << endl;
    }

    return 0;
}

