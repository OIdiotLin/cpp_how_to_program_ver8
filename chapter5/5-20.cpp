// Author:	LHD
// System:	Win 10
// Problem:	5.20
#include <iostream>
using namespace std;

#define sqr(x) ((x)*(x))
bool isRightTriangle(const int &side1, const int &side2, const int &hypotenuse) {
	return sqr(side1) + sqr(side2) == sqr(hypotenuse);
}

int main() {
	const int size = 500;
	for (int a = 1;a <= size;a++) {
		for (int b = a;b <= size;b++) {
			for (int c = b;c <= size;c++) {
				if (isRightTriangle(a, b, c))
					cout << "(" << a << "," << b << "," << c << ")" << endl;
			}
		}
	}
	return 0;
}