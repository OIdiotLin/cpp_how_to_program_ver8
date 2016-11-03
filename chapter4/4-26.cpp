// Author:	LHD
// System:	Win 10
// Problem:	4.26
#include <iostream>
using namespace std;
#define SIZE (5)

int main() {
	char number[SIZE+1];
	bool isPalindrome = true;
	cin >> number;
	for (int i = 0;i < 2;i++) {
		if (number[i] != number[SIZE - 1 - i])
			isPalindrome = false;
	}
	cout << number << " is " << (isPalindrome ? "" : "not ") << "a palindrome." << endl;
	return 0;
}