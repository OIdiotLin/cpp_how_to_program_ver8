// Author:	LHD
// System:	Win 10
// Problem:	6.30 (Reverse Digits)
#include <iostream>
#include <time.h>
using namespace std;

class Coin {
private:
	int headCount;
	int tailCount;
	bool myRand() {
		return rand() % 2;
	}
public:
	Coin() { headCount = 0, tailCount = 0; }
	~Coin() {}
	bool flip() {
		return (this->myRand());
	}
	void start(int times) {
		while (times--) {
			bool t = this->flip();
			switch (t) {
			case true:
				headCount++;
				cout << "Heads" << endl;
				break;
			case false:
				tailCount++;
				cout << "Tails" << endl;
				break;
			}
		}
	}
	void printStatics() {
		cout << "Heads:\t" << headCount << " times" << endl;
		cout << "Tails:\t" << tailCount << " times" << endl;
	}
};

Coin game;

int main() {
	srand(time(NULL));
	cout << "Start Coin Tossing:" << endl;
	game.start(100);
	game.printStatics();
	return 0;
}