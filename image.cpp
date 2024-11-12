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

