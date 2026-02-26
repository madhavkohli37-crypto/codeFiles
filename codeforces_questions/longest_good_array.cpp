#include <iostream>
#include<cmath>
using namespace std;
#define int long long
int32_t main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int l, r;
		cin >> l >> r;
		int d = r - l;
		int n = (pow((1 + (4 * d * 2)), 0.5) - 1) / 2;
		cout << n + 1 << endl;
	}

}