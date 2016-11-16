// Author:	LHD
// System:	Win 10
// Problem:	6.53 (Function Template minimum)
#include <iostream>
using namespace std;

template <class T>
T minimum(T v1, T v2) {
	return v1 < v2 ? v1 : v2;
}

int main() {
	{
		int int1, int2;
		cout << "Enter two integers: ";
		cin >> int1 >> int2;
		cout << "The minimum is " << minimum(int1, int2) << endl << endl;
	}
	{
		char ch1, ch2;
		cout << "Enter two characters: ";
		cin >> ch1 >> ch2;
		cout << "The minimum is " << minimum(ch1, ch2) << endl << endl;
	}
	{
		double float1, float2;
		cout << "Enter two floating-point numbers: ";
		cin >> float1 >> float2;
		cout << "The minimum is " << minimum(float1, float2) << endl;
	}
	return 0;
}