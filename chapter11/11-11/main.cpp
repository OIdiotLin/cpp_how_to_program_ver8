// Author:	LHD
// System:	Win 10
// Problem:	11.11 (Polynomial)

#include <iostream>

#include "Polynomial.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	int t;
	cout << "input number of terms in Polynomial A: ";
	cin >> t;
	Polynomial A = Polynomial(t);
	A.inputTerms();
	cout << "input number of terms in Polynomial B: ";
	cin >> t;
	Polynomial B = Polynomial(t);
	B.inputTerms();

	cout << "A: " << A << endl;
	cout << "B: " << B << endl;

	cout << "A+B = " << (A + B) << endl;
	cout << "A-B = " << (A - B) << endl;
	cout << "A*B = " << (A * B) << endl;


	return 0;
}