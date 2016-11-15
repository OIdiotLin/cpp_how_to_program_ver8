// Author:	LHD
// System:	Win 10
// Problem:	6.20 (Multiples)
#include <iostream>
using namespace std;

bool multiple(int x, int y) {	// return true if the second is a multiple of the first
	return !(y%x);
}

int main() {
	int x, y;
	while (true) {
		cout << "Enter a pair of integers (x,y): " << endl;
		cin >> x >> y;
		cout << "multiple(" << x << "," << y << ") = " << multiple(x, y) << endl << endl;
	}
	return 0;
}