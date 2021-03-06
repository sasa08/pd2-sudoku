
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <deque>
#include "Sudoku.h"
using namespace std;

/*
int qMap[9][9] ={{6,4,9,2,1,5,3,8,7},
			{8,1,7,4,3,6,5,9,2},
			{2,5,3,8,7,9,4,6,1},
			{3,8,4,1,6,2,9,7,5},
			{1,9,5,7,4,8,6,2,3},
			{7,2,6,5,9,3,8,1,4},
			{5,7,1,6,8,4,2,3,9},
			{9,6,2,3,5,1,7,4,8},
			{4,3,8,9,2,7,1,5,6}};
*/

int aMap[9][9] ;
int num[9] = {1,2,3,4,5,6,7,8,9};
int oMap[9][9] =
		{{0,4,0,2,1,0,0,0,0},
		{8,0,7,0,0,0,0,9,0},
		{2,0,0,8,0,0,4,0,1},
		{3,0,0,0,0,2,9,0,5},
		{0,0,5,7,0,8,6,0,0},
		{7,0,6,5,0,0,0,0,4},
		{5,0,1,0,0,4,0,0,9},
		{0,6,0,0,0,0,7,0,8},
		{0,0,0,0,2,7,0,5,0}};
int pMap[9][9];
int cnt = 0,xi=0,yj=0,cntt = 0;
int tnum[81][9] = {0};
int Ans = 0;

Sudoku::Sudoku(){;}

void Sudoku::giveQuestion(){
	//change();
	int qMap[9][9] ={{0,4,0,2,1,0,0,0,0},
		{8,0,7,0,0,0,0,9,0},
		{2,0,0,8,0,0,4,0,1},
		{3,0,0,0,0,2,9,0,5},
		{0,0,5,7,0,8,6,0,0},
		{7,0,6,5,0,0,0,0,4},
		{5,0,1,0,0,4,0,0,9},
		{0,6,0,0,0,0,7,0,8},
		{0,0,0,0,2,7,0,5,0}};

	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			oMap[i][j] = qMap[i][j];
		}
	}
	change();
	
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			cout <<oMap[i][j] << " ";
		}
		cout << endl;
	}

}
void Sudoku::printOut(){
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			cout <<aMap[i][j] << " ";
		}
		cout << endl;
	}
}
bool Sudoku::check(Position p, int n){
	int tmpRow = p.row;
	int tmpCol = p.col;

	for (int i = 0; i < 9; i++) {
		if (n == oMap[i][tmpCol] || n == oMap[tmpRow][i]) {
			return false;
		}
	}

	int gridRow = ( tmpRow / 3 ) * 3;
	int gridCol = ( tmpCol / 3 ) * 3;
	for (int i = 0; i < 3; i++) {
		for(int j = 0 ; j < 3 ; j++){
			if (n == oMap[gridRow+i][gridCol + j ] || n == oMap[gridRow + i][gridCol + j]) {
				return false;
			}
		}
	}

	return true;
}
void Sudoku::numTry(sPos & su){
	if (su.empty()) {
		Ans++;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				aMap[i][j] = oMap[i][j];
			}
		}
	}
	Position tmp(su.front().row, su.front().col);
	su.pop_front();
	for (int i = 1; i <= 9; i++) {
		if ( check(tmp, i) ) {
			oMap[tmp.row][tmp.col] = i;	
			numTry(su);
			oMap[tmp.row][tmp.col] = 0;
		}
	}		
	su.push_front(tmp);
}
void Sudoku::solve(){
	sPos su;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (0 == oMap[i][j])  {
				//cout << i << "+" << j << endl;
				su.push_back(Position(i, j));
 			}
		}
	}

	if(su.size() == 0 ) {
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				aMap[i][j] = oMap[i][j];
			}
		}
		Ans++;
		cout << Ans << endl;
		printOut() ;
	}
	else if(su.size() == 81) cout << 2;
	else if(su.size() < 65){
		numTry(su);
		if(Ans == 1) {
			cout << Ans << endl;
			printOut() ;
		}
		else if (Ans > 1) cout << 2;
		else cout << 0;
	}
	else{
		cout << 0;
	}
}

