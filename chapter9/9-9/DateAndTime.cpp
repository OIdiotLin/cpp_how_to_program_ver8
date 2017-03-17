#include "DateAndTime.h"

#include <iostream>

DateAndTime::DateAndTime()
{
}

DateAndTime::DateAndTime(int day, int month, int year, int hour, int minute, int second) {
	this->time.setTime(hour, minute, second);
	this->date.setDate(day, month, year);
}


DateAndTime::~DateAndTime()
{
}

const Date DateAndTime::getDate() const {
	return this->date;
}

const Time DateAndTime::getTime() const {
	return this->time;
}

DateAndTime & DateAndTime::tick() {
	this->time.tick();
	if (this->time.getHour() == 0 &&
		this->time.getMinute() == 0 && 
		this->time.getSecond() == 0) {
		this->date.nextDay();
	}
	return *this;
}

void DateAndTime::printStandard() const {
	std::cout << this->getDate().toString() << " ";
	this->getTime().printStandard();
}

void DateAndTime::printUniversal() const {
	std::cout << this->getDate().toString() << " ";
	this->getTime().printUniversal();
}
