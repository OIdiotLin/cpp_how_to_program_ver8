// Author:	LHD
// System:	Win 10
// Problem:	7.17 (Dice Rolling)

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
using namespace std;

#define ROLLING_TIME 36000
#define SIZE 13

struct Dice {
	int rolling() {
		return rand() % 6 + 1;
	}
};
Dice A, B;

int counter[SIZE];

int main() {
	srand(time(NULL));

	cout << fixed << setprecision(3);

	for (int i = 0;i < ROLLING_TIME;i++)
		counter[A.rolling() + B.rolling()]++;

	cout << setw(3) << "Sum" << setw(6) << "Times" << setw(6) << "Freq" << endl;
	for (int i = 2;i < SIZE;i++)
		cout << setw(3) << i << setw(6) << counter[i] << setw(6) << counter[i] / (double)ROLLING_TIME << endl;
	return 0;
}