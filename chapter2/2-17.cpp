// Author:	LHD
// System:	Win 10
// Problem:	2.17
#include <iostream>
using namespace std;

int main() {
	// subtask1: Using one statement with one stream insertion operator.
	cout << "1 2 3 4";
	cout << endl;
	// subtask2: Using one statement with four stream insertion operators.
	cout << "1 " << "2 " << "3 " << "4";
	cout << endl;
	// subtask3: Using four statements.
	cout << 1 << " ";
	cout << 2 << " ";
	cout << 3 << " ";
	cout << 4 << endl;
	return 0;
}