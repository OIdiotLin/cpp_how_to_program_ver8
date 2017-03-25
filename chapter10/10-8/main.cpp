// Author:	LHD
// System:	Win 10
// Problem:	10.8 (IntegerSet Class)

#include <iostream>

#include "IntegerSet.h"

using namespace std;

int main() {
	int arrA[] = { 1,2,3,4,5 };
	int arrB[] = { 5,6,7,8,9 };
	int arrC[] = { 1,2,3,4 };
	IntegerSet setA = IntegerSet(arrA, 5);
	IntegerSet setB = IntegerSet(arrB, 5);
	IntegerSet setC = IntegerSet(arrC, 4);

	cout << "setA = " << setA.toString() << endl;
	cout << "setB = " << setB.toString() << endl;
	cout << "setC = " << setC.toString() << endl;

	cout << endl;

	cout << "setA + setB = " << setA.unionOfSets(setB).toString() << endl;
	cout << "setA ¡¤ setB = " << setA.intersectionOfSets(setB).toString() << endl;

	cout << endl;

	cout << "add 5 to setC ..." << endl;
	setC.insertElement(5);
	cout << "setC = " << setC.toString() << endl;

	cout << "setA is " << (setC == setA ? "" : "not ") << "equal to setC" << endl;

	return 0;
}
