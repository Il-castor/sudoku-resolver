/*
 * Sudoku Resolver
 */

#include <iostream>
using namespace std; // @suppress("Symbol is not resolved")

const int N = 9;

int grid[N][N] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0,},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0,}
};

bool isPresentInCol(int col, int num){
	for (int row = 0; row < N; row++){
		if (grid[row][col] == num)
			return true;
	}
	return false;
}

bool isPresentInRow(int row, int num){
	for (int col = 0; col < N; col++){
		if (grid[row][col] == num)
			return true;
	}
	return false;
}

bool isPresentInBox(int startRow, int startCol, int num){
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			if (grid[row + startRow][col + startCol] == num)
				return true;
		}
	}
	return false;
}

void sudokuGrid(){
	for (int row = 0; row < N; row++){
		for (int col = 0; col < N; col++){
			if (col == 3 || col == 6)
				cout<<" | ";
			cout<<grid[row][col]<<" ";
		}
		if (row == 2 || row == 5){
			cout<<endl;
			for (int i = 0; i < N; i++)
				cout<<"---";
		}
		cout<<endl;
	}
}

bool findEmptyPlace(int &row, int &col){
	for (row = 0; row < N; row++){
		for (col = 0; col < N; col++){
			if (grid[row][col] == 0)
				return true;
		}
	}
	return false;
}

bool isValidPlace(int row, int col, int num){
	return !isPresentInRow(row, num) && !isPresentInCol(col, num)
			&& !isPresentInBox(row - row%3, col - col%3, num);
}

bool solveSudoku(){
	int r, c;
	if (!findEmptyPlace(r, c))
		return true;
	for (int i = 1; i <= N; i++){
		grid[r][c] = i;
		if(solveSudoku())
			return true;
		grid[r][c] = 0;
	}
	return false;
}

int main(){
	if(solveSudoku())
		sudokuGrid();
	else
		cout<<"Non esistono soluzioni"<<endl;
	return 0;
}




