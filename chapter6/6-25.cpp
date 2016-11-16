// Author:	LHD
// System:	Win 10
// Problem:	6.25 (Calculating Number of Seconds)
#include <iostream>
using namespace std;

class Time {
private:
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;
public:
	Time() {}
	Time(unsigned int h, unsigned int m, unsigned int s) :
		hours(h), minutes(m), seconds(s) {}
	unsigned int turnToSecs() const {
		return 3600 * hours + 60 * minutes + seconds;
	}
	int operator - (const Time& b) const {
		return (int)(this->turnToSecs()) - (int)(b.turnToSecs());
	}
};

int main() {
	unsigned int hours, minutes, seconds;
	Time T1, T2;
	while (true) {
		cout << "Enter the first time as 3 unsigned integers:" << endl;
		cin >> hours >> minutes >> seconds;
		T1 = Time(hours, minutes, seconds);
		cout << "Enter the second time as 3 unsigned integers:" << endl;
		cin >> hours >> minutes >> seconds;
		T2 = Time(hours, minutes, seconds);
		cout << "The difference between the two times is " << abs(T2 - T1) << " seconds." << endl << endl;
	}
	return 0;
}