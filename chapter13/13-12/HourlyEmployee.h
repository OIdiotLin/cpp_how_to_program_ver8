#ifndef HOURLY_EMPLOYEE_H
#define HOURLY_EMPLOYEE_H

#include <string>
#include <iostream>

#include "Employee.h"

using std::string;
using std::ostream;

class HourlyEmployee : public Employee {
	static const int hoursPerWeek = 24 * 7;

private:
	double wage;
	double hours;

public:
	HourlyEmployee(const string &firstName,
				   const string &lastName, 
				   const string &socialSecurityNumber,
				   int day, int month, int year,
				   double wage = 0, double hours = 0);
	virtual ~HourlyEmployee();

	HourlyEmployee &setWage(double wage);
	double getWage() const;

	HourlyEmployee &setHours(double hour);
	
	double getHours() const;

	virtual double earnings() const;
	virtual string toString() const;

	friend ostream &operator<<(ostream &os, const HourlyEmployee &t);
};

#endif // !HOURLY_EMPLOYEE_H
