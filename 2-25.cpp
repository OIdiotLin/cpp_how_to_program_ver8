// Author:	LHD
// System:	Win 10
// Problem:	2.25
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "Please input 2 integers: ";
	cin >> a >> b;
	cout << a << " is" << ((a%b) ? " not " : " ") << " a multiple of " << b << endl;
	return 0;
}