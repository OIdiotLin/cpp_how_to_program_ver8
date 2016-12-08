// Author:	LHD
// System:	Win 10
// Problem:	7.26 (Eight Queens)
// This program can output all solutions..

#include <iostream>
using namespace std;

#define BOARD_SIZE 8

int queenPos[BOARD_SIZE];	// queen position in each row
int solutionsCount;

bool isValid(int curRow) {
	for (int r = 0;r < curRow;r++) {
		bool isSameCol = (queenPos[r] == queenPos[curRow]);
		bool isDiag = (abs(queenPos[r] - queenPos[curRow]) == (curRow - r));
		if (isSameCol || isDiag)
			return false;
	}
	return true;
}

void output() {
	solutionsCount++;
	for (int r = 0;r < BOARD_SIZE;r++) {
		for (int c = 0;c < queenPos[r];c++)
			cout << "0";
		cout << "*";
		for (int c = queenPos[r] + 1;c < BOARD_SIZE;c++)
			cout << "0";
		cout << endl;
	}
	cout << endl;
	/*
	for (int r = 0;r < BOARD_SIZE;r++)
		cout << "(" << r << "," << queenPos[r] << ")";
	cout << endl;*/
}

void setQueen(int curRow) {	// set queen position in curRow
	for (int curCol = 0;curCol < BOARD_SIZE;curCol++) {
		queenPos[curRow] = curCol;
		if (isValid(curRow)) {
			if (curRow == BOARD_SIZE-1)
				output();
			else
				setQueen(curRow + 1); 
		}
	}
}

int main() {
	solutionsCount = 0;
	setQueen(0);
	cout << "Total Solutions = " << solutionsCount << endl;
	return 0;
}