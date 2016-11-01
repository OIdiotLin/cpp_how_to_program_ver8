// Author:	LHD
// System:	Win 10
// Problem:	4.13
#include <iostream>
#include <iomanip>
using namespace std;

double miles, gallons, milesTotal = 0, gallonsTotal = 0;

int main() {
	cout << fixed << setprecision(6);
	while (true) {
		cout << "Enter miles driven (-1 to quit): ";
		cin >> miles;
		if (miles == -1)
			break;
		cout << "Enter gallons used: ";
		cin >> gallons;
		milesTotal += miles;
		gallonsTotal += gallons;
		cout << "MPG this trip: " << miles / gallons << endl;
		cout << "Total MPG: " << milesTotal / gallonsTotal << endl << endl;
	}
	return 0;
}