#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include <string>
#include <iostream>

#include "Employee.h"

using std::string;
using std::ostream;

class CommissionEmployee : public Employee {
private:
	double grossSales;
	double commissionRate;

public:
	CommissionEmployee(const string &firstName,
				   const string &lastName, 
				   const string &socialSecurityNumber,
				   int day, int month, int year,
				   double grossSales = 0, double commissionRate = 0);
	virtual ~CommissionEmployee();

	CommissionEmployee &setGrossSales(double grossSales);
	double getGrossSales() const;

	CommissionEmployee &setCommissionRate(double commissionRate);
	double getCommissionRate() const;

	virtual double earnings() const;
	virtual string toString() const;

	friend ostream &operator<<(ostream &os, const CommissionEmployee &t);
};

#endif // !COMMISSION_EMPLOYEE_H
