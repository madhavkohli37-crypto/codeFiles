/*
2025
#all rights reserved
sublime C++
*/
#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int f = 0;
vector<vector<string>>p ;
bool visited[100][100] {{0}};
char op[100][100];
void initiate() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			op[i][j] = '.';
		}
	}
}
void F(int i) {
	if (i == n) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				p[f][j][k] = op[j][k];
			}
		}
		f++;
		return;
	}
	for (int j = 0; j < n; j++) {
		bool ans1 = 1, ans2 = 1, ans3 = 1, ans4 = 1, ans5 = 1;
		for (int k = 0; k < n; k++) {
			if (visited[k][j] == 1) {
				ans1 = 0;
				break;
			}
		}
		for (int p = i, q = j; (p >= 0 and q >= 0); p--, q--) {
			if (visited[p][q] == 1) {
				ans2 = 0;
				break;
			}
		}
		for (int p = i, q = j; (p < n and q < n); p++, q++) {
			if (visited[p][q] == 1) {
				ans3 = 0;
				break;
			}
		}
		for (int p = i, q = j; (p >= 0 and q < n); p--, q++) {
			if (visited[p][q] == 1) {
				ans4 = 0;
				break;
			}
		}
		for (int p = i, q = j; (p<n and q >= 0); p++, q--) {
			if (visited[p][q] == 1) {
				ans5 = 0;
				break;
			}
		}
		if (ans1 and ans2 and ans3 and ans4 and ans5) {
			op[i][j] = 'Q';
			visited[i][j] = 1;
			F(i + 1);
			//backtracking
			visited[i][j] = 0;
			op[i][j] = '.';
		}
	}
	return;
}
vector<vector<string>> solveNQueens(int x) {
	n = x;
	initiate();
	string s(x, '.');
	vector<vector<string>>copy(1000, vector<string>(x, s)) ;
	p = copy;
	F(0);
	p.resize(f);
	//cout<<f<<endl;
	return p;
}
int main() {

	int n;
	cin >> n;
	vector<vector<string>>ans = solveNQueens(n);
	cout << "There are a total of " << f << " ways" << endl << endl;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cout << ans[i][j][k];
			}
			cout << endl;
		}
		cout << "___" << endl << endl;
	}

}