// Author:	LHD
// System:	Win 10
// Problem:	2.29
#include <iostream>
#define sqr(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
using namespace std;

int main() {
	cout << "integer\tsquare\tcube" << endl;
	for (int i = 0;i <= 10;i++) {
		cout << i << "\t" << sqr(i) << "\t" << cube(i) << endl;
	}
	return 0;
}