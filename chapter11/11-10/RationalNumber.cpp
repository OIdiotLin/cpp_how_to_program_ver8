#include "RationalNumber.h"

#include <sstream>
#include <algorithm>

using std::ostringstream;
using std::cerr;
using std::swap;
using std::endl;

inline int gcd(int x, int y) {
	if (x > y) swap(x, y);
	if (x == 0) return y;
	else return gcd(y%x, x);
}

inline int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}

string RationalNumber::toString() const {
	ostringstream oss;
	oss.clear();
	oss << this->numberator << "/" << this->denominator;
	return oss.str();
}

RationalNumber & RationalNumber::setNumberator(int x) {
	this->numberator = x;
	return *this;
}

RationalNumber & RationalNumber::setDenominator(int x) {
	if (x == 0) {
		cerr << "Cannot set denominator as 0" << endl;
		this->denominator = 1;
	}
	else if (x < 0) {
		cerr << "Cannot set denominator as a negative number" << endl;
		this->denominator = 1;
	}
	else {
		this->denominator = x;
	}
	return *this;
}

int RationalNumber::getNumberator() const {
	return this->numberator;
}

int RationalNumber::getDenominator() const {
	return this->denominator;
}

RationalNumber & RationalNumber::reduce() {
	int _gcd = gcd(this->getDenominator(), this->getNumberator());
	this->denominator /= _gcd;
	this->numberator /= _gcd;
	return *this;
}

RationalNumber::RationalNumber(int numberator, int denominator) {
	this->setDenominator(denominator);
	this->setNumberator(numberator);
	this->reduce();
}

RationalNumber::RationalNumber(const RationalNumber & t) {
	this->denominator = t.denominator;
	this->numberator = t.numberator;
}

RationalNumber::~RationalNumber()
{
}

RationalNumber RationalNumber::operator+(const RationalNumber &t) const {
	RationalNumber result;
	result.setDenominator(this->getDenominator() * t.getDenominator())
		.setNumberator(this->getDenominator() * t.getNumberator()
			+ this->getNumberator() * t.getDenominator()).reduce();
	return result;
}

RationalNumber RationalNumber::operator-(const RationalNumber &t) const {
	RationalNumber result;
	result.setDenominator(this->getDenominator() * t.getDenominator())
		.setNumberator(this->getDenominator() * t.getNumberator()
			- this->getNumberator() * t.getDenominator()).reduce();
	return result;
}

RationalNumber RationalNumber::operator*(const RationalNumber &t) const {
	RationalNumber result;
	result.setDenominator(this->getDenominator() * t.getDenominator())
		.setNumberator(this->getNumberator() * t.getNumberator()).reduce();
	return result;
}

RationalNumber RationalNumber::operator/(const RationalNumber &t) const {
	return *this * t.reciprocal();
}

RationalNumber RationalNumber::reciprocal() const {
	return RationalNumber(this->getDenominator(), this->getNumberator());
}

bool RationalNumber::operator==(const RationalNumber &t) const {
	return this->getDenominator() == t.getDenominator() && this->getNumberator() == t.getNumberator();
}

bool RationalNumber::operator!=(const RationalNumber &t) const {
	return !(*this == t);
}

bool RationalNumber::operator<(const RationalNumber &t) const {
	return this->getNumberator() * t.getDenominator() < this->getDenominator() * t.getNumberator();
}

bool RationalNumber::operator<=(const RationalNumber &t) const {
	return *this < t || *this == t;
}

bool RationalNumber::operator>(const RationalNumber &t) const {
	return t < *this;
}

bool RationalNumber::operator>=(const RationalNumber &t) const {
	return t < *this || t == *this;
}

ostream & operator<<(ostream & os, const RationalNumber & t) {
	os << t.toString();
	return os;
}

istream & operator >> (istream & is, RationalNumber & t) {
	int n, d;
	char x;
	is >> n >> x >> d;
	t.setNumberator(n).setDenominator(d).reduce();
	return is;
}
