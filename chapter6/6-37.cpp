// Author:	LHD
// System:	Win 10
// Problem:	6.37 (Fibonacci Series)
#include <iostream>
using namespace std;

long long fibonacci(int n) {
	static long long fib[93] = {0};
	if (n == 0)
		return fib[n] = 0;
	if (n == 1)
		return fib[n] = 1;
	if (fib[n])
		return fib[n];
	return fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n;
	while (true) {
		cout << "Enter a integer (no more than 92): ";
		cin >> n;
		cout << "fibonacci(" << n << ") = " << fibonacci(n) << endl << endl;
	}
	return 0;
}