#pragma once
#include <iostream>

enum Quadrants {
	ZeroPoint, First, Second, Third, Fourth,
	XPositive, XNegative, YPositive, YNegative
};

class Point
{
	int x;
	int y;
public:
	Point() = default;
	Point(int pX, int pY) : x{pX}, y{pY}{}

	Point& setX(int pX) { x = pX; return *this; }
	Point& setY(int pY) { y = pY; return *this; }

	int getX() const;
	int getY() const;

	void Show() const;

	friend double distance(const Point& p1, const Point& p2);
	friend int quadrant(const Point& p);
	friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

void quadrantDecode(int quadrant) {
	if (quadrant == Quadrants::ZeroPoint) { std::cout << "Zero Point"; }

	else if (quadrant == Quadrants::First) { std::cout << "First quadrant"; }
	else if (quadrant == Quadrants::Second) { std::cout << "Second quadrant"; }
	else if (quadrant == Quadrants::Third) { std::cout << "Third quadrant"; }
	else if (quadrant == Quadrants::Fourth) { std::cout << "Fourth quadrant"; }

	else if (quadrant == Quadrants::XPositive) { std::cout << "X axis positive"; }
	else if (quadrant == Quadrants::XNegative) { std::cout << "X axis negative"; }
	else if (quadrant == Quadrants::YPositive) { std::cout << "Y axis positive"; }
	else if (quadrant == Quadrants::YNegative) { std::cout << "Y axis negative"; }

}

