#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

#include "Date.h"

using std::ostream;
using std::string;

class Employee {
private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	Date birthday;

public:
	Employee(const string &firstName = "",
			 const string &lastName = "",
			 const string &socialSecurityNumber = "",
			 int day = 1, int month = 1, int year = 1900);
	Employee(const Employee &other);

	Employee& setFirstName(const string &firstName);
	string getFirstName() const;

	Employee& setLastName(const string &lastName);
	string getLastName() const;

	Employee& setSocialSecurityNumber(const string &socialSecurityNumber);
	string getSocialSecurityNumber() const;

	const Date getBirthday() const;
	
	virtual double earnings() const = 0;
	virtual string toString() const;

	friend ostream &operator<<(ostream &os, const Employee &t);
};

#endif // EMPLOYEE_H
