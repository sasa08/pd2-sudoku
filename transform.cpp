#include<iostream>
#include"Sudoku.h"
using namespace std;
int main(){
	Sudoku ss;
	ss.readIn();
	for(int i = 0 ; i < 10000 ; i++){
		ss.transform();
		cout << i << endl ;
	}
	return 0;
}