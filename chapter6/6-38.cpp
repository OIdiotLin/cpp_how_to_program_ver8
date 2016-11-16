// Author:	LHD
// System:	Win 10
// Problem:	6.38 (Towers of Hanoi)
#include <iostream>
using namespace std;

class HanoiTower {
public:
	HanoiTower() {}
	~HanoiTower() {}
	void move(int currentDisk, int start, int temp, int end) {
		if (currentDisk == 1) {
			cout << start << " --> " << end << endl;
			return;
		}
		move(currentDisk - 1, start, end, temp);
		cout << start << " --> " << end << endl;
		move(currentDisk - 1, temp, start, end);
	}
};

int main() {
	int n;
	HanoiTower tower;
	while (true) {
		cout << "Enter the amount of disks: ";
		cin >> n;
		tower.move(n, 1, 2, 3);
	}
	return 0;
}