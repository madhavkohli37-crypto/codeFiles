/*
2025
All Rights Reserved
Solution published by Madhav Kohli
core concept and idea by Madhav Kohli
Taught and learnt by Coding sir
Rat in a Maze v1.0
Build taken 1-2 days
build in 2025
Edited in Sublime text and onecompiler
Language used C++
*/
#include <iostream>
using namespace std;
int n;
bool in[7][7];
bool visited[7][7] {{0}};
char op[100][100] {{'\0'}};
int x = 0, y = 0;
void F(int i, int j) {
	if (i == n and j == n) {
		for (int i = 0; i < y; i++) {
			cout << op[x][i];
		}
		cout << " ";
		return;
	}
	if (visited[i + 1][j] == 1  and i < n) {
		visited[i + 1][j] = 0;
		op[x][y] = 'D';
		y++;
		F(i + 1, j);
		visited[i + 1][j] = 1;
		y--;
		op[x][y] = '\0';
	}
	if (visited[i][j - 1] == 1 and j > 1) {
		visited[i][j - 1] = 0;
		op[x][y] = 'L';
		y++;
		F(i, j - 1);
		visited[i][j - 1] = 1;
		y--;
		op[i][j - 1] = '\0';
	}
	if (visited[i][j + 1] == 1  and j < n) {
		visited[i][j + 1] = 0;
		op[x][y] = 'R';
		y++;
		F(i, j + 1);
		visited[i][j + 1] = 1;
		y--;
		op[x][y] = '\0';
	}
	if (visited[i - 1][j] == 1  and i > 1) {
		visited[i - 1][j] = 0;
		op[x][y] = 'U';
		y++;
		F(i - 1, j);
		visited[i - 1][j] = 1;
		y--;
		op[x][y] = '\0';
	}
	return;

}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> in[i][j];
			visited[i][j] = in[i][j];
		}
	}
	visited[1][1] = 0;
	F(1, 1);

}