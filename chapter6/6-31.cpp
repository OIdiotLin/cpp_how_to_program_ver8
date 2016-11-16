// Author:	LHD
// System:	Win 10
// Problem:	6.31 (Greatest Common Divisor)
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(const int a,const int b) {
	if (!a)	return b;
	if (!b)	return a;
	if (!(a & 1) && !(b & 1))
		return gcd(a >> 1, b >> 1) << 1;
	if (!(a & 1))	return gcd(a >> 1, b);
	if (!(b & 1))	return gcd(b >> 1, a);
	return gcd(abs(a - b), min(a, b));
}

int main() {
	int num1, num2;
	while (true) {
		cout << "Enter two unsigned integers: ";
		cin >> num1 >> num2;
		cout << "gcd( " << num1 << " , " << num2 << " ) = " << gcd(num1, num2) << endl << endl;
	}
	return 0;
}