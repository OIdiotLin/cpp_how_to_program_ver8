// Author:	LHD
// System:	Win 10
// Problem:	6.18 (Exponentiation)
#include <iostream>
using namespace std;

long long integerPower(long long base, int exponent) {
	long long res = 1;
	while (exponent) {
		if (exponent & 1)
			res *= base;
		base *= base;
		exponent >>= 1;
	}
	return res;
}

int main() {
	long long base;
	int exponent;
	while (true) {
		cout << "Enter the base and the exponent:" << endl;
		cin >> base >> exponent;
		cout << "integerPower(" << base << ',' << exponent << ") = " << integerPower(base, exponent) << endl << endl;
	}
	return 0;
}