#include <iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		int a[n + 1] {0};
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a, a + n + 1);
		if (m <= n) {
			sum = 0;
			for (int i = n - m + 1, j = 1; i <= n; i++, j++) {
				sum += a[i] * j;
			}
			cout << sum << endl;
			continue;
		}
		else if (m > n) {
			int l = m / n, p = m % n, j = 1;
			for (int i = n - p + 1; i <= n; i++, j++) {
				sum += (a[i] * j);
			}
			for (int i = 1; i < n - p + 1; i++, j++) {
				sum += (a[i] * j);
			}
			for (int i = n - p + 1; i <= n; i++) {
				sum += (a[i] * n);
			}
			l--;
			if (l > 0) {
				for (int i = 1; i <= n; i++) {
					sum += (a[i] * n * l);
				}
			}
			cout << sum << endl;

		}
	}

}