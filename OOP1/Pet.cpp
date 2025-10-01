#pragma once
#include "Pet.h"
#include <iostream>

// Заполнить информацию о животном
void Pet::fillPet()
{
    cout << "Введите кличку: ";
    cin.getline(name, NAME_SIZE);

    int newAge;
    cout << "Введите возраст: ";
    cin >> newAge;
    setAge(newAge);
}

void Pet::showInfo()
{
    cout << "Кличка: " << name << endl;
    cout << "Возраст: " << age << endl;
}

void Pet::setName(const char* newName)
{
    strcpy_s(name, newName);
}

void Pet::setAge(const unsigned newAge)
{
    // age = NewAge если (newAge <= 100) - true, но если возраст false устанавливаем в переменную 100
    age = newAge <= 100 ? newAge : 100;
}
