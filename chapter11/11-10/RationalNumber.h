#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class RationalNumber {

private:
	int numberator;
	int denominator;
	RationalNumber & reduce();

public:
	RationalNumber(int numberator = 0, int denominator = 1);
	RationalNumber(const RationalNumber & t);
	~RationalNumber();

	int getNumberator() const;
	int getDenominator() const;
	RationalNumber & setNumberator(int x);
	RationalNumber & setDenominator(int x);

	RationalNumber operator+(const RationalNumber &t) const;
	RationalNumber operator-(const RationalNumber &t) const;
	RationalNumber operator*(const RationalNumber &t) const;
	RationalNumber operator/(const RationalNumber &t) const;

	RationalNumber reciprocal() const;

	bool operator==(const RationalNumber &t) const;
	bool operator!=(const RationalNumber &t) const;
	bool operator<(const RationalNumber &t) const;
	bool operator>(const RationalNumber &t) const;
	bool operator<=(const RationalNumber &t) const;
	bool operator>=(const RationalNumber &t) const;

	string toString() const;

	friend ostream &operator<<(ostream &os, const RationalNumber &t);
	friend istream &operator>>(istream &is, RationalNumber &t);
};

#endif // !RATIONAL_NUMBER_H
