// Author:	LHD
// System:	Win 10
// Problem:	4.16
#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
	int workHours;
	double salaryRate;
#define basicHours (40)
#define bonusRate (1.5)
public:
	Employee() {}
	~Employee() {}
	double totalSalary() {
		if (workHours <= basicHours)
			return workHours*salaryRate;
		else
			return basicHours*salaryRate + bonusRate*salaryRate*(workHours - basicHours);
	}
	void setSalaryRate(double r) {
		salaryRate = r;
	}
	void setWorkHours(int h) {
		workHours = h;
	}
};

int main() {
	Employee cur;
	int hours;
	double rate;
	cout << fixed << setprecision(2);
	while (true) {
		cout << "Enter hours worked (-1 to end): ";
		cin >> hours;
		if (hours == -1)
			break;
		cout << "Enter hourly rate of the employee ($00.00): ";
		cin >> rate;
		cur.setSalaryRate(rate), cur.setWorkHours(hours);
		cout << "Salary is $" << cur.totalSalary() << endl << endl;
	}
	return 0;
}