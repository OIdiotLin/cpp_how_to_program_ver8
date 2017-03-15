#include "Date.h"

#include <sstream>
#include <iostream>

const int Date::days[] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

Date::Date(int day, int month, int year) {
	setDate(day, month, year);
}

Date::~Date() {
}

Date & Date::setDate(int day, int month, int year) {
	if (year >= 0 && year <= 9999)
		this->year = year;
	else
		this->year = 2000;

	if (month >= 1 && month <= 12)
		this->month = month;
	else
		this->month = 1;

	if (month == 2 && isLeapYear()) {
		if (day >= 1 && day <= 29)
			this->day = day;
		else
			this->day = 1;
	}
	else {
		if (day >= 1 && day <= days[this->month])
			this->day = day;
		else
			this->day = 1;
	}
	return *this;
}

Date & Date::nextDay() {
	this->day++;
	this->checkDate();
	return *this;
}

void Date::checkDate() {
	if (this->day > ((this->isLeapYear() && this->month == 2) ? 29 : this->days[this->month])) {
		this->day = 1;
		this->month++;
	}
	if (this->month > 12) {
		this->month = 1;
		this->year++;
	}
}

bool Date::isLeapYear() {
	int temp = (this->year % 100) ? (this->year % 4) : (this->year % 400);
	return temp == 0 ? true : false;
}

std::string Date::toString() {
	std::string res;
	std::ostringstream oss;
	oss << this->year << "/" << this->month << "/" << this->day;
	res = oss.str();
	return res;
}
