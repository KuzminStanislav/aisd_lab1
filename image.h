#pragma once 
#include <iostream>
#include <vector>
#include "geom_elements.h"

template <typename T>
class image {
private:
	size_t _width, _height;
	std::vector<std::vector<T>> data;

	void initialize(bool random);
		

public:
	image(size_t w, size_t h, bool random = false);

	T& operator()(size_t x, size_t y);

	const T& operator()(size_t x, size_t y) const;

	image<bool> operator*(const image<bool>& other) const;

	image<bool> operator+(const image<bool>& other) const;

	image<bool> operator*(T scalar) const;

	image<bool> operator+(T scalar) const;

	image<T> operator!() const;

	float fill_coefficient() const;

	void invert_above(const Line<T>& line);

	void print() const;
};