
#include<bits/stdc++.h>
using namespace std;
bool ispossible(int x, int y, vector<vector<char>>& board, char ch) {
        // row check
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == ch) {
                return false;
            }
        }
        // column check
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == ch) {
                return false;
            }
        }
        // box check
        int sx = (x / 3) * 3;
        int sy = (y / 3) * 3;
        for (int i = sx; i < sx + 3; i++) {
            for (int j = sy; j < sy + 3; j++) {
                if (board[i][j] == ch) {
                    return false;
                }
            }
        }
        return true;
    }
    bool ans = false;
    void F(int i, int j, vector<vector<char>>& board) {
        if (i == 9) {
            ans = true;
            return;
        }
        if (j == 9) {
            F(i + 1, 0, board);
            return;
        }
        if (board[i][j] == '.') {
            for (int k = 0; k < 9; k++) {
                char ch = '1' + k;
                if (ispossible(i, j, board, ch)) {
                    board[i][j] = ch;
                    F(i, j + 1, board);
                    if (ans) {
                        return;
                    }
                    board[i][j] = '.';
                }
            }
        } else {
            F(i, j + 1, board);
        }
        return;
    }
    void solveSudoku(vector<vector<char>>& board) {
        F(0, 0, board);
        return;
    }int main() {
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
