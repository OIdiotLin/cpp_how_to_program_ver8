// Fig. 9.17: Date.h
// Date class declaration.
// Member functions are defined in Date.cpp

#include <string>

// prevent multiple inclusions of header
#ifndef DATE_H
#define DATE_H

// class Date definition
class Date {
private:
	int day;
	int month;
	int year;
	static const int days[];

	void checkDate();

public:
	Date(int day = 1, int month = 1, int year = 2000);
	~Date();

	Date &setDate(int day, int month, int year);
	Date &nextDay();

	bool isLeapYear();

	std::string toString();

};	// end class Date

#endif // !DATE_H
