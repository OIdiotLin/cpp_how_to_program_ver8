#ifndef BASE_PLUS_COMMISSION_EMPLOYEE_H
#define BASE_PLUS_COMMISSION_EMPLOYEE_H

#include <string>
#include <iostream>

#include "CommissionEmployee.h"

using std::string;
using std::ostream;

class BasePlusCommissionEmployee : public CommissionEmployee {
private:
	double baseSalary;

public:
	BasePlusCommissionEmployee(const string &firstName,
				   const string &lastName, 
				   const string &socialSecurityNumber,
				   int day, int month, int year,
				   double grossSales, double commissionRate, 
				   double baseSalary = 0);
	virtual ~BasePlusCommissionEmployee();

	BasePlusCommissionEmployee &setBaseSalary(double baseSalary);
	double getBaseSalary() const;

	virtual double earnings() const;
	virtual string toString() const;

	friend ostream &operator<<(ostream &os, const BasePlusCommissionEmployee &t);
};

#endif // !BASE_PLUS_COMMISSION_EMPLOYEE_H
