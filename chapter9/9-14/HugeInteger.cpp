#include "HugeInteger.h"

HugeInteger::HugeInteger() {
	memset(digit, 0, sizeof(digit));
	length = 1;
}

HugeInteger::HugeInteger(const int & num) {
	*this = num;
}

HugeInteger::HugeInteger(const char * num) {
	*this = num;
}

HugeInteger::HugeInteger(const HugeInteger & num) {
	this->length = num.length;
	memcpy(this->digit, num.digit, sizeof(this->digit));
}

HugeInteger::~HugeInteger() {
}

HugeInteger & HugeInteger::operator=(int num) {
	char s[HUGE_INTEGER_MAX_LENGTH];
	sprintf(s, "%d", num);
	*this = s;
	return *this;
}

HugeInteger & HugeInteger::operator=(const char * num) {
	this->length = strlen(num);
	for (int i = 0;i < this->length;i++)
		digit[i] = num[this->length - i - 1] - '0';
	return *this;
}

const string HugeInteger::str() const {
	string res;
	res.clear();
	for (int i = 0;i < this->length;i++)
		res = (char)(digit[i] + '0') + res;
	if (res == "")
		res = "0";
	return res;
}

const HugeInteger & HugeInteger::clear() {
	while (length > 1 && !digit[length - 1])
		length--;
}

const HugeInteger HugeInteger::operator+(const HugeInteger & t) {
	HugeInteger res;
	res.length = 0;
	for (int i = 0, g = 0, x;g || i < max(length, t.length);i++) {
		x = g;
		if (i < length)
			x += digit[i];
		if (i < t.length)
			x += t.digit[i];
		res.digit[res.length++] = x % 10;
		g = x / 10;
	}
	res.clear();
	return res;
}

const HugeInteger HugeInteger::operator-(const HugeInteger & t) {
	HugeInteger res;
	res.length = 0;
	for (int i = 0, g = 0, x;i < length;i++) {
		x = digit[i] - g;
		if (i < t.length)
			x -= t.digit[i];
		if (x >= 0)
			g = 0;
		else {
			g = 1;
			x += 10;
		}
		res.digit[res.length++] = x;
	}
	res.clear();
	return res;
}

const HugeInteger HugeInteger::operator*(const HugeInteger & t) {
	HugeInteger res;
	res.length = this->length + t.length;
	for (int i = 0;i < this->length;i++)
		for (int j = 0;j < t.length;j++)
			res.digit[i + j] += this->digit[i] * t.digit[j];
	for (int i = 0;i < res.length - 1;i++) {
		res.digit[i + 1] += res.digit[i] / 10;
		res.digit[i] %= 10;
	}
	res.clear();
	return res;
}

const bool HugeInteger::operator<(const HugeInteger & t) const {
	if (this->length != t.length) {
		return this->length < t.length;
	}
	for (int i = length - 1;i >= 0;i--)
		if (digit[i] != t.digit[i])
			return digit[i] < t.digit[i];
	return false;
}

const bool HugeInteger::operator>(const HugeInteger & t) const {
	return t < *this;
}

const bool HugeInteger::operator<=(const HugeInteger & t) const {
	return !(*this > t);
}

const bool HugeInteger::operator>=(const HugeInteger & t) const {
	return !(*this < t);
}

const bool HugeInteger::operator==(const HugeInteger & t) const {
	return !(*this < t) && !(*this > t);
}

HugeInteger & HugeInteger::operator+=(const HugeInteger & t) {
	return *this = *this + t;
}

HugeInteger & HugeInteger::operator-=(const HugeInteger & t) {
	return *this = *this - t;
}

HugeInteger & HugeInteger::operator*=(const HugeInteger & t) {
	return *this = *this * t;
}

istream & operator >> (istream & is, HugeInteger & integer) {
	string s;
	is >> s;
	integer = s.c_str();
	return is;
}

ostream & operator<<(ostream & os, const HugeInteger & integer) {
	os << integer.str();
	return os;
}
