// Author:	LHD
// System:	Win 10
// Problem:	7.24 (Knight's Tour)

#include <iostream>
#include <ctime>
#include <iomanip>
#include <utility>
#include <cstring>
using namespace std;

#define BOARD_SIZE 8
#define STEP_MAX 8

#define x first
#define y second
typedef pair<int, int> pos;

inline void delay(int interval) {
	clock_t t = clock();
	while (clock() - t <= interval);
}

const pos step[STEP_MAX] = {
	{2,-1},{1,-2},{-1,-2},{-2,-1},
	{-2,1},{-1,2},{1,2},{2,1}
};
int access[BOARD_SIZE][BOARD_SIZE] = {
	2, 3, 4, 4, 4, 4, 3, 2,
	3, 4, 6, 6, 6, 6, 4, 3,
	4, 6, 8, 8, 8, 8, 6, 4,
	4, 6, 8, 8, 8, 8, 6, 4,
	4, 6, 8, 8, 8, 8, 6, 4,
	4, 6, 8, 8, 8, 8, 6, 4,
	3, 4, 6, 6, 6, 6, 4, 3,
	2, 3, 4, 4, 4, 4, 3, 2
};


int board[BOARD_SIZE][BOARD_SIZE];
pos cur;
int cnt;


void init() {
	cnt = 0;
	srand(time(NULL));
	memset(board, 0, sizeof(board));
	cur = make_pair<int, int>(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
}

void printBoard(const pos &p) {
#define SINGLE_WIDTH 3
	system("cls");
	cout << "STEPPING - " << cnt << endl << endl;
	cout << "   0  1  2  3  4  5  6  7" << endl;
	for (int i = 0;i < BOARD_SIZE;i++) {
		cout << (char)('A'+i);
		for (int j = 0;j < BOARD_SIZE;j++) {
			if (i == cur.x && j == cur.y)
				cout << setw(SINGLE_WIDTH) << "K";
			else if (board[i][j])
				cout << setw(SINGLE_WIDTH) << board[i][j];
			else cout << setw(SINGLE_WIDTH) << "";
		}
		cout << endl;
	}
	delay(200);
}

inline bool isValid(const pos &p) {
	bool inBoard = (p.x >= 0 && p.x < BOARD_SIZE && p.y >= 0 && p.y < BOARD_SIZE);
	bool isAccessible = (access[p.x][p.y] > 0);
	bool isVisited = (board[p.x][p.y]);
	return inBoard && isAccessible && !isVisited;
}

void travel() {
	int minAccessNum;
	pos next;
	while (true) {
		minAccessNum = INT_MAX;
		for (int type = 0;type < STEP_MAX;type++) {
			pos tmp = make_pair<int, int>(cur.x + step[type].x, cur.y + step[type].y);
			if (isValid(tmp) && access[tmp.x][tmp.y] < minAccessNum) {
				minAccessNum = access[tmp.x][tmp.y];
				next = tmp;
			}
		}
		if (minAccessNum < INT_MAX) {
			cur = next;
			board[cur.x][cur.y] = ++cnt;
			printBoard(cur);
			access[cur.x][cur.y]--;
		}
		else break;
	}
	if (cnt == BOARD_SIZE*BOARD_SIZE)
		cout << "This is a full knight's tour" << endl;
	else
		cout << "This is not a full knight's tour" << endl;
}

int main() {
	init();
	travel();
	return 0;
}