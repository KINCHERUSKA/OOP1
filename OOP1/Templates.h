#pragma once
#include <string.h>

template<class T>
void sort(T array[], size_t size) {
    for (int k = size - 1; k > 0; k--) {
        for (int j = 0; j < k; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

template<class T>
void display(T array[], size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <class T>
T Max(T t1,T t2) {
    return (t1 > t2 ? t1 : t2);
}

template<>
const char* Max<const char*>(const char* t1, const char* t2) {
    return (strcmp(t1, t2) > 0 ? t1 : t2);
}