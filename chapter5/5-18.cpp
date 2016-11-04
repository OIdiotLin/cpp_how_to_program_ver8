// Author:	LHD
// System:	Win 10
// Problem:	5.18
#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

int main() {
	cout << setw(3) << "DEC" <<setw(10)<<"BIN"<< setw(5) << "OCT" << setw(5) << "HEX" << endl;
	for (int i = 1;i <= 256;i++) {
		cout << setw(3) << dec << i;
		cout << setw(10) << bitset<sizeof(uint8_t)*9>(i);
		cout << setw(5) << oct << i;
		cout << setw(5) << hex << i << endl;
	}
	return 0;
}