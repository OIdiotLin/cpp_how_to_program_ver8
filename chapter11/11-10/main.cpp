// Author:	LHD
// System:	Win 10
// Problem:	11.10 (Rational Number)
#include <iostream>

#include "RationalNumber.h"

using std::cout;
using std::cin;
using std::endl;

#define LOOPSTART while(true){
#define LOOPEND }

int main() {
	RationalNumber a, b;
LOOPSTART
	cout << "input fraction A (a/b): ";
	cin >> a;
	cout << "input fraction B (a/b): ";
	cin >> b;

	cout << "Frac A = " << a << endl;
	cout << "Frac B = " << b << endl;

	cout << "A + B = " << a + b << endl;
	cout << "A - B = " << a - b << endl;
	cout << "A * B = " << a * b << endl;
	cout << "A / B = " << a / b << endl;

	cout << "A == B : " << (a == b) << endl;
	cout << "A < B : " << (a < b) << endl;

	cout << endl;
LOOPEND
	return 0;
}