// Author:	LHD
// System:	Win 10
// Problem:	5.11
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double deposit(double rate, double principal, int year) {
	return principal*pow(1.0 + rate, year);
}

int main() {
	cout << fixed << setprecision(2);
	cout << "Rate" << setw(21) << "Amount on deposit" << endl;
	for (double rate = 0.05;rate <= 0.1;rate += 0.01) {
		cout << setw(4) << rate << setw(21) << deposit(rate, 1000, 10) << endl;
	}
	return 0;
}
