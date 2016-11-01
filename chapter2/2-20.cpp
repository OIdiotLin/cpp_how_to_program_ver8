// Author:	LHD
// System:	Win 10
// Problem:	2.20
#include <iostream>
#define sqr(x) ((x)*(x))
const double pi = 3.14159;
using namespace std;

int main() {
	int radius;
	cout << "Input the radius of a circle as an integer: ";
	cin >> radius;
	cout << "diameter = " << (radius << 1) << endl;	// diameter = radius * 2
	cout << "circumference = " << 2 * pi*radius << endl;	// circumference = 2 * pi*radius
	cout << "area = " << pi*sqr(radius) << endl;	// area = pi*radius^2
	return 0;
}