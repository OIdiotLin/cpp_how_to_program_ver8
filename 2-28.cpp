// Author:	LHD
// System:	Win 10
// Problem:	2.28
#include <iostream>
#include <cmath>
using namespace std;

// Use the integer division and modulus operators INSTEAD OF String.
int main() {
	int number, currentDigit, zeros;
	cout << "Please input a five-digit integer: ";
	cin >> number;
	for (int i = 4;i >= 1;i--) {
		zeros = (int)pow(10, i);
		currentDigit = number / zeros;
		number %= zeros;
		cout << currentDigit << "   ";		// Output four digits from left to right
	}
	cout << number << endl;		// Output the last digit
	return 0;
}