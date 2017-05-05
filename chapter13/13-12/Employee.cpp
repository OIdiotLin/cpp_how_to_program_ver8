#include <sstream>

#include "Employee.h"

using std::endl;
using std::ostringstream;

Employee::Employee(const string & firstName,
				   const string & lastName, 
				   const string & socialSecurityNumber,
				   int day, int month, int year) 
	: firstName(firstName), lastName(lastName), socialSecurityNumber(socialSecurityNumber),
	  birthday(day, month, year) {
}

Employee::Employee(const Employee &other) {
	this->setFirstName(other.getFirstName());
	this->setLastName(other.getLastName());
	this->setSocialSecurityNumber(other.getSocialSecurityNumber());
}

Employee & Employee::setFirstName(const string & firstName) {
	this->firstName = firstName;
	return *this;
}

string Employee::getFirstName() const {
	return this->firstName;
}

Employee & Employee::setLastName(const string & lastName) {
	this->lastName = lastName;
	return *this;
}

string Employee::getLastName() const {
	return this->lastName;
}

Employee & Employee::setSocialSecurityNumber(const string & socialSecurityNumber) {
	this->socialSecurityNumber = socialSecurityNumber;
	return *this;
}

string Employee::getSocialSecurityNumber() const {
	return this->socialSecurityNumber;
}

const Date Employee::getBirthday() const {
	return this->birthday;
}

string Employee::toString() const {
	ostringstream oss;
	oss.clear();

	oss << "First Name: " << this->getFirstName() << endl;
	oss << "Last Name: " << this->getLastName() << endl;
	oss << "Birthday: " << this->getBirthday().toString() << endl;
	oss << "Social Security Number: " << this->getSocialSecurityNumber() << endl;

	return oss.str();
}

ostream & operator<<(ostream & os, const Employee & t) {
	os << t.toString();
	return os;
}
