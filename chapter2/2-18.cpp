// Author:	LHD
// System:	Win 10
// Problem:	2.18
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cout << "Please enter two integers separated by spaces:" << endl;
	cin >> a >> b;
	if (a == b) {
		cout << "These numbers are equal." << endl;
	}
	else {
		cout << (a > b ? a : b) << "is larger." << endl;
	}
	return 0;
 }