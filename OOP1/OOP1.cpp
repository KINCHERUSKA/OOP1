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

void stopProgram(string message) {
    cout << message << endl;
    exit(1);
}

template<class T>
class Array {
    static const size_t size{ 5 };
    T arr[size];

public:
    Array() {
        for (int i = 0; i < size; i++) {
            arr[i] = T();
        }
    }

    int getSize() const {
        return size;
    }

    T getItem(size_t index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        else {
            stopProgram("Index is out of range!");
        }
    }

    void setItem(size_t index, T value) {
        if (index >= 0 && index < size)
        {
            arr[index] = value;
        }
        else {
            stopProgram("Index is out of range!")
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " "
        }
        cout << endl;
    }

    void sort() {
        for (int k = size - 1; k > 0; k--) {
            for (int j = 0; j < k; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                }
            }
        }
    }
};

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Array<int> intArray;
    intArray.display();
    int size = intArray.getSize();
    for (int i = size; i > 0; i--) {
        intArray.setItem(size - i, i);
    }
    cout << "Массив после установки значений" << endl;

    intArray.display();
    intArray.sort();

    cout << "Массив после сортировки" << endl;

    intArray.display();

    return 0;
}

