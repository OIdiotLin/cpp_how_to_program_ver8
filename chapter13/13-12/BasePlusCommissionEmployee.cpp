#include <sstream>

#include "BasePlusCommissionEmployee.h"

using std::ostringstream;
using std::endl;


BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string & firstName, 
							   const string & lastName,
							   const string & socialSecurityNumber, 
							   int day, int month, int year,
							   double grossSales, double commissionRate,
							   double baseSalary)
	: CommissionEmployee(firstName,lastName,socialSecurityNumber,
						 day,month,year,
						 grossSales, commissionRate) {
	this->setBaseSalary(baseSalary);
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {}

BasePlusCommissionEmployee & BasePlusCommissionEmployee::setBaseSalary(double baseSalary) {
	this->baseSalary = ((baseSalary < 0) ? 0 : baseSalary);
	return *this;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
	return this->baseSalary;
}


double BasePlusCommissionEmployee::earnings() const {
	return getBaseSalary() + this->CommissionEmployee::earnings();
}

string BasePlusCommissionEmployee::toString() const {
	ostringstream oss;
	oss << this->Employee::toString() << endl;
	oss << "Base Salary: " << getBaseSalary() << endl;
	oss << "Total Earnings: " << earnings() << endl;
	return oss.str();
}

ostream & operator<<(ostream & os, const BasePlusCommissionEmployee & t) {
	os << t.toString();
	return os;
}
