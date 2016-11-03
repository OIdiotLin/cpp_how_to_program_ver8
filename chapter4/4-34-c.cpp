// Author:	LHD
// System:	Win 10
// Problem:	4.34(c)
#include <iostream>
#include <iomanip>
using namespace std;

long long fac[21] = { 1,1,0 };
long long pwr[21] = { 1 };

long long factorial(int x) {
	return fac[x] ? fac[x] : fac[x] = factorial(x - 1)*x;
}

long long power(int x, int p) {
	return pwr[p] ? pwr[p] : pwr[p] = pwr[p - 1] * x;
}

double calc(int x, int termsTotal) {
	double ans = 1;
	for (int i = 1;i <= termsTotal;i++) {
		ans += (double)power(x,i) / factorial(i);
	}
	return ans;
}

int main() {
	cout << fixed << setprecision(15);
	int n, x;
	cout << "Enter x (e^x): ";
	cin >> x;
	cout << "Enter the number of terms in the summation in the formula: ";
	cin >> n;
	cout << "e^" << x << " = " << calc(x, n) << endl;
	return 0;
}