#include "Date.h"
#include <sstream>

using std::ostringstream;

const int Date::days[] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

Date & Date::extendFix() {
	if (this->day > ((this->isLeapYear() && this->month == 2) ? 29 : this->days[this->month])) {
		this->day = 1;
		this->month++;
	}
	if (this->month > 12) {
		this->month = 1;
		this->year++;
	}
}

Date::Date(int day, int month, int year) {
	this->setDate(day, month, year);
}

Date::~Date() {}

Date & Date::setDate(int day, int month, int year) {
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date & Date::setDay(int day) {
	if (day > 0 && 
		(day <= days[getMonth()] || 
		 (isLeapYear() && getMonth() == 2 && day == 29))) {
		this->day = day;
	}
	return *this;
}

int Date::getDay() const {
	return this->day;
}

Date & Date::setMonth(int month) {
	if (month >= 1 && month <= 12) {
		this->month = month;
	}
	return *this;
}

int Date::getMonth() const {
	return this->month;
}

Date & Date::setYear(int year) {
	this->year = year;
}

int Date::getYear() const {
	return this->year;
}

Date & Date::nextDay() {
	this->day++;
	this->extendFix();
	return *this;
}

bool Date::isLeapYear() const {
	int temp = (this->year % 100) ? (this->year % 4) : (this->year % 400);
	return temp == 0 ? true : false;
}

string Date::toString() const {
	ostringstream oss;
	oss.clear();
	oss << getYear() << "/" << getMonth() << "/" << getDay();
	return oss.str();
}
