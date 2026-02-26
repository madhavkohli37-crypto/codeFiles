/*
2025
Sublime Text
C++
#All Rights Reserved
Logic and Code by Madhav Kohli
Taught by Coding Sir
*/
#include<bits/stdc++.h>
using namespace std;
bool flag = 0;
vector<vector<char>> b;
bool isPossible(int i, int j, char c) {
	bool ans1 = 1, ans2 = 1, ans3 = 1;
	for (int ni = 0; ni < 9; ni++) {
		if (b[ni][j] == c) {
			ans1 = 0;
		}
	}
	for (int nj = 0; nj < 9; nj++) {
		if (b[i][nj] == c) {
			ans2 = 0;
		}
	}
	int ni = (i / 3) * 3;
	int nj = (j / 3) * 3;
	for (int k = ni; k < ni + 3; k++) {
		for (int l = nj; l < nj + 3; l++) {
			if (b[k][l] == c) {
				ans3 = 0;
			}
		}
	}
	if (ans1 and ans2 and ans3) {
		return true;
	}
	else {
		return false;
	}
}
void F(int i, int j) {
	if (i == 9) {
		flag = 1;
		return;
	}
	if (j == 9) {
		// F(i+1,0);
		return;
	}
	if (b[i][j] == '.') {
		for (int k = 0; k < 9; k++) {
			if (isPossible(i, j, ('1' + k))) {
				b[i][j] = '1' + k;
				F(i, j + 1);
				if (j == 8) {
					F(i + 1, 0);
				}
				if (flag) {
					return;
				}
				b[i][j] = '.'; //backtracking
			}
		}
	}
	else {
		F(i, j + 1);
		if (j == 8) {
			F(i + 1, 0);
		}
	}
	return;

}
void solveSudoku(vector<vector<char>>& board) {
	b = board;
	F(0, 0);
	board = b;
	return;
}
int main() {
	vector<vector<char>> board(9, vector<char>(9, '.')) ;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
	solveSudoku(board);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}



}