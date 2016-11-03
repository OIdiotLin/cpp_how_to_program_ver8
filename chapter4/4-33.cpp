// Author:	LHD
// System:	Win 10
// Problem:	4.33
#include <iostream>
using namespace std;

bool isRightTriangle(const int &a, const int &b, const int &c) {
	return (a == b && b == c);
}

int main() {
	int a, b, c;	// 3 sides
	cout << "Enter 3 integer as 3 sides: ";
	cin >> a >> b >> c;
	cout << "They are " << (isRightTriangle(a, b, c) ? "" : "not ") << "the sides of a right triangle." << endl;
	return 0;
}