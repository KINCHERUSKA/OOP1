#pragma once
#include <iostream>

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



