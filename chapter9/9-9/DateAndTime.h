#include "Date.h"
#include "Time.h"

#ifndef DATE_AND_TIME_H
#define DATE_AND_TIME_H

class DateAndTime {
private:
	Date date;
	Time time;
public:
	DateAndTime();
	DateAndTime(
		int day, int month, int year,
		int hour, int minute, int second);
	~DateAndTime();

	const Date getDate() const;
	const Time getTime() const;

	DateAndTime & tick();

	void printStandard() const;
	void printUniversal() const;
};


#endif // !DATE_AND_TIME_H
