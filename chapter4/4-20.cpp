// Author:	LHD
// System:	Win 10
// Problem:	4.20
#include <iostream>
using namespace std;
#define TOTAL (10)

int main() {
	int passCount = 0, failCount = 0;
	int studentCount = 0;
	int result;	// 1 for pass, 2 for fail
	while (studentCount < TOTAL) {
		cout << "Enter result (1 = pass, 2 = fail): ";
		cin >> result;
		switch (result) {
		case 1:
			++passCount;
			++studentCount;
			break;
		case 2:
			++failCount;
			++studentCount;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	}
	cout << "Passed " << passCount << endl;
	cout << "Failed " << failCount << endl;
	if (passCount > 8)
		cout << "Bonus to instructor!" << endl;
	return 0;
}