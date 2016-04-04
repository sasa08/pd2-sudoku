#include<iostream>
#include"Sudoku.h"
using namespace std;
int main(){
	Sudoku ss;
	ss.readIn();
	ss.changeRow(1,1);
	//ss.changeCol(1,1);

	ss.solve();
	return 0;
}