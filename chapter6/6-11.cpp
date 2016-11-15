// Author:	LHD
// System:	Win 10
// Problem:	6.11
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "a) x = fabs( 7.5 )\t= " << fabs(7.5) << endl;
	cout << "b) x = floor( 7.5 )\t= " << floor(7.5) << endl;
	cout << "c) x = fabs( 0.0 )\t= " << fabs(0.0) << endl;
	cout << "d) x = ceil( 0.0 )\t= " << ceil(0.0) << endl;
	cout << "e) x = fabs( -6.4 )\t= " << fabs(-6.4) << endl;
	cout << "f) x = ceil( -6.4 )\t= " << ceil(-6.4) << endl;
	cout << "g) x = ceil( -fabs( -8 + floor( -5.5 ) ) )\t= " << ceil(-fabs(-8 + floor(-5.5))) << endl;
	return 0;
}