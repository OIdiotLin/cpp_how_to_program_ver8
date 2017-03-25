// Author:	LHD
// System:	Win 10
// Problem:	10.9 (Time Class)

#include <iostream>

#include "Time.h"

using namespace std;

int main() {
	Time t;
	t.setHour(19).setMinute(30).setSecond(22);

	cout << "Universal Time: " << t.toStringUniversal() << endl;

	cout << "Standard Time: " << t.toStringStandard() << endl;

	t.setTime(8, 20, 30);
	cout << "New Time: " << t.toStringStandard() << endl;

	return 0;
}

