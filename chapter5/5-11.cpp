// Author:	LHD
// System:	Win 10
// Problem:	5.10
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

}
