/*
2025
All Rights Reserved
Solution published by Madhav Kohli
core concept and idea by Madhav Kohli
Taught and learnt by Coding sir
Rat in a Maze v2.0
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
int matrixx[4] {1, 0, 0, -1};
int matrixy[4] {0, -1, 1, 0};
char options[4] {'D', 'L', 'R', 'U'};
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
	for (int p = 0; p < 4; p++) {
		if (visited[i + matrixx[p]][j + matrixy[p]] == 1 and (i + matrixx[p]) <= n and (i + matrixx[p] >= 1) and (j + matrixy[p] <= n) and (j + matrixy[p] >= 1)) {
			visited[i + matrixx[p]][j + matrixy[p]] = 0;
			op[x][y] = options[p];
			y++;
			F(i + matrixx[p], j + matrixy[p]);
			visited[i + matrixx[p]][j + matrixy[p]] = 1;
			y--;
			op[x][y] = '\0';
		}
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