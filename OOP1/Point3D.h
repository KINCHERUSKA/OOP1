#pragma once
#include<iostream>

using namespace std;

class Point3D
{
protected:
    double x;
    double y;
    double z;
public:
    void fillPoint();
    void printPoint();

    void setX(const double newX);
    void setY(const double newY);
    void setZ(const double newZ);

    double getX();
    double getY();
    double getZ();

    void saveToFile(const char* path);
    void loadFromFile(const char* path);
};
