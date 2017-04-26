#include "Polynomial.h"

#include <iostream>
#include <sstream>

using std::ostringstream;
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

#define _exponent_ first
#define _coefficient_ second
#define Terms map<int,int>

Polynomial::Polynomial(int termCount) {
	this->termCount = termCount;
	this->terms.clear();
}

Polynomial::Polynomial(const Polynomial & t){
	this->termCount = t.termCount;
	this->terms = map<int, int>(t.terms);
}

Polynomial::~Polynomial() {
}

int Polynomial::getCoefficient(int exponent){
	const map<int, int>::iterator res = this->terms.find(exponent);
	if (res == this->terms.end()) {
		cerr << "Err: out of range when trying to access ceofficient of term " << exponent << endl;
		return 0;
	}
	else {
		return res->_coefficient_;
	}
}

int Polynomial::getTermCount() const {
	return this->termCount;
}

Polynomial Polynomial::operator+(const Polynomial & t) {
	Polynomial res = Polynomial(this->getTermCount() + t.getTermCount());
	res.terms = Terms(t.terms);
	for (Terms::iterator x = this->terms.begin(); x != this->terms.end();x++) {
		if (res.terms.find(x->_exponent_) != res.terms.end()) {
			res.terms[x->_exponent_] += x->_coefficient_;
		}
		else {
			res.terms[x->_exponent_] = x->_coefficient_;
		}
	}
	res.zeroTermsClear();
	return res;
}

Polynomial Polynomial::operator-(const Polynomial & t) {
	Polynomial res = Polynomial(this->getTermCount() + t.getTermCount());
	res.terms = Terms(t.terms);
	for (Terms::iterator x = this->terms.begin(); x != this->terms.end();x++) {
		if (res.terms.find(x->_exponent_) != res.terms.end()) {
			res.terms[x->_exponent_] -= x->_coefficient_;
		}
		else {
			res.terms[x->_exponent_] = -x->_coefficient_;
		}
	}
	res.zeroTermsClear();
	return res;
}

Polynomial Polynomial::operator*(const Polynomial & t) {
	Polynomial res = Polynomial(this->getTermCount() * t.getTermCount());
	res.terms = Terms(t.terms);
	int prodExponent;
	int prodCoefficient;
	for (Terms::iterator x = this->terms.begin(); x != this->terms.end();x++) {
		for (Terms::iterator y = res.terms.begin(); y != res.terms.end();y++) {
			prodExponent = x->_exponent_ + y->_exponent_;
			prodCoefficient = x->_coefficient_ * y->_coefficient_;
			if (res.terms.find(prodExponent) != res.terms.end()) {
				res.terms[prodExponent] += prodCoefficient;
			}
			else {
				res.terms[prodExponent] = prodCoefficient;
			}
		}
	}
	res.zeroTermsClear();
	return res;
}

Polynomial & Polynomial::operator+=(Polynomial & t) {
	for (Terms::iterator x = t.terms.begin(); x != this->terms.end();x++) {
		if (this->terms.find(x->_exponent_) != this->terms.end()) {
			this->terms[x->_exponent_] += x->_coefficient_;
		}
		else {
			this->terms[x->_exponent_] = x->_coefficient_;
		}
	}
	this->zeroTermsClear();
	return *this;
}

Polynomial & Polynomial::operator-=(Polynomial & t) {
	for (Terms::iterator x = t.terms.begin(); x != this->terms.end();x++) {
		if (this->terms.find(x->_exponent_) != this->terms.end()) {
			this->terms[x->_exponent_] -= x->_coefficient_;
		}
		else {
			this->terms[x->_exponent_] = - x->_coefficient_;
		}
	}
	this->zeroTermsClear();
	return *this;
}

Polynomial & Polynomial::operator*=(Polynomial & t) {
	int prodExponent;
	int prodCoefficient;
	for (Terms::iterator x = this->terms.begin(); x != this->terms.end();x++) {
		for (Terms::iterator y = t.terms.begin(); y != t.terms.end();y++) {
			prodExponent = x->_exponent_ + y->_exponent_;
			prodCoefficient = x->_coefficient_ * y->_coefficient_;
			if (this->terms.find(prodExponent) != this->terms.end()) {
				this->terms[prodExponent] += prodCoefficient;
			}
			else {
				this->terms[prodExponent] = prodCoefficient;
			}
		}
	}
	this->zeroTermsClear();
	return *this;
}

Polynomial & Polynomial::operator=(const Polynomial & t) {
	this->termCount = t.termCount;
	this->terms = Terms(t.terms);
	return *this;
}

Polynomial & Polynomial::inputTerms() {
	int curCoefficient;
	int curExponent;
	for (int i = 1;i <= this->termCount;i++) {
		cout << "input coefficient of term #" << i << ": ";
		cin >> curCoefficient;
		cout << "input exponent of term #" << i << ": ";
		cin >> curExponent;
		if (this->terms.find(curExponent) != this->terms.end()) {
			this->terms[curExponent] += curCoefficient;
		}
		else {
			this->terms[curExponent] = curCoefficient;
		}
	}
	this->zeroTermsClear();
	return *this;
}

string Polynomial::toString() {
	ostringstream oss;
	oss.clear();
	if (this->terms.size() == 0) {
		oss << 0;
		return oss.str();
	}

	int curCoef = this->terms.begin()->_coefficient_;
	int curExp = this->terms.begin()->_exponent_;

	for (Terms::iterator it = this->terms.begin(); it != this->terms.end(); it++) {
		curCoef = it->_coefficient_;
		curExp = it->_exponent_;
		if (curCoef < 0 && it != this->terms.begin()) {
			oss << "\b";
		}
		oss << curCoef;
		if (curExp == 1) {
			oss << 'x';
		}
		else if (curExp > 1) {
			oss << "x^" << curExp;
		}
		oss << '+';
	}
	oss << "\b";
	return oss.str();
}

Polynomial & Polynomial::zeroTermsClear() {
	for (Terms::iterator cur = terms.begin(); cur != terms.end();cur++) {
		if (cur->_coefficient_ == 0)
			terms.erase(cur--);	// iterator back 1 position
	}
	this->termCount = terms.size();
	return *this;
}

ostream & operator<<(ostream & os, Polynomial & t) {
	os << t.toString();
	return os;
}
