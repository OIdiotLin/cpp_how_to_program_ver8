#include <sstream>

#include "CommissionEmployee.h"

using std::ostringstream;
using std::endl;


CommissionEmployee::CommissionEmployee(const string & firstName, 
							   const string & lastName,
							   const string & socialSecurityNumber, 
							   int day, int month, int year,
							   double grossSales, double commissionRate)
	: Employee(firstName,lastName,socialSecurityNumber,day,month,year) {
	this->setGrossSales(grossSales);
	this->setCommissionRate(commissionRate);
}

CommissionEmployee::~CommissionEmployee() {}

CommissionEmployee & CommissionEmployee::setGrossSales(double grossSales) {
	this->grossSales = ((grossSales < 0) ? 0 : grossSales);
	return *this;
}

double CommissionEmployee::getGrossSales() const {
	return this->grossSales;
}

CommissionEmployee & CommissionEmployee::setCommissionRate(double commissionRate) {
	this->commissionRate = ((commissionRate < 0 || commissionRate > 1) ? 0 : commissionRate);
	return *this;
}

double CommissionEmployee::getCommissionRate() const {
	return this->commissionRate;
}

double CommissionEmployee::earnings() const {
	return getCommissionRate()*getGrossSales();
}

string CommissionEmployee::toString() const {
	ostringstream oss;
	oss << this->Employee::toString() << endl;
	oss << "Gross Sales: " << getGrossSales() << endl;
	oss << "Commission Rate" << getCommissionRate() << endl;
	oss << "Total Earnings: " << earnings() << endl;
	return oss.str();
}

ostream & operator<<(ostream & os, const CommissionEmployee & t) {
	os << t.toString();
	return os;
}
