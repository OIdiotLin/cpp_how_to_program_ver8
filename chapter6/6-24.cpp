// Author:	LHD
// System:	Win 10
// Problem:	6.24 (Separating Digits)
#include <iostream>
using namespace std;

// Part a)
int quotient(const int& dividend, const int& divisor) {
	return dividend / divisor;
}

//Part b)
int remainder(const int& dividend, const int& divisor) {
	return dividend%divisor;
}

// Part c)
void separate(int number) {
	int divisor = 10000;
	while (number < divisor)
		divisor = quotient(divisor, 10);
	while (divisor) {
		cout << quotient(number, divisor) << " ";
		number = remainder(number, divisor);
		divisor = quotient(divisor, 10);
	}
	cout << endl << endl;
}

int main() {
	int number;
	while (true) {
		cout << "Enter a number (1~32767): ";
		cin >> number;
		if (number < 1 || number >32767) {
			cout << "OVERFLOW!!" << endl;
			continue;
		}
		separate(number);
	}
	return 0;
}