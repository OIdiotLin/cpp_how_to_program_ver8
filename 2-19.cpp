// Author:	LHD
// System:	Win 10
// Problem:	2.19
#include <iostream>
using namespace std;

int max(int a, int b) {
	return (a > b ? a : b);
}
int max(int a, int b, int c) {
	return max(max(a, b), c);
}
int min(int a, int b) {
	return (a < b ? a : b);
}
int min(int a, int b, int c) {
	return min(min(a, b), c);
}

int main() {
	int a, b, c;
	cout << "Input three different integers: ";
	cin >> a >> b >> c;
	cout << "Sum is " << a + b + c << endl;
	cout << "Average is " << ((a + b + c) / 3.0) << endl;
	cout << "Product is " << a*b*c << endl;
	cout << "Smallest is " << min(a, b, c) << endl;
	cout << "Largest is " << max(a, b, c) << endl;
	return 0;
}