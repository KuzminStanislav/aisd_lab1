#include <iostream>
#include <vector>
#include "image.h"
#include "geom_elements.h"
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	image<char> img(5, 5, true);
	img.print();

	cout << "Filling coeficient" << img.fill_coefficient() << endl;

	image<bool> imgBool(5, 5, true);
	imgBool.print();

	auto imgOr = imgBool + imgBool;
	auto imgAnd = imgBool * imgBool;
	imgOr.print();
	imgAnd.print();

	Point<char> p1(0, 1);
	Point<char> p2(4, 4);
	Line<char> line(p1, p2);

	img.invert_above(line);
	cout << img.print() << endl;

	return 0;
}
