#include <sstream>

#include "SalariedEmployee.h"

using std::ostringstream;
using std::endl;


SalariedEmployee::SalariedEmployee(const string & firstName, 
							   const string & lastName,
							   const string & socialSecurityNumber, 
							   int day, int month, int year,
							   double weeklySalary)
	: Employee(firstName,lastName,socialSecurityNumber,day,month,year),
	  weeklySalary(weeklySalary) {

}

SalariedEmployee::~SalariedEmployee() {}

SalariedEmployee & SalariedEmployee::setWeeklySalary(double salary) {
	if (salary < 0) {
		this->weeklySalary = 0;
	}
	else {
		this->weeklySalary = salary;
	}
	return *this;
}

double SalariedEmployee::getWeeklySalary() const {
	return this->weeklySalary;
}

double SalariedEmployee::earnings() const {
	return getWeeklySalary();
}

string SalariedEmployee::toString() const {
	ostringstream oss;
	oss << this->Employee::toString() << endl;
	oss << "Weekly Salary: " << earnings() << endl;
	return oss.str();
}

ostream & operator<<(ostream & os, const SalariedEmployee & t) {
	os << t.toString();
	return os;
}
