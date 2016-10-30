// Author:	LHD
// System:	Win 10
// Problem:	2.27
#include <iostream>
using namespace std;

int main() {
	char ch;
	cout << "Please input a character: ";
	cin >> ch;
	cout << "The integer equivalent of " << "\'" << ch << "\' " << "is " << static_cast<int>(ch) << endl;
	return 0;
}