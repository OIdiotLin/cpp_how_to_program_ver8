#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H

#include <string>
#include <iostream>

#include "Employee.h"

using std::string;
using std::ostream;

class SalariedEmployee : public Employee {
private:
	double weeklySalary;

public:
	SalariedEmployee(const string &firstName,
				   const string &lastName, 
				   const string &socialSecurityNumber,
				   int day, int month, int year,
				   double weeklySalary = 0);
	virtual ~SalariedEmployee();

	SalariedEmployee &setWeeklySalary(double salary);
	double getWeeklySalary() const;

	virtual double earnings() const;
	virtual string toString() const;

	friend ostream &operator<<(ostream &os, const SalariedEmployee &t);
};

#endif // !SALARIED_EMPLOYEE_H
