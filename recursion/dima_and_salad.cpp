#include <bits/stdc++.h>
// #include<algorithm>
// #include<climits>
using namespace std;
int n, k;
int a[105], b[105];
int F(int x, int y) {
	if (x == n) {
		if (y == 0) {
			return 0;
		}
		else {
			return INT_MIN;
		}
	}
	int op1 = a[x] + F(x + 1, y + (a[x] - k * b[x]));
	int op2 = F(x + 1, y);
	int maxi = max(op1, op2);
	return maxi;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int ans = F(0, 0);
	if (ans <= 0) {
		cout << "-1";
	}
	else {
		cout << ans;
	}


}