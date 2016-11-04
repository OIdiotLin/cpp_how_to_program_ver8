// Author:	LHD
// System:	Win 10
// Problem:	5.9
#include <iostream>
using namespace std;

int main() {
	int prod = 1;
	for (int i = 1;i <= 15;i += 2) {
		prod *= i;
	}
	cout << "The product of the odd integers from 1 to 15 is " << prod << endl;
	return 0;
}