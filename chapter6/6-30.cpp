// Author:	LHD
// System:	Win 10
// Problem:	6.30 (Reverse Digits)
#include <iostream>
#include <string>
using namespace std;

string rev(string& st) {
	string res;
	res.clear();
	for (string::iterator c = st.end() - 1;c != st.begin() - 1;c--)
		res.push_back(*c);
	return res;
}

int main() {
	string str;
	while (true) {
		cout << "Enter digits:\t";
		cin >> str;
		cout << "Reverse digits:\t" << rev(str) << endl << endl;
	}
	return 0;
}