/*
void solve(){
	Ans();
	cout << endl;
	for( xi = 0; xi < 9 ; xi++){
		for( yj = 0 ; yj < 9 ;yj++){
			if(oMap[xi][yj] == 0){
				//oMap[i][j] = tnum;
				oMap[xi][yj] = tnum[xi*9+yj][cntt];
				Ans();
				cntt++;
				//cout << endl;
			}
			else oMap[xi][yj] = oMap[xi][yj];

			//cout << endl ;
		}
	}
	for(int r = 0 ; r < 9 ; r++){
		if(record[r]!=0){
			for(int i = 0 ; i < 9 ; i ++){
				for(int j = 0 ; j < 9 ; j++){
					oMap[i][j] = record[r];
					Ans();
				}
			}
		}
	}


		for(int i = 0 ; i < 9 ; i ++){
			for(int j = 0 ; j < 9 ; j++){
				Ans();

				if(pMap[i][j] == 0) break;
				else if(pMap[i][j] == 1) {
					for(int p = 0 ; p < 9 ; p++){
						num[p] != 0 ? oMap[i][j] = num[p] : cnt = cnt;
					}
					break;
				}
				else{
					for(int p = 0 ; p < 9 ; p++){
						num[p] != 0 ? oMap[i][j] = num[p] : cnt = cnt;
					}		
				}
			}
		}	
}
void Ans(){
		for( int i = 0 ; i < 9 ; i ++){
			for( int j = 0 ; j < 9 ; j++){
				if(oMap[i][j] != 0)
					pMap[i][j] = 10;
				else{
					for(int p = 0 ; p < 9 ; p++){
						switch(oMap[i][p]){//直的
							case 1: num[0] = 0;break;
							case 2: num[1] = 0;break;
							case 3: num[2] = 0;break;
							case 4: num[3] = 0;break;
							case 5: num[4] = 0;break;
							case 6: num[5] = 0;break;
							case 7: num[6] = 0;break;
							case 8: num[7] = 0;break;
							case 9: num[8] = 0;break;
							default: num[0] = num[0];
						}
						switch(oMap[p][j]){//橫的
							case 1: num[0] = 0;break;
							case 2: num[1] = 0;break;
							case 3: num[2] = 0;break;
							case 4: num[3] = 0;break;
							case 5: num[4] = 0;break;
							case 6: num[5] = 0;break;
							case 7: num[6] = 0;break;
							case 8: num[7] = 0;break;
							case 9: num[8] = 0;break;
							default: num[0] = num[0];
						}
						int sx,sy;
						sx = i / 3;
						sy = j / 3;
						for(int si = 0 ; si < 3 ; si ++){//小九宮格
							for(int sj = 0 ; sj < 3 ; sj++){
								switch(oMap[sx*3+si][sy*3+sj]){
									case 1: num[0] = 0;break;
									case 2: num[1] = 0;break;
									case 3: num[2] = 0;break;
									case 4: num[3] = 0;break;
									case 5: num[4] = 0;break;
									case 6: num[5] = 0;break;
									case 7: num[6] = 0;break;
									case 8: num[7] = 0;break;
									case 9: num[8] = 0;break;
									default: num[0] = num[0];
								}
							}
						}


					}
					cnt = 0;
					for(int p = 0 ; p < 9 ; p++){
						//num[p] != 0 ? cnt++ : cnt = cnt;
						if(num[p] != 0 && oMap[i][j] == 0){
							//oMap[i][j] = num[p];
							tnum[i*9+j][cnt] = num[p];
							cnt++;
							//break;
							//for(int a1 = 0)
						}
					}
					pMap[i][j] = cnt;

					if(cnt == 0) {
						break;
						oMap[xi][yj] = 0;
						if(yj > 0) yj--;
						else xi--;
					}
					else{
						cntt = 0;
					}

				}
				//initial num vector
				for(int c = 0 ; c < 9 ; c++)
					num[c] = c+1;
			}
		}

		//一直建表

		
		bool tmp = true;
		for(int i = 0 ; i < 9 ; i ++){
			for(int j = 0 ; j < 9 ; j++){
				if(pMap [i][j] == 0) {
					tmp = false;
					break;
				}
			}
		}
		if(tmp == true ) return true;
		else return false;
		*/
		/*
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				cout << setw(3) <<pMap[i][j] << " ";
			}
			cout << endl;
		}
}
*/

void Sudoku::readIn(){
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			cin >> oMap[i][j];
		}
	}}
void Sudoku::changeNum(int a,int b){
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			if (oMap[i][j] == a) aMap[i][j] = b;
			else if(oMap[i][j] == b) aMap[i][j] = a;
			else aMap[i][j] = oMap[i][j];
		}
	}

	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			oMap[i][j] = aMap[i][j];
		}
	}
}
void Sudoku::changeRow(int a,int b){
	if (a == b ){
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				aMap[i][j] = oMap[i][j];
			}
		}
	}
	else{
		int c = 3-a-b;
		int tmp[9][9] = {0};
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				aMap[b*3+i][j] = oMap[a*3+i][j];
				aMap[a*3+i][j] = oMap[b*3+i][j];
				aMap[c*3+i][j] = oMap[c*3+i][j];
			}
		}
	}

	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			oMap[i][j] = aMap[i][j];
		}
	}
}
void Sudoku::changeCol(int a,int b){
	if (a == b ){
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				aMap[i][j] = oMap[i][j];
			}
		}
	}
	else{
		int c = 3-a-b;
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				aMap[i][a*3+j] = oMap[i][b*3+j];
				aMap[i][b*3+j] = oMap[i][a*3+j];
				aMap[i][c*3+j] = oMap[i][c*3+j];
			}
		}
	}

	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			oMap[i][j] = aMap[i][j];
		}
	}
}
void Sudoku::rotate(int n){
	if(n > 3) {
		n%=4;
	}

	for(int t = 0 ; t < n ; t++){
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				aMap[i][j] = oMap[8-j][i];
			}
		}
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				oMap[i][j] = aMap[i][j];
			}
		}
	}	
}
void Sudoku::flip(int n){
	if(n == 0){
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				aMap[i][j] = oMap[8-i][j];
			}
		}
	}
	else{
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				aMap[i][j] = oMap[i][8-j];
			}
		}
	}

	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			oMap[i][j] = aMap[i][j];
		}
	}
}
void Sudoku::change(){
	srand(time(NULL));
	changeNum((rand()%9+1),(rand()%9+1));
	changeRow((rand()%3),(rand()%3));
	changeCol((rand()%3),(rand()%3));
	rotate(rand()%101);
	flip(rand()%2);
}
void Sudoku::transform(){
	change();
	printOut();
}

/*
int main(){
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			cout << oMap[i][j] << " ";
		}
		cout << endl;
	}	
	cout << endl ;

	
}*/