// Author:	LHD
// System:	Win 10
// Problem:	7.20 (Airline Reservations System)
#include <iostream>
using namespace std;

#define CAPACITY 10
#define FIRST_CLASS_LIM 5
#define ECONOMY_LIM 10

int seatsLeft = CAPACITY;
int choice;
int firstClassIndex = 1;
int economyIndex = 6;
bool isReserved[CAPACITY + 1] = { false };

void sellFirstClass() {
	cout << "** Your seat assignment is #" << firstClassIndex << " (First Class)." << endl;
	isReserved[firstClassIndex++] = true;
	seatsLeft--;
}

bool firstClassCheck() {
	return !isReserved[firstClassIndex] && firstClassIndex <= FIRST_CLASS_LIM;
}

bool economyCheck() {
	return !isReserved[economyIndex] && economyIndex <= ECONOMY_LIM;
}

void sellEconomy() {
	cout << "** Your seat assignment is #" << economyIndex << " (Economy)." << endl;
	isReserved[economyIndex++] = true;
	seatsLeft--;
}

void nextFlight() {
	cout << "Next flight leaves in 3 hours." << endl;
}

bool isSoldOut() {
	return seatsLeft == 0;
}

int main() {
	while (true) {
		cout << "* Please type 1 for \"First Class\"" << endl;
		cout << "* Please type 2 for \"Economy\"" << endl;
		cin >> choice;
		switch (choice) {
		case 1:	// first class type
			if (firstClassCheck()) 
				sellFirstClass();
			else{
				char resp;
				cout << "** The First Class tickets are sold out." << endl;
				cout << "** Would you like to take economy ticket ? (Y/N)";
				cin >> resp;
				switch (resp) {
				case 'Y':
				case 'y':
					if (economyCheck()) {
						sellEconomy();
					}
					break;
				case 'N':
				case 'n':
					nextFlight();
					break;
				}
			}
			break;
		case 2:	
			if (economyCheck())
				sellEconomy();
			else {
				char resp;
				cout << "** The Economy tickets are sold out." << endl;
				cout << "** Would you like to take First Class ticket ? (Y/N)";
				cin >> resp;
				switch (resp) {
				case 'Y':
				case 'y':
					if (firstClassCheck()) {
						sellFirstClass();
					}
					break;
				case 'N':
				case 'n':
					nextFlight();
					break;
				}
			}
		}
		cout << endl;
		if (isSoldOut()) break;
	}
	cout << "All Tickets are sold out." << endl;
	nextFlight();
	return 0;
}