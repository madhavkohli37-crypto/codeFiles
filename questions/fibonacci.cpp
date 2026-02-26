#include<iostream>
using namespace std;
#define int long long
int32_t main() {
	int n, temp;
	cin >> n;
	int x = 1, y = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			cout << 0 << " ";
			cout << endl;
			continue;
		}
		if (i == 2) {
			cout << 1 << " " << 1 << " ";
			cout << endl;
			continue;
		}
		if (i == 3) {
			y = 2;
		}
		for (int j = 1; j <= i; j++) {
			cout << y << " ";
			temp = x;
			x = y;
			y = temp + y;
		}
		cout << endl;
	}
}