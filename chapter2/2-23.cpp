// Author:	LHD
// System:	Win 10
// Problem:	2.23
#include <iostream>
using namespace std;

// Use only the programming techniques mentioned in this chapter
int main() {
	int numberRead, numberMax = INT_MIN, numberMin = INT_MAX;
	cout << "Please input 5 integers: ";
	for (int i = 1;i <= 5;i++) {
		cin >> numberRead;
		numberMax = (numberMax < numberRead ? numberRead : numberMax);	// update the Maximum
		numberMin = (numberMin > numberRead ? numberRead : numberMin);	// update the Minimum
	}
	cout << "The largest is " << numberMax << endl;
	cout << "The smallest is " << numberMin << endl;
	return 0;
}