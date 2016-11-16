// Author:	LHD
// System:	Win 10
// Problem:	6.36 (Recursive Exponentiation)
#include <iostream>
using namespace std;

long long power(long long base, int exponent) {
	if (exponent == 0)
		return 1;
	return base*power(base, exponent - 1);
}

int main() {
	int base, exponent;
	while (true) {
		cout << "Enter the base and the exponent: ";
		cin >> base >> exponent;
		cout << "the result is " << power(base, exponent) << endl << endl;
	}
	return 0;
}