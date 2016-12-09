// Author:	LHD
// System:	Win 10
// Problem:	7.29 (The Sieve of Eratosthenes)

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_NUM 1000

bool isCompositeNumber[MAX_NUM];
int primeCount;

int main() {
	memset(isCompositeNumber, false, sizeof(isCompositeNumber));
	for (int i = 2;i < MAX_NUM;i++) {
		for (int j = i + 1;j < MAX_NUM;j++)
			if (j%i == 0)
				isCompositeNumber[j] = true;
	}
	for (int i = 2;i < MAX_NUM;i++) {
		if (!isCompositeNumber[i]) {
			cout << i << endl;
			primeCount++;
		}
	}
	cout << "In range (0,1000), there are totally " << primeCount << " primes." << endl;
}