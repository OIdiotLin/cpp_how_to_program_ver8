// Author:	LHD
// System:	Win 10
// Problem:	9.13 (Enhancing Rectangle Class)

#include <iostream>

#include "Rectangle.h"

int main() {
	Rectangle *rect = new Rectangle(
		Point(4, 4), Point(16, 4), Point(16, 14), Point(4, 14));

	rect->setFillCharacter('*');
	rect->setPerimeterCharacter('#');

	rect->draw();

	return 0;
}