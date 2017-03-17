// Author:	LHD
// System:	Win 10
// Problem:	9.9 (Combining Class Time and Class Date)

#include <iostream>
#include <string>

#include "DateAndTime.h"

using namespace std;

int main() {
	// start from 2016/12/31 23:59:56
	DateAndTime *t = new DateAndTime(31, 12, 2016, 23, 59, 56);
	const int LIMIT = 20;

	for (int i = 0;i < LIMIT;i++) {
		
		t->tick().printUniversal();
	}

	return 0;
}