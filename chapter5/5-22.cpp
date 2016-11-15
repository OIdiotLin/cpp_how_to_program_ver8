// Author:	LHD
// System:	Win 10
// Problem:	5.22 (De Morgan's Laws)
#include <iostream>
using namespace std;

int main() {
	{
		cout << "Case a): x=2, y=9" << endl;
		int x = 2, y = 9;
		cout << "!(x < 5) && !(y >= 7) = " << (!(x < 5) && !(y >= 7)) << endl;
		cout << "!((x < 5) || (y >= 7)) = " << !((x < 5) || (y >= 7)) << endl << endl;
	}
	{
		cout << "Case b): a=3, b=3, g=5" << endl;
		int a = 3, b = 3, g = 5;
		cout << "!(a == b) || !(g != 5) = " << (!(a == b) || !(g != 5)) << endl;
		cout << "!((a == b) && (g != 5)) = " << !((a == b) && (g != 5)) << endl << endl;
	}
	{
		cout << "Case c): x=5, y=5" << endl;
		int x = 5, y = 5;
		cout << "!((x <= 8) && (y > 4)) = " << !((x <= 8) && (y > 4)) << endl;
		cout << "!(x <= 8) || !(y > 4) = " << (!(x <= 8) || !(y > 4)) << endl << endl;
	}
	{
		cout << "Case d): i=5, j=5" << endl;
		int i = 5, j = 5;
		cout << "!((i > 4) || (j <= 6)) = " << !((i > 4) || (j <= 6)) << endl;
		cout << "!(i > 4) && !(j <= 6) = " << (!(i > 4) && !(j <= 6)) << endl << endl;
	}
	return 0;
}