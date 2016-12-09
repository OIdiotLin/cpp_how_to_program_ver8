// Author:	LHD
// System:	Win 10
// Problem:	8.12 (Simulation: The Tortoise and the Hare)

#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define RACE_END_POS 70

inline void delay(int);
void moveTortoise(int *const);
void moveHare(int *const);
void validAdjust(int *const);
void printCurrentRace(const int *const, const int *const);

enum TortoiseStep {
	fastPlod, slip, slowPlod
};
TortoiseStep typeTortoiseStep(const int &step);
enum HareStep {
	sleep, bigHop, bigSlip, smallHop, smallSlip
};
HareStep typeHareStep(const int &step);

int main() {
	srand(time(NULL));

	int tortoise = 1;
	int hare = 1;
	int timeCounter = 0;

	int *const ptrT = &tortoise;
	int *const ptrH = &hare;

	cout << "BANG !!!!!" << endl;
	cout << "AND THEY'RE OFF !!!!!" << endl;
	delay(1000);

	while (tortoise != RACE_END_POS && hare != RACE_END_POS) {
		moveTortoise(ptrT);
		moveHare(ptrH);
		printCurrentRace(ptrT, ptrH);
		timeCounter++;
	}

	if (tortoise >= hare)		// favor the tortoise - the underdog
		cout << "TORTOISE WINS!!! YAY!!!" << endl;
	else
		cout << "Hare wins. Yuch." << endl;

	cout << "Time used = " << timeCounter << "s" << endl;
}

inline void delay(int interval) {
	clock_t t = clock();
	while (clock() - t < interval);
}

void printCurrentRace(const int *const ptrTort, const int *const ptrHare) {
	system("cls");
	if (*ptrTort == *ptrHare)
		cout << setw(*ptrTort) << "OUCH!!!" << endl;
	else if (*ptrTort < *ptrHare)
		cout << setw(*ptrTort) << "T" << setw(*ptrHare - *ptrTort) << "H" << endl;
	else
		cout << setw(*ptrHare) << "H" << setw(*ptrTort - *ptrHare) << "T" << endl;
	delay(250);
}

void moveTortoise(int *const ptrTort) {
	const TortoiseStep step = typeTortoiseStep(rand() % 10 + 1);
	switch (step) {
	case fastPlod:
		*ptrTort += 3; break;
	case slip:
		*ptrTort -= 6; break;
	case slowPlod:
		*ptrTort += 1; break;
	}
	validAdjust(ptrTort);
}

void moveHare(int *const ptrHare) {
	const HareStep step=typeHareStep(rand()%10+1);
	switch (step) {
	case bigHop:
		*ptrHare += 9; break;
	case bigSlip:
		*ptrHare -= 12; break;
	case smallHop:
		*ptrHare += 1; break;
	case smallSlip:
		*ptrHare -= 2; break;
	case sleep:
		break;
	}
	validAdjust(ptrHare);
}

void validAdjust(int *const ptr) {
	*ptr = max(1, *ptr);
	*ptr = min(RACE_END_POS, *ptr);
}

TortoiseStep typeTortoiseStep(const int &step) {
	if (step >= 1 && step <= 5)
		return fastPlod;
	else if (step == 6 || step == 7)
		return slip;
	else
		return slowPlod;
}

HareStep typeHareStep(const int &step) {
	if (step == 1 && step == 2)
		return sleep;
	else if (step == 3 || step == 4)
		return bigHop;
	else if (step <= 5)
		return bigSlip;
	else if (step <= 8)
		return smallHop;
	else
		return smallSlip;
}
