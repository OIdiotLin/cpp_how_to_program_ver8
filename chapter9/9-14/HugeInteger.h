#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using std::string;
using std::istream;
using std::ostream;
using std::max;

#ifndef HUGE_INTEGER_H
#define HUGE_INTEGER_H

#define HUGE_INTEGER_MAX_LENGTH 42 

class HugeInteger {
private:
	int length;
	int digit[HUGE_INTEGER_MAX_LENGTH];

public:
	friend istream &operator >> (istream &is, HugeInteger &integer);
	friend ostream &operator << (ostream &os, const HugeInteger &integer);

	HugeInteger();
	HugeInteger(const int &num);
	HugeInteger(const char *num);
	HugeInteger(const HugeInteger &num);
	~HugeInteger();

	HugeInteger & operator = (int num);
	HugeInteger & operator = (const char *num);

	const string str() const;
	const HugeInteger & clear();

	const HugeInteger operator + (const HugeInteger &t);
	const HugeInteger operator - (const HugeInteger &t);
	const HugeInteger operator * (const HugeInteger &t);

	const bool operator < (const HugeInteger &t) const;
	const bool operator > (const HugeInteger &t) const;
	const bool operator <= (const HugeInteger &t) const;
	const bool operator >= (const HugeInteger &t) const;
	const bool operator == (const HugeInteger &t) const;
	HugeInteger & operator += (const HugeInteger &t);
	HugeInteger & operator -= (const HugeInteger &t);
	HugeInteger & operator *= (const HugeInteger &t);
};

#endif // !HUGE_INTEGER_H
