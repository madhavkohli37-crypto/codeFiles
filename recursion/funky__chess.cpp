/*
https://hack.codingblocks.com/app/contests/8153/288/problem
*/
#include <iostream>
using namespace std;
int n;
int maxi = -1;
int count = 0;
int dx[] {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] {2, -2, 2, -2, 1, -1, 1, -1};
bool matrix[100][100];
bool visited[100][100] {{0}};
void F(int i, int j, int c) {
	visited[i][j] = 0;
	// cout << i << " " << j << " " << c << endl;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << visited[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl << endl;
	for (int p = 0; p < 8; p++) {
		if (visited[i + dx[p]][j + dy[p]] == 1 and (i + dx[p]) >= 1 and (i + dx[p]) <= n and (j + dy[p]) >= 1 and (j + dy[p]) <= n) {
			c++;
			F(i + dx[p], j + dy[p], c);
			c--;
		}
	}
	visited[i][j] = 1;
	maxi = max(maxi, c);
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1) {
				count++;
			}
			visited[i][j] = matrix[i][j];
		}
	}
	visited[1][1] = 0;
	F(1, 1, 1);
	cout << count - maxi;



}