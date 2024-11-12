#include <iostream>
#include "geom_elements.h"

Point::Point(float x, float y): x(x), y(y) {}

Line::Line(Point<T> point1, Point<T> point2): p1(point1), p2(point2) {}

bool Line::is_above(const Point<T>& point) const {
	float A = p2.y - p1.y;
	float B = p1.x - p2.x;
	float C = (p2.x * p1.y) - (p1.x * p2.y);
	return (A * point.x + B * point.y + C) > 0;
}

