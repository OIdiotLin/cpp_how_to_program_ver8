// Author:	LHD
// System:	Win 10
// Problem:	4.27
#include <iostream>
#include <string>
using namespace std;

int main() {
	string binNum;
	int decNum = 0;
	int size;
	cout << "Enter an integer containing only 0s and 1s (less than 32 bits): " << endl;
	cin >> binNum;
	size = binNum.size();
	for (int i = 0;i < size;i++) {
		decNum += (1 << i)*(binNum[size - 1 - i] == '1');
	}
	cout << binNum << "'s decimal equivalent is " << decNum << endl;
	return 0;
}