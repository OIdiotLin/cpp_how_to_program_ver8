#include <sstream>
#include <iostream>
#include "IntegerSet.h"

IntegerSet::IntegerSet(int *arr, int length) 
	: v(SET_SIZE, false) {
	for (int i = 0; i < length; ++i) {
		insertElement(arr[i]);
	}
}

IntegerSet::IntegerSet()
	: v(SET_SIZE, false) {

}

IntegerSet::IntegerSet(const IntegerSet &set) {
	this->v.assign(set.v.begin(), set.v.end());
}

IntegerSet::~IntegerSet() {
	this->v.clear();
}

const bool IntegerSet::insertElement(const int & x) {
	if (isValid(x))
		return v[x] = true;
	return false;
}

inline const bool IntegerSet::isValid(int x) const {
	return (x>=0 && x<SET_SIZE);
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &another) const {
	IntegerSet newSet;
	for (int i = 0; i < SET_SIZE; i++) {
		newSet.v[i] = this->v[i] && another.v[i];
	}
	return newSet;
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet &another) const {
	IntegerSet newSet;
	for (int i = 0;i < SET_SIZE;i++) {
		newSet.v[i] = this->v[i] || another.v[i];
	}
	return newSet;
}

const string IntegerSet::toString() const {

	std::ostringstream oss;
	oss.clear();

	oss << "{";
	for (int i = 0;i < SET_SIZE;i++) {
		if(v[i])
			oss << i << ", ";
	}
	oss << "\b\b";
	oss << "}";
	
	string str = oss.str();

	return str;
}

const bool IntegerSet::operator==(const IntegerSet & another) const {
	for (int i = 0;i < SET_SIZE;i++) {
		if (v[i] ^ another.v[i]) {
			return false;
		}
	}
	return true;
}
