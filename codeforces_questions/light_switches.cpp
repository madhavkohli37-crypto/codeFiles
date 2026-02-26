#include <iostream>
#include<algorithm>
using namespace std;
#define int long long
bool check(int* p, int x, int k, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (((x + p[n - 1] - p[i]) / k) % 2 == 0) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
int32_t main() {

	int t;
	cin >> t;
	// cout << t << endl;
	for (int i = 0; i < t; i++) {
		// int time = -1;
		int n, k, flag = 0;
		cin >> n >> k;
		// cout << n << " " << k << endl;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			// cout << a[i] << " ";
		}
		sort(a, a + n);
		int j = 0;
		for ( j = 0; j < k; j++) {
			if (check(a, j, k, n)) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			cout << a[n - 1] + j << endl;
		}
		else {
			cout << -1 << endl;
		}

		// cout << endl;
	}

}