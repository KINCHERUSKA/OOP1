#pragma once
#include <iostream>

using namespace std;

const int NAME_SIZE = 20;

class Pet // Животное
{
public:
    void fillPet();
    void showInfo();
    void setName(const char* newName);
    void setAge(const unsigned newAge);

    unsigned getAge() { return age; }
    const char* getName() { return name; }

private:
    char name[NAME_SIZE];
    unsigned age;
};


