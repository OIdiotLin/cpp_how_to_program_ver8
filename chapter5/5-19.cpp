// Author:	LHD
// System:	Win 10
// Problem:	5.19
#include <iostream>
#include <iomanip>
using namespace std;

double calc_pi(int termCount) {
	const int sgn[2] = { -1,+1 };
	static double pi = 0;
	return pi += sgn[termCount % 2] * 4.0 / ((termCount << 1) - 1);
}

int main() {
	cout << fixed << setprecision(15);
	for (int i = 1;i <= 1000;i++) {
		cout << "pi = " << calc_pi(i) << endl;
	} 
	return 0;
}