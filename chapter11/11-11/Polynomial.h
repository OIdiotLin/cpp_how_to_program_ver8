#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <algorithm>
#include <map>
#include <string>

using std::pair;
using std::map;
using std::ostream;
using std::string;

class Polynomial {

private:
	map<int, int> terms;	// key <= exponent, value <= coefficient
	int termCount;

	Polynomial & zeroTermsClear();

public:
	Polynomial(int termCount = 1);
	Polynomial(const Polynomial &t);
	~Polynomial();

	int getCoefficient(int exponent);
	int getTermCount() const;

	Polynomial operator+(const Polynomial &t);
	Polynomial operator-(const Polynomial &t);
	Polynomial operator*(const Polynomial &t);
	Polynomial & operator+=(Polynomial &t);
	Polynomial & operator-=(Polynomial &t);
	Polynomial & operator*=(Polynomial &t);
	Polynomial & operator=(const Polynomial &t);

	Polynomial & inputTerms();
	string toString();

	friend ostream &operator<<(ostream &os, Polynomial &t);
};


#endif // !POLYNOMIAL_H
