// Author:	LHD
// System:	Win 10
// Problem:	6.12 (Parking Charges)
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class SingleCustomer {
private:
	unsigned int car;
	double hours;
	double charge;
public:
	SingleCustomer() {}
	SingleCustomer(unsigned int _car, double _hours) :car(_car), hours(_hours) {}
	~SingleCustomer() {}
#define STARTING_PRICE (2.0)
#define STARTING_HOURS (3.0)
#define PRICE_PER_HOUR (0.5)
#define CEILING_PRICE (10)
	void calculateCharge() {
		if (hours <= STARTING_HOURS)
			charge = STARTING_PRICE;
		else
			charge = PRICE_PER_HOUR*(ceil(hours - STARTING_HOURS))+STARTING_PRICE;
		if (charge > 10)
			charge = 10;
	}
	unsigned int getCar() {
		return car;
	}
	double getHours() {
		return hours;
	}
	double getCharge() {
		return charge;
	}
};

class Receipt {
private:
	vector<SingleCustomer> customersList;
	double hoursCount;
	double chargesCount;
public:
	Receipt() {
		customersList.clear();
		hoursCount = chargesCount = 0;
	}
	~Receipt() {}
	void calculateCharges() {
		for (vector<SingleCustomer>::iterator cur = customersList.begin();cur != customersList.end();cur++) {
			cur->calculateCharge();
			hoursCount += cur->getHours();
			chargesCount += cur->getCharge();
		}
	}
	void print() {
		cout << "Car\tHours\tCharge" << endl;
		for (vector<SingleCustomer>::iterator cur = customersList.begin();cur != customersList.end();cur++) {
			cout << cur->getCar() << '\t' << setprecision(1) << cur->getHours() << '\t' << setprecision(2) << cur->getCharge() << endl;
		}
		cout << "TOTAL\t" << setprecision(1) << hoursCount << '\t' << setprecision(2) << chargesCount << endl;
	}
	void addCustomer(double hours) {
		customersList.push_back(SingleCustomer(customersList.size()+1,hours));
	}
};

Receipt sys;

int main() {
	cout << fixed;
	cout << "Please enter the hours parked for each customer (end with -1):" << endl;
	double hours;
	while (true) {
		cin >> hours;
		if (hours == -1)
			break;
		sys.addCustomer(hours);
	}
	sys.calculateCharges();
	sys.print();
	return 0;
}