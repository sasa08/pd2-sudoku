#include<iostream>
#include<vector>
#include<deque>
#include<ctime>

using namespace std;

struct Position {
		Position(int x, int y) : row(x), col(y) {};
		int row;
		int col;
		};

typedef deque <Position> sPos;

class Sudoku{
	public:
		Sudoku();
		void printOut();
		void change();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void readIn();
		void transform();
		void solve();
		void giveQuestion();
		bool check(Position p, int n);
		void numTry(sPos & su);
		

	private:
		int oMap[9][9];
};