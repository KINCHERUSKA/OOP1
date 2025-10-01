#pragma once
#include "Pet.h"
#include <iostream>

// ��������� ���������� � ��������
void Pet::fillPet()
{
    cout << "������� ������: ";
    cin.getline(name, NAME_SIZE);

    int newAge;
    cout << "������� �������: ";
    cin >> newAge;
    setAge(newAge);
}

void Pet::showInfo()
{
    cout << "������: " << name << endl;
    cout << "�������: " << age << endl;
}

void Pet::setName(const char* newName)
{
    strcpy_s(name, newName);
}

void Pet::setAge(const unsigned newAge)
{
    // age = NewAge ���� (newAge <= 100) - true, �� ���� ������� false ������������� � ���������� 100
    age = newAge <= 100 ? newAge : 100;
}
