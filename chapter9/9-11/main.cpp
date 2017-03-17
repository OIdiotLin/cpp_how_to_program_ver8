// Author:	LHD
// System:	Win 10
// Problem:	9.11 (Rectangle Class)

#include <iostream>

#include "Rectangle.h"

using namespace std;

int main() {
	int x, y;
	cout << "input length and width of the rectangle (0~20):" << endl;
	cin >> x >> y;

	Rectangle *shape = new Rectangle(x, y);

	cout << "Perimeter = " << shape->calcPerimeter() << endl;
	cout << "Area = " << shape->calcArea() << endl;

	return 0;
}
