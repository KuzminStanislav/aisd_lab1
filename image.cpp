#include <iostream>
#include <vector>
#include "image.h"
#include "geom_elements.h"

void image::initialize(bool random) {
	if (random) {
		for (size_t i = 0; i < _height; ++i) {
			for (size_t j = 0; j < _width; ++j) {
				if constexpr (std::is_same < T, bool::value) {
					data[i][j] = rand() % 2; //0 or 1 for bool
				}
				else {
					data[i][j] = static_cast<T>(rand() % 256); // Random for char
				}
			}
		}
	}
	else {
		for (size_t i = 0; i < _height; ++i) {
			std::fill(data[i].begin(), data[i].end(), static_cast<T>(0)); // all - 0
		}
	}
}

image::image(size_t w, size_t h, bool random = false) : _width(w), _height(h), data(h, std::vector<T>(w)) { initialize(random); } // constructor

T& image::operator()(size_t x, size_t y) { //access operator
	return data[y][x];
}

const T& image::operator()(size_t x, size_t y) const {
	return data[y][x];
}

image<bool> image::operator*(const image<bool>& other) const { // * for bool
	image<bool> result(_width, _height);
	for (size_t i = 0; i < _height; ++i) {
		for (size_t j = 0; j < _width; ++j) {
			result(i, j) = this->data[i][j] && other.data[i][j];
		}
	}
	return result;
}

image<bool> image::operator+(const image<bool>& other) const { // + for bool
	image<bool> result(_width, _height);
	for (size_t i = 0; i < _height; ++i) {
		for (size_t j = 0; j < _width; ++j) {
			result(i, j) = this->data[i][j] || other.data[i][j];
		}
	}
	return result;
}

image<bool> image::operator*(T scalar) const { // * with scalar
	image<bool> result(_width, _height);
	for (size_t i = 0; i < _height; ++i) {
		for (size_t j = 0; j < _width; ++j) {
			result(i, j) = std::min(static_cast<T>(data[i][j] * scalar), static_cast<T>(255)); // for char
		}
	}
	return result;
}

image<bool> image::operator+(T scalar) const { // + with scalar
	image<bool> result(_width, _height);
	for (size_t i = 0; i < _height; ++i) {
		for (size_t j = 0; j < _width; ++j) {
			result(i, j) = std::min(static_cast<T>(data[i][j] + scalar), static_cast<T>(255)); // for char
		}
	}
	return result;
}