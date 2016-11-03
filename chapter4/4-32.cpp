// Author:	LHD
// System:	Win 10
// Problem:	4.32
#include <iostream>
#include <cmath>
using namespace std;

bool isTriangle(const double &a, const double &b, const double &c) {
	return ((a + b > c) && (fabs(a - b) < c));
}

int main() {
	double a, b, c;	// 3 sides
	cout << "Enter 3 nonzero double value as 3 sides: ";
	cin >> a >> b >> c;
	cout << "It can " << (isTriangle(a, b, c) ? "" : "not ") << "be a triangle." << endl;
	return 0;
}