// Author:	LHD
// System:	Win 10
// Problem:	4.15
#include <iostream>
#include <iomanip>
using namespace std;

const double basicSalary = 200;
const double bonusRate = 0.09;

double totalSalary(double sales) {
	return basicSalary + sales*bonusRate;
}

int main() {
	cout << fixed << setprecision(2);
	double sales;
	while (true) {
		cout << "Enter sales in dollars (-1 to end): ";
		cin >> sales;
		if (sales == -1)
			break;
		cout << "Salary is: $" << totalSalary(sales) << endl << endl;
	}
	return 0;
}