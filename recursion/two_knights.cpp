/*
this is not an optimised code
*/
#include <iostream>
#include<cstring>
using namespace std;
#define int long long
int v = 0;
int c = 0;
int k;
bool board[10005][10005] {0};
void put(int x, int y) {
	if (x >= k) {
		return ;
	}
	if (y >= k) {
		put(x + 1, 0);
		return;
	}
	board[x][y] = 1;
	v++;
	int f = 0;
	if (x + 2 < k and y + 1 < k and board[x + 2][y + 1] == 0) {
		f++;
	}
	if (x + 1 < k and y + 2 < k and board[x + 1][y + 2] == 0) {
		f++;
	}
	if (x + 1 < k and y - 2 >= 0 and board[x + 1][y - 2] == 0) {
		f++;
	}
	if (x + 2 < k and y - 1 >= 0 and board[x + 2][y - 1] == 0) {
		f++;
	}
	if (x - 2 >= 0 and y + 1 < k and board[x - 2][y + 1] == 0) {
		f++;
	}
	if (x - 2 >= 0 and y - 1 >= 0 and board[x - 2][y - 1] == 0) {
		f++;
	}
	if (x - 1 >= 0 and y + 2 < k and board[x - 1][y + 2] == 0) {
		f++;
	}
	if (x - 1 >= 0 and y - 2 >= 0 and board[x - 1][y - 2] == 0) {
		f++;
	}
	// cout<<x<<" "<<y<<endl;
// 	cout<<v<<" "<<f<<endl;
	c += (k * k) - f - v;
	put(x, y + 1);
	return;
}

int32_t main() {
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		k = i;
		put(0, 0);
		cout << c << endl;
		c = 0, v = 0;
		memset(board, 0, sizeof(board));
	}


}