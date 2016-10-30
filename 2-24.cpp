// Author:	LHD
// System:	Win 10
// Problem:	2.24
#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "Please input an integer: ";
	cin >> number;
	// if n % 2 == 0, n is even. Otherwise, n is odd.
	cout << number << " is " << ((number % 2) ? "odd" : "even") << endl;
	return 0;
}