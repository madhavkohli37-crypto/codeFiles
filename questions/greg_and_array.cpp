#include <iostream>
using namespace std;
int main() {

	int n, m, k;
	cin >> n >> m >> k;
	int a[n + 1] {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l[m + 1], r[m + 1], d[m + 1];
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}
	int x, y;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		for (int i = x; i <= y; i++) {
			for (int j = l[i]; j <= r[i]; j++) {
				a[j] = a[j] + d[i];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}

}