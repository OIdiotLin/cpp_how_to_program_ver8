// Author:	LHD
// System:	Win 10
// Problem:	7.15 (Duplicate Elimination)
#include <iostream>
using namespace std;

int main() {
	int numbers[20];
	int cnt = 0;
	const int totalNumber = 20;

	for (int i = 0, number;i < totalNumber;i++) {
		cin >> number;
		if (number >= 10 && number <= 100) {
			bool duplicationFound = false;
			for (int j = 0;j < cnt;j++) {
				if (numbers[j] == number) {
					duplicationFound = true;
					break;
				}
			}
			if (!duplicationFound)
				numbers[cnt++] = number;
		}
	}

	for (int i = 0;i < cnt;i++)
		cout << numbers[i] << " ";
	return 0;
}