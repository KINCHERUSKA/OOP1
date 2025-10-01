#include "Array.h"


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
    std::cout << array[index] << " ";
}

void display(const Array& array) {
    for (int i = 0; i < array.getSize(); i++) {
        array.display(i);
    }
    std::cout << std::endl;
}
