#include<iostream>
#include"Sudoku.h"
using namespace std;
int main(){
	Sudoku ss;
	ss.readIn();
	ss.transform();
	ss.solve();
	return 0;
}