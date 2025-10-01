#include "Point3D.h"
#include <iostream>

using namespace std;

void Point3D::fillPoint()
{
    cout << "x = ";
    cin >> x;

    cout << "y = ";
    cin >> y;

    cout << "z = ";
    cin >> z;
}

void Point3D::printPoint()
{
    cout << "(x:" << x << ", y:" << y << ", z:" << z << ")\n";
}

//сеттеры
void Point3D::setX(const double newX) { x = newX; }
void Point3D::setY(const double newY) { y = newY; }
void Point3D::setZ(const double newZ) { z = newZ; }

//геттеры
double Point3D::getX() { return x; }
double Point3D::getY() { return y; }
double Point3D::getZ() { return z; }

void Point3D::saveToFile(const char* path)
{
    FILE* file;
    fopen_s(&file, path, "w");
    if (file != nullptr)
    {
        int written = fprintf_s(file, "%f %f %f", x, y, z);
        if (written < 0)
            cout << "Ошибка при записи\n";
        else
            cout << "Запись успешна";

        fclose(file);
    }
}
void Point3D::loadFromFile(const char* path)
{
    FILE* file;
    fopen_s(&file, path, "r");
    if (file != nullptr)
    {
        fscanf_s(file, "%lf %lf %lf", &x, &y, &z);
        fclose(file);
    }
}