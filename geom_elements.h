#pragma once
#include <iostream>

template <typename T>
class Point {
private:
	float x, y;

public:
	Point(float x, float y);
};

template <typename T>
class Line {
private:
	Point<T> p1, p2;

public:
	Line(Point<T> point1, Point<T> point2);

	bool is_above(const Point<T>& point) const;
};

