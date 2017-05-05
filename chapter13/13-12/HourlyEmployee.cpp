#include <sstream>

#include "HourlyEmployee.h"

using std::ostringstream;
using std::endl;


HourlyEmployee::HourlyEmployee(const string & firstName, 
							   const string & lastName,
							   const string & socialSecurityNumber, 
							   int day, int month, int year,
							   double wage, double hours)
	: Employee(firstName, lastName, socialSecurityNumber,
			   day, month, year) {
	this->setWage(wage);
	this->setHours(hours);
}

HourlyEmployee::~HourlyEmployee() {}

HourlyEmployee & HourlyEmployee::setWage(double wage) {
	if (wage < 0) {
		this->wage = 0;
	}
	else {
		this->wage = wage;
	}
	return *this;
}

double HourlyEmployee::getWage() const {
	return this->wage;
}

HourlyEmployee & HourlyEmployee::setHours(double hours) {
	if (hours<0 || hours > hoursPerWeek) {
		this->hours = 0;
	}
	else {
		this->hours = hours;
	}
	return *this;
}

double HourlyEmployee::getHours() const {
	return this->hours;
}

double HourlyEmployee::earnings() const {
	if (getHours() <= 40) {
		return getHours()*getWage();
	}
	else {
		return 40 * getWage() + ((getHours() - 40) * getWage() * 1.5);
	}
}

string HourlyEmployee::toString() const {
	ostringstream oss;
	oss << this->Employee::toString() << endl;
	oss << "Hours: " << getHours() << endl;
	oss << "Earnings: " << earnings() << endl;
	return oss.str();
}

ostream & operator<<(ostream & os, const HourlyEmployee & t) {
	os << t.toString();
	return os;
}
