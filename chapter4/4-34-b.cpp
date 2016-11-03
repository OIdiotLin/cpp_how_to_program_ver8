// Author:	LHD
// System:	Win 10
// Problem:	4.34(b)
#include <iostream>
#include <iomanip>
using namespace std;

long long fac[21] = {1,1,0};

long long factorial(int x) {
	return fac[x] ? fac[x] : fac[x] = factorial(x - 1)*x;
}

double calc_e(int termsTotal) {
	double e = 1;
	for (int i = 1;i <= termsTotal;i++) {
		e += 1.0 / factorial(i);
	}
	return e;
}

int main() {
	cout << fixed << setprecision(15);
	int n;
	cout << "Enter the number of terms in the summation in the formula (no more than 20): ";
	cin >> n;
	cout << "e = " << calc_e(n) << endl;
	return 0;
}