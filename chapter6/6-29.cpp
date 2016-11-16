// Author:	LHD
// System:	Win 10
// Problem:	6.29 (Prime Numbers)
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define DEBUG

// Using Miller-Rabbin Prime Testing
// calculate base^exponent%mod
long long expMod(long long base, long long exponent, long long mod) {
	long long res = 1;
	while (exponent) {
		if (exponent & 1) {
			res *= base;
			res %= mod;
		}
		base *= base;
		base %= mod;
		exponent >>= 1;
	}
	return res;
}
inline long long rand(long long N) {
	return (long long)((double)rand() / RAND_MAX*N + 0.5);
}
// Fermat's little theorem: forall prime p, forall  real number a, a^(p-1) == 1 ( mod p ) 
bool fermatTest(long long p) {
	long long a = rand(p)+1;
	return expMod(a, p - 1, p) == 1;
}
// Miller-Rabbin Prime Testing
#define TEST_COUNTER 80	// Pick test_counter number as base for test
bool isPrime(long long number) {
	if (number == 0 || number == 1)
		return false;
	for (int i = 0;i < TEST_COUNTER;i++)
		if (!fermatTest(number))
			return false;
	return true;
}

#define UPPER_LIM 10000
int main() {
	cout << "The prime numbers in [1,10000] are :" << endl;
	for (int i = 3;i <= UPPER_LIM;i++)
		if (isPrime(i))
			cout << setw(5) << i << endl;
	return 0;
}