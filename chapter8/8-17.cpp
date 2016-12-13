// Author:	LHD
// System:	Win 10
// Problem:	8.17 (Generating Mazes Randomly)

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

#define MAX_PATH_POINT 90
#define SHOW_INTERVAL 150
//#define GEN_BY_SINGLE_PATH		// generation 

inline void delay(int interval) {
	clock_t t = clock();
	while (clock() - t < interval);
}

enum Towards { up, down, left, right };	// direction the explorer faces to

class Maze {
#define PATH '.'
#define WALL '#'
#define MAX_BOARD 12
private:

	int size;
	char map[MAX_BOARD][MAX_BOARD];

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
		Position next() {
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
		bool hasWallOnRightside(char map[MAX_BOARD][MAX_BOARD]) {
			Explorer tmp = *(this);
			tmp.turnRight();
			Position R = tmp.next();
			return map[R.x][R.y] != PATH;
		}
		void turnRight() {
			switch (towards) {
			case up:
				towards = right;
				break;
			case down:
				towards = left;
				break;
			case left:
				towards = up;
				break;
			case right:
				towards = down;
				break;
			}
		}
		void turnLeft() {
			switch (towards) {
			case up:
				towards = left;
				break;
			case down:
				towards = right;
				break;
			case left:
				towards = down;
				break;
			case right:
				towards = up;
				break;
			}
		}
	};

	Position entry, exit;
	Explorer explr;

	inline bool isInRange(const Position &t)const {
		return t.x >= 0 && t.x < size && t.y >= 0 && t.y < size;
	}
	inline bool isValid(const Position &t)const {
		return isInRange(t) && map[t.x][t.y] != WALL;
	}
	inline bool isBorder(const Position &t)const {
		bool isTop = (t.x == 0 && t.y >= 1 && t.y < size - 1);
		bool isBottom = (t.x == size - 1 && t.y >= 1 && t.y < size - 1);
		bool isLeft = (t.y == 0 && t.x >= 1 && t.x < size - 1);
		bool isRight = (t.y == size - 1 && t.x >= 1 && t.x < size - 1);
		return isTop || isBottom || isLeft || isRight;
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
		delay(SHOW_INTERVAL);
	}

/****************************** PUBLIC MEMBERS & FUNCS************************/
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
		for (int j = 0;j < size && cnt <= 2;j++) {
			if (map[0][j] == PATH)
				a[cnt++] = Position{ 0,j };
			if (map[size - 1][j] == PATH)
				a[cnt++] = Position{ size - 1,j };
		}
		entry = a[0], exit = a[1];
	}
	void start() {
		if (entry.x == 0)	explr.towards = down;		// towards initialization
		else if (entry.x == size - 1)	explr.towards = up;
		else if (entry.y == 0)	explr.towards = right;
		else if (entry.y == size - 1)	explr.towards = left;
		explr.cur = entry;	// enter the entry
		
		while (true) {		// loop until get the exit
			if (!explr.hasWallOnRightside(map))
				explr.turnRight();

			if (isValid(explr.next())) {	// if next position is on the path
				explr.goNext();		// go on
				show();
			}
			else {
				explr.turnLeft();
			}
			if (explr.cur == entry) {
				cout << "He is trapped in the maze." << endl;
				return ;
			}
			if (explr.cur == exit) {
				cout << "He made it!" << endl;
				return;
			}
		}
	}
/*********************GENERATING MAZE*******************/
	void generate() {

		srand(time(NULL));
		size = MAX_BOARD;
		//mapFile << size << endl;
		for (int i = 0;i < size;i++)
			for (int j = 0;j < size;j++)
				map[i][j] = WALL;

#ifdef GEN_BY_SINGLE_PATH
		//ofstream mapFile;
		//mapFile.open("maze.txt");

		if (rand() % 2) {
			explr.cur.x = rand() % (size - 2) + 1;
			explr.cur.y = (rand() % 2 ? 0 : size - 1);
		}
		else {
			explr.cur.y = rand() % (size - 2) + 1;
			explr.cur.x = (rand() % 2 ? 0 : size - 1);
		}
		entry = explr.cur;
		if (entry.x == 0)	explr.towards = down;		// towards initialization
		else if (entry.x == size - 1)	explr.towards = up;
		else if (entry.y == 0)	explr.towards = right;
		else if (entry.y == size - 1)	explr.towards = left;
		explr.goNext();

		while (true) {
			static bool islastTurn = false;
			for (int i = 4;i;i--) {
				if (isInRange(explr.next())) {
					explr.goNext();
					map[explr.cur.x][explr.cur.y] = PATH;
					islastTurn = false;
				}
			}
			int t = rand() % 3;
			if(!islastTurn)				// if went straight in the last turn
				switch (t) {
				case 0:
					explr.turnLeft();
					islastTurn = true;
					break;
				case 1:
					explr.turnRight();
					islastTurn = true;
					break;
				}
			if (isBorder(explr.cur))	// exit when reach border
				break;
		}
		//for (int i = 0;i < size;i++) {
		//	for (int j = 0;j < size;j++)
		//		mapFile << map[i][j];
		//	mapFile << endl;
		//}
		//mapFile.close();
#else
		do {
			entry = Position{ 0, rand() % (size - 2) + 1 };
			exit = Position{ size - 1, rand() % (size - 2) + 1 };
		} while (entry == exit);
		map[entry.x][entry.y] = PATH;
		map[exit.x][exit.y] = PATH;
		map[entry.x + 1][entry.y] = PATH;
		map[exit.x - 1][exit.y] = PATH;
		for (int cnt = 0;cnt <= MAX_PATH_POINT;cnt++) {
			int x = rand() % (size - 2) + 1;
			int y = rand() % (size - 2) + 1;
			map[x][y] = PATH;
		}
#endif
	}
};

Maze G;
int main() {
	//cout << "The randomized map data are stored in /maze.txt " << endl;
	//system("pause");
	G.generate();
	std::ios::sync_with_stdio(false);
	//G.readSize();
	//G.readMap();
	//G.findEntryAndExit();
	G.start();
	return 0;
}
