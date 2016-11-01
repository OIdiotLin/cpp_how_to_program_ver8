// Author:	LHD
// System:	Win 10
// Problem:	4.14
#include <iostream>
#include <iomanip>
using namespace std;

class CreditCard {
public:
	int account;
	double balanceBegin;
	double chargesTotal;
	double creditsTotal;
	double creditLimit;
	double balanceNew;
};

int main() {
	CreditCard cur;
	cout << fixed << setprecision(2);
	while (true) {
		cout << "Enter account number (or -1 to quit): ";
		cin >> cur.account;
		if (cur.account == -1)
			break;
		cout << "Enter beginning balance: ";
		cin >> cur.balanceBegin;
		cout << "Enter total charges: ";
		cin >> cur.chargesTotal;
		cout << "Enter total credits: ";
		cin >> cur.creditsTotal;
		cout << "Enter credit limit: ";
		cin >> cur.creditLimit;
		cur.balanceNew = cur.balanceBegin + cur.chargesTotal - cur.creditsTotal;
		cout << "New balance is " << cur.balanceNew<<endl;
		if (cur.balanceNew > cur.creditLimit) {
			cout << "Account:\t" << cur.account<<endl;
			cout << "Credit limit:\t" << cur.creditLimit << endl;
			cout << "Balance:\t" << cur.balanceNew<<endl;
			cout << "Credit Limit Exceeded." << endl;
		}
		cout << endl;
	}
	return 0;
}
