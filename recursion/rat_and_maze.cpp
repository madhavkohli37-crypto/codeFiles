/*
This code can be used only for those cases where answer exists if the answer exists because we have used void function and we expect that we will always have an answer but more precisely we need to check if the answer exists or not so for that we need to make the function booleon type.
*/
#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
char in[1005][1005] {'\0'};
char op[1005][1005] {'\0'};
bool flag = 0;
void F(int x, int y) {
	if (x == n and y == m) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << op[i][j] << " ";
			}
			flag = 1;
			cout << endl;
		}
		return;
	}
	if (in[x][y + 1] == 'X' and in[x + 1][y] == 'X') {
		if (flag == 1) {
			return;
		}
		in[x][y] = 'X';
		op[x][y] = '0';//backtracking
		return;
	}
	if (y == m and in[x + 1][y] == 'X') {
		in[x][y] = 'X';
		return;
	}
	if (x == n and in[x][y + 1] == 'X') {
		in[x][y] = 'X';
		return;
	}
	if (in[x][y + 1] == 'X' and y < n) {
		if (flag == 1) {
			return;
		}
		op[x + 1][y] = '1';
		F(x + 1, y);
		op[x][y] = '0';//backtracking
		in[x][y] = 'X';
		return;
	}
	else {
		if (flag == 1) {
			return;
		}
		if (y < m) {
			op[x][y + 1] = '1';
			F(x, y + 1);
			in[x][y] = 'X';
			op[x][y + 1] = '0'; //backtracking
		}
		if (x < n) {
			op[x + 1][y] = '1';
			F(x + 1, y);
			in[x][y] = 'X';
			op[x + 1][y] = '0'; //backtracking
		}
	}
	return ;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> in[i][j];
		}
	}
	memset(op, '0', sizeof(op));
	op[1][1] = '1';
	F(1, 1);
	// cout << endl << endl;
	// cout << "______________\n" << "\n";
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		cout << in[i][j];
	// 	}
	// 	cout << endl;
	// }



}