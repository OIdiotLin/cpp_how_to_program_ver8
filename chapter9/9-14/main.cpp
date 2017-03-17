// Author:	LHD
// System:	Win 10
// Problem:	9.14 (HugeInteger Class)

#include <iostream>

#include "HugeInteger.h"

using namespace std;

int main() {
	string s1, s2;
	cout << "input two numbers(a>b):" << endl;
	cin >> s1 >> s2;

	HugeInteger a = HugeInteger(s1.c_str());
	HugeInteger b = HugeInteger(s2.c_str());

	cout << a << " < " << b << " : " << (a < b ? "true" : "false") << endl;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	
	return 0;
}