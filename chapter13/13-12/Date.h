#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Date {
private:
	int day;
	int month;
	int year;

	static const int days[];

	Date &extendFix();

public:
	Date(int day = 1, int month = 1, int year = 1900);
	~Date();

	Date &setDate(int day, int month, int year);

	Date &setDay(int day);
	int getDay() const;
	Date &setMonth(int month);
	int getMonth() const;
	Date &setYear(int year);
	int getYear() const;

	Date &nextDay();

	bool isLeapYear() const;

	string toString() const;

};

#endif // !DATE_H
