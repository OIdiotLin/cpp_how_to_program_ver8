// Author:	LHD
// System:	Win 10
// Problem:	13.12 (Processing Employee derived-class objects polymorphically.)

#include <iostream>
#include <iomanip>
#include <vector>

#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

using std::vector;

int main() {
	cout << fixed << setprecision(2);

	vector<Employee *> employees(4);

	employees[0] = new SalariedEmployee(
		"John", "Smith", "111-11-1111", 6, 15, 1944, 800);
	employees[1] = new HourlyEmployee(
		"Karen", "Price", "222-22-2222", 12, 29, 1960, 16.75, 40);
	employees[2] = new CommissionEmployee(
		"Sue", "Jones", "333-33-3333", 9, 8, 1954, 10000, .06);
	employees[3] = new BasePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 3, 2, 1965, 5000, .04, 300);

	for (int i = 0;i < 4;i++) {
		cout << *(employees[i]);
		cout << endl;
	}

	return 0;
}
