// Author:	LHD
// System:	Win 10
// Problem:	6.29 (Prime Numbers)
#include <iostream>
#include <algorithm>
using namespace std;

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

int main() {

}