// Author:	LHD
// System:	Win 10
// Problem:	5.8
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int number, numberCount;
	int smallest = INT_MAX;
	cout << "Enter the number of values remaining: ";
	cin >> numberCount;
	cout << "Enter the values:" << endl;
	for (int i = 1;i <= numberCount;i++) {
		cin >> number;
		smallest = smallest > number ? number : smallest;
	}
	cout << "The smallest is " << smallest << endl;
	return 0;
}