#ifndef INTEGER_SET_H
#define INTEGER_SET_H

#include <vector>
#include <string>
using std::vector;
using std::string;

class IntegerSet {
private:
	const int SET_SIZE = 101;
	vector<bool> v;

	inline const bool isValid(int x) const;
	
public:
	IntegerSet();
	IntegerSet(int *arr, int length);
	IntegerSet(const IntegerSet &set);
	~IntegerSet();

	const bool insertElement(const int &x);

	IntegerSet intersectionOfSets(const IntegerSet &another) const;
	IntegerSet unionOfSets(const IntegerSet &another) const;

	const string toString() const;

	const bool operator == (const IntegerSet &another) const;
};

#endif