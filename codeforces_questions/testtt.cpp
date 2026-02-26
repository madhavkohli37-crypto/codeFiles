#include <iostream>
using namespace std;
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		int a[n + 1] = {0} ;
		int sum1 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum1 += a[i];
		}
		int sum = 0, flag = 0;
		for (int i = n; i >= 1; i--, m--) {
			sum += a[i];
			if (m < 2) {
				sum += a[n];
				cout << sum << endl;
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		int b = m / (n - 1); b1 = (m) % (n - 1);
		sum1 -= a[n];
		sum += (b * (sum1 * (n - 1)));
		sum +=
		    // int a[3 + 1] = {0, 1, 2, 3};
		    // cout << a[1] << a[2] << a[3];

	}

}