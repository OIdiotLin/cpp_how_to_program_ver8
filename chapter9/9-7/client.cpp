#include <cstdio>
#include <iostream>

#include "Time.h"

using namespace std;

int main() {
	Time *myTime = new Time(23,59,40);
	for (int i = 0;i < 120;i++) {
		myTime->tick();
		myTime->printStandard();
	}
	return 0;
}