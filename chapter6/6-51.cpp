// Author:	LHD
// System:	Win 10
// Problem:	6.51 (Pass-by-Value vs. Pass-by-Reference)
#include <iostream>
using namespace std;

int tripleByValue(int number) {
	return number *= 3;
}
void tripleByReference(int& number) {
	number *= 3;
}

int main() {
	int number;
	cout << "Enter a integer: ";
	cin >> number;
	cout << endl;
	// using call by value
	cout << "before calling tripleByValue():\t" << number << endl;
	cout << "value returned by tripleByValue():\t" << tripleByValue(number) << endl;
	cout << "after calling tripleByValue():\t" << number << endl << endl;
	// using call by reference
	cout << "before calling tripleByReference():\t" << number << endl;
	tripleByReference(number);
	cout << "after calling tripleByReference():\t" << number<<endl;
	return 0;
}