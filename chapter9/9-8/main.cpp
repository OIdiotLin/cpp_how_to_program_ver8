// Author:	LHD
// System:	Win 10
// Problem:	9.8 (Enhancing Class Date)

#include <iostream>

#include "Date.h"

using namespace std;

int main() {
	const int DAY_INC_LIMIT = 10;

	int startDateDay;
	int startDateMonth;
	int startDateYear;
	
	cout << "input(y m d) : ";
	cin >> startDateYear >> startDateMonth >> startDateDay;

	Date *date = new Date(startDateDay,startDateMonth,startDateYear);

	cout << date->toString() << endl;

	for (int i = 0;i < DAY_INC_LIMIT;i++) {
		cout << date->nextDay().toString() << endl;
	}

	return 0;
}