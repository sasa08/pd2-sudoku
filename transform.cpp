#include<iostream>
#include"Sudoku.h"
using namespace std;
int main(){
	Sudoku ss;
	ss.readIn();
	ss.changeRow(0,1);
	ss.changeCol(0,1);
	ss.rotate(70);
	ss.flip(1);
	ss.solve();
	return 0;
}