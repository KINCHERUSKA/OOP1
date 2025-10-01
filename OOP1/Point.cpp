#include "Point.h"

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

void Point::Show() const {
	std::cout << '(' << x << ',' << y << ')';
}

double distance(const Point& p1, const Point& p2){
	auto xLength{ p2.x - p1.x };
	auto yLength{ p2.y - p1.y };
	return sqrt(xLength * xLength + yLength * yLength);
}

int quadrant(const Point& p) {
	if ((!p.y and !p.x)) {
		return Quadrants::ZeroPoint;
	}
	if (!p.y) {
		return p.x > 0 ? Quadrants::XPositive : Quadrants::XNegative;
	}
	if (!p.x) {
		return p.y > 0 ? Quadrants::YPositive : Quadrants::YNegative;
	}
	if (p.y > 0) {
		return p.x > 0 ? Quadrants::First : Quadrants::Second;
	}
	return p.x > 0 ? Quadrants::Fourth : Quadrants::Third;
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
	out << '(' << point.x << ',' << point.y << ')';
	return out;
}