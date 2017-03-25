
#include "Time.h"

Time::Time(int h, int m, int s) {
	setTime(h, m, s);
}

Time::~Time()
{
}

Time & Time::setTime(int h, int m, int s) {
	this->hour = h;
	this->minute = m;
	this->second = s;
	return *this;
}

Time & Time::setHour(int h) {
	this->hour = h;
	return *this;
}

Time & Time::setMinute(int m) {
	this->minute = m;
	return *this;
}

Time & Time::setSecond(int s) {
	this->second = s;
	return *this;
}

int Time::getHour() const {
	return this->hour;
}

int Time::getMinute() const {
	return this->minute;
}

int Time::getSecond() const {
	return this->second;
}

Time & Time::tick() {
	this->second++;
	if (this->second == 60) {
		this->second = 0;
		this->minute++;
	}
	if (this->minute == 60) {
		this->minute = 0;
		this->hour++;
	}
	if (this->hour == 24) {
		this->hour = 0;
	}
	return *this;
}

string Time::toStringUniversal() const {
	ostringstream oss;
	oss << setfill('0')
		<< setw(2) << this->hour << ":"
		<< setw(2) << this->minute << ":"
		<< setw(2) << this->second;
	return oss.str();
}

string Time::toStringStandard() const {
	ostringstream oss;
	oss << setfill('0')
		<< setw(2) << ((this->hour == 0 || this->hour == 12) ? 12 : this->hour % 12) << ":"
		<< setw(2) << this->minute << ":"
		<< setw(2) << this->second << " "
		<< (this->hour >= 12 ? "PM" : "AM");
	return oss.str();
}
