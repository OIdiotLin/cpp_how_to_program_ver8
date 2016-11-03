// Author:	LHD
// System:	Win 10
// Problem:	4.17
#include <iostream>
using namespace std;
#define TOTAL (10)

int main() {
	int counter = 0;
	int number;
	int largest = INT_MIN;
	cout << "Enter 10 integers (int32): ";
	while (++counter <= TOTAL) {
		cin >> number;
		largest = largest < number ? number : largest;
	}
	cout << "The largest number is " << largest << endl;
	return 0;
}