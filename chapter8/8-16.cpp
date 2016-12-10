// Author:	LHD
// System:	Win 10
// Problem:	8.16 (Maze Traversal)

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

inline void delay(int interval) {
	clock_t t = clock();
	while (clock() - t < interval);
}

enum Towards { up, down, left, right };

class Maze {
#define PATH '.'
#define WALL '#'
#define MAX_BOARD 12
private:
	struct Position {
		int x, y;
		bool operator == (const Position &t)const {
			return x == t.x && y == t.y;
		}
		bool operator !=(const Position &t)const {
			return x != t.x || y != t.y;
		}
	};
	struct Explorer {
		Position cur;
		Towards towards;
		Position next(){
			switch (towards) {
			case up:
				return Position{ cur.x - 1,cur.y };
			case down:
				return Position{ cur.x + 1,cur.y };
			case left:
				return Position{ cur.x,cur.y - 1 };
			case right:
				return Position{ cur.x,cur.y + 1 };
			}
		}
		void goNext() {
			cur = next();
		}
		bool hasWallOnRightside() {

		}
	};

	int size;
	char map[MAX_BOARD][MAX_BOARD];
	Position entry, exit;
	Explorer explr;

	bool isValid(const Position &t)const {
		return t.x >= 0 && t.x < size && t.y >= 0 && t.y < size && map[t.x][t.y] != WALL;
	}
public:
	Maze() {}
	~Maze() {}
	
	void readSize() { cin >> size; }
	void readMap() {
		for (int i = 0;i < size;i++)
			for (int j = 0;j < size;j++)
				cin >> map[i][j];
	}
	void findEntryAndExit() {
		Position a[2];
		int cnt = 0;
		for (int i = 0;i < size && cnt <= 2;i++) {
			if (map[i][0] == PATH)
				a[cnt++] = Position{ i,0 };
			if (map[i][size - 1] == PATH)
				a[cnt++] = Position{ i,size - 1 };
		}
		for (int j = 0;j < size&&cnt <= 2;j++) {
			if (map[0][j] == PATH)
				a[cnt++] = Position{ 0,j };
			if (map[size - 1][j] == PATH)
				a[cnt++] = Position{ size - 1,j };
		}
		entry = a[0], exit = a[1];
	}
	void show() {
		system("cls");
		for (int i = 0;i < size;i++) {
			for (int j = 0;j < size;j++) {
				if (explr.cur == Position{ i,j })
					cout << '@';
				else
					cout << map[i][j];
			}
			cout << endl;
		}
	}
	void start() {
		if (entry.x == 0)	explr.towards = down;		// towards initialization
		else if (entry.x == size - 1)	explr.towards = up;
		else if (entry.y == 0)	explr.towards = right;
		else if (entry.y == size - 1)	explr.towards = left;
		explr.goNext();	// enter the entry

		while (explr.cur != exit) {		// loop until get the exit
			if(explr.hasWallOnRightside())

			if (isValid(explr.next()))	// if next position is on the path
				explr.goNext();		// go on


		}


	}
};

int main() {
	std::ios::sync_with_stdio(false);
}