// Author:	LHD
// System:	Win 10
// Problem:	4.34(a)
#include <iostream>
using namespace std;

long long factorial(int x) {
	if (x == 0)
		return 1;
	long long ans = 1;
	for (int i = 1;i <= x;i++) {
		ans *= i;
	}
	return ans;
}

int main() {
	int n;
	cout << "Enter a nonnegative integer: ";
	cin >> n;
	cout << n << "! = " << factorial(n) << endl;
	return 0;
}