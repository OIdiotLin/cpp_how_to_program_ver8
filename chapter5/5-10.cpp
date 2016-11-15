// Author:	LHD
// System:	Win 10
// Problem:	5.10
#include <iostream>
using namespace std;

long long fac[21] = { 1,1,0 };

long long factorial(int x) {
	return fac[x] ? fac[x] : fac[x] = factorial(x - 1)*x;
}

int main() {
	for (int i = 1;i <= 5;i++) {
		cout <<i<<"! =\t" << factorial(i) << endl;
	}
	return 0;
}